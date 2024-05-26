1, what is a copy constructor?
A, A copy constructor is a member function that initializes an object using another object of the same class.
   Example:
   class A {
   int x,y;
   A(int x,int y) 
   {
    this->x=x;
	this->y=y;
   }
   };
   int main()
   {
      A a1(2,3);
	  A a2=a1; // default copy constructor is called
	  return 0;
	}

   We can define our copy constructor. If we don't define a copy constructor then the default copy constructor is called. 
	
2, what is the difference between shallow copy and deep copy?
A, Shallow Copy:
   * Shallow copy stores the references of objects to the original memory address.
   * shallow copy is faster
   * Shallow copy reflects changes made to the new/copied object in the original object.
   
   Deep Copy:
   * Deep copy makes a new and separate copy of an entire object with its unique memory address.
   * Deep copy is comparatively slower.
   * Deep copy doesn't reflect changes made to the new/copied object in the original object.
   
3, What is the difference between virtual functions and pure virtual functions?
A, 
   Virtual Funcion: 
   
  -  A virtual function is a member function in the base class that you redefine in a derived class.
   It is declared using the virtual keyword.
   Example:
   class base{
	   public:
	   virtual void fun(){
	   }
   };
   
   - A virtual Function has its definition in its respective base class.
   - The base class has a virtual function that can be represented or instanced; In simple words, its object can be made.
   
   Pure virutal function: 
   
   -  A pure virtual function is a function that has no implementation and is declared by assigning 0.It has not body.
   Example:
   class base{
	   public:
	   virtual void fun()=0;
   }
   Here, = sign has got nothing to do with the assignment, and value 0 is not assinged to anything. 
   It is used to simply tell the compiler that a function will be pure and it will not have anybody. 
   
   - A pure virtual function is a member function of a base class that is only declared in a base class and defined
     in a derived class to prevent it from beginning an abstract class.
	 
   - A base class having pure virtual function becomes abstract that cannot be represented or instanced.
     In simple words, it means its object cannot be made.
   
   
   
4, If class D is dervied from a base class B. When creating an object of type D in what order would the constructors of these classes get called?
A, The derived class has two parts, a base part and a dervied part.
   When C++ constructs derived objects, it does so in phases. First, the most-base class(at the top of the inheritance tree) is constructed. 
   Then each child class is constructed in order until the most-child class is constructed last.
   So the first constructor of class B will be called and then the constructor of class D will be called.
   During the destruction exactly reverse order is followed. That is destructor starts at the most-derived class and works its way down to base class.
   So the first destructor of class D will be called and then the destructor of class B will be called.
   
5, Can we call a virtual function from a constructor?
A, Yes, we can call a virtual function from a constructor. But the behaviour is a little different in this case.
   when a virtual function is called, the virtual call is resolved at run time. It is always the member function of the current class that gets called.
   That is the virtual machine doesn't work within the constructor.
   Example:
   class base {
	   private:
	   int value;
	   public:
	   base(int x)
	   {
		   value=x;
	   }
	   virtual void fun()
	   {
	   }
   }
   class derived {
	   private:
	   int a;
	   public:
	   derived(int x,int y):base(x)
	   {
		   base *b;
		   b=this;
		   b->fun(); // calls derived::fun()
	   }
       void fun()
	   {
		   cout << "fun inside derived class" << endl;
	   }
   }
   
   ** Yes, we can call a virtual function from a constructor. But it can throw an exception of overriding.
   
6, what are void pointers?
A, A void pointer is a pointer which is having no datatype assoicated with it. It can hold addresses of any type.
   For example:
   void *ptr;
   char *str;
   p=str; // no error
   str=p; // error because of type mismatch
   We can assign a pointer of any type to a void pointer but the reverse is not true unless you typecast it as
   str=(char *)ptr;
   
   https://www.interviewbit.com/cpp-interview-questions/#copy-constructor-in-c++
    
7, what is this pointer in c++?
A, The member functions of every object have a pointer named this, which points to the object itself.
   The value of this is set to the address of the object for which it is called.
   It can be used to access the data in the object it points to. 
   
   - this pointer enables every object to have access to its own address through an essential pointer.
   - All member functions take this pointer as an implicit argument.
   - this pointer may be used to refer to the calling object within a member function.
	   * this pointer is used to pass an object as a parameter to another method.
	   * Each object gets its own copy of the data members.
	   * this pointers is used to declare indexers.    
    
   
8, How do you allocate and deallocate memory in C++?
A, The new operator is used for memory allocation and deletes operator is used for memory deallocation in C++.
   For example:
   int value = new int;  // allocate memory for storing 1 integer
   delete value;  // deallocate memory taken by value
   
   int *arr = new int[10];  // allocates memory for storing 10 int
   delete[] arr;  // deallocate memory occupied by arr
   
 9, which operator cannot be overloaded in C++?
 A, :: (Scope resolution operator), . (Dot operator) , sizeof operator, Pointer to member function or dereferening operator - ".*" , -> - member dereferencing operator 
 
 10, What will be the output of the following C++ program?
 A, 
 #include<iostream>
 int main()
 {
	 int a=1;
	 cout << (a++)*(++a) << endl;
	 return 0;
 }
 
 Output : 3
        ** First multiplication happen
		** Then increment of post then pre. 
		
11, What will be the value of x in the following C++ program?
A, 
   #include<iostream>
   using namespace std;
   int main()
   {
	   int a=1;
	   int x=(a++)++;
	   cout << x << endl;
	   return 0;
   }
 
 Output: Compile Time Error
 
 main.cpp:6:14: error: lvalue required as increment operand
    6 |      int x=(a++)++;
      |            ~~^~~
	  
12, What is an abstract class?
A, 	Class which has exactely one pure virtual function.


**********************************************************************************************


13, Consider the following C++ program.
#include<iostream>
class A 
{
	public:
	virtual void a()=0;
	A()
	{
		cout << "A";
	}
};

class B: public A
{
	public:
	B()
	{
		cout << "B ";
	}
};

int main()
{
	A *a = new B();
	return 0;
}


Output : 
Compiler-time error 

main.cpp: In function ‘int main()’:
main.cpp:24:22: error: invalid new-expression of abstract class type ‘B’
   24 |         A *a = new B();
      |                      ^
main.cpp:13:7: note:   because the following virtual functions are pure within ‘B’:
   13 | class B: public A
      |       ^
main.cpp:6:22: note:     ‘virtual void A::a()’
    6 |         virtual void a()=0;
      | 
 
************************************************************************************************

 
14, What is the size of void in C++?
A, 0

************************************************************************************************

15, if a base class and derived class each include a member function with same name.
    Function from which class will be called if called by an object of the derived class.
A, Member function of the derived class.

*************************************************************************************************

16, Memory used by an array is continous

**************************************************************************************************

17, Which of the following statement in correct?
A, An object is an instance of the class
   A friend function can access private members of a class
   Members of the class are private by default.
   
*************************************************************************************************

18, what should be the correct statment about string objects?
A, 1, String objects should necessarily be terminated by a null character.
   2, String objects have a static size.
   3, String objects have a dynamic size.
   4, String objects use extra memory than required.

**********************************************************************************************************

19,  what should be the output of the below code?
	#include<iostream>
	using namespace std;
	int main()
	{
     int i;
     int j=10;
     
     i=(j++,j+100,999+j);
     cout << i;
     return 0; 
	}  
A, 1010 -  The value of j is incremented to 11, then j value is added to 100 but not assigned, at last the value of j i.e,11 is 
           added to 999 which gives us 1010


**********************************************************************************************************

20, How to find the frequency of a number in C++?
    #include<iostream>
	using namespace std;
	int frequency(int num, int k)
	{
		int c=0;
		while(num>0)
		{
			if(num%10 == k)
				c++;
			num=num/10;
		}
		return c;
	}
	int main()
	{
		int num=1332422523;
		int k=2;
		cout << frequency(num,k);
		return 0;
	}
	
