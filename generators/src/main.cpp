#include "main.hpp"

#define PROCC2(str, max, var) var = []()->string\
{\
vector <string> strings (max);\
\
fill (strings.begin(), strings.end(), str);\
\
auto a1 = strings[0].find("${");\
\
while (a1 != string::npos)\
{\
if (int a2 = strings[0].find ("}"); a2 != string::npos)\
{\
for (int i = 0; i < max; ++i)\
{\
\
strings[i].replace (strings[i].begin() + a1, strings[i].begin() + a2 + 1, to_string (i));\
}\
}\
a1 = strings[0].find ("${");\
}\
\
string res;\
\
for (auto const& i : strings)\
res += i;\
return res;\
}();// = [&s]->string{return "";}();

#define PROCC(x) PROCC2 (BOOST_PP_STRINGIZE (BOOST_PP_SEQ_ELEM (0, x)), BOOST_PP_SEQ_ELEM (1, x), BOOST_PP_SEQ_ELEM (2, x))//BOOST_PP_SEQ_ELEM (2, x) = [](string s){ \



#define CAT(x) BOOST_PP_SEQ_CAT (x)

#define NL \n
#define TB \t

#define DECL_GPU(z, n, text) \
template <> NL \
struct gpu <n> NL \
{ NL \
TB struct features NL \
TB { NL \
TB TB static constexpr uint32_t    robustBufferAccess = CAT ((GPU_) (n) (_ROBUST_BUFFER_ACCESS)); NL \
TB TB static constexpr uint32_t    fullDrawIndexUint32 = CAT ((GPU_) (n) (_FULL_DRAW_INDEX_UINT_32)); NL \
TB TB static constexpr uint32_t    imageCubeArray = CAT ((GPU_) (n) (_IMAGE_CUBE_ARRAY)); NL \
TB TB static constexpr uint32_t    independentBlend = CAT ((GPU_) (n) (_INDEPENDENT_BLEND)); NL \
TB TB static constexpr uint32_t    geometryShader = CAT ((GPU_) (n) (_GEOMETRY_SHADER)); NL \
TB TB static constexpr uint32_t    tessellationShader = CAT ((GPU_) (n) (_TESSELLATION_SHADER)); NL \
TB TB static constexpr uint32_t    sampleRateShading = CAT ((GPU_) (n) (_SAMPLE_RATE_SHADING)); NL \
TB TB static constexpr uint32_t    dualSrcBlend = CAT ((GPU_) (n) (_DUAL_SRC_BLEND)); NL \
TB TB static constexpr uint32_t    logicOp = CAT ((GPU_) (n) (_LOGIC_OP)); NL \
TB TB static constexpr uint32_t    multiDrawIndirect = CAT ((GPU_) (n) (_MULTI_DRAW_INDIRECT)); NL \
TB TB static constexpr uint32_t    drawIndirectFirstInstance = CAT ((GPU_) (n) (_DRAW_INDIRECT_FIRST_INSTANCE)); NL \
TB TB static constexpr uint32_t    depthClamp = CAT ((GPU_) (n) (_DEPTH_CLAMP)); NL \
TB TB static constexpr uint32_t    depthBiasClamp = CAT ((GPU_) (n) (_DEPTH_BIAS_CLAMP)); NL \
TB TB static constexpr uint32_t    fillModeNonSolid = CAT ((GPU_) (n) (_FILL_MODE_NON_SOLID)); NL \
TB TB static constexpr uint32_t    depthBounds = CAT ((GPU_) (n) (_DEPTH_BOUNDS)); NL \
TB TB static constexpr uint32_t    wideLines = CAT ((GPU_) (n) (_WIDE_LINES)); NL \
TB TB static constexpr uint32_t    largePoints = CAT ((GPU_) (n) (_LARGE_POINTS)); NL \
TB TB static constexpr uint32_t    alphaToOne = CAT ((GPU_) (n) (_ALPHA_TO_ONE)); NL \
TB TB static constexpr uint32_t    multiViewport = CAT ((GPU_) (n) (_MULTI_VIEWPORT)); NL \
TB TB static constexpr uint32_t    samplerAnisotropy = CAT ((GPU_) (n) (_SAMPLER_ANISOTROPY)); NL \
TB TB static constexpr uint32_t    textureCompressionETC2 = CAT ((GPU_) (n) (_TEXTURE_COMPRESSION_ETC_2)); NL \
TB TB static constexpr uint32_t    textureCompressionASTC_LDR = CAT ((GPU_) (n) (_TEXTURE_COMPRESSION_ASTC_LDR)); NL \
TB TB static constexpr uint32_t    textureCompressionBC = CAT ((GPU_) (n) (_TEXTURE_COMPRESSION_BC)); NL \
TB TB static constexpr uint32_t    occlusionQueryPrecise = CAT ((GPU_) (n) (_OCCLUSION_QUERY_PRECISE)); NL \
TB TB static constexpr uint32_t    pipelineStatisticsQuery = CAT ((GPU_) (n) (_PIPELINE_STATISTICS_QUERY)); NL \
TB TB static constexpr uint32_t    vertexPipelineStoresAndAtomics = CAT ((GPU_) (n) (_VERTEX_PIPELINE_STORES_AND_ATOMICS)); NL \
TB TB static constexpr uint32_t    fragmentStoresAndAtomics = CAT ((GPU_) (n) (_FRAGMENT_STORES_AND_ATOMICS)); NL \
TB TB static constexpr uint32_t    shaderTessellationAndGeometryPointSize = CAT ((GPU_) (n) (_SHADER_TESSELLATION_AND_GEOMETRY_POINT_SIZE)); NL \
TB TB static constexpr uint32_t    shaderImageGatherExtended = CAT ((GPU_) (n) (_SHADER_IMAGE_GATHER_EXTENDED)); NL \
TB TB static constexpr uint32_t    shaderStorageImageExtendedFormats = CAT ((GPU_) (n) (_SHADER_STORAGE_IMAGE_EXTENDED_FORMATS)); NL \
TB TB static constexpr uint32_t    shaderStorageImageMultisample = CAT ((GPU_) (n) (_SHADER_STORAGE_IMAGE_MULTISAMPLE)); NL \
TB TB static constexpr uint32_t    shaderStorageImageReadWithoutFormat = CAT ((GPU_) (n) (_SHADER_STORAGE_IMAGE_READ_WITHOUT_FORMAT)); NL \
TB TB static constexpr uint32_t    shaderStorageImageWriteWithoutFormat = CAT ((GPU_) (n) (_SHADER_STORAGE_IMAGE_WRITE_WITHOUT_FORMAT)); NL \
TB TB static constexpr uint32_t    shaderUniformBufferArrayDynamicIndexing = CAT ((GPU_) (n) (_SHADER_UNIFORM_BUFFER_ARRAY_DYNAMIC_INDEXING)); NL \
TB TB static constexpr uint32_t    shaderSampledImageArrayDynamicIndexing = CAT ((GPU_) (n) (_SHADER_SAMPLED_IMAGE_ARRAY_DYNAMIC_INDEXING)); NL \
TB TB static constexpr uint32_t    shaderStorageBufferArrayDynamicIndexing = CAT ((GPU_) (n) (_SHADER_STORAGE_BUFFER_ARRAY_DYNAMIC_INDEXING)); NL \
TB TB static constexpr uint32_t    shaderStorageImageArrayDynamicIndexing = CAT ((GPU_) (n) (_SHADER_STORAGE_IMAGE_ARRAY_DYNAMIC_INDEXING)); NL \
TB TB static constexpr uint32_t    shaderClipDistance = CAT ((GPU_) (n) (_SHADER_CLIP_DISTANCE)); NL \
TB TB static constexpr uint32_t    shaderCullDistance = CAT ((GPU_) (n) (_SHADER_CULL_DISTANCE)); NL \
TB TB static constexpr uint32_t    shaderFloat64 = CAT ((GPU_) (n) (_SHADER_FLOAT_64)); NL \
TB TB static constexpr uint32_t    shaderInt64 = CAT ((GPU_) (n) (_SHADER_INT_64)); NL \
TB TB static constexpr uint32_t    shaderInt16 = CAT ((GPU_) (n) (_SHADER_INT_16)); NL \
TB TB static constexpr uint32_t    shaderResourceResidency = CAT ((GPU_) (n) (_SHADER_RESOURCE_RESIDENCY)); NL \
TB TB static constexpr uint32_t    shaderResourceMinLod = CAT ((GPU_) (n) (_SHADER_RESOURCE_MIN_LOD)); NL \
TB TB static constexpr uint32_t    sparseBinding = CAT ((GPU_) (n) (_SPARSE_BINDING)); NL \
TB TB static constexpr uint32_t    sparseResidencyBuffer = CAT ((GPU_) (n) (_SPARSE_RESIDENCY_BUFFER)); NL \
TB TB static constexpr uint32_t    sparseResidencyImage2D = CAT ((GPU_) (n) (_SPARSE_RESIDENCY_IMAGE_2D)); NL \
TB TB static constexpr uint32_t    sparseResidencyImage3D = CAT ((GPU_) (n) (_SPARSE_RESIDENCY_IMAGE_3D)); NL \
TB TB static constexpr uint32_t    sparseResidency2Samples = CAT ((GPU_) (n) (_SPARSE_RESIDENCY_2SAMPLES)); NL \
TB TB static constexpr uint32_t    sparseResidency4Samples = CAT ((GPU_) (n) (_SPARSE_RESIDENCY_4SAMPLES)); NL \
TB TB static constexpr uint32_t    sparseResidency8Samples = CAT ((GPU_) (n) (_SPARSE_RESIDENCY_8SAMPLES)); NL \
TB TB static constexpr uint32_t    sparseResidency16Samples = CAT ((GPU_) (n) (_SPARSE_RESIDENCY_16SAMPLES)); NL \
TB TB static constexpr uint32_t    sparseResidencyAliased = CAT ((GPU_) (n) (_SPARSE_RESIDENCY_ALIASED)); NL \
TB TB static constexpr uint32_t    variableMultisampleRate = CAT ((GPU_) (n) (_VARIABLE_MULTISAMPLE_RATE)); NL \
TB TB static constexpr uint32_t    inheritedQueries = CAT ((GPU_) (n) (_INHERITED_QUERIES)); NL \
TB }; NL NL \
\
\
TB struct properties NL \
TB { NL \
TB TB static constexpr uint32_t apiVersion =  CAT ((GPU_) (n) (_API_VERSION)); NL \
TB TB static constexpr uint32_t driverVersion =  CAT ((GPU_) (n) (_DRIVER_VERSION)); NL \
TB TB static constexpr uint32_t vendorID =  CAT ((GPU_) (n) (_VENDOR_ID)); NL \
TB TB static constexpr uint32_t deviceID =  CAT ((GPU_) (n) (_DEVICE_ID)); NL \
TB TB static constexpr char deviceName [VK_MAX_PHYSICAL_DEVICE_NAME_SIZE] = BOOST_PP_STRINGIZE (CAT ((GPU_) (n) (_DEVICE_NAME))); NL NL \
\
TB TB struct limits NL \
TB TB { NL \
TB TB TB static constexpr uint32_t max_image_dimension_1D =  CAT ((GPU_) (n) (_MAX_IMAGE_DIMENSION_1D)); NL \
TB TB TB static constexpr uint32_t              maxImageDimension2D = CAT ((GPU_) (n) (_MAX_IMAGE_DIMENSION_1D)); NL \
TB TB TB static constexpr uint32_t              maxImageDimension3D = CAT ((GPU_) (n) (_MAX_IMAGE_DIMENSION_1D));  NL \
TB TB TB static constexpr uint32_t              maxImageDimensionCube = CAT ((GPU_) (n) (_MAX_IMAGE_DIMENSION_CUBE));  NL \
TB TB TB static constexpr uint32_t              maxImageArrayLayers = CAT ((GPU_) (n) (_MAX_IMAGE_ARRAY_LAYERS));  NL \
TB TB TB static constexpr uint32_t              maxTexelBufferElements = CAT ((GPU_) (n) (_MAX_TEXEL_BUFFER_ELEMENTS));  NL \
TB TB TB static constexpr uint32_t              maxUniformBufferRange = CAT ((GPU_) (n) (_MAX_UNIFORM_BUFFER_RANGE));  NL \
TB TB TB static constexpr uint32_t              maxStorageBufferRange = CAT ((GPU_) (n) (_MAX_STORAGE_BUFFER_RANGE));  NL \
TB TB TB static constexpr uint32_t              maxPushConstantsSize = CAT ((GPU_) (n) (_MAX_PUSH_CONSTANTS_SIZE));  NL \
TB TB TB static constexpr uint32_t              maxMemoryAllocationCount = CAT ((GPU_) (n) (_MAX_MEMORY_ALLOCATION_COUNT));  NL \
TB TB TB static constexpr uint32_t              maxSamplerAllocationCount = CAT ((GPU_) (n) (_MAX_SAMPLER_ALLOCATION_COUNT));  NL \
TB TB TB static constexpr uint64_t          bufferImageGranularity = CAT ((GPU_) (n) (_BUFFER_IMAGE_GRANULARITY));  NL \
TB TB TB static constexpr uint64_t          sparseAddressSpaceSize = CAT ((GPU_) (n) (_SPARSE_ADDRESS_SPACE_SIZE));  NL \
TB TB TB static constexpr uint32_t              maxBoundDescriptorSets = CAT ((GPU_) (n) (_MAX_BOUND_DESCRIPTOR_SETS));  NL \
TB TB TB static constexpr uint32_t              maxPerStageDescriptorSamplers = CAT ((GPU_) (n) (_MAX_PER_STAGE_DESCRIPTOR_SAMPLERS));  NL \
TB TB TB static constexpr uint32_t              maxPerStageDescriptorUniformBuffers = CAT ((GPU_) (n) (_MAX_PER_STAGE_DESCRIPTOR_UNIFORM_BUFFERS));  NL \
TB TB TB static constexpr uint32_t              maxPerStageDescriptorStorageBuffers = CAT ((GPU_) (n) (_MAX_PER_STAGE_DESCRIPTOR_STORAGE_BUFFERS));  NL \
TB TB TB static constexpr uint32_t              maxPerStageDescriptorSampledImages = CAT ((GPU_) (n) (_MAX_PER_STAGE_DESCRIPTOR_SAMPLED_IMAGES));  NL \
TB TB TB static constexpr uint32_t              maxPerStageDescriptorStorageImages = CAT ((GPU_) (n) (_MAX_PER_STAGE_DESCRIPTOR_STORAGE_IMAGES));  NL \
TB TB TB static constexpr uint32_t              maxPerStageDescriptorInputAttachments = CAT ((GPU_) (n) (_MAX_PER_STAGE_DESCRIPTOR_INPUT_ATTACHMENTS));  NL \
TB TB TB static constexpr uint32_t              maxPerStageResources = CAT ((GPU_) (n) (_MAX_PER_STAGE_RESOURCES));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetSamplers = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_SAMPLERS));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetUniformBuffers = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_UNIFORM_BUFFERS));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetUniformBuffersDynamic = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_UNIFORM_BUFFERS_DYNAMIC));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetStorageBuffers = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_STORAGE_BUFFERS));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetStorageBuffersDynamic = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_STORAGE_BUFFERS_DYNAMIC));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetSampledImages = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_SAMPLED_IMAGES));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetStorageImages = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_STORAGE_IMAGES));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetInputAttachments = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_INPUT_ATTACHMENTS));  NL \
TB TB TB static constexpr uint32_t              maxVertexInputAttributes = CAT ((GPU_) (n) (_MAX_VERTEX_INPUT_ATTRIBUTES));  NL \
TB TB TB static constexpr uint32_t              maxVertexInputBindings = CAT ((GPU_) (n) (_MAX_VERTEX_INPUT_BINDINGS));  NL \
TB TB TB static constexpr uint32_t              maxVertexInputAttributeOffset = CAT ((GPU_) (n) (_MAX_VERTEX_INPUT_ATTRIBUTE_OFFSET));  NL \
TB TB TB static constexpr uint32_t              maxVertexInputBindingStride = CAT ((GPU_) (n) (_MAX_VERTEX_INPUT_BINDING_STRIDE));  NL \
TB TB TB static constexpr uint32_t              maxVertexOutputComponents = CAT ((GPU_) (n) (_MAX_VERTEX_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxTessellationGenerationLevel = CAT ((GPU_) (n) (_MAX_TESSELLATION_GENERATION_LEVEL));  NL \
TB TB TB static constexpr uint32_t              maxTessellationPatchSize = CAT ((GPU_) (n) (_MAX_TESSELLATION_PATCH_SIZE));  NL \
TB TB TB static constexpr uint32_t              maxTessellationControlPerVertexInputComponents = CAT ((GPU_) (n) (_MAX_TESSELLATION_CONTROL_PER_VERTEX_INPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxTessellationControlPerVertexOutputComponents = CAT ((GPU_) (n) (_MAX_TESSELLATION_CONTROL_PER_VERTEX_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxTessellationControlPerPatchOutputComponents = CAT ((GPU_) (n) (_MAX_TESSELLATION_CONTROL_PER_PATCH_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxTessellationControlTotalOutputComponents = CAT ((GPU_) (n) (_MAX_TESSELLATION_CONTROL_TOTAL_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxTessellationEvaluationInputComponents = CAT ((GPU_) (n) (_MAX_TESSELLATION_EVALUATION_INPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxTessellationEvaluationOutputComponents = CAT ((GPU_) (n) (_MAX_TESSELLATION_EVALUATION_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxGeometryShaderInvocations = CAT ((GPU_) (n) (_MAX_GEOMETRY_SHADER_INVOCATIONS));  NL \
TB TB TB static constexpr uint32_t              maxGeometryInputComponents = CAT ((GPU_) (n) (_MAX_GEOMETRY_INPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxGeometryOutputComponents = CAT ((GPU_) (n) (_MAX_GEOMETRY_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxGeometryOutputVertices = CAT ((GPU_) (n) (_MAX_GEOMETRY_OUTPUT_VERTICES));  NL \
TB TB TB static constexpr uint32_t              maxGeometryTotalOutputComponents = CAT ((GPU_) (n) (_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxFragmentInputComponents = CAT ((GPU_) (n) (_MAX_FRAGMENT_INPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxFragmentOutputAttachments = CAT ((GPU_) (n) (_MAX_FRAGMENT_OUTPUT_ATTACHMENTS));  NL \
TB TB TB static constexpr uint32_t              maxFragmentDualSrcAttachments = CAT ((GPU_) (n) (_MAX_FRAGMENT_DUAL_SRC_ATTACHMENTS));  NL \
TB TB TB static constexpr uint32_t              maxFragmentCombinedOutputResources = CAT ((GPU_) (n) (_MAX_FRAGMENT_COMBINED_OUTPUT_RESOURCES));  NL \
TB TB TB static constexpr uint32_t              maxComputeSharedMemorySize = CAT ((GPU_) (n) (_MAX_COMPUTE_SHARED_MEMORY_SIZE));  NL \
TB TB TB static constexpr uint32_t              maxComputeWorkGroupCount[3] = {CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_COUNT_0)), CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_COUNT_1)), CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_COUNT_2))};  NL \
TB TB TB static constexpr uint32_t              maxComputeWorkGroupInvocations = CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_INVOCATIONS));  NL \
TB TB TB static constexpr uint32_t              maxComputeWorkGroupSize[3] = {CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_SIZE_0)), CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_SIZE_1)), CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_SIZE_2))};  NL \
TB TB TB static constexpr uint32_t              subPixelPrecisionBits = CAT ((GPU_) (n) (_SUB_PIXEL_PRECISION_BITS));  NL \
TB TB TB static constexpr uint32_t              subTexelPrecisionBits = CAT ((GPU_) (n) (_SUB_TEXEL_PRECISION_BITS));  NL \
TB TB TB static constexpr uint32_t              mipmapPrecisionBits = CAT ((GPU_) (n) (_MIPMAP_PRECISION_BITS));  NL \
TB TB TB static constexpr uint32_t              maxDrawIndexedIndexValue = CAT ((GPU_) (n) (_MAX_DRAW_INDEXED_INDEX_VALUE));  NL \
TB TB TB static constexpr uint32_t              maxDrawIndirectCount = CAT ((GPU_) (n) (_MAX_DRAW_INDIRECT_COUNT));  NL \
TB TB TB static constexpr float                 maxSamplerLodBias = CAT ((GPU_) (n) (_MAX_SAMPLER_LOD_BIAS));  NL \
TB TB TB static constexpr float                 maxSamplerAnisotropy = CAT ((GPU_) (n) (_MAX_SAMPLER_ANISOTROPY));  NL \
TB TB TB static constexpr uint32_t              maxViewports = CAT ((GPU_) (n) (_MAX_VIEWPORTS));  NL \
TB TB TB static constexpr uint32_t              maxViewportDimensions[2] = {CAT ((GPU_) (n) (_MAX_VIEWPORT_DIMENSIONS_0)), CAT ((GPU_) (n) (_MAX_VIEWPORT_DIMENSIONS_1))};  NL \
TB TB TB static constexpr float              viewportBoundsRange[2] = {CAT ((GPU_) (n) (_VIEWPORT_BOUNDS_RANGE_0)), CAT ((GPU_) (n) (_VIEWPORT_BOUNDS_RANGE_1))};  NL \
TB TB TB static constexpr uint32_t              viewportSubPixelBits = CAT ((GPU_) (n) (_VIEWPORT_SUB_PIXEL_BITS));  NL \
TB TB TB static constexpr size_t                minMemoryMapAlignment = CAT ((GPU_) (n) (_MIN_MEMORY_MAP_ALIGNMENT));  NL \
TB TB TB static constexpr uint64_t          minTexelBufferOffsetAlignment = CAT ((GPU_) (n) (_MIN_TEXEL_BUFFER_OFFSET_ALIGNMENT));  NL \
TB TB TB static constexpr uint64_t          minUniformBufferOffsetAlignment = CAT ((GPU_) (n) (_MIN_UNIFORM_BUFFER_OFFSET_ALIGNMENT));  NL \
TB TB TB static constexpr uint64_t          minStorageBufferOffsetAlignment = CAT ((GPU_) (n) (_MIN_STORAGE_BUFFER_OFFSET_ALIGNMENT));  NL \
TB TB TB static constexpr int32_t               minTexelOffset = CAT ((GPU_) (n) (_MIN_TEXEL_OFFSET));  NL \
TB TB TB static constexpr uint32_t              maxTexelOffset = CAT ((GPU_) (n) (_MAX_TEXEL_OFFSET));  NL \
TB TB TB static constexpr int32_t               minTexelGatherOffset = CAT ((GPU_) (n) (_MIN_TEXEL_GATHER_OFFSET));  NL \
TB TB TB static constexpr uint32_t              maxTexelGatherOffset = CAT ((GPU_) (n) (_MAX_TEXEL_GATHER_OFFSET));  NL \
TB TB TB static constexpr float                 minInterpolationOffset = CAT ((GPU_) (n) (_MIN_INTERPOLATION_OFFSET));  NL \
TB TB TB static constexpr float                 maxInterpolationOffset = CAT ((GPU_) (n) (_MAX_INTERPOLATION_OFFSET));  NL \
TB TB TB static constexpr uint32_t              subPixelInterpolationOffsetBits = CAT ((GPU_) (n) (_SUB_PIXEL_INTERPOLATION_OFFSET_BITS));  NL \
TB TB TB static constexpr uint32_t              maxFramebufferWidth = CAT ((GPU_) (n) (_MAX_FRAMEBUFFER_WIDTH));  NL \
TB TB TB static constexpr uint32_t              maxFramebufferHeight = CAT ((GPU_) (n) (_MAX_FRAMEBUFFER_HEIGHT));  NL \
TB TB TB static constexpr uint32_t              maxFramebufferLayers = CAT ((GPU_) (n) (_MAX_FRAMEBUFFER_LAYERS));  NL \
TB TB TB static constexpr uint32_t    framebufferColorSampleCounts = CAT ((GPU_) (n) (_FRAMEBUFFER_COLOR_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    framebufferDepthSampleCounts = CAT ((GPU_) (n) (_FRAMEBUFFER_DEPTH_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    framebufferStencilSampleCounts = CAT ((GPU_) (n) (_FRAMEBUFFER_STENCIL_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    framebufferNoAttachmentsSampleCounts = CAT ((GPU_) (n) (_FRAMEBUFFER_NO_ATTACHMENTS_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t              maxColorAttachments = CAT ((GPU_) (n) (_MAX_COLOR_ATTACHMENTS));  NL \
TB TB TB static constexpr uint32_t    sampledImageColorSampleCounts = CAT ((GPU_) (n) (_SAMPLED_IMAGE_COLOR_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    sampledImageIntegerSampleCounts = CAT ((GPU_) (n) (_SAMPLED_IMAGE_INTEGER_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    sampledImageDepthSampleCounts = CAT ((GPU_) (n) (_SAMPLED_IMAGE_DEPTH_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    sampledImageStencilSampleCounts = CAT ((GPU_) (n) (_SAMPLED_IMAGE_STENCIL_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    storageImageSampleCounts = CAT ((GPU_) (n) (_STORAGE_IMAGE_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t              maxSampleMaskWords = CAT ((GPU_) (n) (_MAX_SAMPLE_MASK_WORDS));  NL \
TB TB TB static constexpr uint32_t              timestampComputeAndGraphics = CAT ((GPU_) (n) (_TIMESTAMP_COMPUTE_AND_GRAPHICS));  NL \
TB TB TB static constexpr float                 timestampPeriod = CAT ((GPU_) (n) (_TIMESTAMP_PERIOD));  NL \
TB TB TB static constexpr uint32_t              maxClipDistances = CAT ((GPU_) (n) (_MAX_CLIP_DISTANCES));  NL \
TB TB TB static constexpr uint32_t              maxCullDistances = CAT ((GPU_) (n) (_MAX_CULL_DISTANCES));  NL \
TB TB TB static constexpr uint32_t              maxCombinedClipAndCullDistances = CAT ((GPU_) (n) (_MAX_COMBINED_CLIP_AND_CULL_DISTANCES));  NL \
TB TB TB static constexpr uint32_t              discreteQueuePriorities = CAT ((GPU_) (n) (_DISCRETE_QUEUE_PRIORITIES));  NL \
TB TB TB static constexpr uint32_t              pointSizeRange[2] = {CAT ((GPU_) (n) (_POINT_SIZE_RANGE_0)), CAT ((GPU_) (n) (_POINT_SIZE_RANGE_1))};  NL \
TB TB TB static constexpr uint32_t              lineWidthRange[2] = {CAT ((GPU_) (n) (_LINE_WIDTH_RANGE_0)), CAT ((GPU_) (n) (_LINE_WIDTH_RANGE_1))};  NL \
TB TB TB static constexpr float                 pointSizeGranularity = CAT ((GPU_) (n) (_POINT_SIZE_GRANULARITY));  NL \
TB TB TB static constexpr float                 lineWidthGranularity = CAT ((GPU_) (n) (_LINE_WIDTH_GRANULARITY));  NL \
TB TB TB static constexpr uint32_t              strictLines = CAT ((GPU_) (n) (_STRICT_LINES));  NL \
TB TB TB static constexpr uint32_t              standardSampleLocations = CAT ((GPU_) (n) (_STANDARD_SAMPLE_LOCATIONS));  NL \
TB TB TB static constexpr uint64_t          optimalBufferCopyOffsetAlignment = CAT ((GPU_) (n) (_OPTIMAL_BUFFER_COPY_OFFSET_ALIGNMENT));  NL \
TB TB TB static constexpr uint64_t          optimalBufferCopyRowPitchAlignment = CAT ((GPU_) (n) (_OPTIMAL_BUFFER_COPY_ROW_PITCH_ALIGNMENT));  NL \
TB TB TB static constexpr uint64_t          nonCoherentAtomSize = CAT ((GPU_) (n) (_NON_COHERENT_ATOM_SIZE));  NL \
TB TB }; NL \
TB }; NL \
}; NL NL



#define BB(x)

#define AA(x) BOOST_PP_IF (string (BOOST_PP_STRINGIZE (x) == string ("hej"), BOOST_PP_IDENTITY (BOOST_PP_STRINGIZE (x)), BOOST_PP_EMPTY ())

int main (int argc, const char * argv[])
{
    file <write> instance_header (argv [1]);
    instance_header << "#pragma once \n";
    instance_header << "#include <iostream>\n\n";
    instance_header << "struct instance {";
    
    file <write> gpu_header (argv [2]);
    gpu_header << "#pragma once \n";
    gpu_header << "#include <iostream>\n";
    gpu_header << "#define GPU_COUNT " << GPU_COUNT << "\n\n";
    gpu_header << "template <int>\nstruct gpu;\n\n";
    gpu_header << BOOST_PP_STRINGIZE (BOOST_PP_REPEAT(GPU_COUNT, DECL_GPU, int x));
    
    return 0;
    
    
    PROCC((
           template <int>                                                                                                   \n
           struct gpu;                                                                                                   \n\n
           
           template <>                                                                                                         \n
           struct gpu <${i}>                                                                                                   \n
           {                                                                                                   \n\t
        static constexpr int fitta = GPU_COUNT;                                                                                                   \n\t
        static constexpr int count = GPU_COUNT;                                                                                                   \n\t
        static constexpr uint32_t max_image_dimension_1D = GPU_${i}_MAX_IMAGE_DIMENSION_1D;                                                                                                   \n
    };\n
           
           )(GPU_COUNT)
          (string gpu_class_header))
    
    
    
    return 0;
}


