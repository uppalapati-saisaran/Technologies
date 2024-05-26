Inline variables:

- The inline specifier can be applied to variables as well as to functions.

- A variable declared inline has the same semantics as a function declared inline.

// Disassembly example using compiler explorer.
struct S { int x; }
inline S x1 = S{321}; // move esi, dword ptr[x1]
                      // x1: .long 321
					  
S x2 = S{123};   // move eax, dword ptr[.L_ZZ4mainE2X2]
                 // mov dword ptr [ rbp - 8], eax
				 // .L_ZZ4mainE2x2: .long 123
				 
- It can also be used to declare and define a static member variable, such that it does not need to initialized in the source file.

  struct S {
  S() : id{count++} {}
  ~S() { count--; }
  int id;
  static inline int count{0}; // declare and initialize count to 0 within the class
  };
  
  
