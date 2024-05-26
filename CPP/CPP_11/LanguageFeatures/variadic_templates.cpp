
- The ... syntax creates a parameter packs or expands one.

- A template parameter pack is a template parameter that accepts zero or more template arguments (non types, types, or templates). 

- A template with at least one paramter pack is called a variadic template. 

template<typename... T>
struct arity {
	constexpr static int value = sizeof...(T);
};
static_assert(arity<>::value == 0;
static_assert(arity<char, short, int>::value == 3);

- An interesting use for this is creating an initializer list from a parameter pack in order to iterate over variadic function arguments.

template<typename First, typename... Args>
auto sum(const First first,const Args... args) -> decltype(first) {
	const auto values = {first, args...};
	return std::accumulate(values.begin(),values.end(),First{0});
	
sum(1,2,3,4,5); // 15
sum(1,2,3); // 6
sum(1.5,2.0,3.7);


