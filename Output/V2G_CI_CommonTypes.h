#ifndef V2G_CI_COMMONTYPES
#define V2G_CI_COMMONTYPES

/**
 * \file
 * \brief XMl Schema Parser and C structs generator for V2G xsd files

 * \author Kareem Azab
 * \date   2023-11-02

 *  Copyright (c) 2023-10-19 Kareem Azab
 */


#include "xmldsig-core-schema.h"

#include <stdbool.h>
 























typedef unsigned int numericIDType;

typedef char sessionIDType;

typedef char percentValueType;

typedef char identifierType;

typedef char nameType;

typedef char descriptionType;

typedef char meterIDType;

typedef char meterSignatureType;



typedef enum {
    
    
    Pause,
    
    ExitStandby,
    
    Terminate,
    
    ScheduleRenegotiation,
    
    ServiceRenegotiation,
    
    MeteringConfirmation,
    
} evseNotificationType;

typedef enum {
    
    
    Finished,
    
    Ongoing,
    
    Ongoing_WaitingForCustomerInteraction,
    
} processingType;

typedef enum {
    
    
    OK,
    
    OK_CertificateExpiresSoon,
    
    OK_NewSessionEstablished,
    
    OK_OldSessionJoined,
    
    OK_PowerToleranceConfirmed,
    
    WARNING_AuthorizationSelectionInvalid,
    
    WARNING_CertificateExpired,
    
    WARNING_CertificateNotYetValid,
    
    WARNING_CertificateRevoked,
    
    WARNING_CertificateValidationError,
    
    WARNING_ChallengeInvalid,
    
    WARNING_EIMAuthorizationFailure,
    
    WARNING_eMSPUnknown,
    
    WARNING_EVPowerProfileViolation,
    
    WARNING_GeneralPnCAuthorizationError,
    
    WARNING_NoCertificateAvailable,
    
    WARNING_NoContractMatchingPCIDFound,
    
    WARNING_PowerToleranceNotConfirmed,
    
    WARNING_ScheduleRenegotiationFailed,
    
    WARNING_StandbyNotAllowed,
    
    WARNING_WPT,
    
    FAILED,
    
    FAILED_AssociationError,
    
    FAILED_ContactorError,
    
    FAILED_EVPowerProfileInvalid,
    
    FAILED_EVPowerProfileViolation,
    
    FAILED_MeteringSignatureNotValid,
    
    FAILED_NoEnergyTransferServiceSelected,
    
    FAILED_NoServiceRenegotiationSupported,
    
    FAILED_PauseNotAllowed,
    
    FAILED_PowerDeliveryNotApplied,
    
    FAILED_PowerToleranceNotConfirmed,
    
    FAILED_ScheduleRenegotiation,
    
    FAILED_ScheduleSelectionInvalid,
    
    FAILED_SequenceError,
    
    FAILED_ServiceIDInvalid,
    
    FAILED_ServiceSelectionInvalid,
    
    FAILED_SignatureError,
    
    FAILED_UnknownSession,
    
    FAILED_WrongChargeParameter,
    
} responseCodeType;






typedef struct {
    
        
    sessionIDType SessionID;
        
    
        
    unsigned long TimeStamp;
        
    
        
    SignatureType Signature;
        
    
} MessageHeaderType;



typedef struct {
    
        
    MessageHeaderType Header;
        
    
} V2GMessageType;





typedef struct {
    
        
    responseCodeType ResponseCode;
        
    
} V2GResponseType;







typedef struct {
    
        
    DisplayParametersType DisplayParameters;
        
    
        
    bool MeterInfoRequested;
        
    
} ChargeLoopReqType;



typedef struct {
    
        
    EVSEStatusType EVSEStatus;
        
    
        
    MeterInfoType MeterInfo;
        
    
        
    ReceiptType Receipt;
        
    
} ChargeLoopResType;







typedef struct {
    
        
    RationalNumberType EVTargetEnergyRequest;
        
    
        
    RationalNumberType EVMaximumEnergyRequest;
        
    
        
    RationalNumberType EVMinimumEnergyRequest;
        
    
} Scheduled_CLReqControlModeType;





typedef struct {
    
        
    unsigned int DepartureTime;
        
    
        
    RationalNumberType EVTargetEnergyRequest;
        
    
        
    RationalNumberType EVMaximumEnergyRequest;
        
    
        
    RationalNumberType EVMinimumEnergyRequest;
        
    
} Dynamic_CLReqControlModeType;



typedef struct {
    
        
    unsigned int DepartureTime;
        
    
        
    percentValueType MinimumSOC;
        
    
        
    percentValueType TargetSOC;
        
    
        
    unsigned short AckMaxDelay;
        
    
} Dynamic_CLResControlModeType;



typedef struct {
    
        
    percentValueType PresentSOC;
        
    
        
    percentValueType MinimumSOC;
        
    
        
    percentValueType TargetSOC;
        
    
        
    percentValueType MaximumSOC;
        
    
        
    unsigned int RemainingTimeToMinimumSOC;
        
    
        
    unsigned int RemainingTimeToTargetSOC;
        
    
        
    unsigned int RemainingTimeToMaximumSOC;
        
    
        
    bool ChargingComplete;
        
    
        
    RationalNumberType BatteryEnergyCapacity;
        
    
        
    bool InletHot;
        
    
} DisplayParametersType;



typedef struct {
    
        
    unsigned short NotificationMaxDelay;
        
    
        
    evseNotificationType EVSENotification;
        
    
} EVSEStatusType;



typedef struct {
    
        
    char Exponent;
        
    
        
    short Value;
        
    
} RationalNumberType;



typedef struct {
    
        
    meterIDType MeterID[32];
        
    
        
    unsigned long ChargedEnergyReadingWh;
        
    
        
    unsigned long BPT_DischargedEnergyReadingWh;
        
    
        
    unsigned long CapacitiveEnergyReadingVARh;
        
    
        
    unsigned long BPT_InductiveEnergyReadingVARh;
        
    
        
    meterSignatureType MeterSignature[64];
        
    
        
    short MeterStatus;
        
    
        
    unsigned long MeterTimestamp;
        
    
} MeterInfoType;



typedef struct {
    
        
    RationalNumberType Amount;
        
    
        
    RationalNumberType CostPerUnit;
        
    
} DetailedCostType;



typedef struct {
    
        
    numericIDType TaxRuleID;
        
    
        
    RationalNumberType Amount;
        
    
} DetailedTaxType;



typedef struct {
    
        
    unsigned long TimeAnchor;
        
    
        
    DetailedCostType EnergyCosts;
        
    
        
    DetailedCostType OccupancyCosts;
        
    
        
    DetailedCostType AdditionalServicesCosts;
        
    
        
    DetailedCostType OverstayCosts;
        
    
        
    DetailedTaxType TaxCosts;
        
    
} ReceiptType;



typedef struct {
    
        
    X509IssuerSerialType RootCertificateID;
        
    
} ListOfRootCertificateIDsType;



















#endif // V2G_CI_COMMONTYPES