Delegating constructors

- Constructors can now call other constructors in the same class using an initializer list.

  struct Foo {
	int foo;
	Foo(int foo): foo{foo} {}
	Foo() : Foo(0) {}
  };
  
  Foo foo;
  foo.foo; // == 0
  
 