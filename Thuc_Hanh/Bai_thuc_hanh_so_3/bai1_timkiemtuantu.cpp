#include <bits/stdc++.h>
using namespace std;

int Sequence_Search( int a[], int n, int k )
{
    int i = 0;
    while ( i < n && a[i] != k)
    {
        i++;
    }
    if ( i < n ) 
        return i;
    else 
        return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout<<"n = "<<n<<endl;
    int index = Sequence_Search( arr, n, 94);
    if ( index == -1)
        cout<<"Khong co gia tri 94 trong day."<<endl;
    else
        cout<<"Gia tri 94 o vi tri thu "<< index + 1 <<" trong day."<<endl;
    int index2 = Sequence_Search( arr, n, 55);
    if ( index2 == -1)
        cout<<"Khong co gia tri 55 trong day."<<endl;
    else
        cout<<"Gia tri 55 o vi tri thu "<< index2 + 1 <<" trong day."<<endl;
    return 0;
}
