#ifndef V2G_CI_COMMONMESSAGES
#define V2G_CI_COMMONMESSAGES

/**
 * \file
 * \brief XMl Schema Parser and C structs generator for V2G xsd files

 * \author Kareem Azab
 * \date   2023-11-02

 *  Copyright (c) 2023-10-19 Kareem Azab
 */


#include "V2G_CI_CommonTypes.h"

#include <stdbool.h>
 





















































































typedef char genChallengeType;

typedef unsigned short serviceIDType;

typedef unsigned short maxSupportingPointsScheduleTupleType;

typedef char dhPublicKeyType;

typedef char secp521_EncryptedPrivateKeyType;

typedef char x448_EncryptedPrivateKeyType;

typedef char tpm_EncryptedPrivateKeyType;

typedef char currencyType;

typedef char languageType;

typedef char certificateType;



typedef enum {
    
    
    EIM,
    
    PnC,
    
} authorizationType;

typedef enum {
    
    
    Start,
    
    Stop,
    
    Standby,
    
    ScheduleRenegotiation,
    
} chargeProgressType;

typedef enum {
    
    
    Charge,
    
    Discharge,
    
} channelSelectionType;

typedef enum {
    
    
    SECP521,
    
    X448,
    
} ecdhCurveType;

typedef enum {
    
    
    Pause,
    
    Terminate,
    
    ServiceRenegotiation,
    
} chargingSessionType;

typedef enum {
    
    
    CheckIn,
    
    Processing,
    
    Completed,
    
} evCheckInStatusType;

typedef enum {
    
    
    CheckOut,
    
    Processing,
    
    Completed,
    
} evCheckOutStatusType;

typedef enum {
    
    
    Scheduled,
    
    Completed,
    
} evseCheckOutStatusType;

typedef enum {
    
    
    AutoParking,
    
    MVGuideManual,
    
    Manual,
    
} parkingMethodType;

typedef enum {
    
    
    PowerToleranceNotConfirmed,
    
    PowerToleranceConfirmed,
    
} powerToleranceAcceptanceType;






typedef struct {
    
        
    identifierType EVCCID;
        
    
} SessionSetupReqType;



typedef struct {
    
        
    identifierType EVSEID;
        
    
} SessionSetupResType;





typedef struct {
    
        
    authorizationType AuthorizationServices;
        
    
        
    bool CertificateInstallationService;
        
    
} AuthorizationSetupResType;



typedef struct {
    
        
    authorizationType SelectedAuthorizationService;
        
    
} AuthorizationReqType;



typedef struct {
    
        
    processingType EVSEProcessing;
        
    
} AuthorizationResType;



typedef struct {
    
        
    ServiceIDListType SupportedServiceIDs;
        
    
} ServiceDiscoveryReqType;



typedef struct {
    
        
    bool ServiceRenegotiationSupported;
        
    
        
    ServiceListType EnergyTransferServiceList;
        
    
        
    ServiceListType VASList;
        
    
} ServiceDiscoveryResType;



typedef struct {
    
        
    serviceIDType ServiceID;
        
    
} ServiceDetailReqType;



typedef struct {
    
        
    serviceIDType ServiceID;
        
    
        
    ServiceParameterListType ServiceParameterList;
        
    
} ServiceDetailResType;



typedef struct {
    
        
    SelectedServiceType SelectedEnergyTransferService;
        
    
        
    SelectedServiceListType SelectedVASList;
        
    
} ServiceSelectionReqType;





typedef struct {
    
        
    maxSupportingPointsScheduleTupleType MaximumSupportingPoints;
        
    
} ScheduleExchangeReqType;



typedef struct {
    
        
    processingType EVSEProcessing;
        
    
        
    bool GoToPause;
        
    
} ScheduleExchangeResType;



typedef struct {
    
        
    processingType EVProcessing;
        
    
        
    chargeProgressType ChargeProgress;
        
    
        
    EVPowerProfileType EVPowerProfile;
        
    
        
    channelSelectionType BPT_ChannelSelection;
        
    
} PowerDeliveryReqType;



typedef struct {
    
        
    EVSEStatusType EVSEStatus;
        
    
} PowerDeliveryResType;



typedef struct {
    
        
    SignedMeteringDataType SignedMeteringData;
        
    
} MeteringConfirmationReqType;





typedef struct {
    
        
    chargingSessionType ChargingSession;
        
    
        
    nameType EVTerminationCode;
        
    
        
    descriptionType EVTerminationExplanation;
        
    
} SessionStopReqType;





