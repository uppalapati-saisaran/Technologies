std::make_shared supports_arrays

auto p = std:make_shared<int[]>(5); //pointer to 'int[5]'
or
auto p = std::make_shared<int[5]>();  // pointer to 'int[5]'

