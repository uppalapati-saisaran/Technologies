- Returns the arguments passed to it while maintaining their 
														(01) value category
														(02) cv-qualifiers. 
														
- Useful for 
           (01) generic code 
		   (02) factories 
		   
- Used in conjuction with forward_reference.

- A definition of std::forward:
	template<typename T>
	T&& forward(typename remove_reference<T>::type& arg) {
		return static_cast<T&&>(arg);
	}
	
- An example of a function wrapper which join forwards other A objects to a new A object's copy or move constructor:

  struct A {
	  A() = default;
	  A(const A& o) { std::cout << "copied" << std::endl; }
	  A(A&& o) { std::cout << "moved" << std::endl; }
  };
  
  template<typename T>
  A wrapper(T&& arg) {
  return A{std::forward<T>(arg}};
  }

  wrapper(A{}); //moved
  A a;
  wrapper(a);  // copied
  wrapper(std::move(a)); // moved 
  
  
 **************************************************************************************************************
 
 #include<iostream>
#include<memory>
#include<utility>

struct A 
{
    A(int&& n) { std::cout << "rvalue overload, n=" << n << '\n'; }
    A(int& n) { std::cout << "lvalue overload, n=" << n << '\n'; }
};

class B 
{
public:
    template<class T1,class T2,class T3>
    B(T1&& t1,T2&& t2,T3&& t3): 
    a1_{std::forward<T1>(t1)},
    a2_{std::forward<T2>(t2)},
    a3_{std::forward<T3>(t3)} 
    {}
private:
    A a1_,a2_,a3_;
};

template<class T,class U>
std::unique_ptr<T> make_unique1(U&& u)
{
    return std::unique_ptr<T>(new T(std::forward<U>(u))); 
}

template<class T,class... U>
std::unique_ptr<T> make_unique2(U&&... u)
{
    return std::unique_ptr<T>(new T(std::forward<U>(u)...));
}
/**** C++ 20 
auto make_B(auto&&... args) // Since C++20 
{
    return B(std::forward<decltype(args)>(args)...); 
}
****/

int main()
{
    auto p1 = make_unique1<A>(2); // rvalue
    int i = 1;
    auto p2 = make_unique1<A>(i); // lvalue
    
    std::cout << "B\n";
    auto t = make_unique2<B>(2,i,3);
    
    /*** C++ 20
    std::cout << "make_B\n";
    [[maybe_unused]] B b = make_B(4,i,5);\
    ***/
}

Output: 

rvalue overload, n=2
lvalue overload, n=1
B
rvalue overload, n=2
lvalue overload, n=1
rvalue overload, n=3

*************************************************************************************************************************
  
#include<utility>
#include<iostream>

//function with lvalue and rvalue references overloads:
void overloaded(const int& x) { std::cout << "[lvalue]"; }
void overloaded(int&& x) { std::cout << "[rvalue]"; }

//function template taking rvalue reference to deduced type:
template<class T>
void fn(T&& x) {
    overloaded(x);   // always an lvalue
    overloaded(std::forward<T>(x)); // rvalue if argument is rvalue
}

int main() {
    int a;
    std::cout << "calling fn with lvalue: ";
    fn(a);
    std::cout << '\n';
    
    std::cout << "calling fn with rvalue: ";
    fn(0);
    std::cout << '\n';
    
    return 0;
}

Output: 

calling fn with lvalue: [lvalue][lvalue]
calling fn with rvalue: [lvalue][rvalue]

***********************************************************************************************************************
                   