typedef struct {
    
        
    SignedCertificateChainType OEMProvisioningCertificateChain;
        
    
        
    ListOfRootCertificateIDsType ListOfRootCertificateIDs;
        
    
        
    unsigned char MaximumContractCertificateChains;
        
    
        
    EMAIDListType PrioritizedEMAIDs;
        
    
} CertificateInstallationReqType;



typedef struct {
    
        
    processingType EVSEProcessing;
        
    
        
    CertificateChainType CPSCertificateChain;
        
    
        
    SignedInstallationDataType SignedInstallationData;
        
    
        
    unsigned char RemainingContractCertificateChains;
        
    
} CertificateInstallationResType;



typedef struct {
    
        
    evCheckInStatusType EVCheckInStatus;
        
    
        
    parkingMethodType ParkingMethod;
        
    
        
    short VehicleFrame;
        
    
        
    short DeviceOffset;
        
    
        
    short VehicleTravel;
        
    
} VehicleCheckInReqType;



typedef struct {
    
        
    short ParkingSpace;
        
    
        
    short DeviceLocation;
        
    
        
    short TargetDistance;
        
    
} VehicleCheckInResType;



typedef struct {
    
        
    evCheckOutStatusType EVCheckOutStatus;
        
    
        
    unsigned long CheckOutTime;
        
    
} VehicleCheckOutReqType;



typedef struct {
    
        
    evseCheckOutStatusType EVSECheckOutStatus;
        
    
} VehicleCheckOutResType;



typedef struct {
    
        
    genChallengeType GenChallenge;
        
    
        
    SupportedProvidersListType SupportedProviders;
        
    
} PnC_ASResAuthorizationModeType;



typedef struct {
    
        
    nameType ProviderID;
        
    
} SupportedProvidersListType;





typedef struct {
    
        
    genChallengeType GenChallenge;
        
    
        
    ContractCertificateChainType ContractCertificateChain;
        
    
        
    char* Id;
        
    
} PnC_AReqAuthorizationModeType;





typedef struct {
    
        
    serviceIDType ServiceID;
        
    
} ServiceIDListType;



typedef struct {
    
        
    serviceIDType ServiceID;
        
    
        
    bool FreeService;
        
    
} ServiceType;



typedef struct {
    
        
    ServiceType Service;
        
    
} ServiceListType;



typedef struct {
    
        
    serviceIDType ServiceID;
        
    
        
    serviceIDType ParameterSetID;
        
    
} SelectedServiceType;



typedef struct {
    
        
    SelectedServiceType SelectedService;
        
    
} SelectedServiceListType;



typedef struct {
    
        
    nameType Name;
        
    
} ParameterType;



typedef struct {
    
        
    serviceIDType ParameterSetID;
        
    
        
    ParameterType Parameter;
        
    
} ParameterSetType;



typedef struct {
    
        
    ParameterSetType ParameterSet;
        
    
} ServiceParameterListType;



typedef struct {
    
        
    numericIDType ScheduleTupleID;
        
    
        
    ChargingScheduleType ChargingSchedule;
        
    
        
    ChargingScheduleType DischargingSchedule;
        
    
} ScheduleTupleType;



typedef struct {
    
        
    PowerScheduleType PowerSchedule;
        
    
        
    union {
            
        AbsolutePriceScheduleType AbsolutePriceSchedule;
            
        PriceLevelScheduleType PriceLevelSchedule;
            
    };
        
    
} ChargingScheduleType;



typedef struct {
    
        
    unsigned int DepartureTime;
        
    
        
    RationalNumberType EVTargetEnergyRequest;
        
    
        
    RationalNumberType EVMaximumEnergyRequest;
        
    
        
    RationalNumberType EVMinimumEnergyRequest;
        
    
        
    EVEnergyOfferType EVEnergyOffer;
        
    
} Scheduled_SEReqControlModeType;



typedef struct {
    
        
    ScheduleTupleType ScheduleTuple;
        
    
} Scheduled_SEResControlModeType;



typedef struct {
    
        
    unsigned int DepartureTime;
        
    
        
    percentValueType MinimumSOC;
        
    
        
    percentValueType TargetSOC;
        
    
        
    RationalNumberType EVTargetEnergyRequest;
        
    
        
    RationalNumberType EVMaximumEnergyRequest;
        
    
        
    RationalNumberType EVMinimumEnergyRequest;
        
    
        
    RationalNumberType EVMaximumV2XEnergyRequest;
        
    
        
    RationalNumberType EVMinimumV2XEnergyRequest;
        
    
} Dynamic_SEReqControlModeType;



