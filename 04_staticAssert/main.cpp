#include <type_traits>
#include <concepts>

using namespace std;

static_assert(sizeof(void*) == 8, "Requires 64-bit compilation.");

template <integral T>
void foo(const T& t)
{
	static_assert(is_integral_v<T>, "T should be an integral type.");
}

int main()
{
	foo(123);
	return 0;
}