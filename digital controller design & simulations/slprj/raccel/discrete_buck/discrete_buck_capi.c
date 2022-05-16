#include "__cf_discrete_buck.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "discrete_buck_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "discrete_buck.h"
#include "discrete_buck_capi.h"
#include "discrete_buck_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"discrete_buck/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0
, TARGET_STRING ( "discrete_buck/Discrete Transfer Fcn" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"discrete_buck/Subsystem/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 3 , 0 , TARGET_STRING ( "discrete_buck/Subsystem/Sum1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0
, 0 } } ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 4
, TARGET_STRING ( "discrete_buck/Constant" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 5 , TARGET_STRING ( "discrete_buck/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 6 , TARGET_STRING (
"discrete_buck/Discrete Transfer Fcn" ) , TARGET_STRING ( "Numerator" ) , 0 ,
1 , 0 } , { 7 , TARGET_STRING ( "discrete_buck/Discrete Transfer Fcn" ) ,
TARGET_STRING ( "Denominator" ) , 0 , 2 , 0 } , { 8 , TARGET_STRING (
"discrete_buck/Discrete Transfer Fcn" ) , TARGET_STRING ( "InitialStates" ) ,
0 , 0 , 0 } , { 9 , TARGET_STRING ( "discrete_buck/Subsystem/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 10 , TARGET_STRING (
"discrete_buck/Subsystem/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } ,
{ 11 , TARGET_STRING ( "discrete_buck/Subsystem/Gain2" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 12 , TARGET_STRING (
"discrete_buck/Subsystem/Delay" ) , TARGET_STRING ( "DelayLength" ) , 1 , 0 ,
0 } , { 13 , TARGET_STRING ( "discrete_buck/Subsystem/Delay" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 14 , TARGET_STRING (
"discrete_buck/Subsystem/Delay1" ) , TARGET_STRING ( "DelayLength" ) , 1 , 0
, 0 } , { 15 , TARGET_STRING ( "discrete_buck/Subsystem/Delay1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [
] = { { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . h4ggnwv2is , & rtB . bkyphiynml ,
& rtB . ehcp4ye11o , & rtB . ekfyt1ufxk , & rtP . Constant_Value , & rtP .
Gain_Gain , & rtP . DiscreteTransferFcn_NumCoef [ 0 ] , & rtP .
DiscreteTransferFcn_DenCoef [ 0 ] , & rtP . DiscreteTransferFcn_InitialStates
, & rtP . Gain_Gain_av4lqwgh23 , & rtP . Gain1_Gain , & rtP . Gain2_Gain , &
rtP . Delay_DelayLength , & rtP . Delay_InitialCondition , & rtP .
Delay1_DelayLength , & rtP . Delay1_InitialCondition , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } , { "unsigned int"
, "uint32_T" , 0 , 0 , sizeof ( uint32_T ) , SS_UINT32 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 , 1 , 2 , 1 , 3 } ; static const real_T rtcapiStoredFloats [ ] = { 0.4
, 0.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , (
NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 1 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 4 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 12 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 4120331180U , 2148891758U , 1729628525U , 491399547U } , ( NULL ) , 0 , 0
} ; const rtwCAPI_ModelMappingStaticInfo * discrete_buck_GetCAPIStaticMap (
void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void discrete_buck_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void discrete_buck_host_InitializeDataMapInfo (
discrete_buck_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
