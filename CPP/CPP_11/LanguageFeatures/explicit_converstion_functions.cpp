Explicit converstion functions:

- Conversion functions can now be made explicit using the explicit specifier.

struct A 
{
operator bool() const { return true; }
};

struct B
{
explicit operator bool() const { return true; }
};

A a;
if(a);  // OK calls A::operator bool()
bool ba = a; // Ok copy-initialization selects A::operator bool() 

B b;
if(b); // OK calls B::operator bool()
bool bb = b; // error copy-initialization does not consider B:operator bool()

