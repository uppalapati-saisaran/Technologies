Splicing for maps and sets

- Moving nodes and merging containers without the overload of expensive copies, moves, or heap allocation/deallocations.

(a)  Moving elements from one map to another:

  std::map<int, string> src {{1,"one"},{2,"two"},{3,"buckle m shoe"}};
  std::map<int, string> dst {{3,"three"}};
  
  dst.insert(src.extract(src.find(1)))); // Cheap remove and insert of {1,"one"} from 'src' to 'dst'
  dst.insert(src.extract(2)); // Cheap remove and insert of {2, "two"} from 'src' to 'dst'
  
  // dst == {{1,"one"}, {2,"two"},{3,"three"}} 
  
(b) Inserting an entire set:

	std::set<int> src {1,3,5};
	std::set<int> dst {2,4,5};
	dst.merge(src);
	// src == {5}
	// dst == {1,2,3,4,5}
	
(c) Inserting elements with outlive the container:

	auto elementFactory() {
		std::set<...> s;
		s.emplace(...);
		return s.extract(s.begin());
	}
	s2.insert(elementFactory());
	
(d) Changing the key of a map element:

	std::map<int,string> m {{1,"one"},{2,"two"},{3,"three"}};
	auto e = m.extract(2);
	e.key() = 4;
	m.insert(std::move(e));
	// m == { {1,"one"}, { 3, "three" }, {4,"two"}}
	
	

	

