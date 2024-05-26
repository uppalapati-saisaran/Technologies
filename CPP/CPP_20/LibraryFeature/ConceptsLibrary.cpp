Concepts library

- Concepts are also provided by the standard library for building more complicated complicated concepts.

- Some of these include:

1, Core language concepts: 

a, same_as - specfies two types are the same.
b, derived_from - specifies that a type is derived from another type.
c, convertible_to - specifies that a type is implicitly convertible to another type.
d, common_with - specifies that two types share a common type.
e, integral - specifies that a type is an integral type.
f. default_constructible - specifies that an object of a type can be default-constructed.

2, Comparsion concepts:

a, boolean - specifies that a type can be used in Boolean contexts.
b, equality_comparable - specifies that operator== is an equivalence relation.

3, Object concepts:

a, movable - specifies that an object of a type can be moved and swapped.
b, copyable - specifies that an object of a type can be copied, moved and swapped.
c, semi regular - specifies that an object of a type can be copied,moved,swapped and default constructed.
d, regular - specifies that a type is regular that is it is both semiregular and equality_comparable.

4, callable concepts :

a, invocable - specifies that a callable type can be invoked with a given set of argument types.
b, predicate - specifies that a callable type is a Boolean predicate.


