* The std::bind function is part of the Standard Function Objects and is a versatile tool used for
  creating new function objects by binding arguments to a given function.
  
* It essentially adapts a function by fixing some of its arguments or rearranging them.

#include<iostream>
#include<functional>
using namespace std;
using namespace std::placeholders;
int add(int first,int second)
{
    return first + second;
}
int main()
{
    auto add_func = bind(&add,_1,_2); 
    auto add_func2 = bind(&add,12,5);
    auto add_func3 = bind(&add,_1,12);
    cout << add_func(4,5) << endl; 
    cout << add_func2() << endl; 
    cout << add_func3(3) << endl;
}

// Using std::bind with STL algorithms 

bool divisible(int num,int den) {
	return num % den == 0;
}

* The function takes two arguments and checks if num is divisible by den.
* To adapt this function to work with std::count_if, you need a unary predicate - a function that takes a single argument. 




