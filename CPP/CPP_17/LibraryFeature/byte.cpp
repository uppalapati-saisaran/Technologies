- The new std::byte provides a standard way of representing data as a byte.

- Benefits of using std::byte over char or unsigned char is that it is not a character type, and is also not an arithmetic type;
  while the only operator overloads available are bitwise operations.
  
  std::byte a {0};
  std::byte b { 0xFF };
  int i = std::to_integer<int>(b); // 0xFF
  std::byte c = a & b;
  int j = std::to_integer<int>(c); // 0 
  
  