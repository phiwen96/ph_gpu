#pragma once
#include <iostream>
#include <regex>
using namespace std;


// "-46"
bool is_number (string const& s)
{
      return regex_match (s, regex ("(\\+|-)?[[:digit:]]+"));
}
