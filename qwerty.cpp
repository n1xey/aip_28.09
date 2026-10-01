#include <iostream>
#include <cstddef>
#include <new>

int main()
{
    long long mIn = 0;
    long long nIn = 0;
    std::cin >> mIn >> nIn;
    if (!std::cin || mIn <= 0 || nIn <= 0)
    {
        return 1;
    }
    size_t m = static_cast<size_t>(mIn);
    size_t n = static_cast<size_t>(nIn);
    return 0;
}