********************************************************************************************************

21, Ternary operator

*********************************************************************************************************

22, what is abstraction?
A, Abstraction can be defined as a techique in which you only show functionality to the user i.e, the
   details that you want the user to see, hiding the internal details or implementation details.
   
**********************************************************************************************************

23, inheritance 

***********************************************************************************************************

24, Write a program to find the factorial of a number?
A, 
#include<iostream>
using namepsace std;
int main()
{
	int n;
	int fact=1;
	cout << "Enter a positive integer: ";
	cin >> n;
	if(n<0)
	{
		cout << "Error!";
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			fact*=i;
		}
	}
	return 0;
} 

*************************************************************************************************************

25, how to write a program to check if a number is a palidrome or not?
A.
#include<iostream>
using namespace std;
int main()
{
	int n,num,digit,rev = 0;
	cout << "Enter a positive number: ";
	cin >> num;
	n = num;
	
    do{
		digit = num%10;
		rev=(rev*10) + digit;
		num=num/10;
	} while(num!=0);
	
	cout << "The reverse of the number is: " << rev << endl;
	if(n == rev)
		cout<< "The number is a palidrome.";
    else
		cout << "The number is not a palindrome.";
	return 0;
}

************************************************************************************************************


26, what is STL?
A, STL stands for standard template library. It is a library of container templates that provide generic classes and functions.

STL components are containers, algorithms, iterators, and function objects (functors). 

Algorithms :  Binary, Lower/Upper bound, Min/Max, Reverse/Rotate --> Sort/Scoop

Containers :

a, Sequence Container : Array, Vector, Deque, and List.
b, Container Adapters : Stack, Queue, and Priority Queue.
c, Associative Containers : Set and Map
d, Unordered Associative : Unordered Set and Unordered Map 


***********************************************************************************************************


27, Friend is not a member of a class. Static, virtual and const are a members of a class.

**********************************************************************************************************

28, sizeof operator is used to give the size of the object.

**********************************************************************************************************

29, what is a friend function?
A, You can define a friend function as a function that can access private, public, and protect members of the class.
   you declare the friend function with the help of the friend keyword.
   You declare friend function inside the class.
   
**********************************************************************************************************

https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-interview-questions


30, what among these is used to return the number of characters in the string?
A, Size and Length are used to return the number of characters in the string.

31, what is operator overloading?
A, Operator overloading is a mechanism in which a special meaning is given to an operator.
   For example, you can overload the '+' operator in a class-lie string to concatenate two strings by only using '+'
   
32, Discuss the difference between new and malloc?
A, new 
   * new is an operator
   * it calls the constructor.
   * There is no need to specify memory size while using new()
   * new operator can be overloaded.
   
   malloc
   * malloc() is a function.
   * The malloc function doesn't call the constructor.
   * You have to specify the memory size.
   * malloc can never be overloaded.
   
33, Define operator overloading and function overloading?
A, An example of compile-time polymorphism is operator overloading. It is the concept of modifying an existing c++ operator
   without altering its original meaning.
   
34, what is a constructor?
A, A constructor is defined as a member function that is invoked whenever you create an object;
   it has the same name as that of the class.
   
   There are two types of constructors:
   - Default constructor - This auto-generated constructor doesn't take any arguments.
   - Parameterized constructor - In this constructor, it can pass arguments.
   
65, what is a scope resolution operator?
A, A scope resolution operator is represented as ::
   This operator is used to associate function definition to a particular class.
   The scope operator is used for the following purposes:
   - To access a global variable when you have a local variable with the same name.
   - To define a function outside the class.
   - In case of multiple inheritances.
   - For namespace 
   
 66, Is it possible to overload a deconstructor? Give reasons your answer?
 A, No, it is impossible as destructors do not take arugment or return anything.
    There has to be only one empty destructor per class. It should have a void parameter list.
	
67, what is an abstraction in c++?
A, Abstraction means displaying the essential details to the user while hiding the irrelevent or particular details
   that you don't want to show to a user. It is of two types:
   1, Control abstraction
   2, Data abstraction 
   
68, what are the different data types present in C++?
A, Primary : Integer (stores integers) , Character (stores single characters), Boolean (stores a value that is either true or false) , 
             Floating Point (stores floating-point values) , 
			 Double Floating point ( stores float-points with twice as much precision as float) , 
			 void (represents the absence of a type) , Wide character
   Derived : Function, Array, Pointer and Reference
   User Defined : Class, Structure, Union, Enum, Typedef
   
 69, Define 'std'?
 A, 'std' is also known as Standard or it can be interpreted as a namespace.
     The command "using namespace std" informs the compiler to add everything under the std namespace and inculate them in the global namespace.
	 This all inculcation of global namespace benefits us to use "cout" and "cin" without using "std::_operator_".
	 
70, Define token in C++?
A. A token is the smallest individual element of a program that is understood by a compiler. A token comprises the following:
   1, Keywords - That contain a special meaning to the compiler.
   2, Identifiers - That hold a unique value/identity
   3, Constants - That never change their value throughout the program
   4, Strings - That contains the homogenous sequence of data
   5, Special Symbols - They  have some special meaning and cannot be used for another purpose 
   6, Operators - Who perform operations on the operand
   
71, what is a virtual destructor?
A,  When destroying instances or objects of a derived class using a base class pointer object, a virtual destructor is invoked to free up memory space
    allocated by the derived class object or instance.
	Virtual destructor guarantees that first the derived class destructor is called.
	Then the base class's destructor is called to release the space occupied by both destructors in the inheritance class which saves us from the memory leak.
	It is advised to make your destructor virtual whenever your class is polymorphic.
	
72, Is destructor overloading possible? If yes then explain and if no then why?
A,  The simple answer is NO we cannot overload a destructor. It is mandatory to only destructor per class in C++.
    Also to mention, Destructor neither take arguments nor they have a paramter that might help to overload.
   
73, which operations are permitteed on pointers?
A, Pointers are the variables that are used to store the address location of another variable.
   Operations that are permitted to a pointer are:
   1, Increment/Decrement of a pointer
   2, Addition and Substraction of integer to a pointer
   3, Comparsion of pointers of the same type

74, what is the purpose of the "delete" operator?
A, The delete operator is used to delete/remove all the characterisitcs/properities from an object by deallocating its memory;
   furturemore, it returns true or false in the end. In simple terms, it destroys or deallocate array and non-array(pointer) objects which are created by new expressions.
   
   int GFG = new int[100]
   //uses GFG for deletion
   delete [] GFG;
   
75, How delete[] is different from delete?
A, delete[] :
   - It is used for deleting a whole array
   - It is used for deleting the objects of new[]; By this,we can say that delete[] is used to delete an array of objects.
   - It can call as many destructors it wants.
   
   delete:
   - It is used to delete only one single pointer.
   - It is used for deleting the objects of new; By this, we can say that delete is used to delete a single object.
   - It can only call the destructor of a class once.
  
76, What do you know about friend class and friend fucntion?
A, A friend class is a class that can access both the protected and private variables of the classes where it is declared as a friend.
   Example of friend class:
   class Class_1st
   {
	   //ClassB is a friend class of ClassA
	   friend class Class_2nd;
	   statements;
   }
   class Class_2nd{
	   statements;
   }
   
   A friend function is a function used to access the private,protected and public data members or member functions of other classes.
   it is declared with a friend keyword.
   The advantage of a friend function is that it is not bound to the scope of the class and once it is declared in a class, furthermore to that,
   it cannot be called by an object of the class; therefore it can be called by other functions.
   Considering all the mentioned points we can say that a friend function is a global function.
   
   class GFG{
	   statements;
	   friend datatype function_Name(arguments);
	   statements;
   }
   OR
   class GFG{
	   statements;
	   friend int divide(10,5);
	   statements;
   }
 
