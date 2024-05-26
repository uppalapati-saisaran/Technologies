- C++ 11 introduces a new null pointer type desinged to replace C's NULL macro.

- nullptr itself is of type std::nullptr_t and can be implicitly converted into pointer types, and unlike NULL, 
  not convertiable to integral types except bool. 
  
  void foo(int);
  void foo(char *);
  
  foo(NULL);  //error -- ambigous
  foo(nullptr); // calls foo(char *) 