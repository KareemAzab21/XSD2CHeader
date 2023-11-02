#ifndef V2G_CI_AC
#define V2G_CI_AC

/**
 * \file
 * \brief XMl Schema Parser and C structs generator for V2G xsd files

 * \author Kareem Azab
 * \date   2023-11-02

 *  Copyright (c) 2023-10-19 Kareem Azab
 */


#include "V2G_CI_CommonTypes.h"

 
























typedef struct {
    
        
    AC_CPDReqEnergyTransferModeType AC_CPDReqEnergyTransferMode;
        
    
} AC_ChargeParameterDiscoveryReqType;



typedef struct {
    
        
    AC_CPDResEnergyTransferModeType AC_CPDResEnergyTransferMode;
        
    
} AC_ChargeParameterDiscoveryResType;



typedef struct {
    
        
    CLReqControlModeType CLReqControlMode;
        
    
} AC_ChargeLoopReqType;



typedef struct {
    
        
    RationalNumberType EVSETargetFrequency;
        
    
        
    CLResControlModeType CLResControlMode;
        
    
} AC_ChargeLoopResType;



typedef struct {
    
        
    RationalNumberType EVMaximumChargePower;
        
    
        
    RationalNumberType EVMaximumChargePower_L2;
        
    
        
    RationalNumberType EVMaximumChargePower_L3;
        
    
        
    RationalNumberType EVMinimumChargePower;
        
    
        
    RationalNumberType EVMinimumChargePower_L2;
        
    
        
    RationalNumberType EVMinimumChargePower_L3;
        
    
} AC_CPDReqEnergyTransferModeType;



typedef struct {
    
        
    RationalNumberType EVSEMaximumChargePower;
        
    
        
    RationalNumberType EVSEMaximumChargePower_L2;
        
    
        
    RationalNumberType EVSEMaximumChargePower_L3;
        
    
        
    RationalNumberType EVSEMinimumChargePower;
        
    
        
    RationalNumberType EVSEMinimumChargePower_L2;
        
    
        
    RationalNumberType EVSEMinimumChargePower_L3;
        
    
        
    RationalNumberType EVSENominalFrequency;
        
    
        
    RationalNumberType MaximumPowerAsymmetry;
        
    
        
    RationalNumberType EVSEPowerRampLimitation;
        
    
        
    RationalNumberType EVSEPresentActivePower;
        
    
        
    RationalNumberType EVSEPresentActivePower_L2;
        
    
        
    RationalNumberType EVSEPresentActivePower_L3;
        
    
} AC_CPDResEnergyTransferModeType;



typedef struct {
    
        
    RationalNumberType EVMaximumDischargePower;
        
    
        
    RationalNumberType EVMaximumDischargePower_L2;
        
    
        
    RationalNumberType EVMaximumDischargePower_L3;
        
    
        
    RationalNumberType EVMinimumDischargePower;
        
    
        
    RationalNumberType EVMinimumDischargePower_L2;
        
    
        
    RationalNumberType EVMinimumDischargePower_L3;
        
    
} BPT_AC_CPDReqEnergyTransferModeType;



typedef struct {
    
        
    RationalNumberType EVSEMaximumDischargePower;
        
    
        
    RationalNumberType EVSEMaximumDischargePower_L2;
        
    
        
    RationalNumberType EVSEMaximumDischargePower_L3;
        
    
        
    RationalNumberType EVSEMinimumDischargePower;
        
    
        
    RationalNumberType EVSEMinimumDischargePower_L2;
        
    
        
    RationalNumberType EVSEMinimumDischargePower_L3;
        
    
} BPT_AC_CPDResEnergyTransferModeType;



