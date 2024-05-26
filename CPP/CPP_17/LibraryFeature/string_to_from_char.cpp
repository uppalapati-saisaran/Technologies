String conversion to/from numbers

- Convert integrals and floats to a string or vice versa.

- Conversions are non-throwing, do not allocate, and are more secure than the equivalents from the C standard library.

- Users are responsiable for allocating enough storage required for std::to_chars, or the function will fail by setting
  the error code object in its return value.
  
- These functions allow you to optionally pass a base (defaults to base-10) or a format specifier for floating type input.

(01) std::to_chars returns a (non-const) char pointer which is one-past-the-end of the string that the function 
     wrote to inside the given buffer, and an error code object.
	 
(02) std::from_chars returns a const char pointer which on success is equal to the end pointer passed to the function,
     and an error code object.
	 
- Both error code objects returned from these functions are equal to the default-initialized error code object on success.

- Convert the number 123 to a std::string

	const int n = 123
	
	//can use any container, string, array, etc 
	std::string str;
	str.resize(3); // hold enough storage for each digit of 'n'
	
	const auto [ ptr, ec ] = std::to_chars(str.data(),str.data()+str.size(),n);
	
	if(ec == std::errc{}) {	std::cout << str << std::endl; 	}
	else
	{ /* handle failure */ 
	
- Convert from a std::string with value "123" to an integer
  const std::string str { "123" }
  int n;
  
  const auto[ ptr,ec ] = std::from_chars(str.data(),str.data()+str.size(),n);
  
  if (ec == std::errc()} { std::cout << n << std::endl; }  // 123
  else { /* handle failure */ }
  
  