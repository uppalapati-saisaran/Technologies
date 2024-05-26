constexpr lambda

- compile time lambdas using constexpr

  auto identity = [](int n) constexpr { return n; };
  static_assert(identity(123) == 123);
  
  constexpr auto add = [](int x,int y) { 
   auto L = [=] { return x; }; 
   auto R = [=] { return y; };
   return [=] { return L() + R(); };
   };
   
   static_assert(add(1,2)() == 3);
   
   constexpr int addOne(int n) {
	return [n] { return n+1; } ();
	
    static_assert(addOne(1) == 2); 
	
	
  