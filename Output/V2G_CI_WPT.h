#ifndef V2G_CI_WPT
#define V2G_CI_WPT

/**
 * \file
 * \brief XMl Schema Parser and C structs generator for V2G xsd files

 * \author Kareem Azab
 * \date   2023-11-02

 *  Copyright (c) 2023-10-19 Kareem Azab
 */


#include "V2G_CI_CommonTypes.h"

#include <stdbool.h>
 



































typedef char bssidType;

typedef char ipaddressType;

typedef char WPT_DataContainerType;



typedef enum {
    
    
    Manual,
    
    LF_TxEV,
    
    LF_TxPrimaryDevice,
    
    LPE,
    
    Proprietary,
    
} WPT_FinePositioningMethodType;

typedef enum {
    
    
    Externalconfirmation,
    
    LPE,
    
    LF_TxEV,
    
    LF_TxPrimaryDevice,
    
    Optical,
    
    Proprietary,
    
} WPT_PairingMethodType;

typedef enum {
    
    
    PowerCheck,
    
    LPE,
    
    Proprietary,
    
} WPT_AlignmentCheckMethodType;

typedef enum {
    
    
    EVPCNoIssue,
    
    EVPCTempOverheatDetected,
    
    EVPCPowerTransferAnomalyDetected,
    
    EVPCAnomalyDetected,
    
} WPT_EVPCChargeDiagnosticsType;

typedef enum {
    
    
    SPCNoIssue,
    
    SPCFODDetected,
    
    SPCLOPDetected,
    
    SPCTempOverheatDetected,
    
    SPCPowerTransferAnomalyDetected,
    
    SPCAnomalyDetected,
    
} WPT_SPCChargeDiagnosticsType;

typedef enum {
    
    
    MF_WPT1,
    
    MF_WPT2,
    
    MF_WPT3,
    
    MF_WPT4,
    
} WPT_PowerClassType;

typedef enum {
    
    
    EVResultUnknown,
    
    EVResultSuccess,
    
    EVResultFailed,
    
} WPT_EVResultType;






typedef struct {
    
        
    processingType EVProcessing;
        
    
        
    WPT_FinePositioningMethodListType EVDeviceFinePositioningMethodList;
        
    
        
    WPT_PairingMethodListType EVDevicePairingMethodList;
        
    
        
    WPT_AlignmentCheckMethodListType EVDeviceAlignmentCheckMethodList;
        
    
        
    unsigned short NaturalOffset;
        
    
        
    WPT_DataContainerType VendorSpecificDataContainer[256];
        
    
        
    WPT_LF_SystemSetupDataType LF_SystemSetupData;
        
    
} WPT_FinePositioningSetupReqType;



typedef struct {
    
        
    WPT_FinePositioningMethodListType PrimaryDeviceFinePositioningMethodList;
        
    
        
    WPT_PairingMethodListType PrimaryDevicePairingMethodList;
        
    
        
    WPT_AlignmentCheckMethodListType PrimaryDeviceAlignmentCheckMethodList;
        
    
        
    unsigned short NaturalOffset;
        
    
        
    WPT_DataContainerType VendorSpecificDataContainer[256];
        
    
        
    WPT_LF_SystemSetupDataType LF_SystemSetupData;
        
    
} WPT_FinePositioningSetupResType;



typedef struct {
    
        
    processingType EVProcessing;
        
    
        
    WPT_EVResultType EVResultCode;
        
    
        
    WPT_DataContainerType VendorSpecificDataContainer[256];
        
    
        
    WPT_LF_DataPackageListType WPT_LF_DataPackageList;
        
    
} WPT_FinePositioningReqType;



typedef struct {
    
        
    processingType EVSEProcessing;
        
    
        
    WPT_DataContainerType VendorSpecificDataContainer[256];
        
    
        
    WPT_LF_DataPackageListType WPT_LF_DataPackageList;
        
    
} WPT_FinePositioningResType;



