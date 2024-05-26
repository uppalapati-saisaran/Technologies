auto-typed variables are deduced by the compiler according to the type of their initializer.

auto a = 3.14; // double
auto b = 1; // int
auto &c = b; // int&
auto d = {0}; // std::initializer<int>
auto&& e = 1; // int&&
auto&& f = b; // int& 
auto g = new auto(123); // int*
const auto h = 1; // const int
auto i = 1, j = 2, k = 3; // int,int,int
auto l = 1, m = true, m = 1.61; // error -- '1' deduced to be int, 'm' is bool
auto o; // error -- 'o' requires initializer

Extremely useful for readability, especially for complicated types:

std::vector<int> v = ...;
std::vector>int>::const_iterator cit = v.cbegin();
or
auto cit = v.cbegin();

- Functions can also deduce the return type using auto.

- In C++ 11, a return type must be specified either explicitly or using decltype like so.

template<typename X, typename Y>
auto add(X x,Y x) -> decltype(x+y) {
return x+y;
}

add(1,2);  // == 3
add(1,2.0); // == 3.0 
add(1.5,1.5) // == 3.0 

- The trailing return type in the above example is the declared type of the expression x+y.
  For example, if x is an integer and y is a double, decltype(x+y) is a double. Therefore, the above function will deduce the type depending on that type the expression x+y yields.
- Notice that the trailing return types has access to its parameters, and this when appropriate.


