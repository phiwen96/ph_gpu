#include "main.hpp"


#define DEF(x) string("#define ") + string(BOOST_PP_STRINGIZE (x))


auto PARSE_H (string s)
{
      
}



struct Kiss {string getString = "hej";};

#define PARSE_1(s) [](string str){str = regex_replace (str, regex ("(.*)(\\[)"), R"($1)");str = regex_replace (str, regex ("(.*)(\\])"), R"($1)");str = regex_replace (str, regex ("(.*)(\\.)"), R"()");str = regex_replace (str, regex ("([a-z])([A-Z])"), R"($1_$2)");str = regex_replace (str, regex ("([[:digit:]]+)"), R"(_$1)");for (auto & c: str) c = toupper(c);str.insert (0, "_"); return str;}(string (s))

#define PARSE(x, ...) PARSE_1 (BOOST_PP_STRINGIZE (x)) __VA_ARGS__ x
// PARSE (k.getString, ...)  ->  GET_STRING ... k.getString
int main (int argc, const char * argv[])
{
      
      
      
      //      cout << parse ("k.getString") << endl;
//      Kiss k;
//      cout << "GET_STRING" << k.getString << endl;
//      cout << "GPU_" << PARSE (k.getString, << " " <<) << endl;
//      cout << []{return 0;}() << endl;
//      return 0;
      
      

      
      
      
      

      
      
      string const output_file_path = argv [1];
      
      file <write> output_file (output_file_path);
      output_file << "#pragma once\n";
      
      
      
      
      string ss = "maxImageDimension30f80D";
      
      
      //      subject = regex_replace (subject, regex ("[a-z][A-Z]"), R"($&\)");
      
      
      //      output_file << "#define SELF \"" << argv[1] << "\"\n";
      
      
      glfwInit();
      auto instanceExtensions = []{
            uint32_t extensionCount = 0;
            vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
            vector<VkExtensionProperties> extensions (extensionCount);
            vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
            return extensions;
      }();
      auto instanceValidationLayers = []{
            uint32_t layerCount = 0;
            vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
            vector<VkLayerProperties> availableLayers (layerCount);
            vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
            return availableLayers;
      }();
      auto instance = []{
            VkApplicationInfo appInfo
            {
                  .sType                  = VK_STRUCTURE_TYPE_APPLICATION_INFO,
                  .pApplicationName       = "generator",
                  .applicationVersion     = VK_MAKE_VERSION (1, 0, 0),
                  .pEngineName            = "No Engine",
                  .engineVersion          = VK_MAKE_VERSION (1, 0, 0),
                  .apiVersion             = VK_API_VERSION_1_2
            };
            
            
            
            VkInstance instance;
            
            VkInstanceCreateInfo createInfo
            {
                  .sType                        = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                  .pApplicationInfo             = &appInfo,
                  .enabledExtensionCount        = 0,//glfwExtensionCount,
                  .ppEnabledExtensionNames      = nullptr,//glfwExtensions,
                  .enabledLayerCount            = 0
            };
            
            
            
            
            
            if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
            {
                  throw runtime_error ("failed to create instance");
            }
            return instance;
      }();
      auto physicalDevices = [&instance] {
            uint32_t deviceCount = 0;
            vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
            vector<VkPhysicalDevice> devices (deviceCount);
            vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());
            return devices;
      }();
