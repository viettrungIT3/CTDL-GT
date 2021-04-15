#include <bits/stdc++.h>
using namespace std;

#define MAX 100
//Khai báo cấu trúc dl của ds
struct SINHVIEN
{
    char maSV[10];
    char hoDem[20];
    char ten[10];
    int namSinh;
    float diem;
};

struct Lish
{
    int count;
    SINHVIEN E[MAX];
};

//Khởi tạo ds rỗng
void Initialize(Lish &L)
{
    L.count = -1;
}

//Kiểm tra ds đầy
int isFull(Lish L)
{
    return L.count == MAX - 1;
}

//Kiểm tra ds rỗng
int isEmpty(Lish L)
{
    return L.count == -1;
}

//Thêm SV vào cuối ds
int addSV(Lish &L, SINHVIEN X)
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

//Nhập thông tin SV
void inputSV(SINHVIEN &sv)
{
    cout << "\tNhap ma SV    : ";
    fflush(stdin);
    gets(sv.maSV);
    if (strcmp(sv.maSV, "***") == 0)
        return;
    cout << "\tNhap ho dem   : ";
    fflush(stdin);
    gets(sv.hoDem);
    cout << "\tNhap ten SV   : ";
    fflush(stdin);
    gets(sv.ten);
    cout << "\tNhap nam Sinh : ";
    cin >> sv.namSinh;
    cout << "\tNhap diem TK  : ";
    cin >> sv.diem;
}

//Nhập ds SV
void inputLish(Lish &L)
{
    Initialize(L);
    int i = 1;
    SINHVIEN x;
    do
    {
        cout << "Nhap sinh vien thu " << i << ": " << endl;
        inputSV(x);
        if (strcmp(x.maSV, "***") == 0)
            return;
        if (!addSV(L, x))
            return;
        i++;
    } while (1);
}

//Hiên thị ds
void outputLish(Lish L)
{
    cout << left << setw(5) << "STT" << setw(10) << "maSV" << setw(20) << "hoDem"
         << setw(10) << "ten" << setw(10) << "namSinh" << setw(5) << "diem" << endl;
    for (int i = i; i <= L.count; i++)
    {
        cout << left << setw(5) << i + 1 << setw(10) << L.E[i].maSV << setw(20) << L.E[i].hoDem
             << setw(10) << L.E[i].ten << setw(10) << L.E[i].namSinh << setw(5) << L.E[i].diem << endl;
    }
}

//Xóa sinh viên đầu tiên trong khỏi ds
void delete_first(Lish &L)
{
    if (isEmpty(L))
        return;
    for (int i = 1; i <= L.count; i++)
    {
        L.E[i - 1] = L.E[i];
    }
    L.count--;
}

//Tim index sinh vien theo maSV
int Search(Lish L, char *ma)
{
    int i = 0;
    while (i <= L.count && strcmp(L.E[i].maSV, ma) != 0)
        i++;
    if (i <= L.count)
        return i + 1;
    else
        return 0;
}

//Hàm xóa sv ra khỏi ds
void Remove(Lish &L, int k)
{
    for (int i = k - 1; i < L.count; i++)
        L.E[i] = L.E[i + 1];
    L.count--;
}

//Xóa sinh viên có ma 8089
int Delete_sv8089(Lish &L)
{
    int k = Search(L, "sv8089");
    if (k == 0)
        return 0;
    Remove(L, k);
    return 1;
}

//Bo sung sinh sinh vien vao vi tri k
int Insert(Lish &L, int k)
{
    int i;
    SINHVIEN x;
    if (!isFull(L) && k <= L.count + 1 && k >= 1)
    {
        cout << "Nhap thong tin sv can bo sung: " << endl;
        inputSV(x);
        for (int i = L.count; i >= k -1; i--)
            L.E[i + 1] = L.E[i];
        L.count = L.count + 1;
        L.E[k - 1] = x;
        return 1;
    }
    else
        return 0;
}

//Liet ke nhung sv co ten 'Doanh'
void LietKe()

int main(int argc, char const *argv[])
{
    Lish L;
    cout << "Nhap ds: " << endl;
    inputLish(L);
    cout << "Hien thi ds" << endl;
    outputLish(L);
    // cout<<"Hien thi ds sau khi xoa sinh vien dau tien: "<<endl;
    // delete_first(L);
    // outputLish(L);
    // cout << "Hien thi ds sau khi xoa sinh vien co ma la 8089: " << endl;
    // Delete_sv8089(L);
    // outputLish(L);
    int k;
    cout << "Nhap k = ";
    cin >> k;
    if (Insert(L, k) == 1)
    {
        cout << "Hien thi ds sau khi them sinh vien vao vi tri"<<k<<": " << endl;
        outputLish(L);
    }
    else cout<<"Vi tri khong hop le."<<endl;
    return 0;
}
