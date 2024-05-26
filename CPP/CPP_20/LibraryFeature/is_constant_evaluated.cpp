std::is_constant_evaluated 

- Predicate function which is truthy when it is called in a compile-time context.

constexpr bool is_compile_time(); // true
bool b = is_compile_time(); // false


