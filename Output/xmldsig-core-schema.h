#ifndef XMLDSIG_CORE_SCHEMA
#define XMLDSIG_CORE_SCHEMA

/**
 * \file
 * \brief XMl Schema Parser and C structs generator for V2G xsd files

 * \author Kareem Azab
 * \date   2023-11-02

 *  Copyright (c) 2023-10-19 Kareem Azab
 */



 























typedef char CryptoBinary;

typedef char DigestValueType;

typedef int HMACOutputLengthType;








typedef struct {
    
        
    SignedInfoType SignedInfo;
        
    
        
    SignatureValueType SignatureValue;
        
    
        
    KeyInfoType KeyInfo;
        
    
        
    ObjectType Object;
        
    
        
    char* Id;
        
    
} SignatureType;



typedef struct {
    
        
    char* Id;
        
    
} SignatureValueType;



typedef struct {
    
        
    CanonicalizationMethodType CanonicalizationMethod;
        
    
        
    SignatureMethodType SignatureMethod;
        
    
        
    ReferenceType Reference;
        
    
        
    char* Id;
        
    
} SignedInfoType;



typedef struct {
    
        
    char Algorithm;
        
    
} CanonicalizationMethodType;



typedef struct {
    
        
    HMACOutputLengthType HMACOutputLength;
        
    
        
    char Algorithm;
        
    
} SignatureMethodType;



typedef struct {
    
        
    TransformsType Transforms;
        
    
        
    DigestMethodType DigestMethod;
        
    
        
    DigestValueType DigestValue;
        
    
        
    char* Id;
        
    
} ReferenceType;



typedef struct {
    
        
    TransformType Transform;
        
    
} TransformsType;



typedef struct {
    
        
    char Algorithm;
        
    
} TransformType;



typedef struct {
    
        
    char Algorithm;
        
    
} DigestMethodType;



typedef struct {
    
        
    char* Id;
        
    
} KeyInfoType;





typedef struct {
    
        
    TransformsType Transforms;
        
    
        
    char URI;
        
    
} RetrievalMethodType;



typedef struct {
    
        
    union {
            
        X509IssuerSerialType X509IssuerSerial;
            
        char X509SKI;
            
        char X509SubjectName;
            
        char X509Certificate;
            
        char X509CRL;
            
    };
        
    
} X509DataType;



typedef struct {
    
        
    char X509IssuerName;
        
    
        
    int X509SerialNumber;
        
    
} X509IssuerSerialType;





typedef struct {
    
        
    char SPKISexp;
        
    
} SPKIDataType;



typedef struct {
    
        
    char* Id;
        
    
} ObjectType;



typedef struct {
    
        
    ReferenceType Reference;
        
    
        
    char* Id;
        
    
} ManifestType;



typedef struct {
    
        
    SignaturePropertyType SignatureProperty;
        
    
        
    char* Id;
        
    
} SignaturePropertiesType;



typedef struct {
    
        
    char Target;
        
    
} SignaturePropertyType;



typedef struct {
    
        
    CryptoBinary G;
        
    
        
    CryptoBinary Y;
        
    
        
    CryptoBinary J;
        
    
} DSAKeyValueType;



typedef struct {
    
        
    CryptoBinary Modulus;
        
    
        
    CryptoBinary Exponent;
        
    
} RSAKeyValueType;









#endif // XMLDSIG_CORE_SCHEMA