//      output_file << "constexpr int GPU_COUNT = " << physicalDevices.size() << ";\n";
      output_file << "#define GPU_COUNT " << physicalDevices.size() << "\n";

      auto getPhysicalDeviceProperties = [](VkPhysicalDevice const& physicalDevice) {
            VkPhysicalDeviceProperties properties;
            vkGetPhysicalDeviceProperties(physicalDevice, &properties);
            return properties;
      };
      auto getPhysicalDeviceFeatures = [](VkPhysicalDevice const& physicalDevice) {
            VkPhysicalDeviceFeatures features;
            vkGetPhysicalDeviceFeatures(physicalDevice, &features);
            return features;
      };
      
      [&]{
            for (auto& i : instanceExtensions)
                  cout << "\t" << i.extensionName << endl;
            
            cout << endl;
            
            for (auto& i : instanceValidationLayers)
                  cout << "\t" << i.layerName << endl;
      };
      
      int nr_of_gpus = 0;
      
      
      

      
      for (auto& i : physicalDevices)
      {
            VkPhysicalDeviceProperties props = getPhysicalDeviceProperties (i);
            VkPhysicalDeviceFeatures feats = getPhysicalDeviceFeatures (i);
            VkPhysicalDeviceLimits limits = props.limits;
            
            
            
            output_file << DEF (GPU_) << nr_of_gpus << "_TYPE_DISCRETE " << (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << "_TYPE_INTEGRATED " << (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << "_TYPE_VIRTUAL " << (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << "_TYPE_CPU " << (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_CPU) << "\n";

            output_file << "\n";
            
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.robustBufferAccess, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.fullDrawIndexUint32, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.imageCubeArray, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.independentBlend, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.geometryShader, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.tessellationShader, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.sampleRateShading, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.dualSrcBlend, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.logicOp, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.multiDrawIndirect, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.drawIndirectFirstInstance, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.depthClamp, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.depthBiasClamp, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.fillModeNonSolid, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.depthBounds, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.wideLines, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.largePoints, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.alphaToOne, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.multiViewport, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.samplerAnisotropy, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.textureCompressionETC2, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.textureCompressionASTC_LDR, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.textureCompressionBC, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.occlusionQueryPrecise, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.pipelineStatisticsQuery, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.vertexPipelineStoresAndAtomics, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.fragmentStoresAndAtomics, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderTessellationAndGeometryPointSize, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderImageGatherExtended, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderStorageImageExtendedFormats, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderStorageImageMultisample, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderStorageImageReadWithoutFormat, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderStorageImageWriteWithoutFormat, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderUniformBufferArrayDynamicIndexing, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderSampledImageArrayDynamicIndexing, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderStorageBufferArrayDynamicIndexing, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderStorageImageArrayDynamicIndexing, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderClipDistance, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderCullDistance, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderFloat64, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderInt64, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderInt16, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderResourceResidency, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.shaderResourceMinLod, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.sparseBinding, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.sparseResidencyBuffer, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.sparseResidencyImage2D, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.sparseResidencyImage3D, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.sparseResidency2Samples, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.sparseResidency4Samples, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.sparseResidency8Samples, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.sparseResidency16Samples, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.sparseResidencyAliased, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.variableMultisampleRate, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (feats.inheritedQueries, << " " <<) << " \n";
            
            
            
            output_file << "\n";

            
            
            
            
            
            
//            output_file << "constexpr uint32_t GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D = " <<  limits.maxImageDimension1D << ";\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxImageDimension1D, << " " <<) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxImageDimension2D, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxDescriptorSetUniformBuffersDynamic, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxDescriptorSetUniformBuffers, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxPerStageResources, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxPerStageDescriptorInputAttachments, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxPerStageDescriptorStorageImages, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxPerStageDescriptorSampledImages, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxPerStageDescriptorSamplers, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxPerStageDescriptorSamplers, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxPerStageDescriptorSamplers, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxBoundDescriptorSets, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.sparseAddressSpaceSize, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.bufferImageGranularity, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxSamplerAllocationCount, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxPushConstantsSize, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxStorageBufferRange, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxUniformBufferRange, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxTexelBufferElements, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxImageArrayLayers, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxImageDimensionCube, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxImageDimension3D, << " " << ) << " \n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxDescriptorSetStorageBuffers, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxDescriptorSetStorageBuffersDynamic, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxDescriptorSetSampledImages, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxDescriptorSetStorageImages, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxDescriptorSetInputAttachments, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxVertexInputAttributes, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxVertexInputBindings, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxVertexInputAttributeOffset, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxVertexInputBindingStride, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxVertexOutputComponents, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxTessellationGenerationLevel, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxTessellationPatchSize, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxTessellationControlPerVertexInputComponents, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxTessellationControlPerVertexOutputComponents, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxTessellationControlPerPatchOutputComponents, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxTessellationControlTotalOutputComponents, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxTessellationEvaluationInputComponents, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxTessellationEvaluationOutputComponents, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxGeometryShaderInvocations, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxGeometryInputComponents, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxGeometryOutputComponents, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxGeometryOutputVertices, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxGeometryTotalOutputComponents, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxFragmentInputComponents, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxFragmentOutputAttachments, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxFragmentDualSrcAttachments, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxFragmentCombinedOutputResources, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxComputeSharedMemorySize, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxComputeWorkGroupCount[0], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxComputeWorkGroupCount[1], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxComputeWorkGroupCount[2], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxComputeWorkGroupInvocations, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxComputeWorkGroupSize[0], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxComputeWorkGroupSize[1], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxComputeWorkGroupSize[2], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.subPixelPrecisionBits, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.subTexelPrecisionBits, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.mipmapPrecisionBits, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxDrawIndexedIndexValue, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxDrawIndirectCount, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxSamplerLodBias, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxSamplerAnisotropy, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxViewports, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxViewportDimensions[0], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxViewportDimensions[1], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.viewportBoundsRange[0], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.viewportBoundsRange[1], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.viewportSubPixelBits, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.minMemoryMapAlignment, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.minTexelBufferOffsetAlignment, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.minUniformBufferOffsetAlignment, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.minStorageBufferOffsetAlignment, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.minTexelOffset, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxTexelOffset, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.minTexelGatherOffset, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxTexelGatherOffset, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.minInterpolationOffset, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxInterpolationOffset, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.subPixelInterpolationOffsetBits, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxFramebufferWidth, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxFramebufferHeight, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxFramebufferLayers, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.framebufferColorSampleCounts, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.framebufferDepthSampleCounts, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.framebufferStencilSampleCounts, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.framebufferNoAttachmentsSampleCounts, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxColorAttachments, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.sampledImageColorSampleCounts, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.sampledImageIntegerSampleCounts, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.sampledImageDepthSampleCounts, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.sampledImageStencilSampleCounts, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.storageImageSampleCounts, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxSampleMaskWords, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.timestampComputeAndGraphics, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.timestampPeriod, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxClipDistances, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxCullDistances, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.maxCombinedClipAndCullDistances, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.discreteQueuePriorities, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.pointSizeRange[0], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.pointSizeRange[1], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.lineWidthRange[0], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.lineWidthRange[1], << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.pointSizeGranularity, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.lineWidthGranularity, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.strictLines, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.standardSampleLocations, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.optimalBufferCopyOffsetAlignment, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.optimalBufferCopyRowPitchAlignment, << " " <<) << "\n";
            output_file << DEF (GPU_) << nr_of_gpus << PARSE (limits.nonCoherentAtomSize, << " " <<) << "\n";
            

            
            ++nr_of_gpus;
      }
      
      
      vkDestroyInstance(instance, nullptr);
      glfwTerminate();
      
      //      system("open test.hpp");
      return 0;
}

