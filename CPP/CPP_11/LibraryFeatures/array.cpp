- array is a container built on top of a c-style array.

- supports common container operations such as sorting.

**********************************************************************************

std::array<int,3> a = {2,1,3}
std::sort(a.begin(),a.end());  // a == {1,2,3}
for(int& x : a) x*=2;  // a == {2,4,6}


**********************************************************************************

https://en.cppreference.com/w/cpp/container/array

#include<iostream>
#include<array>
#include<algorithm>
#include<iterator>
using namespace std; 
int main()
{
    //Construction uses aggregate initialization 
    // Double-braces required in C++11 prior to the CWG 1270 revision
    // (not need in C++11) after the revision and in C++ 14 and beyond 
    array<int, 3> a1{{1,2,3}}; 
    
    array<int, 3> a2 = {1,2,3};  // Double braces never required after =
    
    //container operations are supported
    sort(a1.begin(),a1.end());
    // ranges is in C++ 20
    ranges::reverse_copy(a2, ostream_iterator<int>(cout, " "));
    cout << '\n';
    
    //Ranged for loop is supported
    array<string, 2> a3{"E", "\u018E"};
    for(const auto& s : a3)
        cout << s << ' ';
    cout << '\n';
    
    // Deduction guide for array creation (since C++17)
    [[maybe_unused]] array a4{3.0, 1.0, 4.0};  // array<double, 3>
    
    // Behaviour of unspecified elements is the same as with built-in arrays.
    // No list init, a5[0] and a5[1] are default initialized 
    [[maybe_unused]] std::array<int, 2> a5; 
    // List init, both elements are value initialized, a6[0] = a6[1] = 0
    [[maybe_unused]] std::array<int, 2> a6{};
    // List init, unspecified element is value initialized a7[0] = 1, a7[1] = 0 
    [[maybe_unused]] std::array<int, 2> a7{1};
}

**************************************************************************************