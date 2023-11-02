#ifndef V2G_CI_ACDP
#define V2G_CI_ACDP

/**
 * \file
 * \brief XMl Schema Parser and C structs generator for V2G xsd files

 * \author Kareem Azab
 * \date   2023-11-02

 *  Copyright (c) 2023-10-19 Kareem Azab
 */


#include "V2G_CI_CommonTypes.h"

#include <stdbool.h>
 










typedef enum {
    
    
    StateA,
    
    StateB,
    
    StateC,
    
    StateD,
    
    StateE,
    
} cpStatusType;

typedef enum {
    
    
    OK_NoEVError,
    
    FAILED,
    
    FAILED_EmergencyEvent,
    
    FAILED_Breaker,
    
    FAILED_RESSTemperatureInhibit,
    
    FAILED_RESS,
    
    FAILED_ChargingCurrentDifferential,
    
    FAILED_ChargingVoltageOutOfRange,
    
    FAILED_Reserved1,
    
    FAILED_Reserved2,
    
} errorCodeType;

typedef enum {
    
    
    Invalid,
    
    Safe,
    
    Warning,
    
    Fault,
    
} isolationStatusType;

typedef enum {
    
    
    State_A,
    
    State_B,
    
    State_C,
    
    State_D,
    
} electricalChargingDeviceStatusType;

typedef enum {
    
    
    Home,
    
    Moving,
    
    EndPosition,
    
} mechanicalChargingDeviceStatusType;






typedef struct {
    
        
    bool EVMobilityStatus;
        
    
        
    bool EVPositioningSupport;
        
    
} ACDP_VehiclePositioningReqType;



typedef struct {
    
        
    processingType EVSEProcessing;
        
    
        
    bool EVSEPositioningSupport;
        
    
        
    short EVRelativeXDeviation;
        
    
        
    short EVRelativeYDeviation;
        
    
        
    short ContactWindowXc;
        
    
        
    short ContactWindowYc;
        
    
        
    bool EVInChargePosition;
        
    
} ACDP_VehiclePositioningResType;



typedef struct {
    
        
    electricalChargingDeviceStatusType EVElectricalChargingDeviceStatus;
        
    
} ACDP_ConnectReqType;



typedef struct {
    
        
    processingType EVSEProcessing;
        
    
        
    electricalChargingDeviceStatusType EVSEElectricalChargingDeviceStatus;
        
    
        
    mechanicalChargingDeviceStatusType EVSEMechanicalChargingDeviceStatus;
        
    
} ACDP_ConnectResType;



typedef struct {
    
        
    EVTechnicalStatusType EVTechnicalStatus;
        
    
} ACDP_SystemStatusReqType;



typedef struct {
    
        
    mechanicalChargingDeviceStatusType EVSEMechanicalChargingDeviceStatus;
        
    
        
    bool EVSEReadyToCharge;
        
    
        
    isolationStatusType EVSEIsolationStatus;
        
    
        
    bool EVSEDisabled;
        
    
        
    bool EVSEUtilityInterruptEvent;
        
    
        
    bool EVSEEmergencyShutdown;
        
    
        
    bool EVSEMalfunction;
        
    
        
    bool EVInChargePosition;
        
    
        
    bool EVAssociationStatus;
        
    
} ACDP_SystemStatusResType;



typedef struct {
    
        
    bool EVReadyToCharge;
        
    
        
    bool EVImmobilizationRequest;
        
    
        
    bool EVImmobilized;
        
    
        
    RationalNumberType EVWLANStrength;
        
    
        
    cpStatusType EVCPStatus;
        
    
        
    percentValueType EVSOC;
        
    
        
    errorCodeType EVErrorCode;
        
    
        
    bool EVTimeout;
        
    
} EVTechnicalStatusType;



#endif // V2G_CI_ACDP