https://www.geeksforgeeks.org/cpp-interview-questions/
 
 77, what is an overflow error?
 A,  Overflow Error occurs when the number is too large for the data type to handle. In simple terms, it is a type of error that is
     valid for the defined but exceeds used the defined range where it should coincide/lie.
	 
	 For example, the range of int data type is -2147483648 to 2147483647 and if we declare a variable of size
	 2247483648 it will generate a overflow error.
	 
78, How to write a running C code with out main?
A,  Every program must have a main() function because-
    1, It's an entry point of every C/C++ program.
	2, All predefined and user-defined functions are called directly or indirectly through the main.
	
	Therefore we will use preprocessor(a program which processes the source code before compilation) directive 
	#define with arguments to give an impression that the program runs without main. 
	But in reality it runs with a hidden main function.
	Let's see how the preprocessor doing their job:-
	Preprocessing -> Compilation -> Assembly -> Linking (Machine Program)
	
	1, Using a macro that defines main
	#include<stdio.h>
	#define fun main
	int fun(void)
	{
		printf("Greeksforgeeks");
	}
	Output: Geeksforgeeks
	
	2, Using Token-Pasting Operator: The above solution has word 'main' in it.
	If we are not allowed to even write main, we can use token-pasting operator.
	
	#include<stdio.h>
	#define fun m##a##i##n
	int fun()
	{
		printf("Greeksforgeeks");
	}
	Output: Geeksforgeeks
	
	3, Using Argumented Macro
	
	#include<stdio.h>
	#define begin(m,a,i,n) m##a##i##n
	#define start begin(m,a,i,n)
	void start()
	{
		printf("Greeksforgreeks");
	}
	
	4, Modify the entry point during compilation
	#include<stdio.h>
	#include<stdlib.h>
	//entry point function
	int nomain();
	void _start() {
		//calling entry point
		nomain();
		exit(0)
	}
    int nomain() 
	{
		puts("Greeks");
		return 0;
	}
	Output:
	Geeksforgeeks
	
	Compilation using command: gcc filename.c -nostartfiles
	(nostartfiles option tells the compiler to avoid standard linking) appended to every code during normal compilation],
	so if that main() definition is not present it will result in error like "In function '_start': undefined to 'main'.
	In the above code what we have done is that we have defined our own _start() and defined our own entry point i.e nomain()
	
	
79, Define inline function. Can we have a recursive inline function in C++?
A, 	- An inline function is a form of request not an order to a compiler which results in the inlining of our function to the main function body.
    - An inline function can become overhead if the execution time of the function is less than the switching time from the caller function to called function.
	- To make a function inline use the keyword inline before and define the function before any calls are made to the function.
	
	Syntax:
	inline data_type function_name()
	{
		Body;
	}
	
	The answer is No; it cannot be recursive.
	An inline function cannot be recursive because in the case of an inline function the code is merely placed into the position from where it is called and 
	does not maintain a piece of information on the stack which is necessary for recursion.
	Plus, if you write an inline keyword in front of a recursive function, the compiler will automatically ignore it because the inline is only taken
	as suggestion by the compiler.

80, What is an abstract class and when do you use it?
A, 	An abstract class is a class that is specifically designed to be used as a base class.	
    An abstract class contains at least one pure virtual function.
	You declare a pure virtual function by using a pure specifier(=0) in the declaration of a virtual member function in the class declaration.
	
	you cannot use an abstract class as a parameter type, a function return type, or the type of an explicit conversion, nor 
	can you declare an object of an abstract class.
	However, it can be used to declare pointers and references to an abstract class.
	
	An abstract class is used if you want to provide a common, implemented functionality among all the implemenations of the component.
	Abstract classes will allow you to partially implement your class, whereas interfaces would have no implementation for any members whatsoever.
	In simple words, Abstract classes are a good fit if you want to provide implemenation details to your children but don't want to allow
	an instance of your class to be directly instantiated.
	
81, what is wide characters?
A,  Wide characters are similar to character datatype. The main difference is that char takes 1-bytes space, but wide character takes 2bytes. 
    For 2-byte space wide character can hold 64K (65536) different characters.
	So the wide char can hold UNICODE characters.
	The UNICODE values are international standard which allows for encoding for characters virtually for any character of any language.
	

82, what is c++ ?  what are the advantages of C++?
A,  C++ of an object oriented programming language. 
    By object oriented we mean that it works with the concept of polymorphism, inheritance, abstraction , encapsulation, object and class
	
	Advantages of C++:
	1, C++ is an OOPS language that means the data is considered as objects.
	2, C++ is a multi-paradigm language. In simple terms, it means that we can program the logic, structure and procedure of the program.
	3, Memory management is a key feature in C++ as it enables dynamic memory allocation.
	4, it is a mid-level programming language which means it can develop games, desktop applications, drivers and kernels.
	
83, what are references in C++?
A, - When a variable is described as a reference it becomes an alias of the already existing variable. In simple terms, a reference variable  
     is another named variable of an existing variable keeping in mind that changes made in the reference will be reflected in the already existing variable.
   - A reference variable is preceded with a '&' symbol.

   Syntax: 
   int GFG = 10;
   // reference variable
   int &ref = GFG;
   
84, what do you mean by call by value and call by reference?
A,  In this programming language to call a function we have 2 methods.
    Call by Value:
    - A copy of a variable is passed.
    - Calling a function by sending the values by copying variables.
    - The changes made in the function are never reflected outside the function on the variable. In short, the original value is never altered in Call by Value.
    - Passed actual and formal parameters are stored in different memory locations. Therefore, making call by value a little memory insufficient.

    Call by Reference:
    - A variable itself is passed fundamentally.
    - Calling a function by sending the address of the passed variable.
    - The changes made in the functions can be seen outside the function on the passed function.In short, the original values is altered in call by reference.
    - Passed actual and formal parameters are stored in the same memory location. Therefore, making Calll by Reference a little more memory efficient.

85, what is the difference between C and C++?
A, C: 
   - It is procedural programming language. In simple words, it does not support classes and objects.
   - It does not support any OOPs concepts like polymorphism, data abstraction, encapsulation, classes and objects.
   - It does not support Function and Operator Overlaoding.
   - It is a function-driven language.

   C++:
    - It is a mixture of both procedural and object oriented programming languages. In simple words, it supports classes and objects.
    - It supports all concepts of data.
    - It supports Function and Operator overloading respectively.
    - It is an object-driven language.

86, what is the difference between struct and class?
A, Struct:
   - Members of the struct are always by default public mode.
   - Structures are of the value type. They only hold value in memory.
   - The memory in structures is stored as stacks.
    
   Class:
   - Members of the class can be in private, protected and public modes.
   - Classes are of reference type.It holds a reference of an object in memory.
   - The memory in classes is stored as heaps.

87, what is the difference between reference and pointer?
A, Reference:
   - The value of a reference cannot be reassigned.
   - it can never hold null value as it needs an existing value to become an alias of.
   - it cannot work with arrays.
   - To access the members of class/struct it uses a '.'
   - The memory location of reference can be accessed easily or it can be used directly.
   
   Pointer
   - The value of a pointer can be reassigned.
   - It can hold or point at a null value and be termed as a nullptr or null pointer.
   - it can work with arrays.
   - To access the members of class/struct it uses a '->'
   - The memory location of a pointe cannot be accessed easily as we have to use a deference '*'
   
88, what is the difference between function overloading and operator overloading?
A, Function overloading:
   - it is basically defining a function in numerous ways such that there are many ways to call it.
     or in simple terms you have multiple versions of the same function.
   - Parameterized functions are a good example of function overloading as just by changing the 
     argument or parameter of a funcion you make it useful for different purposes.
   - Example of Function Overloading
     1, int GFG(int X,int Y)
     2, int GFG(char X,char Y)
  
  Operator Overloading: 
  - It is basically giving practice of giving a special meaning to the existing meaning of an operator
    or in simple terms redefining the pre-redefined meaning.
  - Polymorphism is a good example of an operator overloading as an object of allocations class
    can be used and called by different classes for different purposes.
  - Example of operator overloading
    int GFG() = X() + Y()
	int GFG() = X() - Y()
	
