#ifndef V2G_CI_DC
#define V2G_CI_DC

/**
 * \file
 * \brief XMl Schema Parser and C structs generator for V2G xsd files

 * \author Kareem Azab
 * \date   2023-10-26

 *  Copyright (c) 2023-10-26 Kareem Azab
 */


#include "V2G_CI_CommonTypes.h"

#include <stdbool.h>
 



typedef  DC_CableCheckReqType;


























typedef struct {
    
    DC_CPDReqEnergyTransferModeType DC_CPDReqEnergyTransferMode;
    
} DC_ChargeParameterDiscoveryReqType;



typedef struct {
    
    DC_CPDResEnergyTransferModeType DC_CPDResEnergyTransferMode;
    
} DC_ChargeParameterDiscoveryResType;





typedef struct {
    
    processingType EVSEProcessing;
    
} DC_CableCheckResType;



typedef struct {
    
    processingType EVProcessing;
    
    RationalNumberType EVPresentVoltage;
    
    RationalNumberType EVTargetVoltage;
    
} DC_PreChargeReqType;



typedef struct {
    
    RationalNumberType EVSEPresentVoltage;
    
} DC_PreChargeResType;



typedef struct {
    
    RationalNumberType EVPresentVoltage;
    
     None;
    
} DC_ChargeLoopReqType;



typedef struct {
    
    RationalNumberType EVSEPresentCurrent;
    
    RationalNumberType EVSEPresentVoltage;
    
    bool EVSEPowerLimitAchieved;
    
    bool EVSECurrentLimitAchieved;
    
    bool EVSEVoltageLimitAchieved;
    
     None;
    
} DC_ChargeLoopResType;



typedef struct {
    
    processingType EVProcessing;
    
} DC_WeldingDetectionReqType;



typedef struct {
    
    RationalNumberType EVSEPresentVoltage;
    
} DC_WeldingDetectionResType;



typedef struct {
    
    RationalNumberType EVMaximumChargePower;
    
    RationalNumberType EVMinimumChargePower;
    
    RationalNumberType EVMaximumChargeCurrent;
    
    RationalNumberType EVMinimumChargeCurrent;
    
    RationalNumberType EVMaximumVoltage;
    
    RationalNumberType EVMinimumVoltage;
    
    percentValueType TargetSOC;
    
} DC_CPDReqEnergyTransferModeType;



typedef struct {
    
    RationalNumberType EVSEMaximumChargePower;
    
    RationalNumberType EVSEMinimumChargePower;
    
    RationalNumberType EVSEMaximumChargeCurrent;
    
    RationalNumberType EVSEMinimumChargeCurrent;
    
    RationalNumberType EVSEMaximumVoltage;
    
    RationalNumberType EVSEMinimumVoltage;
    
    RationalNumberType EVSEPowerRampLimitation;
    
} DC_CPDResEnergyTransferModeType;



typedef struct {
    
    RationalNumberType EVMaximumDischargePower;
    
    RationalNumberType EVMinimumDischargePower;
    
    RationalNumberType EVMaximumDischargeCurrent;
    
    RationalNumberType EVMinimumDischargeCurrent;
    
} BPT_DC_CPDReqEnergyTransferModeType;



typedef struct {
    
    RationalNumberType EVSEMaximumDischargePower;
    
    RationalNumberType EVSEMinimumDischargePower;
    
    RationalNumberType EVSEMaximumDischargeCurrent;
    
    RationalNumberType EVSEMinimumDischargeCurrent;
    
} BPT_DC_CPDResEnergyTransferModeType;



typedef struct {
    
    RationalNumberType EVTargetCurrent;
    
    RationalNumberType EVTargetVoltage;
    
    RationalNumberType EVMaximumChargePower;
    
    RationalNumberType EVMinimumChargePower;
    
    RationalNumberType EVMaximumChargeCurrent;
    
    RationalNumberType EVMaximumVoltage;
    
    RationalNumberType EVMinimumVoltage;
    
} Scheduled_DC_CLReqControlModeType;



typedef struct {
    
    RationalNumberType EVSEMaximumChargePower;
    
    RationalNumberType EVSEMinimumChargePower;
    
    RationalNumberType EVSEMaximumChargeCurrent;
    
    RationalNumberType EVSEMaximumVoltage;
    
} Scheduled_DC_CLResControlModeType;



typedef struct {
    
    RationalNumberType EVMaximumDischargePower;
    
    RationalNumberType EVMinimumDischargePower;
    
    RationalNumberType EVMaximumDischargeCurrent;
    
} BPT_Scheduled_DC_CLReqControlModeType;



typedef struct {
    
    RationalNumberType EVSEMaximumDischargePower;
    
    RationalNumberType EVSEMinimumDischargePower;
    
    RationalNumberType EVSEMaximumDischargeCurrent;
    
    RationalNumberType EVSEMinimumVoltage;
    
} BPT_Scheduled_DC_CLResControlModeType;



typedef struct {
    
    RationalNumberType EVMaximumChargePower;
    
    RationalNumberType EVMinimumChargePower;
    
    RationalNumberType EVMaximumChargeCurrent;
    
    RationalNumberType EVMaximumVoltage;
    
    RationalNumberType EVMinimumVoltage;
    
} Dynamic_DC_CLReqControlModeType;



typedef struct {
    
    RationalNumberType EVSEMaximumChargePower;
    
    RationalNumberType EVSEMinimumChargePower;
    
    RationalNumberType EVSEMaximumChargeCurrent;
    
    RationalNumberType EVSEMaximumVoltage;
    
} Dynamic_DC_CLResControlModeType;



typedef struct {
    
    RationalNumberType EVMaximumDischargePower;
    
    RationalNumberType EVMinimumDischargePower;
    
    RationalNumberType EVMaximumDischargeCurrent;
    
    RationalNumberType EVMaximumV2XEnergyRequest;
    
    RationalNumberType EVMinimumV2XEnergyRequest;
    
} BPT_Dynamic_DC_CLReqControlModeType;



typedef struct {
    
    RationalNumberType EVSEMaximumDischargePower;
    
    RationalNumberType EVSEMinimumDischargePower;
    
    RationalNumberType EVSEMaximumDischargeCurrent;
    
    RationalNumberType EVSEMinimumVoltage;
    
} BPT_Dynamic_DC_CLResControlModeType;




#endif // V2G_CI_DC