#pragma once 
#include <iostream>
#define GPU_COUNT 1

template <int>
struct gpu;

template <> 
 struct gpu <0> 
 { 
 	 struct features 
 	 { 
 	 	 static constexpr uint32_t robustBufferAccess = 1; 
 	 	 static constexpr uint32_t fullDrawIndexUint32 = 1; 
 	 	 static constexpr uint32_t imageCubeArray = 1; 
 	 	 static constexpr uint32_t independentBlend = 1; 
 	 	 static constexpr uint32_t geometryShader = 0; 
 	 	 static constexpr uint32_t tessellationShader = 1; 
 	 	 static constexpr uint32_t sampleRateShading = 1; 
 	 	 static constexpr uint32_t dualSrcBlend = 1; 
 	 	 static constexpr uint32_t logicOp = 0; 
 	 	 static constexpr uint32_t multiDrawIndirect = 1; 
 	 	 static constexpr uint32_t drawIndirectFirstInstance = 1; 
 	 	 static constexpr uint32_t depthClamp = 1; 
 	 	 static constexpr uint32_t depthBiasClamp = 1; 
 	 	 static constexpr uint32_t fillModeNonSolid = 1; 
 	 	 static constexpr uint32_t depthBounds = 0; 
 	 	 static constexpr uint32_t wideLines = 0; 
 	 	 static constexpr uint32_t largePoints = 1; 
 	 	 static constexpr uint32_t alphaToOne = 1; 
 	 	 static constexpr uint32_t multiViewport = 1; 
 	 	 static constexpr uint32_t samplerAnisotropy = 1; 
 	 	 static constexpr uint32_t textureCompressionETC2 = 0; 
 	 	 static constexpr uint32_t textureCompressionASTC_LDR = 0; 
 	 	 static constexpr uint32_t textureCompressionBC = 1; 
 	 	 static constexpr uint32_t occlusionQueryPrecise = 1; 
 	 	 static constexpr uint32_t pipelineStatisticsQuery = 0; 
 	 	 static constexpr uint32_t vertexPipelineStoresAndAtomics = 1; 
 	 	 static constexpr uint32_t fragmentStoresAndAtomics = 1; 
 	 	 static constexpr uint32_t shaderTessellationAndGeometryPointSize = 1; 
 	 	 static constexpr uint32_t shaderImageGatherExtended = 1; 
 	 	 static constexpr uint32_t shaderStorageImageExtendedFormats = 1; 
 	 	 static constexpr uint32_t shaderStorageImageMultisample = 0; 
 	 	 static constexpr uint32_t shaderStorageImageReadWithoutFormat = 1; 
 	 	 static constexpr uint32_t shaderStorageImageWriteWithoutFormat = 1; 
 	 	 static constexpr uint32_t shaderUniformBufferArrayDynamicIndexing = 1; 
 	 	 static constexpr uint32_t shaderSampledImageArrayDynamicIndexing = 1; 
 	 	 static constexpr uint32_t shaderStorageBufferArrayDynamicIndexing = 1; 
 	 	 static constexpr uint32_t shaderStorageImageArrayDynamicIndexing = 1; 
 	 	 static constexpr uint32_t shaderClipDistance = 1; 
 	 	 static constexpr uint32_t shaderCullDistance = 0; 
 	 	 static constexpr uint32_t shaderFloat64 = 0; 
 	 	 static constexpr uint32_t shaderInt64 = 0; 
 	 	 static constexpr uint32_t shaderInt16 = 1; 
 	 	 static constexpr uint32_t shaderResourceResidency = 0; 
 	 	 static constexpr uint32_t shaderResourceMinLod = 1; 
 	 	 static constexpr uint32_t sparseBinding = 0; 
 	 	 static constexpr uint32_t sparseResidencyBuffer = 0; 
 	 	 static constexpr uint32_t sparseResidencyImage2D = 0; 
 	 	 static constexpr uint32_t sparseResidencyImage3D = 0; 
 	 	 static constexpr uint32_t sparseResidency2Samples = 0; 
 	 	 static constexpr uint32_t sparseResidency4Samples = 0; 
 	 	 static constexpr uint32_t sparseResidency8Samples = 0; 
 	 	 static constexpr uint32_t sparseResidency16Samples = 0; 
 	 	 static constexpr uint32_t sparseResidencyAliased = 0; 
 	 	 static constexpr uint32_t variableMultisampleRate = 0; 
 	 	 static constexpr uint32_t inheritedQueries = 1; 
 	 }; 
 
 	 struct properties 
 	 { 
 	 	 static constexpr uint32_t apiVersion = 4198570; 
 	 	 static constexpr uint32_t driverVersion = 10102; 
 	 	 static constexpr uint32_t vendorID = 32902; 
 	 	 static constexpr uint32_t deviceID = 22822; 
 	 	 static constexpr char deviceName [256] = "Intel(R) Iris(TM) Plus Graphics 640"; 
 
 	 	 struct limits 
 	 	 { 
 	 	 	 static constexpr uint32_t max_image_dimension_1D = 16384; 
 	 	 	 static constexpr uint32_t maxImageDimension2D = 16384; 
 	 	 	 static constexpr uint32_t maxImageDimension3D = 16384; 
 	 	 	 static constexpr uint32_t maxImageDimensionCube = 16384; 
 	 	 	 static constexpr uint32_t maxImageArrayLayers = 2048; 
 	 	 	 static constexpr uint32_t maxTexelBufferElements = 67108864; 
 	 	 	 static constexpr uint32_t maxUniformBufferRange = 65536; 
 	 	 	 static constexpr uint32_t maxStorageBufferRange = 2147483648; 
 	 	 	 static constexpr uint32_t maxPushConstantsSize = 4096; 
 	 	 	 static constexpr uint32_t maxMemoryAllocationCount = 1073741824; 
 	 	 	 static constexpr uint32_t maxSamplerAllocationCount = 1073741824; 
 	 	 	 static constexpr uint64_t bufferImageGranularity = 256; 
 	 	 	 static constexpr uint64_t sparseAddressSpaceSize = 0; 
 	 	 	 static constexpr uint32_t maxBoundDescriptorSets = 8; 
 	 	 	 static constexpr uint32_t maxPerStageDescriptorSamplers = 16; 
 	 	 	 static constexpr uint32_t maxPerStageDescriptorUniformBuffers = 31; 
 	 	 	 static constexpr uint32_t maxPerStageDescriptorStorageBuffers = 31; 
 	 	 	 static constexpr uint32_t maxPerStageDescriptorSampledImages = 128; 
 	 	 	 static constexpr uint32_t maxPerStageDescriptorStorageImages = 8; 
 	 	 	 static constexpr uint32_t maxPerStageDescriptorInputAttachments = 128; 
 	 	 	 static constexpr uint32_t maxPerStageResources = 159; 
 	 	 	 static constexpr uint32_t maxDescriptorSetSamplers = 80; 
 	 	 	 static constexpr uint32_t maxDescriptorSetUniformBuffers = 155; 
 	 	 	 static constexpr uint32_t maxDescriptorSetUniformBuffersDynamic = 155; 
 	 	 	 static constexpr uint32_t maxDescriptorSetStorageBuffers = 155; 
 	 	 	 static constexpr uint32_t maxDescriptorSetStorageBuffersDynamic = 155; 
 	 	 	 static constexpr uint32_t maxDescriptorSetSampledImages = 640; 
 	 	 	 static constexpr uint32_t maxDescriptorSetStorageImages = 40; 
 	 	 	 static constexpr uint32_t maxDescriptorSetInputAttachments = 640; 
 	 	 	 static constexpr uint32_t maxVertexInputAttributes = 31; 
 	 	 	 static constexpr uint32_t maxVertexInputBindings = 31; 
 	 	 	 static constexpr uint32_t maxVertexInputAttributeOffset = 2047; 
 	 	 	 static constexpr uint32_t maxVertexInputBindingStride = 2048; 
 	 	 	 static constexpr uint32_t maxVertexOutputComponents = 124; 
 	 	 	 static constexpr uint32_t maxTessellationGenerationLevel = 64; 
 	 	 	 static constexpr uint32_t maxTessellationPatchSize = 32; 
 	 	 	 static constexpr uint32_t maxTessellationControlPerVertexInputComponents = 124; 
 	 	 	 static constexpr uint32_t maxTessellationControlPerVertexOutputComponents = 124; 
 	 	 	 static constexpr uint32_t maxTessellationControlPerPatchOutputComponents = 120; 
 	 	 	 static constexpr uint32_t maxTessellationControlTotalOutputComponents = 4088; 
 	 	 	 static constexpr uint32_t maxTessellationEvaluationInputComponents = 124; 
 	 	 	 static constexpr uint32_t maxTessellationEvaluationOutputComponents = 124; 
 	 	 	 static constexpr uint32_t maxGeometryShaderInvocations = 0; 
 	 	 	 static constexpr uint32_t maxGeometryInputComponents = 0; 
 	 	 	 static constexpr uint32_t maxGeometryOutputComponents = 0; 
 	 	 	 static constexpr uint32_t maxGeometryOutputVertices = 0; 
 	 	 	 static constexpr uint32_t maxGeometryTotalOutputComponents = 0; 
 	 	 	 static constexpr uint32_t maxFragmentInputComponents = 124; 
 	 	 	 static constexpr uint32_t maxFragmentOutputAttachments = 8; 
 	 	 	 static constexpr uint32_t maxFragmentDualSrcAttachments = 1; 
 	 	 	 static constexpr uint32_t maxFragmentCombinedOutputResources = 159; 
 	 	 	 static constexpr uint32_t maxComputeSharedMemorySize = 65536; 
 	 	 	 static constexpr uint32_t maxComputeWorkGroupCount[3] = {1073741824, 1073741824, 1073741824}; 
 	 	 	 static constexpr uint32_t maxComputeWorkGroupInvocations = 1024; 
 	 	 	 static constexpr uint32_t maxComputeWorkGroupSize[3] = {1024, 1024, 1024}; 
 	 	 	 static constexpr uint32_t subPixelPrecisionBits = 4; 
 	 	 	 static constexpr uint32_t subTexelPrecisionBits = 4; 
 	 	 	 static constexpr uint32_t mipmapPrecisionBits = 4; 
 	 	 	 static constexpr uint32_t maxDrawIndexedIndexValue = 4294967295; 
 	 	 	 static constexpr uint32_t maxDrawIndirectCount = 1073741824; 
 	 	 	 static constexpr float maxSamplerLodBias = 0; 
 	 	 	 static constexpr float maxSamplerAnisotropy = 16; 
 	 	 	 static constexpr uint32_t maxViewports = 16; 
 	 	 	 static constexpr uint32_t maxViewportDimensions[2] = {16384, 16384}; 
 	 	 	 static constexpr float viewportBoundsRange[2] = {-32768, 32767}; 
 	 	 	 static constexpr uint32_t viewportSubPixelBits = 0; 
 	 	 	 static constexpr size_t minMemoryMapAlignment = 256; 
 	 	 	 static constexpr uint64_t minTexelBufferOffsetAlignment = 16; 
 	 	 	 static constexpr uint64_t minUniformBufferOffsetAlignment = 256; 
 	 	 	 static constexpr uint64_t minStorageBufferOffsetAlignment = 16; 
 	 	 	 static constexpr int32_t minTexelOffset = -8; 
 	 	 	 static constexpr uint32_t maxTexelOffset = 7; 
 	 	 	 static constexpr int32_t minTexelGatherOffset = -8; 
 	 	 	 static constexpr uint32_t maxTexelGatherOffset = 7; 
 	 	 	 static constexpr float minInterpolationOffset = -0.5; 
 	 	 	 static constexpr float maxInterpolationOffset = 0.5; 
 	 	 	 static constexpr uint32_t subPixelInterpolationOffsetBits = 4; 
 	 	 	 static constexpr uint32_t maxFramebufferWidth = 16384; 
 	 	 	 static constexpr uint32_t maxFramebufferHeight = 16384; 
 	 	 	 static constexpr uint32_t maxFramebufferLayers = 2048; 
 	 	 	 static constexpr uint32_t framebufferColorSampleCounts = 15; 
 	 	 	 static constexpr uint32_t framebufferDepthSampleCounts = 15; 
 	 	 	 static constexpr uint32_t framebufferStencilSampleCounts = 15; 
 	 	 	 static constexpr uint32_t framebufferNoAttachmentsSampleCounts = 15; 
 	 	 	 static constexpr uint32_t maxColorAttachments = 8; 
 	 	 	 static constexpr uint32_t sampledImageColorSampleCounts = 15; 
 	 	 	 static constexpr uint32_t sampledImageIntegerSampleCounts = 15; 
 	 	 	 static constexpr uint32_t sampledImageDepthSampleCounts = 15; 
 	 	 	 static constexpr uint32_t sampledImageStencilSampleCounts = 15; 
 	 	 	 static constexpr uint32_t storageImageSampleCounts = 1; 
 	 	 	 static constexpr uint32_t maxSampleMaskWords = 1; 
 	 	 	 static constexpr uint32_t timestampComputeAndGraphics = 1; 
 	 	 	 static constexpr float timestampPeriod = 1; 
 	 	 	 static constexpr uint32_t maxClipDistances = 1073741824; 
 	 	 	 static constexpr uint32_t maxCullDistances = 0; 
 	 	 	 static constexpr uint32_t maxCombinedClipAndCullDistances = 1073741824; 
 	 	 	 static constexpr uint32_t discreteQueuePriorities = 2; 
 	 	 	 static constexpr uint32_t pointSizeRange[2] = {1, 64}; 
 	 	 	 static constexpr uint32_t lineWidthRange[2] = {1, 1}; 
 	 	 	 static constexpr float pointSizeGranularity = 1; 
 	 	 	 static constexpr float lineWidthGranularity = 1; 
 	 	 	 static constexpr uint32_t strictLines = 1; 
 	 	 	 static constexpr uint32_t standardSampleLocations = 1; 
 	 	 	 static constexpr uint64_t optimalBufferCopyOffsetAlignment = 256; 
 	 	 	 static constexpr uint64_t optimalBufferCopyRowPitchAlignment = 1; 
 	 	 	 static constexpr uint64_t nonCoherentAtomSize = 256; 
 	 	 }; 
 	 }; 
 }; 
 
