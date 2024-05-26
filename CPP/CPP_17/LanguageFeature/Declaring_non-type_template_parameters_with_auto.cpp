Declaring non-type template parameters with auto

- Following the deduction rules of auto, while respecting the non-type template parameter lsit of allowable types[*],
  template arguments can be deduced from the types of its arguments:
  
  template<auto... seq>
  struct my_integer_sequence {
	// Implementation here....
  };
  
  // Explicitly pass type 'int' as template argument.
  auto seq = std::integer_sequence<int,0,1,2>();
  // Type is deduced to be 'int'
  auto seq2 = my_integer_sequence<0,1,2>();
  
- For example, you cannot use a double as a template paramer type, which also makes this an invalid deduction using auto.


  