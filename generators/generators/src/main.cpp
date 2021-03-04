#include "main.hpp"


#define DEF(x) string("#define ") + string(BOOST_PP_STRINGIZE (x))


auto PARSE_H (string s)
{
      
}



struct Kiss {string getString = "hej";};

#define PARSE_1(s) [](string str){}(string (s))

#define PARSE(x, y)

int main (int argc, const char * argv[])
{
      Kiss k;
      cout << "GET_STRING" << k.getString << endl;
      cout << []{return 0;}() << endl;
      return 0;
      
      ss = regex_replace (ss, regex ("([a-z])([A-Z])"), R"($1_$2)");
      ss = regex_replace (ss, regex ("([[:digit:]]+)"), R"(_$1)");
      for (auto & c: ss) c = toupper(c);
      cout << ss << endl;
      
      
      
      

      
      
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
            auto props = getPhysicalDeviceProperties (i);
            auto feats = getPhysicalDeviceFeatures (i);
            VkPhysicalDeviceLimits limits = props.limits;
            auto _int = to_string (nr_of_gpus);
//            output_file << "constexpr uint32_t GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D = " <<  limits.maxImageDimension1D << ";\n";
            output_file << DEF (GPU_) << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxImageDimension1D << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_2D " <<  limits.maxImageDimension2D << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_3D " <<  limits.maxImageDimension3D << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_CUBE " <<  limits.maxImageDimensionCube << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_ARRAY_LAYERS " <<  limits.maxImageArrayLayers << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_TEXEL_BUFFER_ELEMENTS " <<  limits.maxTexelBufferElements << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_UNIFORM_BUFFER_RANGE " <<  limits.maxUniformBufferRange << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_STORAGE_BUFFER_RANGE " <<  limits.maxStorageBufferRange << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_PUSH_CONSTANTS_SIZE " <<  limits.maxPushConstantsSize << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_SAMPLER_ALLOCATION_COUNT " <<  limits.maxSamplerAllocationCount << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.bufferImageGranularity << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.sparseAddressSpaceSize << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxBoundDescriptorSets << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxPerStageDescriptorSamplers << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxPerStageDescriptorSamplers << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxPerStageDescriptorSamplers << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxPerStageDescriptorSampledImages << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxPerStageDescriptorStorageImages << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxPerStageDescriptorInputAttachments << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxPerStageResources << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxPerStageResources << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxDescriptorSetUniformBuffers << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxDescriptorSetUniformBuffersDynamic << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxDescriptorSetStorageBuffers << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxDescriptorSetStorageBuffersDynamic << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxDescriptorSetSampledImages << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxDescriptorSetStorageImages << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxDescriptorSetInputAttachments << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxVertexInputAttributes << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxVertexInputBindings << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxVertexInputAttributeOffset << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxVertexInputBindingStride << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxVertexOutputComponents << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxTessellationGenerationLevel << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxTessellationPatchSize << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxTessellationControlPerVertexInputComponents << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxTessellationControlPerVertexOutputComponents << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxTessellationControlPerPatchOutputComponents << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxTessellationControlTotalOutputComponents << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxTessellationEvaluationInputComponents << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxTessellationEvaluationOutputComponents << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxGeometryShaderInvocations << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxGeometryInputComponents << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxGeometryOutputComponents << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxGeometryOutputVertices << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxGeometryTotalOutputComponents << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxFragmentInputComponents << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxFragmentOutputAttachments << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxFragmentDualSrcAttachments << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxFragmentCombinedOutputResources << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxComputeSharedMemorySize << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxComputeWorkGroupCount[0] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxComputeWorkGroupCount[1] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxComputeWorkGroupCount[2] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxComputeWorkGroupInvocations << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxComputeWorkGroupSize[0] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxComputeWorkGroupSize[1] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxComputeWorkGroupSize[2] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.subPixelPrecisionBits << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.subTexelPrecisionBits << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.mipmapPrecisionBits << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxDrawIndexedIndexValue << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxDrawIndirectCount << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxSamplerLodBias << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxSamplerAnisotropy << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxViewports << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxViewportDimensions[0] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxViewportDimensions[1] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.viewportBoundsRange[0] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.viewportBoundsRange[1] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.viewportSubPixelBits << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.minMemoryMapAlignment << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.minTexelBufferOffsetAlignment << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.minUniformBufferOffsetAlignment << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.minStorageBufferOffsetAlignment << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.minTexelOffset << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxTexelOffset << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.minTexelGatherOffset << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxTexelGatherOffset << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.minInterpolationOffset << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxInterpolationOffset << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.subPixelInterpolationOffsetBits << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxFramebufferWidth << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxFramebufferHeight << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxFramebufferLayers << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.framebufferColorSampleCounts << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.framebufferDepthSampleCounts << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.framebufferStencilSampleCounts << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.framebufferNoAttachmentsSampleCounts << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.maxColorAttachments << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.sampledImageColorSampleCounts << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.sampledImageIntegerSampleCounts << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.sampledImageDepthSampleCounts << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.sampledImageStencilSampleCounts << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_IMAGE_DIMENSION_1D " <<  limits.storageImageSampleCounts << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_SAMPLE_MASK_WORDS " <<  limits.maxSampleMaskWords << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_TIMESTAMP_COMPUTE_AND_GRAPHICS " <<  limits.timestampComputeAndGraphics << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_TIMESTAMP_PERIOD " <<  limits.timestampPeriod << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_CLIP_DISTANCES " <<  limits.maxClipDistances << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_CULL_DISTANCES " <<  limits.maxCullDistances << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_MAX_COMBINED_CLIP_AND_CULL_DISTANCES " <<  limits.maxCombinedClipAndCullDistances << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_DISCRETE_QUEUE_PRIORITIES " <<  limits.discreteQueuePriorities << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_POINT_SIZE_RANGE_0 " <<  limits.pointSizeRange[0] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_POINT_SIZE_RANGE_1 " <<  limits.pointSizeRange[1] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_LINE_WIDTH_RANGE_0 " <<  limits.lineWidthRange[0] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_LINE_WIDTH_RANGE_1 " <<  limits.lineWidthRange[1] << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_POINT_SIZE_GRANULARITY " <<  limits.pointSizeGranularity << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_LINES_WIDTH_GRANULARITY " <<  limits.lineWidthGranularity << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_STRUCT_LINES " <<  limits.strictLines << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_STANDARD_SAMPLE_LOCATIONS" <<  limits.standardSampleLocations << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_OPTIMAL_BUFFER_COPY_OFFSET_ALIGNMENT " <<  limits.optimalBufferCopyOffsetAlignment << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_OPTIMAL_BUFFER_COPY_ROW_PITCH_ALIGNMENT" <<  limits.optimalBufferCopyRowPitchAlignment << "\n";
            output_file << "#define GPU_" << nr_of_gpus << "_NO_CHOHERENT_ATOM_SIZE " <<  limits.nonCoherentAtomSize << "\n";


            
            ++nr_of_gpus;
      }
      
      
      vkDestroyInstance(instance, nullptr);
      glfwTerminate();
      
      //      system("open test.hpp");
      return 0;
}

