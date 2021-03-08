#pragma once
#include <type_traits>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
//#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
//#include <GLFW/glfw3.h>
#include <fstream>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <boost/preprocessor/facilities/expand.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/cat.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/facilities/empty.hpp>
#include <boost/preprocessor/facilities/identity.hpp>
using namespace std;

template <class T, class U>
concept convertible = is_convertible_v<T, U> and is_convertible_v<U, T>;
struct read;
struct write;
template <class>
struct file;
template <>
struct file <write>
{
      ofstream m_file;
      using self = file<write>;
      
      
      file (string const& n)
      {
            m_file.open (n);
      }
      
      template <class T>
      auto operator<< (T&& v) -> decltype (auto)
      {
            m_file << forward<T>(v);
            return *this;
      }
      
      ~file ()
      {
            m_file.close ();
      }
};


