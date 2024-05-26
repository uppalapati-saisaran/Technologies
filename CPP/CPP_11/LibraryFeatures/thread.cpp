- The std::thread library provides a standard way to control threads, such as spawing and killing them.

- In the example below, multiple threads are spawned to do different calculations and then the program waits for all of them to finish.

  void foo(bool clause) { /** do something ...*/ }
  
  std::vector<std::thread> threadsVector;
  threadsVector.emplace_back([](() {
   // Lambda function that will be invoked
   });
   
  threadsVector.emplace_back(foo,true); // thread will run foo(true)
  for(auto& thread : threadsVector) {
	thread.join(); // wait for thread to finish 
  }  
