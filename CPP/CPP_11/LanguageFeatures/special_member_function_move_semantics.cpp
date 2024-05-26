Special member functions for move semantics:

- The copy constructor and copy assignment operator are called when copies are made.

- There is not a move constructor and move assignment operator for moves.

  struct A {
  std::string s;
  A() : s{"test"} {}
  A(const A& o):s{o.s} {}
  A(A&& o): s{std::move(o.s)} {}
  A& operator=(A&& o) {
   s=std::move(o.s);
   return *this;
  }
  };
  
  A f(A a) {
	return a;
  }
  
  A a1 = f(A{});  // move-constructed from rvalue temporary
  A a2 = std::move(a1); // move-constructed using std::move
  A a3 = A{};
  a2 = std::move(a3); // move-assignment using std::move
  a1 = f(A{}); // move-assignmet from rvalue temporary 
  
  
  