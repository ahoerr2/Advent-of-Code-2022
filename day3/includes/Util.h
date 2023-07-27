#include <iostream>
# pragma once

namespace Util
{
  template<typename T>
  concept printable = requires(T t){
    {std::cout << t} -> std::same_as<std::ostream&>;
  };

  template<printable T>
  void printVector(const std::vector<T>& vec, const std::string& name = "Vec"){
    std::cout << name << ": [";
      for (auto item : vec){
          std::cout << item << ", ";
      }
      std::cout << "]" << std::endl;
    };
}