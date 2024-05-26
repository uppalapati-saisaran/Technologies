Class types in non-type template parameters

- Classes can now be used in non-type template paremeters. 

- Objects passed in as template arguments have the type const T, where T is the type of the object, and 
  has static storage duration.
  
  struct foo {
  foo() = default;
  constexpr foo(int) {}
  };
  
  template<foo f>
  auto get_foo() 
  {
    return f;
  }
  
  get_foo(); // uses implicit constructor
  get_foo<foo{123}>();
  
  
  