#include <bits/stdc++.h>
using namespace std;

void BubleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j] > a[j - 1])
            {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
}

int main(int argc, char const *argv[])
{
    int a[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = sizeof(a) / sizeof(a[0]);

    BubleSort( a, n);
    cout<<"Mang sau sap xep: ";
    for ( int i = 0; i <n; i++)
        cout<<a[i]<<" ";
    return 0;
}
