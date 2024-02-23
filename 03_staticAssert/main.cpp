#include <iostream>

template <typename T>
void print_size() {
    static_assert(sizeof(T) >= 4, "Type size must be at least 4 bytes");
    std::cout << "Size of type T: " << sizeof(T) << " bytes\n";
}

int main() {
    print_size<int>(); // OK
    // print_size<short>(); // Error: Type size must be at least 4 bytes
    return 0;
}
