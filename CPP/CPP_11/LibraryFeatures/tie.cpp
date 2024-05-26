tie

- Creates a tuple of lvalue references.

- Useful for unpacking std::pair and std::tuple objects.

- Use std::ignore as a placeholder for ignored values. 

**********************************************************************************************
   // With tuples...
   std::string playerName;
   std::tie(std::ignore,playName,std::ignore)=std::make_tuple(91,"John Tavares","NYI");
   
   // with pairs..
   std::string yes,no;
   std::tie(yes,no) = std::make_pair("yes","no"); 
   
*********************************************************************************************

*********************************************************************************************
 
https://en.cppreference.com/w/cpp/utility/tuple/tie
 
#include<cassert>
#include<iostream>
#include<set>
#include<string>
#include<tuple>
using namespace std;
struct S 
{
   int n;
   string s;
   float d;
   
   friend bool operator<(const S& lhs,const S& rhs) noexcept 
   {
       // compares lhs.n to rhs.n,
       // then lhs.s to rhs.s,
       // then lhs.d to rhs.d
       // in that order, first non-equal result is returned
       // or false if all elements are equal 
       return tie(lhs.n, lhs.s, lhs.d) < tie(rhs.n, rhs.s, rhs.d); 
   }
}; 

int main() 
{
    //Lexicographical comparsion demo: 
    set<S> set_of_s;
    
    S value{42,"Test",3.14};
    std::set<S>::iterator iter;
    bool is_inserted; 
    
    //Unpack a pair:
    std::tie(iter,is_inserted) = set_of_s.insert(value);
    assert(is_inserted); 
    
    //std::tie and structure bindings:
    auto position = [](int w) { return tuple(1*w,2*w); };
    
    auto [x,y] = position(1);
    assert(x == 1 && y == 2); 
    
    tie(x,y) = position(2); // reuse x,y with tie
    assert(x == 2 && y == 4); 
    
    //Implicit conversions are permitted
    tuple<char, short> coordinates(6,9);
    tie(x,y) = coordinates;
    assert(x == 6 && y == 9);
  }
   
 ********************************************************************************************* 