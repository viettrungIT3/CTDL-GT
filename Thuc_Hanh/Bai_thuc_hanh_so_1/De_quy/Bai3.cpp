#include <bits/stdc++.h>
using namespace std;

int Gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return Gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    int a, b;
    // cout<<"Nhap lan luot a va b ";  cin>>a>>b;
    a = 10;
    b = 24;
    cout << "GCD( " << a << ", " << b << ") = " << __gcd(a, b) << endl;
    cout << "GCD( " << a << ", " << b << ") = " << Gcd(a, b) << endl;
    return 0;
}
