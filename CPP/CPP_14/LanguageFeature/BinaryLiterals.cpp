- Binary literals provide a convenient way to represent a base-2 number.

- It is possible to separate digits with '.

0b110 // == 6
0b1111'1111 // == 255

- The standard library supports binary literals as well.
  In otherwords:
  (01) Do iostream objects recognize the std::bin manipulator?
  (02) Will fstream objects know how to format binary literals when writing them to files?
  (03) Will stringstream objects know how to parse a string containing 0b1010, for example?
  - The answer to all these questions is "NO". 

*****************************************************************************

// C++ program to illustrate the hexadecimal and octal number
// using literals
#include<iostream>
using namespace std;

//Driver Code
int main() {
    //Hexadecimal number with prefix '0x'
    int h = 0x13ac;
    
    //Octal number with prefix '0'
    int o = 0117;
    
    // Print the number of the hexadecmial form
    cout << h << endl;
    
    //Print the number of the octal form
    cout << o << endl;
    
    return 0;
}


Output:

5036
79 

*******************************************************************************

// C++ program to illustrate the 
// binary number using literals
#include<iostream>
using namespace std;

//Driver Code
int main()
{
    //Binary literal with prefix '0b'
    int a = 0b00001111;
    
    cout << a << '\n';
    
    //Binary literal with prefix '0B'
    int b = 0B00001111;
    cout << b;
    
    return 0;
}

Output:

15
15 

*******************************************************************************

//C++ 14
int x = 0b11111100;
if(var==0b101)
   //...
switch(binliteral)
{
	case 0B100:
			// ...
			break;
	case 0B101:
			// ...
			break;
	//...
}

*******************************************************************************

- The type of a binary literal is int. You can use a binary literal wherever a constant
  integer value is excepted.
  
  enum class Bits //C++ 14
  {
	  CLEAR = 0b0;
	  SET = 0b1
  };
  
  
*********************************************************************************

- The single quotation mark as a digit separator:

//C++ 14. All of the following variables equal 1048576
long decval=1'048'576;  // groups of three digits
long hexval=0x10'0000; // four digits
long octval=00'04'00'00'00' // two digits
long binval=0b100'000000'000000'00000; // six digits

******************************************************************************** 



