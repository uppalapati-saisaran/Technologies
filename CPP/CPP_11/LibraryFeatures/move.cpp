- std::move indicates that the object passed to it may have its resource transferred.

- Using objects that have been moved from should be used with care, as they can be left in an unspecified state. 

- A definition of std::move ( Performing a move is nothing more than casting to an rvalue reference):

  template<typename T>
  typename remove_reference<T>::type&& move(T&& arg) {
	return static_cast<typename remove_reference<T>::type&&>(arg); 
  }
  
  Transferring std::unique_ptr s:
  std::unique_ptr<int> p1{new int{0}}; // in pratice, use std::make_unique
  std::unique_ptr<int> p2 = p1; // error -- cannot copy unique pointers
  std::unique_ptr<int> p3 = std::move(p1); // move 'p1' into 'p3' 
                                           // now unsafe to deference object held by 'p1' 
										
***********************************************************************************************************************

#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std; 
int main() 
{
    std::string str="Salut";
    std::vector<std::string> v;
    
    //uses the push_back(const T&), which means
    // we'll incur the cost of copying string
    
    v.push_back(str);
    std::cout << "After copy, str is " << std::quoted(str) << '\n';
    
    
    //uses the rvalue reference push_back(T&&) overload,
    //which means no strings will be copied; instead, the contents
    // of str will be moved into the vector. This is less expensive,
    // but also means str might now be empty.
    v.push_back(std::move(str));
    std::cout << "After move, str is " << std::quoted(str) << '\n';
    
    std::cout << "The contents of the vector are { " << std::quoted(v[0])
              << " , " << std::quoted(v[1]) << " }\n";     
    return 0;
}

Output : 

After copy, str is "Salut"
After move, str is ""
The contents of the vector are { "Salut" , "Salut" }

*************************************************************************************************************************

/****
https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
***/
#include<iostream>
#include<memory>
using namespace std;
class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main() 
{
    std::unique_ptr<Resource> res1{new Resource{}};  // Resource created here
    std::unique_ptr<Resource> res2{}; // Start as nullptr
    
    std::cout << "res1 is " << (res1 ? "non null\n" : "null\n");
    std::cout << "res2 is " << (res2 ? "non null\n" : "null\n");
    
    // res2 = res1;  // Won't compile: copy assignement is disabled
    res2 = std::move(res1);  // res2 assumes ownership, res1 is set to null
    
    std::cout << "Ownership transferred\n";
    
    std::cout << "res1 is " << (res1 ? "non null\n" : "null\n");
    std::cout << "res2 is " << (res2 ? "non null\n" : "null\n");
    
    return 0;
} // Resource destroyed here when res2 goes out of scope

Output: 

Resource acquired
res1 is non null
res2 is null
Ownership transferred
res1 is null
res2 is non null
Resource destroyed


**************************************************************************************************************************

// C++ program to implement the above approch
#include<string>
#include<iostream> 
// for EXIT_SUCCESS macro
#include<cstdlib>
// std::move() 
#include<utility>
using namespace std;
#include<vector>

//Declaration
vector<string> createAndInsert();

//Driver Code
int main() 
{ 
    // Constructint an empty vector of strings
    vector<string> vecString;
    // calling createAndInsert() and
    // initializing the local vecString object
    vecString = createAndInsert();
    //Printing content of the vector
    for(const auto& s : vecString) 
    {
        cout << s << '\n'; 
    }
    return EXIT_SUCCESS;
}

//Definition
vector<string> createAndInsert()
{
    // Constructing a vector of strings with an size of 3 elements
    vector<string> vec;
    vec.reserve(3); 
    string str("Hello");
    vec.push_back(str);
    vec.push_back(str + str);
    vec.push_back(move(str));
    return vec; 
 }
 
 
 ***************************************************************************************************************************
 
 
 