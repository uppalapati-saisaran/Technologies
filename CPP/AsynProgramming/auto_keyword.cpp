* auto keyword for type inference.
* The addition of auto allows developers to write less code, reduce redundancy, and maintain code more easily,
  especially when dealing with complex data types or templates or obvious from the context.
 
* the auto keyword enables developers to declare a variable without explicitly specifying its data type.
* Instead, the compiler deduces the type of the variable from the initialization expression.

* The auto keyword is versatile and can be used with any type, including functions or iterators.

* Important Points About auto in C++ 11

(01) Once you have initialized an auto variable, you can change its value but not its type:

	auto x = 1;
	// This will cause a compile-time error because 'x' is of type int.
	// x = "dummy";

(02) An auto variable cannot be left uninitialized because its type is deduced from the initializer.

    // This will cause a compile-time error
	// auto a;
	
(03) When you want to return an auto variable from a function, you use a trailing return type:

	auto sum(int x,int y) -> int {
		return x+y;
	}
	
	//calling the function that returns 'auto'
	auto value = sum(3,5);
	
	In this example, auto is used to specify that the return type of the function sum is the same
	as the type of the expression in the return statement. 
	The -> int is a trailing return type specifying that the return type is int. 

#include<iostream>
using namespace std;
int main() 
{
    //storing an int in an auto variable
    auto var_1 = 5;
    //storing a character in an auto variable
    auto var_2 = 'C';
    
    cout << var_1 << endl;
    cout << var_2 << endl;
}


// lambda function in an auto variables 
#include<iostream>
using namespace std;

int main() 
{
// Storing a Lambda function in an auto variable. 
auto fun_sum = [](int a,int b) { return a+b; }; 

   cout << fun_sum(4,5) << endl; 
}


// Simplifying Complex Type Declarations. 
#include<map>
#include<string>
#include<iostream>
using namespace std;
int main() 
{
    map<string,string> mapOfStrs;
    
    //Inserting data into the mapOfStrs
    mapOfStrs.insert({"first","1"});
    mapOfStrs.insert({"second","2"}); 
    mapOfStrs.insert({"thrird","3"});
    
    //Iterating over the map and displaying all data
    for(map<string,string>::iterator it = mapOfStrs.begin();it!=mapOfStrs.end();++it)
    {
        cout << it->first << ":" << it->second << endl; 
    }
    
    //Iterating with auto
    for(auto it = mapOfStrs.begin();it!=mapOfStrs.end();++it) 
    {
        cout << it->first << ":" << it->second << endl; 
    }
    return 0; 
}



