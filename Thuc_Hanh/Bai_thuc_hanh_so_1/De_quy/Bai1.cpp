#include <bits/stdc++.h>
using namespace std;

long Fibonaci( int n) {
    if ( n <= 2 )
    {
        return 1;
    }
    else
    {
        return Fibonaci( n-1) + Fibonaci(n-2);
    }
    
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Nhap n = ";
    cin>>n;
    cout<<"so Fibonaci thu "<<n<<" la: "<<Fibonaci(n)<<endl;
    cout<<"Day n so fibonaci: ";
    for (int i = 1; i <= n; i++)
    {
        cout<<Fibonaci(i)<<" ";
    }
    
    return 0;
}
