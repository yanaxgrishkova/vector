#include <vector.hpp>
#include <catch.hpp>

SCENARIO("default constructor") {
	vector_t vector;
	REQUIRE(vector.size() == 0);
	REQUIRE(vector.capacity() == 0);
}

SCENARIO("constructor with params") {
	vector_t vector(1);
	REQUIRE(vector.size() == 1);
}

SCENARIO("copy constructor") {
	vector_t vector(1);
	vector_t copy(vector);
	REQUIRE(copy.size() == 1);
}

SCENARIO("operator =") {
	vector_t v1(1); 
	vector_t v2=v1;
	REQUIRE(v2==v1);
}