89, What is the difference between an array and a list?
A, Arrays:
   - Array are continous memory locations of homogenous data types stored in a fixed location or size.
   - Arrays are static in nature.
   - Uses less memory than linked lists.
   - An array supports random access using indexes.

   Lists:
   - Lists are classic individual elements that are linked or connected to each other with the help of pointers
     and do not have a fixed size.
   - Lists are dynamic in nature.
   - Uses more memory as it has to store the value and the pointer memory location.
   - List supports sequential access.Where the user has to tranverse through
     the elements to find a specific index.

90, what is the difference between a while loop and a do-while loop?
A,  While loop 
    - While loop is also termed an entry-controlled loop.
    - if the condition is not satified the statements inside the loop will not execute.
    - Example of a while loop:
        while(condition)
        { statements to be executed }
	
	
	do-while loop 
	- The do-while loop is termed an exit control loop.
	- Even if the condistoin is not satified the statements inside the loop will execute
	  for at least one time.
    Example of a do-while loop:
     do {
     statements to be executed.
     } while(condition or expression)	 

     
    https://www.geeksforgeeks.org/cpp-interview-questions/
	
	
91, Discuss the difference between prefix and postfix?
A, prefix :
   - it simply means putting the operator before the operand.
   - it executes itself before ;
   - Associativity of prefix++ is right to left.
   
   postfix :
   - it simply means putting the operator after the operand
   - it executes itself after ;
   - Associativity of postfix ++ is left to right.   
   
92, What are classes and objects in C++?
A, A class is a user-defined data type where all the member functions and data members are tailor-made
   according to demands and requirements in addition to which these all can be accessed with the help
   of an object. 
   To declare user-defined data type we use a keyword class.
   
   An object is an instance of a class and an entity with value and state; In simple terms, it is used
   as a catalyst or to represent a class member.
   It may contain different parameters or none.
   
   A class is a blueprint that defines functions which are used by an object.
   
93, What is function overriding ?
A, When a function of the same name, same arguments or parameters, and same return type already present/declared
   in the base class is used in a derived class is known as function overriding.
   It is an example of runtime polymorphism or Late binding which means the overridden function will be executed
   at the runtime of the execution.
   
 
94, what are various OOPS concepts in C++?
A, Classes : it is user-defined data type.
   Objects : It is an instance of a class.
   Abstraction : it is technique of showing only necessary details.
   Encapsulation : Wrapping of data into single unit.
   Inheritance: The capability of  a class to derive properties and characteristics from another class.
   Polymorphism : Polymorphism is known as many forms of the same thing.

95, Explain inheritance?
A, The capability or ability of a class to derive properities and characteristics from another class is known as inheritance.
   In simple terms, it is a system or techique of reusing and extending existing class without modifying them.

96, when should we use multiple inheritance?
A, Multiple inheritance mean that a derived class can inherit two or  more base/parent classes. 
   It is useful when a derived class needs to combine numerous attributes/constracts and inherit some of all, of the implemenation
   from the attributes/contracts.
   To take a real-life example consider your parents where Parent A is your DAD parent B is your MOM and Child C is you.

97, what is virtual inheritance?
A. Virutal inheritance is a technique that ensures only one copy of a base class's member variables is inherited by grandchild-derived classes.
   or in simple terms, virtual inheritance is used when we are dealing with a situation of multiple inheritances but want to prevent multiple instances
   of the same class from appearing in the inheritance hieracy.

 98, what is polymorphism in C++?
A. Polymarphism is known as many forms of the same thing.
   In simple terms, we can say that polymorphism is the ability to display a member function in multiple forms depending on the type of object that calls them.
   In other words, we can also say that a man can be an employee to someone, a son of someone, a father of someone, and a husband of some one; 
   this is how polymorphism can be projected in real life.

   There is 2 types of polymorphism
   1, compile time polymorphism - function overloading , operator overloading 
   2, Run time polymorphism - Function overloading and virtual function

99, what are different types of polymorphism in C++?
A, There is 2 type of polymorphism
   1, Compile time polymorphism or Static binding or early binding : 
   - This type of polymorphism is achieved during the compile time of the program which results in it making a bit faster than Run time.
     Also, inheritance is not involved in it. 
   - It comprised of 2 further techniques.
     a, Function overloading:  when there are multiple function with the same name but different parameters then this is known as function overloading.
     b, operator overloading: It is basically giving practice of giving a special meaning to the existing meaning of an operator or in simple terms
	                          redefining the pre-defined meaning.
							  
    2, Run time polymorphism  or late binding or Dynamic binding: 
	- Run time polymorphism takes place when functions are invoked during run time.
	a, Function overriding : Function overriding occurs when a base class member function is redefined in a derived class with the same arguments and return types.
	
	
100, Explain the constructor in C++?
A, A constructor is a special type of member function of a class, whose name is the same as that of the class by whom it is invoked and initializes value 
   to the object of the class.
   There are 3 types of constructor:
   1, Default constructor:
    - It is the most basic type of constructor which accepts no arugments or parameters. Even if it is not called the compiler calls it automatically 
      when the object is created.
   2, Parameterized constructor:
    - It is type of constructor which accepts arguments or parameters.
    - It has to be called explicitly by passing values in the arguments as these arguments help intitialize an object when it is created.
    - It also has the same name as that of the class.

   3, copy constructor:
    - A copy constructor is a member function that initializes an object using another object of the same class. 
    - Also, the copy constructor takes a reference to an object of the same class as an argument.

https://www.geeksforgeeks.org/cpp-interview-questions/

101, what are destructors in C++?
A, Destructors are members of functions in  a class that delete an object when an object of the class goes out of scope.
   Destructors have the same name as the class preceded by a tilde(~) sign. 
   Also, destructors follow a down-to-top approach, unlike constructors which follow a top-to-down.
   
   Syntax : ~constructor_name() ;  // tilde sign signifies that it is a destructor.
   

102, what are the static data members and static member functions?
A, The static data member of a class is a normal data member but preceded with a static keyword. 
   It executes before main() in a program and is initialized to 0 when the first object of the class is created.
   It is only visible to a defined class but its scope is of a lifetime.
   Syntax: 
   static Data_Type Data_Member;
   
   The static member function is the member function that is used to access other static data members or other static member function.
   It is also define with a static keyword. We can access the static member function using the class name or class objects.
   
   Syntax:
   classname::function_name(parameter);
   
103, what is the main use of the keyword "Volatile"?
A, Just like its name, things can change suddenly and unexpectantly; so it is used to inform the compiler that the value may change any time.
   Also, the volatile keyword prevents the compiler from performing optimization on the code.
   It was intended to be used when interfacing with memory-mapped hardware, signal handlers, and machine code instruction.
   
104, Define storage class in C++ and name some?
A, Storage class is used to define the features(lifetime and visibility) of a variable or function. 
   These features usually help in tracing the existence of a variable during the runtime of a program. 
   
   Syntax: storage_class var_data_type var_name;
   
   Some types of storage classes:
   
   1, Storage class : Automatic; Keyword : auto; Lifetime : Function Block; Visibility: Local; InitialValue : Garbage
   2, Storage class : External ; Keyword : extern; Lifetime : Whole Program; Visibility : Global; Initialvalue : Zero
   3, Storage class : Static; Keyword : static; Lifetime : Whole program; Visibility: Local; Initialvalue : zero 
   4, Storage class : Register; Keyword : register; Lifetime : Function Block; Visibility : Local; InitialValue : Garbage
   5, Storage class : mutable; keyword : class; Lifetime : class ; Visibility : Local ; InitialValue : Garbage
   
