Synchorized buffered outputstream

- Buffers output operations for the wrapped output stream ensuring synchronization(i.e. no interleaving of output).

  std::osyncstream{std::cout} << "The value of x is:" << x << std::endl;
  
  