typedef struct {
    
        
    processingType EVProcessing;
        
    
        
    numericIDType ObservedIDCode;
        
    
        
    WPT_EVResultType EVResultCode;
        
    
        
    WPT_DataContainerType VendorSpecificDataContainer[256];
        
    
} WPT_PairingReqType;



typedef struct {
    
        
    processingType EVSEProcessing;
        
    
        
    numericIDType ObservedIDCode;
        
    
        
    AlternativeSECCListType AlternativeSECCList;
        
    
        
    WPT_DataContainerType VendorSpecificDataContainer[256];
        
    
} WPT_PairingResType;



typedef struct {
    
        
    RationalNumberType EVPCMaxReceivablePower;
        
    
        
    unsigned short SDMaxGroundClearence;
        
    
        
    unsigned short SDMinGroundClearence;
        
    
        
    RationalNumberType EVPCNaturalFrequency;
        
    
        
    bool EVPCDeviceLocalControl;
        
    
        
    WPT_DataContainerType VendorSpecificDataContainer[256];
        
    
} WPT_ChargeParameterDiscoveryReqType;



typedef struct {
    
        
    WPT_PowerClassType PDInputPowerClass;
        
    
        
    RationalNumberType SDMinOutputPower;
        
    
        
    RationalNumberType SDMaxOutputPower;
        
    
        
    unsigned short SDMaxGroundClearanceSupport;
        
    
        
    unsigned short SDMinGroundClearanceSupport;
        
    
        
    RationalNumberType PDMinCoilCurrent;
        
    
        
    RationalNumberType PDMaxCoilCurrent;
        
    
        
    WPT_DataContainerType SDManufacturerSpecificDataContainer[256];
        
    
} WPT_ChargeParameterDiscoveryResType;



typedef struct {
    
        
    processingType EVProcessing;
        
    
        
    RationalNumberType TargetCoilCurrent;
        
    
        
    WPT_EVResultType EVResultCode;
        
    
        
    WPT_DataContainerType VendorSpecificDataContainer[256];
        
    
} WPT_AlignmentCheckReqType;



typedef struct {
    
        
    processingType EVSEProcessing;
        
    
        
    RationalNumberType PowerTransmitted;
        
    
        
    RationalNumberType SupplyDeviceCurrent;
        
    
        
    WPT_DataContainerType VendorSpecificDataContainer[256];
        
    
} WPT_AlignmentCheckResType;



typedef struct {
    
        
    RationalNumberType EVPCPowerRequest;
        
    
        
    RationalNumberType EVPCPowerOutput;
        
    
        
    WPT_EVPCChargeDiagnosticsType EVPCChargeDiagnostics;
        
    
        
    RationalNumberType EVPCOperatingFrequency;
        
    
        
    WPT_EVPCPowerControlParameterType EVPCPowerControlParameter;
        
    
        
    WPT_DataContainerType ManufacturerSpecificDataContainer[256];
        
    
} WPT_ChargeLoopReqType;



typedef struct {
    
        
    RationalNumberType EVPCPowerRequest;
        
    
        
    RationalNumberType SDPowerInput;
        
    
        
    RationalNumberType SPCMaxOutputPowerLimit;
        
    
        
    RationalNumberType SPCMinOutputPowerLimit;
        
    
        
    WPT_SPCChargeDiagnosticsType SPCChargeDiagnostics;
        
    
        
    RationalNumberType SPCOperatingFrequency;
        
    
        
    WPT_SPCPowerControlParameterType SPCPowerControlParameter;
        
    
        
    WPT_DataContainerType ManufacturerSpecificDataContainer[256];
        
    
} WPT_ChargeLoopResType;



typedef struct {
    
        
    WPT_FinePositioningMethodType WPT_FinePositioningMethod;
        
    
} WPT_FinePositioningMethodListType;



typedef struct {
    
        
    WPT_PairingMethodType WPT_PairingMethod;
        
    
} WPT_PairingMethodListType;



typedef struct {
    
        
    WPT_AlignmentCheckMethodType WPT_AlignmentCheckMethod;
        
    
} WPT_AlignmentCheckMethodListType;



