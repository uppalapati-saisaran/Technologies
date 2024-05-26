Deleted functions:

- A more elegant, efficient way to provide a delete implementation of a function.

- Useful for preventing copies on objects.

  class A {
  int x;
  
  public:
	A(int x) : x{x} {};
	A(const A&) = delete;
	A& operator=(const A&) = delete;
  };
  
  A x {123};
  A y = x; error -- call to deleted copy constructor
  y = x; // error -- operator - deleted. 