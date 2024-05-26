to_array :

- Converts the given array/array-like object to a std::array.

  std::to_array("foo");  // returns 'std::array<char,4>'
  std::to_array<int>({1,2,3});  // returns 'std::array<int,3>'
  
  int a[]={1,2,3};
  
  std::to_array(a); // returns 'std::array<int,2>' 
  
  
  