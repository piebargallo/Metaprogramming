#include <iostream>
#include <string>
#include <tuple>

template <typename TupleType, int n>
class TuplePrint
{
public:
	TuplePrint(const TupleType& t) {
		TuplePrint<TupleType, n - 1> tp{ t };
		std::cout << get<n - 1>(t) << std::endl;
	}
};

template <typename TupleType>
class TuplePrint<TupleType, 0>
{
public:
	TuplePrint(const TupleType&) { }
};

int main()
{
	using MyTuple = std::tuple<int, std::string, bool>;
	MyTuple t1{ 16, "Test", true };
	TuplePrint<MyTuple, std::tuple_size<MyTuple>::value> tp{ t1 };
}
