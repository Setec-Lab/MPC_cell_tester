#include "__cf_discrete_buck.h"
#ifndef RTW_HEADER_discrete_buck_h_
#define RTW_HEADER_discrete_buck_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef discrete_buck_COMMON_INCLUDES_
#define discrete_buck_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "discrete_buck_types.h"
#include "multiword_types.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME discrete_buck
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (4) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T bkyphiynml ; real_T h4ggnwv2is ; real_T ehcp4ye11o ;
real_T ekfyt1ufxk ; } B ; typedef struct { real_T h5dc1rpojv [ 2 ] ; real_T
ln3jvbo3qx ; real_T nqmsf5lihu ; struct { void * LoggedData ; } km2loxe1op ;
struct { void * LoggedData ; } go0wbzcttl ; struct { void * LoggedData ; }
mx05sizwf2 ; } DW ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T DiscreteTransferFcn_NumCoef [ 2 ] ; real_T
DiscreteTransferFcn_DenCoef [ 3 ] ; real_T DiscreteTransferFcn_InitialStates
; real_T Gain_Gain ; real_T Constant_Value ; real_T Gain_Gain_av4lqwgh23 ;
real_T Delay_InitialCondition ; real_T Gain1_Gain ; real_T
Delay1_InitialCondition ; real_T Gain2_Gain ; uint32_T Delay_DelayLength ;
uint32_T Delay1_DelayLength ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern P rtP ;
extern const rtwCAPI_ModelMappingStaticInfo * discrete_buck_GetCAPIStaticMap
( void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
extern const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern const
int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
