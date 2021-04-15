#include <bits/stdc++.h>
using namespace std;

struct SINHVIEN
{
    char maSV[12];
    char hoDem[20];
    char ten[10];
    int namSinh;
    float diem;
};

struct Node
{
    SINHVIEN infor;
    Node *next;
};

typedef Node *TRO;

void Initialize ( TRO &L)
{
    L = NULL;
}

int isEmpty(TRO L)
{
    return L == NULL;
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

void NhapDS ( TRO &L)
{
    Initialize(L);
    SINHVIEN X;
    TRO Q, P;
    char tieptuc[1];
    int i = 1;
    Initialize(L);
    do
    {
    cout<<"Nhap sinh vien thu "<<i<<":"<<endl;
    NhapSV(X);
    if (strcmp(X.maSV, "***") == 0)
        return;
    P = new (Node);
    P->infor = X;
    P->next = NULL;
    if ( L == NULL )
        L = P;
    else
        Q->next = P;
    Q = P;
    i++;
    cout<<"Co nhap nua khong(c/k)?:";   cin>>tieptuc;
    } while (strcmp(tieptuc, "k") != 0);
}

void hienThiDS( TRO L)
{
    if ( L == NULL)
    {
        cout<<"Danh sach rong"<<endl;
        return;
    }
    else
    {
        cout<<left<<setw(5)<<"STT"<<setw(12)<<"MSV"<<setw(20)<<"Ho dem"<<setw(10)<<"Ten";
        cout<<left<<setw(10)<<"Nam sinh"<<setw(10)<<"Diem TK"<<endl;
        TRO Q = L;
        int i = 0;
        while ( Q != NULL)
        {
            SINHVIEN X = Q->infor;
            cout<<left<<setw(5)<<i+1<<setw(12)<<X.maSV<<setw(20)<<X.hoDem<<setw(10)<<X.ten;
            cout<<left<<setw(10)<<X.namSinh<<setw(10)<<X.diem<<endl;
            Q = Q->next;
            i++;
        }
    }
}


int main(int argc, char const *argv[])
{
    TRO L;
    Initialize(L);
    NhapDS(L);
    hienThiDS(L);
    return 0;
}
