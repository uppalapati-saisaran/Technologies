
* Variadic templates are a powerful feature that allows programmers to write functions and classes 
  that can take any number of arguments, of any type.
* This has signiciant implications for the flexibility and reusability of code.
* greatly expanidng the potential for generic programming.



* Implementing the variadic Function 

  template<typename T, typename... Args>
  void log(T first, Args... args)
  {
	cout << first << ",";
	if constexpr(sizeof...(args) > 0)
	{
		log(args...); 
	}
  }
  
  Here's how it works:
  1, It prints the first arugment.
  2, It recursively calls log() with the remaining arguments.
  
  When log() is called with no arguments, it reaches the base case of the recursion and stops.
  
  The call Stack Template:
  
  when you call log(2,3.4,"aaa");, the following happens internally:
  
  1, log(int,double,const char*) is instantiated and print 2, then calls log(double, const char*).
  2, log(double,const char*) is instantiated and prints 3.4, then calls log(const char*)
  3, log(const char*) is instantiated and prints "aaa", then calls log() with no arguments.
  4, The recursion stops as there's no overloaded function of log() that takes no arguments.
  
#include<iostream>
using namespace std;
//Function to end the recursion of varidiac template function
void log()
{
    // This can be empty or used to print something that marks the end of the output.
}

template<typename T,typename... Args>
void log(T first,Args... args)
{
    std::cout << first;
    if constexpr (sizeof... (args) > 0)
    {
        cout << ",";
        log(args...);
    }
    else
    {
        cout << endl; // New line for the last element. 
    }
}
int main() 
{
    // calling log() function with 3 arguments
    log(1,4.3,"Hello");
    
    // calling log() function with 4 arguments
    log('a',"test",78L,5);
    
    // calling log() function with 2 arguments
    log("sample","test"); 
}


* Important Points about variadic template in C++ 11

- When using variadic templates, recursion is a common pattern to process arguments.
- Be careful with the number of recursive calls; too many could lead to a stcak overflow.
- Since C++ 17, you can use fold exprssions to process arguments, which can be more efficient anc concise. 

  
