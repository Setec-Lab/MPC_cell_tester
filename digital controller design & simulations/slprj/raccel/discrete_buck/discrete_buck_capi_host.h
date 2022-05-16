#include "__cf_discrete_buck.h"
#ifndef RTW_HEADER_discrete_buck_cap_host_h_
#define RTW_HEADER_discrete_buck_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
discrete_buck_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void discrete_buck_host_InitializeDataMapInfo (
discrete_buck_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