105, what is a mutable storage class specifier? How can they are used?
A. - Just like its name, the mutable storage class specifier is used only on a class data member to make it modifiable even though 
	the member is part of an object declared as const. 
   - Static or const , or reference members cannot use the mutable specifier. when we declare a function as const, this pointer passed to the function becomes const. 
   
 106, Define the Block scope variable?
 A. - So the scope of a variable in a region where a variable is accessible. 
    - There are two scope regions, A global and block or local.
	- A block scope variable is also known as a local scope varible. 
	- A variable that is defined inside a funciton or inside a block is a local variable.
	- it can be used only inside the particular function/block in which it is declared
	- A block-scoped variable will not be available outside the block even if the block is inside a function.
	
107, what is the function of the keyword "Auto"?
A, The auto keyword may be used to declare a variable with a complex type in a straightforward fashion.
   you can use auto to declare a variable if the initialization phrases contains templates, pointers to functions, references to members etc.
   With type reference capabilities, we can spend less time having to write out things the compiler alreadys knows.
   As all the types are deduced at compiler phase only, the time of compilation increases slightly but it does not affect the runtime of the program.
   
108, Define namespace in C++?
A, - Namespaces enable us to organize named items that would otherwise have global scope into smaller scopes, allowing us to give them namespace scope.
   - This permits program parts to be organized into distinct logical scopes with names.
   - The namespace provides a place to define or declare identifiers such as variables, methods, and classes.
   - Or We could say that A namespace is a declartive zone that gives the identifiers (names of types, functions, varaibles, and so on)
     within it a scope.
   - Namespaces are used to arrange code into logical categories and avoid name clashes, which might happen when you have many libraries in your code base.
   
 109, when is void() return type used?
 A, - The void keyword, when used as a function return type, indicates that the function does not return a value.
    - When used as a parameter list for a function, void indicates that the function takes no parameters.
	- Non-value returning functions are also known as void functions, They are called void since they're not designed to return anything.
	- True, but only partically. We cann't return values from void functions, but we are certainly return something.
	- Although void functions have no return type, they can return values.

https://www.cppbuzz.com/interview-questions-on-c++-11
	
110, what is the correct syntax for lamdba expression in C++ 11?
A,  [ capture ] (parameters)->return-type {body}

111, Does below code compiles successfully on C++11?
A,
  class C 
  {
	  int a=7;
	  public:
	  C();
  }
  Yes, it will compiles successfully.
  
112, what do you understand from lexical analysis?
A, Making up tokens from characters.

113, In C++ 11 which data types is newly introduced among these?
A, long long

114, which keyword in C++ 11 is used to prevent a virtual function from being overridden?
A, final

115, C++ 11 introduces a new keyword. Find out that keyword?
A, override

116, which one is correct syntax to use C++ 11 features while compilation?
A, g++ -std=c++11 -o output.out source.cpp

117, Is below program of C++ 11 valid & runs without compilation error?
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void print_square(int i)
{
cout << i*i << endl;
}

int main()
{
vector<int> v;
//vectors gets filled
for_each(v.begin(),v.end(),print_square);
return 0;
}

A, Yes

118, Is this valid C++ 11 program & get compiled without any error?
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v;
	// vector gets filled.
	
for_each(v.begin(),v.end(),[](int i) { cout << i*i << endl; });
return 0;
}

A, Yes 

119, Correct syntax for creating a thread using Functin Pointer?
thread_function is the name of function which need to be executed in separate thread.

A, std::thread threadObj(thread_function)

120, How to input string in C++?
A, There are three ways to input a string, using cin, get, and getline. 
   All three methods are mentioned in the sample program below.
   
   #include<iostream>
   using namespace std;
   int main()
   {
	    char s[10];
		cout << "Enter a string :";
		cin >> str;
		cout << "Enter another string:";
		cin.get(s,10);
		getline(cin,str);
		return 0;
   }
   
