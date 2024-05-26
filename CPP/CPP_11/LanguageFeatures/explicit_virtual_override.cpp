Explicit virtual overrides

- Specifies that a virtual function overrides another virtual function.

- If the virtual function does not override a parent's virtual function,
  throws a compiler error.
  
  struct A {
	virtual void foo();
	void bar();
  };
  
  struct B : A {
	void foo() override;  // correct -- B::foo overrides A::foo
	void bar() override;  // error -- A::bar is not virtual
	void baz() override;  // error -- A:baz does not override A::baz
