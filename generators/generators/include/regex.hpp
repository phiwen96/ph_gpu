#pragma once
#include <iostream>
#include <regex>
using namespace std;


// "-46"
bool is_number (string const& s)
{
      return regex_match (s, regex ("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?"));
}



//auto const regex = std::regex("(MY|your) regex)", std::regex::icase);




template <typename UnaryFunction>
inline std::string RegexReplace(const std::string& source, const char* const re_str, UnaryFunction f, size_t* numMatches = nullptr)
{
      try
      {
            std::string s;
            
            std::smatch::difference_type positionOfLastMatch = 0;
            std::string::const_iterator first = std::begin(source), last = std::end(source);
            auto endOfLastMatch = first;
            
            if (numMatches)
                  *numMatches = 0;
            
            auto callback = [&](const std::smatch& match)
            {
                  auto positionOfThisMatch = match.position(0);
                  auto diff = positionOfThisMatch - positionOfLastMatch;
                  
                  auto startOfThisMatch = endOfLastMatch;
                  std::advance(startOfThisMatch, diff);
                  
                  s.append(endOfLastMatch, startOfThisMatch);
                  s.append(f(match));
                  
                  auto lengthOfMatch = match.length(0);
                  
                  positionOfLastMatch = positionOfThisMatch + lengthOfMatch;
                  
                  endOfLastMatch = startOfThisMatch;
                  std::advance(endOfLastMatch, lengthOfMatch);
                  
                  if (numMatches)
                        (*numMatches)++;
            };
            
            std::regex re{re_str};
            std::sregex_iterator begin(first, last, re), end;
            std::for_each(begin, end, callback);
            
            s.append(endOfLastMatch, last);
            return s;
      }
      catch (const std::regex_error&)
      {
            return "";
      }
}

//const std::string str2 = "HELLO WORLD HOW ARE YOU TODAY";
//auto lowercaseSecondSubmatch = [](const std::smatch& match) -> std::string
//{
//      if (match.size() != 3)
//            return "WTF";
//      
//      std::string result = match.str(0);
//      
//      // Lowercase the second submatch
//      const auto pos = match.position(2) - match.position(0);
//      const auto len = match.length(2);
//      const auto start = result.begin() + pos;
//      const auto end   = result.begin() + pos + len;
//      std::transform(start, end, start, ::tolower);
//      return result;
//};
//
//size_t n = 0;
//std::cout << RegexReplace(str2, R"(\b([AEIOUY])([A-Z]+))", lowercaseSecondSubmatch, &n) << '\n';
//std::cout << n << " matches\n";
