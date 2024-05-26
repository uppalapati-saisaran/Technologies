- A span is a view(i.e., non-owning) of a container providing bounds-checked access to a contigous group of elements.

- Since views do not own their elements they are cheap to construct and copy -- a simplified way to think about views is they are 
  holding references to their data.
  
- As opposed to maintaining a pointer/iterator and length field, a span wraps both of those up in a single object.

- Spans can be dynamically-sized or fixe-sized. Fixed-size spans benefit from bounds-checking.

- Span doesn't propogate const so to construct a read-only span use std::span<const T>.

- Example: using a dynamically-sized span to print integers from various containers.

  void print_ints(std::span<const int> ints) {
	for(const auto n : ints) {
	std::cout << n << std::endl;
	}
  }
  
  print_ints(std::vector {1,2,3});
  print_ints(std::array<int,5>{1,2,3,4,5});
  
  int a[10]={0};
  print_ints(a);
  // etc
  
- Example: a statically-sized span will fail to compile for continers that doesn't match the extent of the span.

  void print_three_ints(std::span<const int,3> ints) {
	  for(const auto n : ints) {
		  std::cout << n << std::endl;
	  }
  }
  
  print_three_ints(std::vector{1,2,3}); // ERROR
  print_three_ints(std::array<int,5>{1,2,3,4,5}); // ERROR
  int a[10]={0}
  print_three_ints(a); // ERROR
  
  std::array<int,3> b = {1,2,3};
  print_three_ints(b); // OK
  
  // You can construct a span manually if required
  std::vector c{1,2,3};
  print_three_ints(std::span<const int,3>{c.data(),3}); // OK: set pointer and length field
  print_three_ints(std::span<const int,3>{c.cbegin(),c.cend()}); // OK: use iterator pairs.
  
  