- decltype is an operator which returns the declared type of an expression passed to it.

- cv-qualifiers and references are maintained if they are part of the expression.

- Example of decltype:

  int a = 1; // 'a' is declared as type 'int'
  decltype(a) b = a; // 'decltype(a) is 'int' 
  const int&c = a; // 'c' is declared a type 'const int&'
  decltype(c) d = a; // 'decltype(c) is 'const int&'
  decltype(123) e = 123; // 'decltype(123) is 'int'
  int&&f = 1; // f is declared as type 'int&&'
  decltype(f) g = 1; // 'decltype(f) is 'int&&'
  decltype((a)) h = g; // 'decltype((a)) is int& 
  
  template<typename X,typename Y>
  auto add(X x,Y y) -> decltype(x+y) {
	  return x+y;
  }
  add(1,2.0); // 'decltype(x+y)' ==> 'decltype(3.0)' => 'double' 