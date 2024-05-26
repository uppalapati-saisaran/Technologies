- In C++ 11, constexpr function bodies could only contain a very limited
  set of syntaxes, including ( but not limited to ):
  typedef s, using s, and a single return statement.
 
- C++ 14, the set of allowable syntaxes expands greatly to include the 
  most common syntax such as if statements, multiple return s,loops, etc.

constexpr int factorial(int n) {
 if (n<=1) 
 {
	return 1;
 } else
 {
    return n*factorial(n-1);
 }
}
factorial(5); // == 120


  
  