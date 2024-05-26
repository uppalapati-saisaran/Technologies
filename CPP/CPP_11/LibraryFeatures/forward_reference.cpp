- Also known as universal references.

- A forwarding reference is created with the syntax T&& where T is a template type parameter or using auto&&. 

- This enables perfect forwading: the ability to pass arguments while maintaining their value catetory (e.g. lvalues stay as lvalues, tempories are forwarded as rvalues).

- Forwarding references allow a reference to bind to either an lvalue or rvalue depending on the type.

- Forwarding references follow the rules of reference collapsing. 

  . T& & becomes T&
  . T& && becomes T&
  . T&& & becomes T& 
  . T&& && becomes T&&
  
- auto type deduction with lvalues and rvalues:

	int x = 0; //'x' is an lvalue of type 'int'
	auto&& a1 = x; //'a1' is an lvalue of type 'int&' -- binds to the lvalue, 'x'
	auto&& ar = 0; // 'ar' is an lvalue of type 'int&&'
	

- Template type parameter deduction with lvalues and rvalues:

  // Since C++ 14 or later:
  void f(auto&& t) {
  }
  
  // Since C++ or later:
  void f(T&& t) {
  // ...
  }
  
  int x = 0;
  f(0); // T is int, deduces as f(int &&) => f(int&&)
  f(x); // T is int&, deduces as f(int& &&) => f(int&)
  
  int&y = x;
  f(y); // T is int&, deduces as f(int& &&) => f(int&)
  
  int&& z = 0; // NOTE: 'z' is an lvalue with type 'int&&'.
  f(z); // T is int&, deduces as f(int& &&) => f(int&)
  f(std::std::move(z)); // T is int,deduces as f(int &&) => f(int&&) 
  