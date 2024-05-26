- Invoke a callable object with a tuple of arguments.

	auto add = [](int x,int y) {
		return x+y;
	};
	std::apply(add, std::make_tuple(1,2)) 
	
	
	
	
   