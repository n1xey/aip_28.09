#include <iostream>
#include <cstddef>
#include <new>

void rmMtx(int ** mtx, size_t m)
{
    for (size_t i = 0; i < m; ++i)
    {
        delete[] mtx[i];
    }
    delete[] mtx;
}

int ** makeMtx(size_t m, size_t n)
{
    int ** mtxR = new int *[m];
    for (size_t i = 0; i < m; ++i)
    {
        mtxR[i] = new int[n];
    }
    return mtxR;
}

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
