#pragma once 
#include <iostream>
namespace{
#pragma once
#define GPU_COUNT 1
#define GPU_0_MAX_IMAGE_DIMENSION_1D 16384
}
template <int> 
 struct gpu; 

 template <> 
 struct gpu <0> 
 { 
	 static constexpr int fitta = GPU_COUNT; 
	 static constexpr int count = GPU_COUNT; 
	 static constexpr uint32_t max_image_dimension_1D = GPU_0_MAX_IMAGE_DIMENSION_1D; 
 };
