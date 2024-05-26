- C++ 14 now allows the auto type-specifier in the parameter list, 
  enabling polymorphic lambdas.
  
 auto identity =[](auto x) { return x; };
 int three = identity(3); // ==3
 str::string foo = identity("foo")
 
*********************************************************************************************** 
 
// Cpp program to demostrate 
// generalized lambda expressions
#include<iostream>
#include<string>

using namespace std;
int main()
{
    //Declare a generalized lambda and store it in sum
    // By using auto keyword it cant be used for recursion.
    auto sum = [](auto a,auto b) {
        return a+b; 
    };
    
    // Find sume of two integers
    cout << sum(1,6) << endl;
    
    // Find sum of two floating numbers 
    cout << sum(1.0,5.6) << endl;
    
    // Find sum of two strings
    cout << sum(string("Geeks"),string("ForGeeks")) << endl;
    
    return 0;
}

Output:

7
6.6
GeeksForGeeks

***********************************************************************************************


// CPP program to demostrate
// how to sort integers, floats, strings
// floating data types using a
// generalized lamdba and sort function

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

//Utility Function to print the elements of a collection
template<typename T>
void printElements(T& c)
{
    for(auto e : c)
      cout << e << " ";
    
    cout << endl;
}

int main()
{
     //Declare a generalized lambda and store it in greater
     auto greater = [](auto a,auto b) -> bool {
         return a>b;
     };
     
     //Initialize a vector of integers
     vector<int> vi = {1,4,2,1,6,62,636};
     
     //Initialize a vector of doubles
     vector<double> vd = {4.62,161.3,62.26,13.4,235.5};
     
     //Initialize a vector of strings
     vector<string> vs = {"Tom","Harry","Ram","Shyam"}; 
     
     // sort integers
     sort(vi.begin(),vi.end(),greater);
     
     // sort doubles
     sort(vd.begin(),vd.end(),greater);
     
     // Sort strings
     sort(vs.begin(),vs.end(),greater);
     
     printElements(vi);
     printElements(vd);
     printElements(vs);
     
     return 0; 
}

Output:

636 62 6 4 2 1 1 
235.5 161.3 62.26 13.4 4.62 
Tom Shyam Ram Harry 

******************************************************************************************