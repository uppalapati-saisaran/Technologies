Depreciate implicit capture of this:

- Implicitly capturing this in a lambda capture using [=] is now deprecated; 
  prefer capturing explicitly using [=,this] or [=,*this].
  
- 
  struct int_value {
  int n=0;
  auto getter_fn() {
    // BAD:
	// return [=]() { return n; };
	
    // GOOD:
	return [=.*this]() { return n; };
	}
	};
	
	