Ref-qualified member functions:

- Member functions can now be qualified depending on whether *this 
  is an lvalue or rvalue reference.
  
- struct Bar {
  // ...
  };
  
  struct Foo {
	Bar getBar() & { return bar; }
	Bar getBar() const& { return bar; }
	Bar getBar() && { return std::move(bar); }
  private:
    Bar bar;
  }
  
  Foo foo{};
  Bar bar = foo.getBar(); // calls 'Bar getBar() &'
  
  const Foo foo2{};
  Bar bar2 = foo2.getBar(); // calls 'Bar Foo::getBar() const&'
  
  Foo{}.getBar();  // calls 'Bar Foo::getBar() &&'
  std::move(foo).getBar(); //calls 'Bar Foo::getBar() &&'
  
  std::move(foo2).getBar(); //calls 'Bar Foo::getBar() const&&'
  
  