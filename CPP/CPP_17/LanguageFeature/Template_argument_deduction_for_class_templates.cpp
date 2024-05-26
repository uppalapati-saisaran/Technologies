Template argument deduction for class templates

- Automatic template argument deduction much like how it is done for functions, but now including class constructors.

  template<typename T = float>
  struct MyContainer {
   T val;
   MyContainer() : val{} {}
   MyContainer(T val) : val{val} {}
   // ..
   };
   
   MyContainer c1{1}; // OK MyContainer<int>
   MyContainer c2;  // OK MyContainer<float>
   
   