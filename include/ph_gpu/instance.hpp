#pragma once 
#include <iostream>

struct instance 
{
		static constexpr int extension_count = 12;
		static constexpr int layer_count = 4;

		template <int>
		struct extension;

		template <int>
		struct layer;

	struct layers 
	{
	};
	 template <> 
 	 struct extension <0> 
 	 { 
 	 	 static constexpr char name [] = "VK_KHR_device_group_creation"; 
 	 }; 
 	 template <> 
 	 struct extension <1> 
 	 { 
 	 	 static constexpr char name [] = "VK_KHR_external_fence_capabilities"; 
 	 }; 
 	 template <> 
 	 struct extension <2> 
 	 { 
 	 	 static constexpr char name [] = "VK_KHR_external_memory_capabilities"; 
 	 }; 
 	 template <> 
 	 struct extension <3> 
 	 { 
 	 	 static constexpr char name [] = "VK_KHR_external_semaphore_capabilities"; 
 	 }; 
 	 template <> 
 	 struct extension <4> 
 	 { 
 	 	 static constexpr char name [] = "VK_KHR_get_physical_device_properties2"; 
 	 }; 
 	 template <> 
 	 struct extension <5> 
 	 { 
 	 	 static constexpr char name [] = "VK_KHR_get_surface_capabilities2"; 
 	 }; 
 	 template <> 
 	 struct extension <6> 
 	 { 
 	 	 static constexpr char name [] = "VK_KHR_surface"; 
 	 }; 
 	 template <> 
 	 struct extension <7> 
 	 { 
 	 	 static constexpr char name [] = "VK_EXT_debug_report"; 
 	 }; 
 	 template <> 
 	 struct extension <8> 
 	 { 
 	 	 static constexpr char name [] = "VK_EXT_debug_utils"; 
 	 }; 
 	 template <> 
 	 struct extension <9> 
 	 { 
 	 	 static constexpr char name [] = "VK_EXT_metal_surface"; 
 	 }; 
 	 template <> 
 	 struct extension <10> 
 	 { 
 	 	 static constexpr char name [] = "VK_EXT_swapchain_colorspace"; 
 	 }; 
 	 template <> 
 	 struct extension <11> 
 	 { 
 	 	 static constexpr char name [] = "VK_MVK_macos_surface"; 
 	 }; 
	 template <> 
 	 struct layers <0> 
 	 { 
 	 	 static constexpr char name [] = "VK_LAYER_LUNARG_api_dump"; 
 	 }; 
 	 template <> 
 	 struct layers <1> 
 	 { 
 	 	 static constexpr char name [] = "VK_LAYER_KHRONOS_validation"; 
 	 }; 
 	 template <> 
 	 struct layers <2> 
 	 { 
 	 	 static constexpr char name [] = "VK_LAYER_LUNARG_device_simulation"; 
 	 }; 
 	 template <> 
 	 struct layers <3> 
 	 { 
 	 	 static constexpr char name [] = "VK_LAYER_KHRONOS_synchronization2"; 
 	 }; 
};
