Structured bindings :

- A proposal for de-structuring initialization, that would allow writing auto [x,y,z] = expr; 
  where the type of expr was a tuple-like object, whose elements would be bound to the variables x,y, and z (which this contruct declares).
  
- Tuple-like objects include std::tuple, std::pair, std::array and aggregate structures.

  using Coordinate = std::pair<int,int>;
  Coordinate origin() {
	return Coordinate{0,0};
  }
  
  const auto [x,y ] = origin();
  x; // == 0
  y; // == 0
  
  std::unordered_map<std::string,int> mapping {
  {"a",1},
  {"b",2},
  {"c",3}
  };
  // Destructive by reference
  for (const auto&[key,value] : mapping) {
    // Do something with key and value
  }
  