Return type deduction

- Using an auto return type in C++ 14, the compiler will attempt to deduce the type for you.

- With lambdas, you can now deduce its return type using auto, which makes returning a deduced reference or rvalue reference possible.

// Deduce return type as 'int'.
   auto f(int i)
   {
   return i;
   }
   
   template<typename T>
   auto& f(T& t)
   {
   return t;
   }
   
   // Returns a reference to be deduced type.
   auto g = [](auto &x) -> auto& { return f(x); };
   int y = 123
   int& z = g(y); // reference to 'y'
   
   
