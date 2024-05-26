- Coroutines are special functios that can have their execution suspended and resumed.

- To define a coroutine, the co_return, co_wait, or co_yield keywords must be present in the function's body.

- C++ 20's coroutines are stakeless; unless optimized out by the compiler, their state is allocated on the heap.

- An example of a coroutine is a generator function, which yields (i.e., generates) a value at each invocation.

 generator<int> range(int start,int end) {
	 while(start < end) {
		 co_yield start;
		 start++;
	 }
	 // Implicit co_return at the end of this function
	 // co_return;
 }
 
 for(int n : range(0,10)) {
	 std::cout << n << std::endl;
 }
 
	 The above range generator function generates values starting at start until and end (exclusive), with each iteration
	 step yielding the current value stored in start. 
	 The generator maintains its state across each invocation of range (in this case, the invocation is for each iteratorn in the for loop).
	 co_yield takes the given expression, yields(i.e. returns) its value, and suspends the coroutine at that point. Upon resuming, execution continues after the co_yield.
 
 
 - Another example of a coroutine is a task, which is an asynchronous computation that is executed when the task is awaited.
 
  task<void> echo(socket s) {
	  for(;;) {
		  auto data = co_wait s.async_read();
		  co_await async_write(s,data);
	  }
	  
	  //Implicit co_retrun at the end of this function
	  //co_return;
  }
  
	This keyword takes an expression and suspends execution if the thing you're waiting on is not ready, otherwise you continue execution.
	(Note that under the hood, co_yield uses co_await.)
	
- Using a task to lazily evaluate a value:
	
	task<int> calculate_meaning_of_life() {
		co_return 42;
	}
	
	auto meaning_of_life = calculate_meaning_of_life();
	// ...
	co_await meaning_of_life; // == 42
	
	
- Since the generator and task classes are not provided by the standard library yet, I used the cppcore library to compile these examples.


		  
 
 
 
 
	 