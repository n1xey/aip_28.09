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
    int ** mtxR = new int *[m]();
    try
    {
        for (size_t i = 0; i < m; ++i)
        {
            mtxR[i] = new int[n];
        }
    }
    catch (const std::bad_alloc &)
    {
        rmMtx(mtxR, m);
        throw;
    }
    return mtxR;
}

int ** transpose(int ** mtx, size_t m, size_t n)
{
    int ** res = makeMtx(n, m);
    for (size_t i = 0; i < m; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            res[j][i] = mtx[i][j];
        }
    }
    return res;
}

void printMtx(int ** mtx, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            if (j > 0)
            {
                std::cout << ' ';
            }
            std::cout << mtx[i][j];
        }
        std::cout << '\n';
    }
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
    int ** mtx = nullptr;
    try
    {
        mtx = makeMtx(m, n);
    }
    catch (const std::bad_alloc &)
    {
        return 2;
    }
    for (size_t i = 0; i < m; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            if (!(std::cin >> mtx[i][j]))
            {
                rmMtx(mtx, m);
                return 1;
            }
        }
    }
    int ** mtxT = nullptr;
    try
    {
        mtxT = transpose(mtx, m, n);
    }
    catch (const std::bad_alloc &)
    {
        rmMtx(mtx, m);
        return 2;
    }
    rmMtx(mtx, m);
    mtx = mtxT;
    printMtx(mtx, n, m);
    rmMtx(mtx, n);
    return 0;
}
