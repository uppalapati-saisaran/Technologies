Range-based for loop with initializer:

- This feature simplifies common code patterns, helps keep scopes tight, and offers an elegant solution to a common lifetime problem.

  for(auto v = std::vector{1,2,3}; auto& e: v) {
	std::cout << e;
  }
  //prints "123" 