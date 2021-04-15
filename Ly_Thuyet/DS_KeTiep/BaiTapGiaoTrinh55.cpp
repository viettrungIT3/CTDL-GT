#include <bits/stdc++.h>
using namespace std;

#define MAX 100

struct SINHVIEN
{
    char maSV[12];
    char hoDem[20];
    char ten[10];
    int namSinh;
    float diem;
};

struct List
{
    int count;
    SINHVIEN E[MAX];
};

void InitList(List &L)
{
    L.count = -1;
}

int isEmpty(List L)
{
    return L.count == -1;
}

int isFull(List L)
{
    return L.count == MAX - 1;
}

int ADD(List &L, SINHVIEN X)
{
    if (isFull(L))
        return 0;
    else
    {
        L.count++;
        L.E[L.count] = X;
        return 1;
    }
}

void NhapSV(SINHVIEN &X)
{
    cout << "  Nhap ma sv   : ";    fflush(stdin);  gets(X.maSV);
    if ( strcmp(X.maSV, "***") == 0)
        return;
    cout << "  Nhap ho dem  : ";    fflush(stdin);  gets(X.hoDem);
    cout << "  Nhap ten     : ";    fflush(stdin);  gets(X.ten);
    cout << "  Nhap nam sinh: ";    cin>>X.namSinh;
    cout << "  Nhap diem Tk : ";    cin>>X.diem;
}

void NhapDS ( List &L)
{
    InitList(L);
    SINHVIEN X;
    int i = 1;
    do
    {
    cout<<"Nhap sinh vien thu "<<i<<":"<<endl;
    NhapSV(X);
    if (strcmp(X.maSV, "***") == 0)
        return;
    if ( !ADD(L, X) )
        return;
    i++;
    } while (1);
}

void hienThiDS( List L)
{
    cout<<left<<setw(5)<<"STT"<<setw(12)<<"MSV"<<setw(20)<<"Ho dem"<<setw(10)<<"Ten";
    cout<<left<<setw(10)<<"Nam sinh"<<setw(10)<<"Diem TK"<<endl;
    for (int i = 0; i <= L.count; i++)
    {
        cout<<left<<setw(5)<<i+1<<setw(12)<<L.E[i].maSV<<setw(20)<<L.E[i].hoDem<<setw(10)<<L.E[i].ten;
        cout<<left<<setw(10)<<L.E[i].namSinh<<setw(10)<<L.E[i].diem<<endl;
    }
}

//Ham xoa sinh vien thu 3
void Remove3 (List &L)
{
    for (int i = 2; i < L.count; i++)
    {
        L.E[i] = L.E[i+1];
    }
    L.count--;
}

//Them mot sinh vien vao vi tri k vao ds
int Insert( int k, List &L )
{
    int i;
    SINHVIEN X;
    if ( !isFull(L) && k<= L.count + 1 && k >= 1 )
    {
        cout<<"Nhap sinh vien can them: "<<endl;
        NhapSV(X);
        for (int i = L.count; i >= k; i--)
            L.E[i+1] = L.E[i];
        L.count = L.count + 1;
        L.E[k-1] = X;
        return 1;
    } 
    else return 0;
}

int main(int argc, char const *argv[])
{
    List L;
    InitList(L);
    NhapDS(L);
    // Remove3(L);
    // Insert(3, L);
    hienThiDS(L);
    return 0;
}