typedef struct {
    
        
    RationalNumberType EVMaximumChargePower;
        
    
        
    RationalNumberType EVMaximumChargePower_L2;
        
    
        
    RationalNumberType EVMaximumChargePower_L3;
        
    
        
    RationalNumberType EVMinimumChargePower;
        
    
        
    RationalNumberType EVMinimumChargePower_L2;
        
    
        
    RationalNumberType EVMinimumChargePower_L3;
        
    
        
    RationalNumberType EVPresentActivePower;
        
    
        
    RationalNumberType EVPresentActivePower_L2;
        
    
        
    RationalNumberType EVPresentActivePower_L3;
        
    
        
    RationalNumberType EVPresentReactivePower;
        
    
        
    RationalNumberType EVPresentReactivePower_L2;
        
    
        
    RationalNumberType EVPresentReactivePower_L3;
        
    
} Scheduled_AC_CLReqControlModeType;



typedef struct {
    
        
    RationalNumberType EVSETargetActivePower;
        
    
        
    RationalNumberType EVSETargetActivePower_L2;
        
    
        
    RationalNumberType EVSETargetActivePower_L3;
        
    
        
    RationalNumberType EVSETargetReactivePower;
        
    
        
    RationalNumberType EVSETargetReactivePower_L2;
        
    
        
    RationalNumberType EVSETargetReactivePower_L3;
        
    
        
    RationalNumberType EVSEPresentActivePower;
        
    
        
    RationalNumberType EVSEPresentActivePower_L2;
        
    
        
    RationalNumberType EVSEPresentActivePower_L3;
        
    
} Scheduled_AC_CLResControlModeType;



typedef struct {
    
        
    RationalNumberType EVMaximumDischargePower;
        
    
        
    RationalNumberType EVMaximumDischargePower_L2;
        
    
        
    RationalNumberType EVMaximumDischargePower_L3;
        
    
        
    RationalNumberType EVMinimumDischargePower;
        
    
        
    RationalNumberType EVMinimumDischargePower_L2;
        
    
        
    RationalNumberType EVMinimumDischargePower_L3;
        
    
} BPT_Scheduled_AC_CLReqControlModeType;





typedef struct {
    
        
    RationalNumberType EVMaximumChargePower;
        
    
        
    RationalNumberType EVMaximumChargePower_L2;
        
    
        
    RationalNumberType EVMaximumChargePower_L3;
        
    
        
    RationalNumberType EVMinimumChargePower;
        
    
        
    RationalNumberType EVMinimumChargePower_L2;
        
    
        
    RationalNumberType EVMinimumChargePower_L3;
        
    
        
    RationalNumberType EVPresentActivePower;
        
    
        
    RationalNumberType EVPresentActivePower_L2;
        
    
        
    RationalNumberType EVPresentActivePower_L3;
        
    
        
    RationalNumberType EVPresentReactivePower;
        
    
        
    RationalNumberType EVPresentReactivePower_L2;
        
    
        
    RationalNumberType EVPresentReactivePower_L3;
        
    
} Dynamic_AC_CLReqControlModeType;



typedef struct {
    
        
    RationalNumberType EVSETargetActivePower;
        
    
        
    RationalNumberType EVSETargetActivePower_L2;
        
    
        
    RationalNumberType EVSETargetActivePower_L3;
        
    
        
    RationalNumberType EVSETargetReactivePower;
        
    
        
    RationalNumberType EVSETargetReactivePower_L2;
        
    
        
    RationalNumberType EVSETargetReactivePower_L3;
        
    
        
    RationalNumberType EVSEPresentActivePower;
        
    
        
    RationalNumberType EVSEPresentActivePower_L2;
        
    
        
    RationalNumberType EVSEPresentActivePower_L3;
        
    
} Dynamic_AC_CLResControlModeType;



typedef struct {
    
        
    RationalNumberType EVMaximumDischargePower;
        
    
        
    RationalNumberType EVMaximumDischargePower_L2;
        
    
        
    RationalNumberType EVMaximumDischargePower_L3;
        
    
        
    RationalNumberType EVMinimumDischargePower;
        
    
        
    RationalNumberType EVMinimumDischargePower_L2;
        
    
        
    RationalNumberType EVMinimumDischargePower_L3;
        
    
        
    RationalNumberType EVMaximumV2XEnergyRequest;
        
    
        
    RationalNumberType EVMinimumV2XEnergyRequest;
        
    
} BPT_Dynamic_AC_CLReqControlModeType;





#endif // V2G_CI_AC