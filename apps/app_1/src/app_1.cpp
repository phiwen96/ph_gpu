//#include <ph_gpu/ph_gpu.hpp>
//#include <phulkan_generator/phulkan_generator.hpp>
#include "app_1.hpp"

#include <iostream>
using namespace std;

consteval int ja ()
{
    return gpu<0>::queueFamilyCount;
}

int main ()
{
    constexpr int q = ja();
    cout << q << endl;
    cout << gpu<0>::properties::limits::nonCoherentAtomSize << endl;
      cout << GPU_COUNT << endl;
      cout << "hi" << endl;
      return 0;
}


