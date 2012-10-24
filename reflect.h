#ifndef REFLECT_H
#define REFLECT_H

#include "tokens.h"
#include "bstrlib.h"

typedef enum ResourceType_TAG
{
    RTYPE_CBUFFER,//0
    RTYPE_TBUFFER,//1
    RTYPE_TEXTURE,//2
    RTYPE_SAMPLER,//3
    RTYPE_UAV_RWTYPED,//4
    RTYPE_STRUCTURED,//5
    RTYPE_UAV_RWSTRUCTURED,//6
    RTYPE_BYTEADDRESS,//7
    RTYPE_UAV_RWBYTEADDRESS,//8
    RTYPE_UAV_APPEND_STRUCTURED,//9
    RTYPE_UAV_CONSUME_STRUCTURED,//10
    RTYPE_UAV_RWSTRUCTURED_WITH_COUNTER,//11
} ResourceType;

#define MAX_RESOURCE_BINDING_NAME_LENGTH 512

typedef struct ResourceBinding_TAG
{
    char Name[MAX_RESOURCE_BINDING_NAME_LENGTH];
    ResourceType eType;
    uint32_t ui32BindPoint;
    uint32_t ui32BindCount;
    uint32_t ui32Flags;
    uint32_t ui32Dimension;
    uint32_t ui32ReturnType;
    uint32_t ui32NumSamples;
} ResourceBinding;

typedef struct ShaderInfo_TAG
{
    uint32_t ui32NumResourceBindings;
    ResourceBinding* psResourceBindings;
} ShaderInfo;

void ReadResources(const uint32_t* pui32Tokens,//in
                   ShaderInfo* psShaderInfo);//out

int GetResourceFromBindingPoint(ResourceType eType, uint32_t ui32BindPoint, ShaderInfo* psShaderInfo, ResourceBinding** ppsOutBinding);

#if 0
//--- Utility functions ---

//Returns 0 if not found, 1 otherwise.
int GetResourceFromName(const char* name, ShaderInfo* psShaderInfo, ResourceBinding* psBinding);

//These call into OpenGL and modify the uniforms of the currently bound program.
void SetResourceValueF(ResourceBinding* psBinding, float* value);
void SetResourceValueI(ResourceBinding* psBinding, int* value);
void SetResourceValueStr(ResourceBinding* psBinding, char* value); //Used for interfaces/subroutines. Also for constant buffers?

void CreateUniformBufferObjectFromResource(ResourceBinding* psBinding, uint32_t* ui32GLHandle);
//------------------------
#endif

#endif

