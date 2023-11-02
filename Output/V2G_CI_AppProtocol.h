#ifndef V2G_CI_APPPROTOCOL
#define V2G_CI_APPPROTOCOL

/**
 * \file
 * \brief XMl Schema Parser and C structs generator for V2G xsd files

 * \author Kareem Azab
 * \date   2023-11-02

 *  Copyright (c) 2023-10-19 Kareem Azab
 */



 




typedef unsigned char idType;

typedef char protocolNameType;

typedef char protocolNamespaceType;

typedef unsigned char priorityType;



typedef enum {
    
    
    OK_SuccessfulNegotiation,
    
    OK_SuccessfulNegotiationWithMinorDeviation,
    
    Failed_NoNegotiation,
    
} responseCodeType;






typedef struct {
    
        
    protocolNamespaceType ProtocolNamespace[100];
        
    
        
    unsigned int VersionNumberMajor;
        
    
        
    unsigned int VersionNumberMinor;
        
    
        
    idType SchemaID;
        
    
        
    priorityType Priority;
        
    
} AppProtocolType;



typedef struct {
    
        
    AppProtocolType AppProtocol;
        
    
} supportedAppProtocolReq;



typedef struct {
    
        
    responseCodeType ResponseCode;
        
    
        
    idType SchemaID;
        
    
} supportedAppProtocolRes;











#endif // V2G_CI_APPPROTOCOL