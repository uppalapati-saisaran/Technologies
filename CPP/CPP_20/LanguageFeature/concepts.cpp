- concepts are named compile-time predicates which constrain types.

- They take the following form:

	template< template-parameter-list >
	concept concept-name = constraint-expression;
	
    - where constraint-expression evaluates to a constexpr boolean.
	- Constraints should model semantic requirements,such as whether a type is a numeric or hashtable.
	- A compiler error results if a given type does not satisfy the concept it's bound by(i.e., constraint-expression returns false).
	- Because constraints are evaluated at compile time they can provide more meaningful error messages and runtime safety.
	
// 'T' is not limited by any constraints.
template<typename T>
concept always_satisfied = true;

// Limit 'T' to integrals.
template<typename T>
concept integral = std::is_integral_v<T>;

// Limit 'T' to both the integral constraint and signedness.
template<typename T>
concept signed_integral = integral<T> && std::is_signed_v<T>;

//Limit 'T' to both the 'integral' constraint and the negation of the 'signed_integral' constraint.
template<typename T>
concept unsigend_integral = integral<T> && !signed_integral<T>;

There are a variety of syntactic forms for enforcing concepts:

// Forms for function parameters:

// 'T' is a constrained type template parameter.
template<my_concept T>
void f(T v);

// 'T' is a constrained type template parameter.
template<typename T>
	requires my_concept<T>
void f(T v);

// 'T' is a constrained type template parameter.
template<typename T> void f(T v) requires my_concept<T>;

// 'v' is a constrained deduced parameter.
void f(my_concept auto v);

// 'v' is a constrained non-type template parameter.
template<my_concept auto v>
void g();

// Forms for auto-deduced variables:
// 'foo' is a constrained auto-deduced value.
my_concept auto foo = ...;

// Forms for lamdbas:
// 'T' is a constrained type template parameter.
auto f = []<my_concept T> ( T v) {
// .. 
};

// 'T' is a constrained type template parameter.
auto f = []<typename T> requires my_concept<T> ( T v) {
	// ...
}

// 'T' is a constrained type template parameter.
auto f = []<typename T> ( T v) requires my_concept<T> {
	  // ..
};

// 'v' is a constrained deduced parameter.
auto f=[](my_concept auto v) {
	//...
}

// 'v' is a constrained non-type template parameter.
auto g = []<myconcept auto v>() {
	//...
};

- The requires keyword is used either to start a requires clause or a requires expression.

  template<typename T>
	requires my_concept<T> // 'requires' clause
  void f(T);
  
  template<typename T>
  concept callable = requires(T f) { f(); }; // 'requires' expression
  
  template<typename T>
  requires requires(T x) { x + x; } // 'requires' clause and expression on same line.
  T add(T a, T b) {
	  return a + b;
  }
  
- Note that the parameter list in a requires expression is optional. Each requirement in a requires expression are one of the following.
  
1, Simple requirements - asserts that the given expression is valid.

   template<typename T>
   concept callable = requires(T f) { f(); }
   
2, type requirements - denoted by the typename keyword followed by a type name, asserts that the given type name is valid.

	struct foo {
		int foo;
	};
	
	struct bar {
		using value = int;
		value data;
	};
	
	struct baz {
		using value = int;
		value data;
	};
	
	// Using SFINAE, enable if 'T' is a 'baz'
	template<typename T,typename = std::enable_if_t<std::is_same_v<T, baz>>>
	
	
	
   
   
















	