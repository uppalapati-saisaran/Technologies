* The powerful feature allows programmers to explicitly forbid the use of certain functions,
  including automatically generated ones like default constructors and assignment operators.
  
* The 'delete' keyword can be applied to functions to make them uncallable, effectively 
  preventing their use in a program.
* When a function is marked as deleted, any attempt to call it will result in a compile-time error.
* This is particulary useful for managing special member functions that the compiler might otherwise automaticlly generate.

* The 'delete' keyword is particularly useful for:

1, Deleting compiler-generated functions like copy constructors, assignment operators, move constructors, move assignment operators, and default constructors.
2, Deleting member functions to prevent implicit type converstions that lead to data loss.
3, Restricting object creation on the heap by deleting the new operator for a class.
4, Deleting specific template specializations.


// Deleting copy constructors and assignment operator.
#include<string>
#include<iostream>
using namespace std; 
class User 
{
    int id;
    string name;
public:
    /** To test assignment operator 
    User() = default; 
    ***/

    User(int userId,string userName) : id(userId),name(userName) {} 
    
    //Copy constructor is deleted
    User(const User& obj) = delete;
    
    //Assignment operator is deleted
    User& operator=(const User& obj) = delete;
    
    void display() {
        cout << id << ":::" << name << endl; 
    }
};

int main() 
{
    User userObj(3,"John");
    userObj.display(); 
    /**
    User anotherUser = userObj; 
    main.cpp: In function ‘int main()’:
    main.cpp:26:24: error: use of deleted function ‘User::User(const User&)’
     26 |     User anotherUser = userObj;
      |                        ^~~~~~~
     main.cpp:12:5: note: declared here
    12 |     User(const User& obj) = delete;
    ***/
    /****
    User user;
    user = userObj; 
    main.cpp: In function ‘int main()’:
    main.cpp:38:12: error: use of deleted function ‘User& User::operator=(const User&)’
   38 |     user = userObj;
      |            ^~~~~~~
    main.cpp:17:11: note: declared here
   17 |     User& operator=(const User& obj) = delete;
      |           ^~~~~~~~
    **/
}

// Deleting Member Functions in a clas in C++ 
#include<string>
#include<iostream>
using namespace std; 
class User 
{
    int id;
    string name;
public:
    User(int userId,string userName) : id(userId),name(userName) {} 
    //User(double userId,string userName) = delete;
    //(char userId,string userName) = delete; 

    void display() {
        cout << id << ":::" << name << endl; 
    }
};

int main() 
{
    User userObj1(3,"John");
    userObj1.display(); 
    User userObj2(5.4,"John"); 
    userObj2.display();
    User userObj3('a',"John");
    userObj3.display();
    /*************
        User userObj2(5.4,"John"); 
        main.cpp: In function ‘int main()’:
        main.cpp:22:29: error: use of deleted function ‘User::User(double, std::string)’
       22 |     User userObj2(5.4,"John");
          |                             ^
        main.cpp:10:5: note: declared here
       10 |     User(double userId,string userName) = delete;
          |     ^~~~
      *************/
      /***********
        User userObj3('a',"John"); 
        main.cpp: In function ‘int main()’:
        main.cpp:32:29: error: use of deleted function ‘User::User(char, std::string)’
       32 |     User userObj3('a',"John");
          |                             ^
        main.cpp:11:5: note: declared here
       11 |     User(char userId,string userName) = delete;
          |     ^~~~
      ***************/
}


// Restricting Object creation on the Heap 

#include<string>
#include<iostream>
using namespace std; 
class User 
{
    int id;
    string name;
public:
    User(int userId,string userName) : id(userId),name(userName) {} 
    /****
        void *operator new(size_t) = delete; 
        main.cpp: In function ‘int main()’:
        main.cpp:18:40: error: use of deleted function ‘static void* User::operator new(size_t)’
       18 |     User *userObj1 = new User(12,"John");
          |                                        ^
        main.cpp:10:11: note: declared here
       10 |     void *operator new(size_t) = delete;
          |   
    ****/
    void display() {
        cout << id << ":::" << name << endl; 
    }
};

int main() 
{
    User *userObj1 = new User(12,"John"); 
    userObj1->display();
    return 0; 
}

// Deleting specific template specializations 
#include<iostream>
using namespace std;
template<typename T>
class ComplexNumber 
{
    T x;
    T y;
public:
    ComplexNumber(T a,T b) : x(a), y(b)
    {}
    void display()
    {
        cout << x << " + i" << y << endl;
    }
    /***********
    ComplexNumber(double a,double b) = delete;
    ComplexNumber(char a,char b) = delete; 
    main.cpp: In instantiation of ‘class ComplexNumber<double>’:
    main.cpp:22:32:   required from here
    main.cpp:15:5: error: ‘ComplexNumber::ComplexNumber(double, double) [with T = double]’ cannot be overloaded with ‘ComplexNumber::ComplexNumber(T, T) [with T = double]’
   15 |     ComplexNumber(double a,double b) = delete;
      |     ^~~~~~~~~~~~~
    main.cpp:9:5: note: previous declaration ‘ComplexNumber::ComplexNumber(T, T) [with T = double]’
    9 |     ComplexNumber(T a,T b) : x(a), y(b)
      |     ^~~~~~~~~~~~~
    main.cpp: In instantiation of ‘class ComplexNumber<char>’:
    main.cpp:23:30:   required from here
    main.cpp:16:5: error: ‘ComplexNumber::ComplexNumber(char, char) [with T = char]’ cannot be overloaded with ‘ComplexNumber::ComplexNumber(T, T) [with T = char]’
   16 |     ComplexNumber(char a,char b) = delete;
      |     ^~~~~~~~~~~~~
main.cpp:9:5: note: previous declaration ‘ComplexNumber::ComplexNumber(T, T) [with T = char]’
    9 |     ComplexNumber(T a,T b) : x(a), y(b)
      |     ^~~~~~~~~~~~~
      *******/
}

