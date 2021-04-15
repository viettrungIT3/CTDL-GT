#include <bits/stdc++.h>
using namespace std;

void SelectSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] > a[m])
                m = j;
        if (m != i)
        {
            int temp = a[i];
            a[i] = a[m];
            a[m] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = sizeof(a) / sizeof(a[0]);

    SelectSort(a, n);
    cout << "Mang sau sap xep: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
