constexpr 

- Constant expressions are expressions that are possibly evaluated by the compiler at compile-time.

- Only non-complex computations can be carried out in a constant expression (these rules are progressively relaxed in later versions).

- Use the constexpr specifier to indicate the variable, function, etc. is a constant expression.

  constexpr int square(int x) {
     return x*x;
  }
  
  int square2(int x) {
    return x*x;
  }
  
  int a = square(2);  // move DWORD PTR [rbp-4], 4 
  
  int b = square2(2); // mov edi,2
                      // call square2(int)
					  // move DWORD PTR [rbp-8], eax
					  
- In the previous snippet,notice that the computation when calling square is carried out at compile-time, and then the
  result is embedded in the code generation, while square2 is called at run time.
  
- constexpr values are those that the compiler can evaluate, but are not gurranteed to, at compile time.

  const int x = 123;
  constexpr const int& y = x; //error - constepxr variable 'y' must be initialized by a constant expression.
  
- Constant expressions with classes:
 
  struct Complex {
	constexpr Complex(double r,double i): re{r},im{i} {}
	constexpr double real() { return re; }
	constexpr double imag() { return im; }

  private:
	double re;
	double im;
  };
  
  constexpr Complex I(0,1); 
  
  