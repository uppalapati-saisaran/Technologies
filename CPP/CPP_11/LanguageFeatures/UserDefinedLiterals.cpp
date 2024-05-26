User defined literals

- User-defined literals allow you to extend the language and 
  add your own syntax.
  
- To create a literal, define a T operator " " X(...) { ... }
  function that returns a type T, with a name X.
  
- Note that the name of this function defines the name of the literal.

- Any literal names not starting with an underscore are reserved and
  won't be invoked.
  
- There are rules on what parameters a user-defined literal function should
  accept, according to what type the literl is called on.
  
- Converting Celsius to Fahrenheit:

  // 'unsigned long long' parameter required.
  long long operator " " _celsius(unsigned long long tempCelsius) 
  {
	return std::llround(tempCelsius * 1.8 + 32)
  }
  24_celsius
  
- String to integer conversion:

  // 'const char*' and 'std::size_t' required
  int operator " " _int(const char* str,std::size_t)
  {
   return std::stoi(str);
  }
  
  "123"_int;  // == 123, with type 'int' 


 