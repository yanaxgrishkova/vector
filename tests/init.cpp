#include <vector.hpp>
#include <catch.hpp>

SCENARIO("init", "[init]") {
	vector_t vector;
	REQUIRE(vector.size() == 0);
	REQUIRE(vector.capacity() == 0);
}

SCENARIO("init with params", "[init param]") {
	vector_t vector(1);
	REQUIRE(vector.size() == 1);
	REQUIRE(vector.capacity() == 1);
	REQUIRE(vector[0] == 1);
}

SCENARIO("init object", "[init object]") {
	vector_t v(1);
	vector_t c(v);
	REQUIRE(c.size() == v.size());
	REQUIRE(c.capacity() == v.capacity());
	REQUIRE(c[0] == v[0]);
}

SCENARIO("operator =", "[op=]") {
	vector_t v1(1);
	vector_t v2 = v1;
	REQUIRE(v2.size() == v1.size());
	REQUIRE(v2.capacity() == v1.capacity());
	REQUIRE(v2[0] == v1[0]);
}

SCENARIO("operator []", "[op[]]")
{
	vector_t vector(3);
	REQUIRE(vector.size() == 3);
	REQUIRE(vector.capacity() == 3);
	for (int i = 0; i < vector.size(); i++)
	{
		REQUIRE(vector[i] == 0);
	}
}

SCENARIO("push", "[push]")
{
	vector_t vector(3);

	REQUIRE(vector.size() == 3);
	REQUIRE(vector.capacity() == 3);

	vector.push_back(4);
	vector.push_back(19);
	vector.push_back(0);

	REQUIRE(vector.size() == 6);
	REQUIRE(vector.capacity() == 6);

	for (int i = 0; i < 3; i++)
	{
		REQUIRE(vector[i] == 0);
	}
	REQUIRE(vector[3] == 4);
	REQUIRE(vector[4] == 19);
	REQUIRE(vector[5] == 0);
}
