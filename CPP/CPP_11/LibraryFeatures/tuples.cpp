tuples 

- Tuples are a fixed-size collection of heterogeneous values.

- Access the elements of std::tuple by unpacking using std::tie, or using std::get

 'playerProfile' has type 'std::tuple<int,const char*,const char*>'
 auto playProfile = std::make_tuple(51,"Frans Nielsen","NYI");
 std::get<0>(playerProfile); //51
 std::get<1>(playerProfile); // "Frans Nielsen"
 std::get<2>(playerProfile); // "NYI"
 
************************************************************************************

https://www.geeksforgeeks.org/tuples-in-c/

// C++ code to demostrate tuple, get() and make_pair()
#include<iostream>
#include<tuple> // for tuple
using namespace std;
int main() {
    //Declaring tuple
    tuple<char,int,float> geek;
    
    //Assigning values to tuple using make_tuple()
    geek = make_tuple('a',10,15.5);
    
    //Printing initial tuple values using get()
    cout << "The initial values of tuples are: ";
    cout << get<0>(geek) << " " << get<1>(geek);
    cout << " " << get<2>(geek) << endl;
    
    //Use of get() to change values of tuples
    get<0>(geek) = 'b';
    get<2>(geek) = 20.5;
    
    //Printing modified tuple values
    cout << "The modified values of tuple are : ";
    cout << get<0>(geek) << " " << get<1>(geek);
    cout << " " << get<2>(geek) << endl; 
}
 
**************************************************************************************
 
 
 