typedef struct {
    
        
    unsigned int DepartureTime;
        
    
        
    percentValueType MinimumSOC;
        
    
        
    percentValueType TargetSOC;
        
    
        
    union {
            
        AbsolutePriceScheduleType AbsolutePriceSchedule;
            
        PriceLevelScheduleType PriceLevelSchedule;
            
    };
        
    
} Dynamic_SEResControlModeType;



typedef struct {
    
        
    ContractCertificateChainType ContractCertificateChain;
        
    
        
    ecdhCurveType ECDHCurve;
        
    
        
    dhPublicKeyType DHPublicKey;
        
    
        
    union {
            
        secp521_EncryptedPrivateKeyType SECP521_EncryptedPrivateKey;
            
        x448_EncryptedPrivateKeyType X448_EncryptedPrivateKey;
            
        tpm_EncryptedPrivateKeyType TPM_EncryptedPrivateKey;
            
    };
        
    
        
    char* Id;
        
    
} SignedInstallationDataType;



typedef struct {
    
        
    sessionIDType SessionID;
        
    
        
    MeterInfoType MeterInfo;
        
    
        
    ReceiptType Receipt;
        
    
        
    union {
            
        Dynamic_SMDTControlModeType Dynamic_SMDTControlMode;
            
        Scheduled_SMDTControlModeType Scheduled_SMDTControlMode;
            
    };
        
    
        
    char* Id;
        
    
} SignedMeteringDataType;



typedef struct {
    
        
    numericIDType SelectedScheduleTupleID;
        
    
} Scheduled_SMDTControlModeType;





typedef struct {
    
        
    unsigned short TargetOffsetX;
        
    
        
    unsigned short TargetOffsetY;
        
    
} TargetPositionType;



typedef struct {
    
        
    unsigned long TimeAnchor;
        
    
        
    RationalNumberType AvailableEnergy;
        
    
        
    RationalNumberType PowerTolerance;
        
    
        
    PowerScheduleEntryListType PowerScheduleEntries;
        
    
} PowerScheduleType;



typedef struct {
    
        
    PowerScheduleEntryType PowerScheduleEntry;
        
    
} PowerScheduleEntryListType;



typedef struct {
    
        
    unsigned int Duration;
        
    
        
    RationalNumberType Power;
        
    
        
    RationalNumberType Power_L2;
        
    
        
    RationalNumberType Power_L3;
        
    
} PowerScheduleEntryType;



typedef struct {
    
        
    unsigned long TimeAnchor;
        
    
        
    numericIDType PriceScheduleID;
        
    
        
    descriptionType PriceScheduleDescription;
        
    
} PriceScheduleType;



typedef struct {
    
        
    unsigned char NumberOfPriceLevels;
        
    
        
    PriceLevelScheduleEntryListType PriceLevelScheduleEntries;
        
    
} PriceLevelScheduleType;



typedef struct {
    
        
    PriceLevelScheduleEntryType PriceLevelScheduleEntry;
        
    
} PriceLevelScheduleEntryListType;



typedef struct {
    
        
    unsigned int Duration;
        
    
        
    unsigned char PriceLevel;
        
    
} PriceLevelScheduleEntryType;



typedef struct {
    
        
    currencyType Currency[3];
        
    
        
    languageType Language[3];
        
    
        
    identifierType PriceAlgorithm;
        
    
        
    RationalNumberType MinimumCost;
        
    
        
    RationalNumberType MaximumCost;
        
    
        
    TaxRuleListType TaxRules;
        
    
        
    PriceRuleStackListType PriceRuleStacks;
        
    
        
    OverstayRuleListType OverstayRules;
        
    
        
    AdditionalServiceListType AdditionalSelectedServices;
        
    
} AbsolutePriceScheduleType;



typedef struct {
    
        
    TaxRuleType TaxRule;
        
    
} TaxRuleListType;



typedef struct {
    
        
    numericIDType TaxRuleID;
        
    
        
    nameType TaxRuleName;
        
    
        
    RationalNumberType TaxRate;
        
    
        
    bool TaxIncludedInPrice;
        
    
        
    bool AppliesToEnergyFee;
        
    
        
    bool AppliesToParkingFee;
        
    
        
    bool AppliesToOverstayFee;
        
    
        
    bool AppliesMinimumMaximumCost;
        
    
} TaxRuleType;



