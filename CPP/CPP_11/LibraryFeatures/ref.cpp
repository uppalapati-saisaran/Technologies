- std::ref(val) is used to create object of type std::reference_wrapper that holds reference of val.

- Used in cases when 

              (01) usual reference passing using & does not compile 
			                   or
			  (02) & is dropped due to type deduction.
			  
- std::cref is similar but created reference wrapper holds a const reference to val.


******************************************************************************************************

// create a container to store reference of objects.
auto val = 99;
auto _ref = std::ref(val);
_ref++;

auto _cref = std::cref(val);
//_cref++  // does not compile

std::vector<std::reference_wrapper<int>> vec; // vector<int&>vec does not compile
vec.push_back(_ref); // vec.push_back(&i) does not compile
cout << val << endl; //prints 100
cout << vec[0] << endl; // prints 100
cout << _cref; // prints 100

*******************************************************************************************************

#include<functional>
#include<iostream>

void f(int& n1,int& n2,const int& n3)
{
    std::cout << "In function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
	++n1;  // increments the copy of n1 stored in the function object
	++n2;  // increments the main()'s n3
	// ++n3; // compiler error 
}
int main() 
{
	int n1=1, n2 = 2, n3 = 3;
	std::function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
	n1 = 10;
	n2 = 11;
	n3 = 12;
	std::cout << "Before function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
	bound_f();
	std::cout << "After function: " << n1 << ' ' << n2 << ' ' << n3 << '\n'; 
}

Output :
Before function: 10 11 12
In function: 1 11 12
After function: 10 12 12 

**********************************************************************************************************

	


