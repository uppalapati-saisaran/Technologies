- A type-safe container for single values of any type. 

  std::any x{5}
  x.has_value() // == true
  std::any_cast<int>(x) //  == 5
  std::any_cast<int&>(x) = 10;
  std::any_cast<int>(x) // == 10
  
  
