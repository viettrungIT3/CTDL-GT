#include <bits/stdc++.h>
using namespace std;

void InsertSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int t = a[i];
        int j = i - 1;
        while (j >= 0 && t > a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = sizeof(a) / sizeof(a[0]);

    InsertSort( a, n);
    cout << "Mang sau sap xep: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
