constexpr virtual functions

- Virtual functions can now be constexpr and evaluated at compile time.

- constexpr virtual functions can override non-constexpr virtual functions and vice-versa.

  struct x1 {
	virtual int f() const = 0;
  };
  
  struct X2: public X1 {
	constexpr virtual int f() const { return 2; }
  };
  
  struct X3: public X2 {
    virtual int f() const { return 3; }
  };
  
  struct X4: public X3 {
	constexpr virtual int f() const { return 4; }
	};
	
  constexpr X4 x4;
  x4.f(); // == 4 