typedef struct {
    
        
    PriceRuleStackType PriceRuleStack;
        
    
} PriceRuleStackListType;



typedef struct {
    
        
    unsigned int Duration;
        
    
        
    PriceRuleType PriceRule;
        
    
} PriceRuleStackType;



typedef struct {
    
        
    RationalNumberType EnergyFee;
        
    
        
    RationalNumberType ParkingFee;
        
    
        
    unsigned int ParkingFeePeriod;
        
    
        
    unsigned short CarbonDioxideEmission;
        
    
        
    unsigned char RenewableGenerationPercentage;
        
    
        
    RationalNumberType PowerRangeStart;
        
    
} PriceRuleType;



typedef struct {
    
        
    unsigned int OverstayTimeThreshold;
        
    
        
    RationalNumberType OverstayPowerThreshold;
        
    
        
    OverstayRuleType OverstayRule;
        
    
} OverstayRuleListType;



typedef struct {
    
        
    descriptionType OverstayRuleDescription;
        
    
        
    unsigned int StartTime;
        
    
        
    RationalNumberType OverstayFee;
        
    
        
    unsigned int OverstayFeePeriod;
        
    
} OverstayRuleType;



typedef struct {
    
        
    AdditionalServiceType AdditionalService;
        
    
} AdditionalServiceListType;



typedef struct {
    
        
    nameType ServiceName;
        
    
        
    RationalNumberType ServiceFee;
        
    
} AdditionalServiceType;



typedef struct {
    
        
    PowerScheduleEntryType EVPowerProfileEntry;
        
    
} EVPowerProfileEntryListType;



typedef struct {
    
        
    unsigned long TimeAnchor;
        
    
        
    EVPowerProfileEntryListType EVPowerProfileEntries;
        
    
        
    union {
            
        Dynamic_EVPPTControlModeType Dynamic_EVPPTControlMode;
            
        Scheduled_EVPPTControlModeType Scheduled_EVPPTControlMode;
            
    };
        
    
} EVPowerProfileType;



typedef struct {
    
        
    numericIDType SelectedScheduleTupleID;
        
    
        
    powerToleranceAcceptanceType PowerToleranceAcceptance;
        
    
} Scheduled_EVPPTControlModeType;





typedef struct {
    
        
    EVPowerScheduleType EVPowerSchedule;
        
    
        
    EVAbsolutePriceScheduleType EVAbsolutePriceSchedule;
        
    
} EVEnergyOfferType;



typedef struct {
    
        
    unsigned long TimeAnchor;
        
    
        
    EVPowerScheduleEntryListType EVPowerScheduleEntries;
        
    
} EVPowerScheduleType;



typedef struct {
    
        
    EVPowerScheduleEntryType EVPowerScheduleEntry;
        
    
} EVPowerScheduleEntryListType;



typedef struct {
    
        
    unsigned int Duration;
        
    
        
    RationalNumberType Power;
        
    
} EVPowerScheduleEntryType;



typedef struct {
    
        
    unsigned long TimeAnchor;
        
    
        
    currencyType Currency[3];
        
    
        
    identifierType PriceAlgorithm;
        
    
        
    EVPriceRuleStackListType EVPriceRuleStacks;
        
    
} EVAbsolutePriceScheduleType;



typedef struct {
    
        
    EVPriceRuleStackType EVPriceRuleStack;
        
    
} EVPriceRuleStackListType;



typedef struct {
    
        
    unsigned int Duration;
        
    
        
    EVPriceRuleType EVPriceRule;
        
    
} EVPriceRuleStackType;



typedef struct {
    
        
    RationalNumberType EnergyFee;
        
    
        
    RationalNumberType PowerRangeStart;
        
    
} EVPriceRuleType;



typedef struct {
    
        
    identifierType EMAID;
        
    
} EMAIDListType;



typedef struct {
    
        
    certificateType Certificate[1600];
        
    
} SubCertificatesType;



typedef struct {
    
        
    certificateType Certificate[1600];
        
    
        
    SubCertificatesType SubCertificates;
        
    
} CertificateChainType;



typedef struct {
    
        
    certificateType Certificate[1600];
        
    
        
    SubCertificatesType SubCertificates;
        
    
        
    char* Id;
        
    
} SignedCertificateChainType;



typedef struct {
    
        
    certificateType Certificate[1600];
        
    
        
    SubCertificatesType SubCertificates;
        
    
} ContractCertificateChainType;























#endif // V2G_CI_COMMONMESSAGES