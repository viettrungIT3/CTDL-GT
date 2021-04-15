#include <bits/stdc++.h>
using namespace std;

#define MAX 100
//Khai báo cấu trúc dl của ds
struct BENHNHAN
{
    char maBN[10];
    char hoTen[30];
    char ngaySinh[15];
    char tinhTrang[10];
};

struct Lish
{
    int count;
    BENHNHAN E[MAX];
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

//Thêm BN vào cuối ds
int addBN(Lish &L, BENHNHAN X)
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

//Nhập thông tin BN
void inputBN(BENHNHAN &BN)
{
    cout << "\tNhap ma benh nhan: ";    fflush(stdin);  gets(BN.maBN);
    if (strcmp(BN.maBN, "***") == 0)
        return;
    cout << "\tNhap ho ten BN: ";   fflush(stdin);  gets(BN.hoTen);
    cout << "\tNhap ngay sinh: ";   fflush(stdin);  gets(BN.ngaySinh);
    cout << "\tNhap tinh trang BN: ";   fflush(stdin);  gets(BN.tinhTrang);
}

//Nhập ds BN
void inputLish(Lish &L)
{
    Initialize(L);
    int i = 1;
    BENHNHAN x;
    do
    {
        cout << "Nhap benh nhan thu " << i << ": " << endl;
        inputBN(x);
        if (strcmp(x.maBN, "***") == 0)
            return;
        if (!addBN(L, x))
            return;
        i++;
    } while (1);
}

//Hiên thị ds
void outputLish(Lish L)
{
    cout << left << setw(5) << "STT" << setw(10) << "Ma BN" << setw(30) << "Ho ten"<<setw(15) << "ngay sinh" << setw(10) << "tinh trang" << endl;
    for (int i = i; i <= L.count; i++)
    {
        cout << left << setw(5) << i + 1 << setw(10) << L.E[i].maBN << setw(30) << L.E[i].hoTen;
        cout << left << setw(15) << L.E[i].ngaySinh << setw(10) << L.E[i].tinhTrang << endl;
    }
}

//Xóa Benh nhan đầu tiên trong khỏi ds
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

// //Tim index sinh vien theo maBN
// int Search(Lish L, char *ma)
// {
//     int i = 0;
//     while (i <= L.count && strcmp(L.E[i].maBN, ma) != 0)
//         i++;
//     if (i <= L.count)
//         return i + 1;
//     else
//         return 0;
// }

// //Hàm xóa BN ra khỏi ds
// void Remove(Lish &L, int k)
// {
//     for (int i = k - 1; i < L.count; i++)
//         L.E[i] = L.E[i + 1];
//     L.count--;
// }

// //Xóa sinh viên có ma 8089
// int Delete_BN8089(Lish &L)
// {
//     int k = Search(L, "BN8089");
//     if (k == 0)
//         return 0;
//     Remove(L, k);
//     return 1;
// }

// //Bo sung sinh sinh vien vao vi tri k
// int Insert(Lish &L, int k)
// {
//     int i;
//     BENHNHAN x;
//     if (!isFull(L) && k <= L.count + 1 && k >= 1)
//     {
//         cout << "Nhap thong tin BN can bo sung: " << endl;
//         inputBN(x);
//         for (int i = L.count; i >= k - 1; i--)
//             L.E[i + 1] = L.E[i];
//         L.count = L.count + 1;
//         L.E[k - 1] = x;
//         return 1;
//     }
//     else
//         return 0;
// }

// //Liet ke nhung BN co hoTen 'Doanh'
// void LietKe()

    int main(int argc, char const *argv[])
{
    Lish L;
    cout << "Nhap ds: " << endl;
    inputLish(L);
    cout << "Hien thi ds" << endl;
    outputLish(L);
    cout<<"Hien thi ds sau khi xoa sinh vien dau tien: "<<endl;
    delete_first(L);
    outputLish(L);
    // cout << "Hien thi ds sau khi xoa sinh vien co ma la 8089: " << endl;
    // Delete_BN8089(L);
    // outputLish(L);
    // int k;
    // cout << "Nhap k = ";
    // cin >> k;
    // if (Insert(L, k) == 1)
    // {
    //     cout << "Hien thi ds sau khi them sinh vien vao vi tri" << k << ": " << endl;
    //     outputLish(L);
    // }
    // else
    //     cout << "Vi tri khong hop le." << endl;
    return 0;
}
