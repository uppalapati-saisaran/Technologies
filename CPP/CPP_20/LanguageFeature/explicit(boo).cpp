explicit(boo)

- Conditionally select at compile time whether a construct is made explicit or not.

- explicit(true) is the same as specifying explicit.

  struct foo {
  // Specify non-integral types ( strings, floats, etc.) require explicit construct
  template<typename T>
  explicit(!std::is_integral_v<T>) foo(T) {}
  };
  
  foo a = 123;  // OK
  foo b = "123"; // ERROR: explicit constructor is not a condidate (explicit specifier evaluates to true) 
  foo c{"123"}; // OK 
  