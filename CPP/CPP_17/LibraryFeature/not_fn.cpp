std::not_fn 

- Utility function that returns the negation of the result of the given function.

  const std::ostream_iterator<int> ostream_it { std::cout, " "};
  const auto is_even = [](const auto n) { return n%2 == 0; };
  std::vector<int> v{0,1,2,3,4};
  
  //Print all even numbers
  std::copy_if(std::cbegin(v),std::cend(v),ostream_it, is_even); // 0 2 4
  // Print all odd (not even) numbers
  std::copy_if(std::cbegin(v),std::cend(v),ostream_it, std::not_fn(is_even)); // 1 3
  
  
  