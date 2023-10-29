import sys
import os
from datetime import date
import xml.etree.ElementTree as ET
from jinja2 import Environment, FileSystemLoader
from itertools import chain


def get_guard_name(xsd_filename):
    # Extract the filename from the path
    base_name = os.path.basename(xsd_filename)
    name_without_extension = os.path.splitext(
        base_name)[0]  # Remove the .xsd extension
    return name_without_extension.upper().replace('.', '_').replace('-', '_')


def xsd_to_c_header(xsd_filename):
    tree = ET.parse(xsd_filename)
    root = tree.getroot()
    schemas = []
    new_schemas = []

    namespace = {"xs": "http://www.w3.org/2001/XMLSchema"}

    # Find all import elements
    import_elements = root.findall("xs:import", namespace)

    for import_element in import_elements:
        schema_location = import_element.attrib.get("schemaLocation", None)
        if schema_location:
            schemas.append(schema_location)

    # Convert schemaLocation extension from .xsd to .h
    if schemas:
        new_schemas = [schema.replace('.xsd', '.h') for schema in schemas]

    return new_schemas


def get_output_filename(xsd_filename):
    # Extract the filename from the path
    base_name = os.path.basename(xsd_filename)
    name_without_extension = os.path.splitext(
        base_name)[0]  # Remove the .xsd extension
    return name_without_extension + ".h"  # Append .h extension


def generate_c_structs_from_xml(xml_filename, guard_name, date, include):
    tree = ET.parse(xml_filename)
    root = tree.getroot()
    bool_found = False

    # Namespace mapping for XML schema
    ns = {"xs": "http://www.w3.org/2001/XMLSchema"}

    def generate_c_type_mapping(root, ns):
        # Default mappings for standard XSD data types to C data types
        mapping = {
            "unsignedInt": "unsigned int",
            "unsignedByte": "unsigned char",
            "unsignedShort": "unsigned short",
            "unsignedLong": "unsigned long",
            "string": "char",
            "base64Binary": "char",
            "byte": "char",
            "hexBinary": "char",
            "boolean": "bool",
            "anyURI": "char",
        }

        # Find all simpleType elements in the XSD and add them to the mapping
        for simple_type in root.findall('xs:simpleType', ns):
            type_name = simple_type.attrib['name']
            mapping[type_name] = type_name
        return mapping

    c_mapping = generate_c_type_mapping(root, ns)

    # Convert XML types to C types
    def get_c_type(xml_type):
        return c_mapping.get(xml_type, xml_type)

    def generate_max_length_mapping(root, ns):
        max_length_mapping = {}
        for simple_type in root.findall('xs:simpleType', ns):
            type_name = simple_type.attrib['name']
            restriction = simple_type.find('xs:restriction', ns)
            if restriction is not None:
                max_length = restriction.find('xs:maxLength', ns)
                if max_length is not None:
                    max_length_mapping[type_name] = int(
                        max_length.attrib['value'])
        return max_length_mapping

    max_length_mapping = generate_max_length_mapping(root, ns)

    structs = []
    enums = []
    found = False

    def find_element_by_name(name):
        """Find an xs:element by its name attribute."""
        for element in root.findall('xs:element', ns):
            if element.attrib.get('name') == name:
                return element
        return None

    def handle_element(element):
        global bool_found
        """Process an individual xs:element and return its field representation."""
        field_name = element.attrib.get('name')
        field_type = element.attrib.get('type', '').split(':')[-1]
        # Handle ref attributes
        if 'ref' in element.attrib:
            ref_name = element.attrib['ref']
            ref_name = ref_name.split(':')[-1]
            field_name = ref_name
            field_type = ref_name
        # print(field_name, field_type)
        return {"name": field_name, "type": get_c_type(field_type)}

    # ... [Your existing code before the loops]

    for complex_type in root.findall('xs:complexType', ns):
        type_name = complex_type.attrib['name']
        fields = []
        elements_seq = complex_type.findall(
            'xs:complexContent/xs:extension/xs:sequence/xs:element', ns)
        elements_choice = complex_type.findall(
            'xs:sequence/xs:choice/xs:element', ns)
        elements_original = complex_type.findall('xs:sequence/xs:element', ns)

        for element in chain(elements_seq, elements_choice, elements_original):
            fields.append(handle_element(element))
        for field in fields:
            if field['type'] == 'bool':
                bool_found = True
                break
        structs.append({"name": type_name, "fields": fields})

    for element in root.findall('xs:element', ns):
        complex_type = element.find('xs:complexType', ns)
        if complex_type is not None:
            type_name = element.attrib['name']
            fields = []
            for sub_element in complex_type.findall('xs:sequence/xs:element', ns):
                field_name = sub_element.attrib['name']
                field_type = sub_element.attrib['type'].split(':')[-1]
                if field_type == 'boolean':
                    bool_found = True
                fields.append(
                    {"name": field_name, "type": get_c_type(field_type)})
            structs.append({"name": type_name, "fields": fields})

    # For Generating Enums
    for simple_type in root.findall('xs:simpleType', ns):
        type_name = simple_type.attrib['name']
        restriction = simple_type.find('xs:restriction', ns)

        if restriction is not None:
            enumerations = restriction.findall('xs:enumeration', ns)
            if enumerations:
                # If enumerations are found, add them to the 'enums' list
                values = [enum_val.attrib['value'].replace(
                    ' ', '').replace('-', '_') for enum_val in enumerations]
                enums.append({"name": type_name, "values": values})
        # For Generating simple typedefs
    for simple_type in root.findall('xs:simpleType', ns):
        type_name = simple_type.attrib['name']
        base_type = simple_type.find(
            'xs:restriction', ns).attrib['base'].split(':')[-1]

        for enum in enums:
            if enum['name'] == type_name:
                found = True
                break
        if not found:
            structs.append(
                {"name": type_name, "type": get_c_type(base_type), "fields": None})
        found = False
    # Use Jinja to render the C code
    env = Environment(loader=FileSystemLoader('.'))
    template = env.get_template('c_struct_template.jinja')
    c_code = template.render(
        structs=structs, guard_name=guard_name, date=date, enums=enums, max_length=max_length_mapping, include=include, boolean=bool_found)

    return c_code


def generate(xml_filename):

    today = date.today()
    guard = get_guard_name(xml_filename)
    include = xsd_to_c_header(xml_filename)
    c_structs = generate_c_structs_from_xml(
        xml_filename, guard, today, include)
    output_filename = get_output_filename(xml_filename)

    if not os.path.exists("Output"):
        os.mkdir("Output")
    with open(os.path.join("Output", output_filename), 'w') as f:
        f.write(c_structs)

    return "C structs have been written to /Output/" + output_filename
