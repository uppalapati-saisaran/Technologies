- The class template std::variant represents a type-safe union.

- An instance of std::variant at any given time holds a value of one of its alternative types. 

  std::variant<int,double> v{ 12 };
  std::get<int>(v);  // == 12
  std::get<0>(v); // == 12
  v = 12.0
  set::get<double>(v); == 12.0 
  std::get<1>(v); // == 12.0 
  
#include<iostream>
#include<variant>
using namespace std;
int main()
{
    variant<int,double> v{ 12 };
    cout << "Variant Integer : " << get<int>(v) << endl; 
    cout << "Variant Integer : " << get<0>(v) << endl;
    v = { 12.5 };
    cout << "Variant Double : " << get<double>(v) << endl;
    cout << "Variant Double : " << get<1>(v) << endl;
    return 0;
}

Output: 
Variant Integer : 12
Variant Integer : 12
Variant Double : 12.5
Variant Double : 12.5