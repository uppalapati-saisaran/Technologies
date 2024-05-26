- Fold over a given range of elements.

- conceptually similar to std::accumulate, but std::reduce will perform the fold in parallel.

- Due to the fold being done in parallel, if you specify a binary operation,it is required to ba associative and cummulative.

- A given binary operation also should not change any element or invalidate any iterators within the range.

- The default binary operation is std::plus with an initial value of 0.

  const std::array<int,3> a {1,2,3};
  std::reduce(std::cbegin(a),std::cend(a)); // == 0
  // Using a custom binary op:
  std::reduce(std::cbegin(a),std::cend(a),1,std::multiplies<>{}); // == 6
  
- Additionally you can specify transformations for reducers:
  
  std::transform_reduce(std::cbegin(a),std::cend(a),0,std::plus<>{}, times_ten); // == 60 
  
  const std::array<int,3> b{1,2,3};
  const auto product_times_ten = [](const auto a, const auto b) { return a*b*10; }
  
  std::transform_reduce(std::cbegin(a),std::cend(a),std::cbegin(b),0,std::plus<>{},product_times_ten)
  
  
  
  
  