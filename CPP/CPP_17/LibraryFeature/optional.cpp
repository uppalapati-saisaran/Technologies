- The class template std::optional manages an optional contained value, i.e., a value that 
  may or may be present.
 
- A common use case for optional is the return value of a function that may fail.
 

 std::optional<std::string> create(bool b)
 {
	if(b) {
	return "GodZilla";
	} else {
	return {};
	}
 }
 
 create(false).value_or("empty"); // == "empty" 
 create(true).value(); // == "GodZilla" 
 
 //optional-returning factory functions are usable as conditions of while and if
 if(auto str = create(true)) {
 // ...
 } 