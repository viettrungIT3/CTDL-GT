#include <bits/stdc++.h>
using namespace std;

void QuickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int mid = (left + right) / 2;
        int t = a[mid];
        do
        {
            while (a[i] < t)
                i++;
            while (a[j] > t)
                j--;
            if (i <= j)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
        } while (i <= j);
        QuickSort(a, left, j);
        QuickSort(a, i, right);
    }
}

// void quickSort(int x[], int left, int right)
// {
//     if (left < right)
//     {
//         int k = (left + right) / 2;
//         int t = x[k];
//         int i = left;
//         int j = right;
//         do
//         {
//             while (x[i] < t)
//                 i = i + 1;
//             while (x[j] > t)
//                 j = j - 1;
//             if (i <= j)
//             {
//                 int tg = x[i];
//                 x[i] = x[j];
//                 x[j] = tg;
//                 i = i + 1;
//                 j = j - 1;
//             }
//         } while (i <= j);
//         quickSort(x, left, j);
//         quickSort(x, i, right);
//     }
// }
// // 
int main(int argc, char const *argv[])
{
    int a[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = sizeof(a) / sizeof(a[0]);
    QuickSort(a, 0, n-1);
    // quickSort(a, 0, n - 1);
    cout << "Display array after sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
