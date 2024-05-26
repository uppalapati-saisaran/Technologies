- This allows creating lambda captures initialized with arbitrary expressions.

- The name given to the captured value does not need to be related to any variables
  in the enclosing scopes and introduces a new name inside the lambda body.
  
 - The initializing expression is evaluated when the lambda is created.
 
 ********************************************************************
 
   int factory(int i) { return i * 10 }
   auto f = [ x = factory(2)] { return x; }; // returns 20
   
*********************************************************************

**********************************************************************
   
   auto generator = [ x = 0 ] () mutable {
   // this would not compile without 'mutable' as we are modifying
   // x on each call 
   return x++;
   }
   
	auto a = generator(); // == 0
	auto b = generator(); // == 1
	auto c = generator(); // == 2

- Because it is now possible to move values into a lambda that could previously
  be only captured by copy or reference we can now capture move-only types 
  in a lambda by value.
  
**********************************************************************
  
- Note that in the below example the p in the capture-list of task2 on the 
  left-hand-side of = is a new variable private to the lamda body and does
  not refer to the original p.
  
  auto p = std::make_unique<int>(1)
  
  auto task1 = [=]{*p=5;}; //ERROR: std::unique_ptr cannot be copied
  // vs
  auto task2 = [ p = std::move(p)] { *p = 5; };
  // OK: p is move-constructed into the closure object
  // the original p is empty after task2 is created.
  
  *******************************************************************************
  
- Using this reference-captures can have different names than the 
  referenced variable.
  
  auto x = 1;
  auto f = [&r = x,x = x * 10 ] {
	  ++r;
	  return r+x;
  }
  f(); // sets x to 2 and returns 12
  
  
  
  
  
  
  
   
   