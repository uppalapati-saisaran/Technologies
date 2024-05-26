bit_cast

- A safter way to reinterpret an object from one type to another.

 float f = 123.0;
 int i = std::bit_cast<int>(f);
 
 