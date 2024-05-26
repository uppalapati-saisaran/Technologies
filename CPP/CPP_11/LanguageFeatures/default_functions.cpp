Default functions:

- A more elegant, efficient way to provide a default implemenation of a function, such as a constructor.

  struct A {
  A() = default;
  A(int x): x{x} {}
  int x {1};
  };
  
  A a; // a.x == 1
  A a2 {123}; //a.x == 123
  
- With inheritance

  struct B {
  B() : x{1} {}
  int x;
  };
  
  struct C : B {
    // Calls B::B
	C() = default;
  };
  
  C c; // c.x == 1 