#include <iostream>
#include <string>

template <int i>
class Loop
{
public:
	template <typename FuncType>
	static inline void run(FuncType func) {
		Loop<i - 1>::run(func);
		func(i);
	}
};

template <>
class Loop<0>
{
public:
	template <typename FuncType>
	static inline void run(FuncType /* func */) { }
};

void doWork(int i)
{
	std::cout << "doWork(" << i << ")" << std::endl;
}

int main()
{
	Loop<3>::run(doWork);
}
