#include <iostream>

using namespace std;

int dem(int a[], int n, int x)
{
    if (n == -1)
        return 0;
    else if (a[n] == x)
        return dem(a, n - 1, x) + 1;
    return dem(a, n - 1, x);
}

void Remove( List &L, int k)
{
    for (int i = k-1; i < L.count; i++)
    {
        L.E[i] = L.E[i+1];
    }
    
}

int main()
{
    int a[] = {1, 1, 2, 3, 4, 5, 1, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);
    cout << dem(a, n, 1);
    return 0;
}
