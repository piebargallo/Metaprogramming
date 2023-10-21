#include <cstddef>
#include <iostream>
#include <utility>
#include <string>
#include <tuple>

template <typename Tuple, size_t... Indices>
void tuplePrintHelper(const Tuple& t, std::index_sequence<Indices...>)
{
	((std::cout << std::get<Indices>(t) << std::endl), ...);
}

template <typename... Args>
void tuplePrint(const std::tuple<Args...>& t)
{
	tuplePrintHelper(t, std::index_sequence_for<Args...>());
}

int main()
{
	std::tuple t1{ 167, "Testing", false, 2.3 };
	tuplePrint(t1);
}