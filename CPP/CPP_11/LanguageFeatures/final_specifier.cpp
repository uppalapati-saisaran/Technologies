Final Specifier

- Specifies that a virtual function cannot be overridden 
  in a derived class or that a class cannot be inherited from
  
  struct A {
    virtual void foo();
  };
  
  struct B : A {
    virtual void foo() final;
  };
  
  struct C : B {
	virtual void foo(); // error-- declaration of foo override a final function
  };
  
- Class cannot be inherited from.

  struct A final {};
  struct B : A {}; // error -- base 'A' is marked 'final'
  