121, what is template in C++?
A, A template in C++ is used to pass data types as parameters. 
   These make it easier and more simpler to use classes and functions.
   template<typename T>
   int fun(T a,T b)
   {
	   return(a+b);
   }
   int main()
   {
	   cout << fun<int>(11,22);
   }
   
 122, what is stream in C++?
 A, Stream refers to a stream of characters to be transferred between program thread and i/o;
 
 123, How to clear screen in c++?
 A, one can clear screen using - clrscr() or system("clear"
 
 124, How many keywords in C++?
 A, There are 95 reserved keywords in C++ which are not available for re-definintion or overloading.
 
 125, what is iostream in C++?
 A, it is a header file that includes basic objects such as cin,cout,cerr,clog
 
 126, How to dynamically allcate a 2d array in C++?
 A, There are several methods by whihc one cal allocate memory to 2D array dynamically one which is as follows.
    #include<iostream>
	int main()
	{
		int row=2,col=2;
		int* a = new int[row * col];
		int i,j,count = 0;
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				*(a+i*col+j)=count ++;
			
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				print("%d",*(a+i*col+j));
		delete[ ] a;
		return 0;
	}
	
127, How to use goto statement in C++?
A, Goto statement provided unconditional jump in the code. The syntax is: goto label;
   label: statement;
   #include<iostream>
   using namespace std;

   void main()
   {
     float d, avg, add = 0.0;
     int j,n;
     cin >> n;	 
	 for(j=1;j<=n;++j)
	 {
		 cout << "Enter number" << i;
		 cin >> d;
		 if(d < 0.0)
         {
		   goto jump;
		 }
        add+=d;		 
	 }
	 jump:
	 avg = add/(j-1);
	 cout << avg; 
   }	 


128, what is bool in C++?
A, Bool is a datatype in C++ which takes two values - True and False. 
   Syntax is as follows:
   bool b1 = true;
   A sample code is as follows:
   #include<iostream>
   using namespace std;
   int main()
   {
	   int a=60,b=70;
	   bool c, d;
	   c= a==b; // false
	   c= a<b; // true
	   cout << b1;
	   cout << b2;
	   return 0;
   }
   
 129, what is exception in C++?
 A, Runtime abnormal conditions that occur in the program are called exceptions. 
    These are of 2 types.
	- Synchronous - Asynchronous
	C++ has 3 specific keywords for handling these exceptions: try, catch, throw
	
	
130, How to set decimal places in C++?
A, - For limiting the decimal places in C++ there are five functions: floor(),ceil(),trunc(),round() and setprecision().
   - Out of these five, only setprecision() function is used to for setting the decimal places to put as output.
   #include<bits/stdc++.h>
   using namespace std;
   int main()
   {
	   float a=2.3333;
	   cout << floor(a) << endl;
	   cout << ceil(a) << endl;
	   cout << trunc(a) << endl;
	   cout << round(a) << endl;
	   cout << setprecision(2) << a;
	   return 0;
   }
	
131, how to get absolute value in c++?
A, In C++, there are threee functions in the cstdlib header file to return the absolute value of the integer.
   Those are : abs() - int - <<Number>>  , labs() - long int - <<Number>>L , llabs() - long long int - <<Number>>LL
   
   https://iies.in/wp-content/uploads/2021/07/Interview-level-QA-on-C-1.pdf

132, How to convert char to int in c++?
A, There are three methods for converting char variable to int type variable. These are as follow:
   (a) atoi()   (b) sscanf() (c) typecasting

133, what is containership?
A, 
 - You can contain an object of one class into another, and that object will be a member of the other class.
 - This relationship between classes wherein once class contains the object of another class is referred to as containership.
 
 
 134, what is a singleton design pattern?
 A, 
 - Design patterns are reusable solutions that you can apply to recurreing object oriented design problems.
 - Single design patterns fall under the category of creational design patterns.
 - This pattern helps design a class with a maximum of a single instance at any time.
 - It cannot be instantiated further.
 - The concept of a singleton design pattern can be applied to creating a logger or hardware interface class.
 
135, what do you understand about RTTI?
A, 
- RTTI  stands for Run-time type information.
- This mechanism gives information about an object's data type at runtime.
- It is available only for classes that have at least one virtual function.
- You can determine the type of an object during program runtime execution.

136, what is the spare matrix?
A, An array of elements wherein many elements have a value of zero is called a sparse matrix.
   For instance, if you are given a matrix with several elements and the number of zeroes is more than half the elements of the matrix, then it is a spare matrix.
   
 137, what do you understand about smart pointers in C++?
 A, Smart pointers are employed in garbage collection to ensure no memory leaks. 
    If you use smart pointers, you need not call delete for any memory allocated dynamically as it is automatically deallocated.
	you can implement smart pointers in C++11 and higher versions.
	C++11 has the following four kinds of smart pointers:
	1, auto_ptr 2, unique_ptr 3, shared_ptr 4,weak_ptr
	
138, what is stringstream in c++?
A, Stringstream is a class in C++ that associates a string object with a stream allowing to read from the string as if it were a stream.
   Syntax is as follows:
      stringstream string_name(str)
	  
139, Explain what is multi-threading in C++?
A, To run two or more programs simutaneously multi-threading is useful. There are two types of
   (01) process-based - it handles the concurrent execution of the program.
   (02) Thread-based - it deals with the concurrent execution of pieces of the same program.
   
140, Explain what is upcasting in C++?
A, upcasting is the act of converting a sub class references or pointer into its super class reference or pointer is called upcasting.

141, Explain what is preprocessor in C++?
A, Pre-processors are the directives, which give instruction to the compiler to pre-process the information before actual compilation starts.

142, what is the parent class for all exceptions?
A, std::exception

143, An exception is always raised using a throw expression?
A, True

144, Any object (built-in or user-defined) can be thrown.
A, True

145, The formal parameter can be an ellipsis, in which case it handles all exceptions not yet handled.
A, True

146, Exceptions can be ignored
A, True

147, If not caught by handlers right after try block, exception moves to next-higther level and may be caught there?
A, True

148, If no handler at any level catches the exception, terminate() will be called and program will terminate.
A, True

149, 
void some_function() throw();
how does above function behaves?
A, Function will not throw any exception

150, 
// find the output of below code on singleton class
#include<iostream>


151, What are the strengths of C++?
A, C++ has many strenghs, including:
1, Portability : 
- C++ programs can be used across different operating systems.
2, Multi-paradigm frameworks :
- C++ offers great programming flexbility, supporting object-oriented
  generic, and procedural programming frameworks.
3, Scalability: 
- C++ is a powerful programming language that can be used to create
  resource-incentive programs as well as simpler, low-level programs.
  
152, what are the weeknesses of C++?
A, There are a few drawbacks of using C++. These include:
  1, Its steep learning curve:
  - C++ is a challenging programming language to learn, especially 
    for junior developers.
  2, Security4
  - The presence of pointers and global variables in C++ pose a 
    relatively high security threat.
  3, Memory management:
  - Manual memory allocation can be time-comsuming.
  4, Pointers:
  - Pointers are complex and will disrupt performance if implemented incorrtely.
  
153, what are the five types of inheritance in C++?
A, There are five different types of inheritance, each one with its own
   set of behaviours. 
   These include:
   1, single inheritance, where the derived class is inherited from only one base class.
   2, Multiple inheritance, where the derived class is inherited from two or more base classes.
   3, Multilevel inheritance, where the derived class is inherited from another derived class.
   4, Hybrid inheritance, where two or more different types of inheritance are used together.
   5, Hierarchical inheritance, where two or more derived classes are derived from a single base class.
  
  
 https://www.testgorilla.com/blog/cpp-interview-questions-sample-answers/?utm_term=&utm_campaign=Performance+Max+%7C+Premium+Old&utm_source=google&utm_medium=cpc&hsa_acc=4932434860&hsa_cam=14324002500&hsa_grp=&hsa_ad=&hsa_src=x&hsa_tgt=&hsa_kw=&hsa_mt=&hsa_net=adwords&hsa_ver=3&gclid=Cj0KCQiAr8eqBhD3ARIsAIe-buOhv18JjPNeiQSA2vciytzpI76QjdidQJ0ApCC6ZzJy9EdsT0bzFa4aAsvoEALw_wcB

154, 

class complex {
	private:
	float r,i;
	public:
	complex(float r,float i) {
	this->r = r;
	this->i = i;
	}
	complex(){}
	void displaydata() {
	cout << "real part =" << r << endl;
	cout << "imaginary part =" << i << endl;
	}
	complex operator+(complex c) {
	return complex(r+c.r,i+c.i);
	}
};

int main()
{
	complex a(2,3);
	complex b(3,4);
	complex c=a+b;
	c.displaydata();
	return 0;
}

155, 

class A {
	private:
	int val;
	public:
	A(int x) { // one argument constructor
		val=x;
	}
	A() {  // Zero argument constructor
	}
}
int main()
{
	A a(3);
	return 0;
}

156, 

int add(int a, int b) {
	return a+b;
}	
int add(int a,int b,int c) {
	return a+b+c;
}

int main()
{
	cout << add(2,3) << endl;
	cout << add(2,3,4) << endl;
	return 0;
}

157,

class A {
	public:
	virtual void fun() {
		cout << "base";
	}
};

class B: public A {
	public:
	void fun() {
	  cout << "derived";
	}
};

int main()
{
	A *a = new B();
	a->fun();
    return 0;
}


158,

class A {
	private:
	int data_a;
	public:
	A(int x) {
		data_a=x;
	}
	friend int fun(A,B);
};

class B {
	private:
	int data_b;
	public:
	B(int x) {
		data_b=x;
	}
	friend int fun(A,B);
};

int fun(A a,B b)
{
	return a.data_a+b.data_b;
}

int main()
{
	A a(10);
	B b(20);
	cout << fun(a,b) << endl;
	return 0;
}

159,

int x=10;
int &ref=x;


160,

class A {
	private:
	int val;
	public:
	A(int x) {
		val=x;
	}
	A() {}
	~A() {}
};
int main() 
{
	A a(3);
	return 0;
}


161,

class A 
{
int x,y;
A(int x,int y) {
this->x=x;
this->y=y;
}
};

int main() 
{
	A a1(2,3);
	A a2=a1; // default copy constructor is called.
	return 0;
}
	

162,

class base{
	private:
	int value;
	public:
	base(int x){
		x=value;
	}
	virtual void fun(){
	}
}

class derived{
	private:
	int a;
	public:
	derived(int x,int y):base(x){
		base *b;
		b=this;
		b->fun(); // calls derived::fun()
	}
	void fun(){
		cout << "fun inside derived class" << endl;
	}
}

163,

int value=new int; // allocates memory for storing 1 integer
delete value;  // deallocates memory taken by value

int *arr=new int[10]; // allocates memory for storing 10 int
delete []arr; //deallocates memory occupied by arr


164,

#include<iostream>
int main(int argc,char **argv)
{
	std::cout << 25u - 50;
	return 0;
}

- The answer is not -25. Rather, the answer is 4294967271, assuming 32 bit integers. Why?
- In C++, if the types of two operands differ from one another, then the operand with the "lower type"
  will be promoted to the type of the "higher type" operand, using the following type hierarchy 
 ( listed here from highest type to lowest type): long double, double, float, unsigned long int, long int, unsigned int, int (lowest)
- So when the two operands are, as in our example, 25u (unsigned int) and 50(int), the 50 is promoted to also being
  an unsigned integer(i.e., 50u)
- More over, the result of the operation will be of the type of the operands. Therefore, the result of 25u - 50u will itself be an unsigned integer as well.
  So the result of -25 converts to 4294967271 when promoted to being an unsigned integer.
  
165,

what is the error in the code below and how should it be corrected?
my_struct_t *bar;
// .. do stuff, including setting bar to point to a defined my_struct_t object ..
memset(bar,0,sizeof(bar));

The last argument to memset should be sizeof(*bar), not sizeof(bar).
sizeof(bar) calculates the size of bar (i.e., the pointer itself) rather than the size of the structure pointed to by bar.

The code can therefore be corrected by using sizeof(*bar) as the last argument in the call to memset.

A sharp candidate might point out that using *bar will cause a dereferencing error if bar has not been assigned.
Therefore an even safer solution would be to use sizeof(my_struct_t). 
However, an even sharper candidate must know that in this cause using *bar is absolutely safe within the call to sizeof,
even if bar has not been initialized yet, since sizeof is a compile time construct.


https://www.toptal.com/c-plus-plus/interview-questions

166, what will i and j equal after the code below is executed? Explain your answer.
int i = 5;
int j = i++;

A, After the above code executes, i will equal 6, but j will equal 5.
- Understanding the reason for this is fundamental to understanding how the unary increment(++) and decrement(--) operators work in C++.
- When these operators precede a variable, the value of the variable is modified first and then the modified value is used.
- For example, if we modified the above code snippet to instead say int j=++i;, i would be incremented to 6 then j would be set
  to that modified value, so both would endup being equal to 6
- However, when these operators follow a variable, then unmodified value of the variable is used and then it is incremented or decremented.
  That's why, in the statement int j=i++; in the above code snippet, j is first set to the unmodified value of i (i.e., 5) and then i is incremented to 6.
  
  
167, Assuming buf is a valid pointer, what is the problem in the code below?
     what would be an alternate way of implementing this that would avoid the problem?
A,   size_t sz=buf->size();
     while(--sz >= 0)
	 {
		 /* do something */
	 }
	 
- The problem in the above code is that --sz >= 0 will always be true so you'll never exit the while loop(so you'll probably end up corrupting memory or
  causing some sort of memory violation or having some other program failure, depending on what you're doing inside the loop).
- The reasons that --sz >= 0 will always be true is that the type of sz is size_t. 
- size_t is really just an alias to one of the fundamental unsigned integer types.
- Therefore, since sz is unsigned, it can never be less than (so the condition can never be true).

- One example of an alternative implementation that would avoid this problem would be instead use a for loop as follows:
  for(size_t i=0;i<sz;i++)
  {
	  /** do something **/
  }
  
168, Consider the two code snippets below for printing a vector.
     Is there any advantage of one vs the other? Explain.
   
    Option 1:
    vector vec;
    /* ... .. ... */
    for(auto itr=vec.begin(); itr!=vec.end(); itr++){
		itr->print();
    }	
	
	Option 2:
	vector vec;
	/* ... .. ... */
	for(auto itr=vec.begin(); itr!=vec.end(); ++itr){
		itr->print();
	}
	
A, 
- Although both options will accomplish precisely the same thing, the second option is better from a performance standpoint.
- This is because the post-increment operator (i.e., itr++) is more expensive than pre-increment (i.e., ++itr).
- The underlying implemenation of the post-increment operator makes a copy of the element before incrementing it and then returns the copy.
- That said, many compilers will automtically optimize the first option by converting it into the second.

169, Implement a template function IsDerivedFrom() that takes class C and class P as template parameters.
     It should return true when class C is derived from class P and false otherwise?
A,
-  This question tests understanding of C++ templates.
-  An experienced developer will know that this is already a part of the C++11 std library ( std::is_base_of ) 
   or
   part of the boost library for C++ (boost::is_base_of).
-  Even an interviewee with only passing knowledge should write something similar to this, mostly likely involving a helper class:

   template<typename D,typename B>
   class IsDerviedFromHelper
   {
	 class No {};
     class Yes { No no[3]; };

     static Yes Test( B* );
     static No  Test(...);
     public:
     enum { Is = sizeof(Test(static_cast<D*>(0))) = sizeof(Yes) }; 	 
   };
   
   template<Class C,Class P>
   bool IsDerivedFrom()
   {
	   return IsDerivedFromHelper<C,P>::Is;
   }
   
 170, Implement a template boolean IsSameClass() that takes class A and B as template parameters.
      It should compare class A and B and return false when they are different classes and true if they are the same class.
A, 	  
     template<typename T,typename U>
	 struct is_same
	 {
	   static const bool value=false;
	 };
	 template<typename T>
	 struct is_same<T,T>
	 {
		 static const bool value=true;
	 };
	 template<class A, class B>
	 bool IsSameClass() {
		 return is_same<A,B>::value;
	 }
	 
171, Is it possible to have a recursive inline function?
A, 
- Although you can call an inline function from within itself, the compiler may not generate inline code since the compiler cannot determine the depth of recursion at compile time.
- A compiler will a good optimizer can inline recursive calls till some depth fixed at compile-time ( say threee or five recursive calls), and insert non-recursive calls at compile time for cases
  hen the actual depth gets exceeded at runtime.
  
172, What is the output of the following code:
A, 
  #include<iostream>
  class A {
	  public:
	  A() {}
	  ~A() {
		  throw 42;
	  }
  };
  int main(int argc,const char* argv[])
  {
	  try {
		  A a;
		  throw 32;
	  }
	  catch(int a) {
		  std::cout << a;
	  }
  }
 
- The program will terminate abnormally, throw 32 will start unwinding the stack and destroy class A.
- The class A destructor will throw another exception during the exception handling, which will cause program to crash.
- This question is testing if developer has experience working with exceptions.

 https://www.toptal.com/c-plus-plus/interview-questions
 
 173, You are given library class Something as follows:
 
class Something {
public:
	Something() {
		topSecretValue=42;
	}
	bool somePublicBool;
	int somePublicInt;
	std::string somePublicString;
private:
	int topSecretValue;
};

Implement a method to get topSecretValue for any given Something* object.
The method should be cross-platform compatible and not depend on sizeof(int,bool,string).

A, 
Create another class which has all the members of Something in the same order, but has additional public method which returns the value.
Your replica Something class should look like:

class SomethingReplica {
	public:
	int getTopSecretValue() { return topSecretValue; }
	bool somePublicBool;
	int somePublicInt;
	std::string somePublicString;
	private:
	int topSecretValue;
};

Then, to get the value:

int main(int argc,const char *argv[])
{
	Something a;
	SomethingReplica* b = reinterpret_cast<SomethingReplica *>(&a);
    std::cout << b->getTopScretValue();	
}

- It's important to avoid code like this in a final product, but it's nevertheless a good technique when dealing with legacy code,
  as it can be used to extract intermediate calculation values from a library class.
  ( Note: if it turns out that the alignment of the external library is mismatched to your code, you can resolve this using #pragma pack.)
  
174, Implement a void funciton F that takes pointers to two arrays of integers ( A and B ) and a size N as parameters. 
     It then populates B where B[i] is the produce of all A[j] where j!=i.
	 
	 For example : if A={2,1,5,9}, then B would be {45,90,18,10}
	 
A, This problem seems easy at first glance so a careless developer might write something like this:
   void F(int* A,int* B, int N) 
   {
    int m = 1;
    for(int i=0;i<N;i++) {
	 m*=A[i];
	}		
    for(int i=0;i<N;++i) {
     B[i]=m/A[i];
    }
   }

   This will work for the given example, but when you add a 0 into input array A, the program will crash because the division by zero. 
   The correct answer should take that edge case into account and look like this:

   void F(int* A,int* B,int N) {
   // Set prod to the neutral multiplication element
   int prod = 1;
   for(int i=0;i<N;++i)
   {
		// For element "i" set B[i] to A[0] * ...* A[i-1]
		B[i] = prod;
		// Multiply with A[i] to set prod to A[0] *...* A[i]
		prod*=A[i];
   }
   
   // Reset prod and use it for the right elements
   prod = 1
   for(i=N-1;i>=0;--i) {
	   //For element i multiply B[i] with A[i+1] * ...* A[N-1] 
	   B[i]*=prod;
       // Multiply with A[i] to set prod to A[i] * ... * A[N-1]
       prod *= A[i];
   }
   }

The presented solution above has a Big O complexity of O(N).
while there are simpler solutions available (ones that would ignore the need to take 0 into account), that simplicity has a price
of complexity, generally running significantly slower.

175, When you should use virtual inheritance?
A, 
While it's ideal to avoid virtual inheritance altogether (you should know how your class is going to be used)
havning a solid understanding of how virtual inheritance works is still important.

so when you have a class (class A) which inherits from 2 parents (B and c), both of which share a parent (class D), as demostracted below.

#include<iostream>
class D {
	public:
	void foo() {
	  std::cout << "Fooooooo" << std::endl;	
	{
};

class C: public D 
{
};

class B: public D
{
};

class A: public B, public C 
{
};

int main(int argc, const char* argv[]) 
{
	A a;
	a.foo();
}

If you don't use virtual inheritance in this case, you will get two copies of D in class A: 
one from B and one from C. To fix this you need to change the declarations of classes C and B to be virtual, as follows:

class C: virtual public D 
{
};

class B: virtual public D 
{
};

176, what is the output of the following code?

#include<iostream>
int main(int argc,cont char *argv[]) 
{
int a[]={1,2,3,4,5,6}
std::cout << (1+3)[a] - a[0] + (a+1)[2]; 
}

A,

The above will output 8, since:
(1+3)[a] is the same as a[1+3] == 5

a[0] == 1

(a+1)[2] is the same as a[3] == 4

This question is testing pointer arithmetic knowledge, and the magic behind square brackets with pointers.
while some might argue that this isn't a valuable question as it appears to only test the capability of reading C constructs,
it's still important for a candidate to be able to work through it mentally; it's not an answer they're expected to know off
the top of their head, but one where they talk about what conclusion they reach and how.

176, What is the output of the following code?
#include<iostream>
class Base {
	virtual void method() 
	{
		std::cout << "from base" << std::endl;
	}
	public:
	virtual ~Base() { method(); }
	virtual baseMethod() { method(); }
};

class A : public Base {
	void method() 
	{ std::cout << "from A" << std::endl; }
    public:
	~A() { method(); }
};

int main(void) 
{
	Base *base = new A;
	base->baseMethod();
	delete base;
	return 0; 
}

A, The above will output
from A
from A
from Base

The important thing to note here is the order of destruction of classes and how Base's method
reverts back to its own implementation once A has been destroyed.

177, How amny times will this loop execute? Explain your answer? 
A,

unsigned char half_limit = 150;
for(unsigned char i=0;i<2*half_limit;++i)
{
	// do something;
}

If you said 300, you would have been correct if i had been declared as an int.
However, since i was declared as an unsigned char, the correct answer is that this code will result in an infinite loop.

Here's why:

The expression 2*half_limit will get promoted to an int (based on C++ conversion rules) and will have a value of 300.
However, since is is an unsigned char, it is rerepresented by an 8 bit value which after reaching 255,
will overflow (so it will go back to 0) and the loop will therefore go on forever.

178, how can you make sure a C++ function can be called as e.g., void foo(int,int)
     but not as any other type like void foo(long, long)?
	 
A, 
void foo(int,int);
void foo(int a,int b) {
	//whatever
}

and delete all others through a template:
template<typename T1,typename T2> void foo(T1 a,T2 b) = delete;
or without the delete keyword
template<class T,class U>
void f(T arg1,U arg2);

template<>
void f(int arg1,int arg2)
{
	//...
}

179, What is the problem with the following code?
class A 
{
	public:
	A() {}
	~A() {}
};
class B: public A
{
	public:
	B():A() {}
	~B(){}
};

int main(void)
{
	A *a = new B();
	delete a;
}

A, 
The behaviour is undefined because A's destructor is not virtual. From the spec.
if the static type of the object to be deleted is different from its dynamic type, the static
shall be a base class of the dynamic type of the object to be deleted and the static type shall have
a virtual destructor or the behaviour is undefined.

180, how can a C function be called in a C++ program?
A.

Using an extern "C" declaration:

// C code
void func(int i)
{
// code
}
void print(int i)
{
// code
}

//C++ code
extern "C"
{
	void func(int i);
	void print(int i);
}

void myfunc(int i)
{
	func(i);
	print(i);
}

181, what will be the output of the following program?
#include<iostrea>
struct A 
{
	int data[2];
	A(int x,int y) : data{x,y} {}
	virtual void f() {}
};

int main(int argc,char **argv)
{
	A a(22,33);
	int *arr = (int *)&a;
	std::cout << arr[2] << std::endl;
	return 0;
}

- In the main function the instance of struct A is treated as an array of integer values.
- On 32-bit architectures the output will be 33, and 64-bit architectures it will be 22.
- This is because there is virtual method f() in the struct which makes compiler insert a vptr pointer that points to vtable
  ( a table of pointers to virtual functions of class or struct.)
- On 32-bit architectures the vptr takes 4 bytes of the struct instance and the rest is the data array, so arr[2] represents access to second eleemnt of the data array.
  which holds value 33.
- On 64-bit architectures the vptr takes 8 bytes so arr[2] represents access to the first eleemnt of the data array, which holds 22.

- This question is testing knowledge of virtual functions internals and knowledge of C++11-specific syntax as well,
  because the constructor of A uses the extended initializer list of the c++11 standard.
  
  g++ question_vptr.cpp -m32 -std=c++11
  g++ question_vptr.cpp -std=c++11
  
  
182, Are you allowed to have a static const member function? Explain your answer?
A, 

- A const member function in one which isn't allowed to modify the members of the object for which it is called.
- A static member function is on which cann't be called for a specific object.
- Thus, the const modifier to a static member function is meaningless, because there is no object associated with the call.
- A more detailed explanation of this reason comes from the c programming language.
- In C, there were no classes and member functions, so all functions were global.
- A member function call is translated to a global function call. 
- Consider a member function like this:

void foo(int i);
A call like this:
obj.foo(10);
is translated to this
foo(&obj,10);

This means that the member function foo has a hidden first argument of type T*:
void foo(T* const this,int i);

If a member function is const, this is of type const T* const this;

void foo(const T* const this,int i);

Static member functions don't have such a hidden argument, so there is no this pointer to tbe const or not.


183, Explain the volatile and mutable keywords?
A,

The volatile keyword informs the compiler that a variable may change without the compiler knowing it.
Variables that are declared as volatile will not be cached by the compiler, and will thus always be read from memory.

The mutable keyword can be used for class member variables. Mutable variables are allowd to change from within const member functions  of the class.


184, C++ supports multiple inheritance, What is the diamond problem that can occur with multiple inheritance? Give an example?
A, 

- It means that we cannot create hybrid inheritance using multiple and hierarchical inheritance.
- Let's consider a simple example. A university has people who are affiliated with it.
- Some are students, some are faculity members, some are administrators, and so on.
- So a simple inheritance scheme might have different types of people in different roles, all of whome inherit from one common "Person" class.
- The person class could an abstract getRole() method which would then be overridden by its subclasses to return the current role type.

- But now that happens if we want to model the role of a Teaching Assitant(TAI)? Typically, a TA is both a grad student and a faculty member.
- This yields the classic diamond of multiple inheritance and the resulting ambiguity regarding the TA's getRole() method.

https://www.toptal.com/c-plus-plus/interview-questions























	
	


  
	 


 
 
 
   

   

















  




	

	
	











       

   
 
 
	

   
   
	
	
    
   
		   
	
   
	  
	  
   