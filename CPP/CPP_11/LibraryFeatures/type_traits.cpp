-  Type traits define a compile-time template-based interface to query or modify the properties of types. 

   static_assert(std::is_integral<int>::value);
   static_assert(std::is_same<int,int>::value);
   static_assert(std::is_same<std::conditional<true,int,double>::type,int>::value);
   
 - Example : given a generic type T - it could be int, bool , std::vector or whatever you want - with type traits
   you can ask the compiler some questions: is it an Integer? Is it a function? Is it a pointer? Or
   maybe a class? Does it have a destructor? Can you copy it? Will it throw exceptions? and so on.
   This is extremly useful in conditional compilation, where you instruct the compiler to pick the 
   right path according to the type in input. 
   
 - Type traits can also apply some tranformation to a type. For example, given T, you can add/remove the const
   specifiers, the reference or the pointer, or yet turn it into a signed/unsigned type and many other crazy operations.
   Extremely handy when writing libraries that make use of templates.
 
******************************************************************************************

	#include<iostream>
	#include<type_traits>
	using namespace std; 

	class Class {};

	int main() 
	{
		cout << is_floating_point<Class>::value << '\n';
		cout << is_floating_point<float>::value << '\n'; 
		cout << is_floating_point<int>::value << '\n';
		return 0; 
	}
	
*******************************************************************************************
   
#include<type_traits>
#include<iostream>
template<typename T>
void Function(T Param) {
    if(std::is_arithmetic_v<T>) {
        std::cout << Param << " is arithmetic\n"; 
    } else {
        std::cout << Param << " is not arithmetic\n";
    }
}

int main() {
    Function(42);
    Function("Hello World"); 
}
   
*********************************************************************************************
   