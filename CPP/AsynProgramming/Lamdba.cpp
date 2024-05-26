
* This feature is particularly useful for creating concise and temporary functions for specific,
  often shortlived task such as callbacks to other functions or APIs.
  
* General Structure 

 [capture](parameters) mutable exception -> return_type {
       // function body
 } 
 
 1, Capture Clause: [capture] This is how you can define what from the outside scope is available inside the lamdba,
    and how (by value, by reference, etc). 
	The capture clause can be one of the following:
	[] : Nothing is captured.
	[x, &y] : x is captured by value and y is captured by reference.
	[=]: All variables in scope are captured by value
	[&]: All variables in scope are captured by reference
	[this] : The current object[*this] is captured by reference.
	
2, Parameter List: (parameter) Just like regular functions, lambas can have parameters.  This part can be omitted if the lambda takes no parameters:
   [] { /* ... */ }
   
3, Mutable specification: mutable 

   If you want to modify the values captured by value, you can add the mutable keyword. 
   By default, a lamdda that captures variables by value cannot modify them:
   [x]() mutable { x = 2; } // OK, x can be modified because of 'mutable'
   
 4, Exception specification:
   
    This part allows you to specify the exceptions that a lambda can throw. It's often omitted in basic use cases.
	
	[]() noexcept { /* ... */ }

5,  Return Type -> return_type

    The return type of a lamdba function can be explicitly specified after the parameters.
	if it is not provided, the compiler will infer the return type based on the return statment in the lambda body. 
	
	[] () -> int { return 42; } // Lambda that explicitly specifies return type as int 

    However, if the body of the lambda consists of a single return statmen, the return type can be omitted and the compiler will deduce it.
	
	[] { return 42; } // Return type is deduced to be int
	
6, Lamdba Function Body 

   Inside the curely braces {} is the body of the lambda function. It can contain any valid C++ statements, including variable declarations, loops and other lambdas:
   
   [](int x) {
	   cout << "The value is :" << x << endl;
   }
   
   
* Putting it All Together to create a Lambda Function 

  int y = 10;
  auto lambda = [&y](int x) mutable {
		y = x * y; // This is valid because y is captured by reference and the lambda is mutable 
		cout << y << endl;
  };
  lambda(5); 
  
**************************************************************************************************************************

#include<iostream>
#include<algorithm>
using namespace std; 
void display(int a) {
    cout << a << " ";
}

int main() {
    int arr[] = { 1,2,3,4,5 };
    for_each(arr,arr+sizeof(arr)/sizeof(int), &display);
    cout << endl; 
    for_each(arr,arr+sizeof(arr)/sizeof(int), [](int x) { cout << x << " "; });
    cout << endl; 
}

***************************************************************************************************************************

#include<iostream>
#include<algorithm>
using namespace std; 
int main()
{
    int arr[] = {1,2,3,4,5 };
    int discount1 = 50;
    int discount2 = 50;
    
    //Capture by reference
    for_each(arr,arr+sizeof(arr)/sizeof(int), [&](int x) { 
          cout << x << " "; 
          // We can modify 'discount' here since it's captured
          discount1 = 20;
    }); 
    
    //Capture by value 
    for_each(arr,arr+sizeof(arr)/sizeof(int),[=](int x) mutable {
        cout << x << " ";
        // Cannot modify discount here since it's captured
        // unless 'mutable' is used .
        discount2 = 20; 
        
    }); 
    
    cout << endl;
    cout << "discount1 value : " << discount1 << endl;   // == 20
    cout << "discount2 value : " << discount2 << endl;  // == 50 
    return 0; 
}

*************************************************************************************************************************
  
 #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class OddCounter
{
    // Tracks the count of odd numbers encountered.
    int mCounter  = 0;
    public:
        int getCount() const
        {
            return mCounter;    
        }
        void update(vector<int> &vec) 
        {
            // Capturing this pointer to access member variable mCounter
            for_each(vec.begin(),vec.end(),[this](int element)  
            {
                if(element % 2)
                {
                    //Accessing member variable through this
                    this->mCounter++;
                }
            });
        }
}; 
int main() {
    vector<int> vec = {12,3,2,1,8,9,0,2,3,9,7};
    OddCounter counterObj;
    
    //Passing the vector to OddCounter object.
    counterObj.update(vec); 
}

**************************************************************************************************************************