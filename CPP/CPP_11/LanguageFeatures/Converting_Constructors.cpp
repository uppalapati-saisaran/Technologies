Converting constructors:

- Converting constructors will convert values of braced list syntax into constructor arguments.

  struct A {
  A(int) {}
  A(int,int) {}
  A(int,int,int) {}
  };
  
  A a{0,0}; //calls A::A(int,int)
  A b(0,0); //calls A::A(int,int)
  A c = {0,0}; // calls A::A(int,int)
  A d {0,0,0}; // calls A::A(int,int,int)

- Note that the braced list syntax does not allow narrowing:

  struct A {
	A(int) {}
  };
  
  A a(1.1);  // OK
  A b {1.1}; // Error narrowing conversion from double to int

- Note that if a constructor accepts a std::initializer_list, it will be called instead:
  
  struct A {
	A(int) {}
	A(int,int) {}
	A(int,int,int) {}
	A(std::initializer_list<int>) {}
  };
  
  A a{0,0}; // calls A::A(std::initializer_list<int>)
  A b(0,0); // calls A::A(int,int)
  A c = {0,0}; // calls A::A(std::initializer_list<int>)
  A d {0,0,0}; // calls A::A(std::initializer_list<int>)
  
  