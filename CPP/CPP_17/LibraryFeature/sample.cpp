std::sample :

- Samples n elements in the given sequence (without replacement) where every element has an equal chance of being selected.

  const std::string ALLOWED_CHARS = "a..zA..Z0..2";
  std::string guid;
  
  //Sample 5 characters from ALLOWED_CHARS
  std::sample(ALLOWED_CHARS.begin(),ALLOWED_CHARS.end(),std::back_inserter(guid),5,std::mt19937{ std::random_device{}() });
  
  std::cout << guid;  //e.g. G1fW2
  
  