typedef struct {
    
        
    RationalNumberType EVPCCoilCurrentRequest;
        
    
        
    RationalNumberType EVPCCoilCurrentInformation;
        
    
        
    RationalNumberType EVPCCurrentOutputInformation;
        
    
        
    RationalNumberType EVPCVoltageOutputInformation;
        
    
} WPT_EVPCPowerControlParameterType;



typedef struct {
    
        
    RationalNumberType SPCPrimaryDeviceCoilCurrentInformation;
        
    
} WPT_SPCPowerControlParameterType;



typedef struct {
    
        
    union {
            
        WPT_LF_TransmitterDataType LF_TransmitterSetupData;
            
        WPT_LF_ReceiverDataType LF_ReceiverSetupData;
            
    };
        
    
} WPT_LF_SystemSetupDataType;



typedef struct {
    
        
    unsigned char NumberOfTransmitters;
        
    
        
    RationalNumberType SignalFrequency;
        
    
        
    WPT_TxRxSpecDataType TxSpecData;
        
    
        
    WPT_TxRxPackageSpecDataType TxPackageSpecData;
        
    
} WPT_LF_TransmitterDataType;



typedef struct {
    
        
    unsigned char NumberOfReceivers;
        
    
        
    WPT_TxRxSpecDataType RxSpecData;
        
    
} WPT_LF_ReceiverDataType;



typedef struct {
    
        
    numericIDType TxRxIdentifier;
        
    
        
    WPT_CoordinateXYZType TxRxPosition;
        
    
        
    WPT_CoordinateXYZType TxRxOrientation;
        
    
} WPT_TxRxSpecDataType;



typedef struct {
    
        
    short Coord_X;
        
    
        
    short Coord_Y;
        
    
        
    short Coord_Z;
        
    
} WPT_CoordinateXYZType;



typedef struct {
    
        
    WPT_TxRxPulseOrderType PulseSequenceOrder;
        
    
        
    unsigned short PulseSeparationTime;
        
    
        
    unsigned short PulseDuration;
        
    
        
    unsigned short PackageSeparationTime;
        
    
} WPT_TxRxPackageSpecDataType;



typedef struct {
    
        
    unsigned short IndexNumber;
        
    
        
    numericIDType TxRxIdentifier;
        
    
} WPT_TxRxPulseOrderType;



typedef struct {
    
        
    WPT_LF_TxDataType WPT_LF_TxDataList;
        
    
} WPT_LF_TxDataListType;



typedef struct {
    
        
    numericIDType TxIdentifier;
        
    
        
    RationalNumberType EIRP;
        
    
} WPT_LF_TxDataType;



typedef struct {
    
        
    WPT_LF_RxDataType WPT_LF_RxDataList;
        
    
} WPT_LF_RxDataListType;



typedef struct {
    
        
    numericIDType RxIdentifier;
        
    
        
    WPT_LF_RxRSSIListType RSSIData;
        
    
} WPT_LF_RxDataType;



typedef struct {
    
        
    WPT_LF_RxRSSIType RSSIDataList;
        
    
} WPT_LF_RxRSSIListType;



typedef struct {
    
        
    numericIDType TxIdentifier;
        
    
        
    RationalNumberType RSSI;
        
    
} WPT_LF_RxRSSIType;



typedef struct {
    
        
    unsigned char NumPackages;
        
    
        
    WPT_LF_DataPackageType WPT_LF_DataPackage;
        
    
} WPT_LF_DataPackageListType;



typedef struct {
    
        
    unsigned char PackageIndex;
        
    
        
    union {
            
        WPT_LF_TxDataListType LF_TxData;
            
        WPT_LF_RxDataListType LF_RxData;
            
    };
        
    
} WPT_LF_DataPackageType;



typedef struct {
    
        
    AlternativeSECCType AlternativeSECC;
        
    
} AlternativeSECCListType;



typedef struct {
    
        
    identifierType SSID;
        
    
        
    bssidType BSSID[12];
        
    
        
    ipaddressType IPAddress[39];
        
    
        
    unsigned short Port;
        
    
} AlternativeSECCType;









#endif // V2G_CI_WPT