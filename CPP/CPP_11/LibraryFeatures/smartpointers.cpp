- C++ 11 introduces new smart pointer std::unique_ptr,std::shared_ptr,std:weak_ptr

- C++ 17 becomes deprecated and then eventually removed in C++ 17.

- std::unique_ptr is a non-copytable, movable pointer that manages its own heap-allocated memory. 

- Note: Prefer using the std::make_X helper functions as opposed to using constructors. std::make_unique and std::make_shared 

*****************************************************************************************

 std::unique_ptr<Foo> p1 { new Foo{} ); // 'p1' owns 'Foo'
 if(p1) {
	 p1->bar();
 }
 
 {
	 std::unique_ptr<Foo> p2 {std::move(p1)}; // Now 'p2' owns 'Foo'
	 f(*p2);
	 
	 p1=std::move(p2); // Ownership returns to 'p1' -- 'p2' gets destroyed
 }
 
 if(p1) {
	 p1->bar();
 }
 // 'Foo' instance is destroyed when 'p1' goes out of scope. 
 
 
***************************************************************************************
 
 
 
	 
	 
	 
 