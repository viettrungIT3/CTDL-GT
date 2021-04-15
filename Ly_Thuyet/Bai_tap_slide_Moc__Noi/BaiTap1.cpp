#include <bits/stdc++.h>
using namespace std;

//Khai bao cau truc du lieu cua danh sach
struct SINHVIEN
{
	char maSV[10];
	char hoTen[30];
	int namSinh;
	float diemTK;
};

struct Node
{
	SINHVIEN infor;
	Node *next;
};

typedef Node *TRO;

TRO L;

//Khoi tao danh sach rong
void InitializeListNull(TRO &L)
{
	L = NULL;
}

//Kiem tra danh sach rong
int isEmpty(TRO L)
{
	return L == NULL;
}

// int checkStudentCode( SINHVIEN sv) {
// 	for (int i = 0; i < count; i++)
// 	{
// 		/* code */
// 	}

// }

//Nhap thong tin sinh vien
void InputStudent(SINHVIEN &sv)
{
	cout << "\tNhap ma sv:  ";
	fflush(stdin);
	gets(sv.maSV);
	cout << "\tNhap ho ten: ";
	fflush(stdin);
	gets(sv.hoTen);
	cout << "\tNhap nam sinh: ";
	cin >> sv.namSinh;
	cout << "\tNhap diem TK:  ";
	cin >> sv.diemTK;
}

//Nhap danh sinh vien
void InputList(TRO &L)
{
	InitializeListNull(L);
	SINHVIEN X;
	TRO Q, P;
	int i = 1;
	do
	{
		cout << "Nhap sinh vien thu " << i << ": " << endl;
		InputStudent(X);
		char check[1];
		cout << "Do you continue(y/n)? ";
		cin >> check;
		if (strcmp(check, "n") == 0)
		{
			return;
		}
		P = new Node;
		P->infor = X;
		P->next = NULL;
		if (L == NULL)
			L = P;
		else
			Q->next = P;
		Q = P;
		i++;

	} while (1);
}

// hien thi danh sach Sinh Vien
void DisplayList(TRO L)
{
	if (L == NULL)
	{
		cout << "Danh sach rong!\n";
		return;
	}
	cout << setw(10) << "Ma SV";
	cout << setw(25) << "Ho va ten";
	cout << setw(10) << "Nam sinh";
	cout << setw(10) << "Diem TK" << endl;
	TRO Q = L;
	int i = 0;
	while (Q != NULL)
	{
		SINHVIEN x = Q->infor;
		cout << setw(10) << x.maSV;
		cout << setw(30) << x.hoTen;
		cout << setw(10) << x.namSinh;
		cout << setw(10) << x.diemTK << endl;
		Q = Q->next;
	}
}

//xac dinh chieu dai ds
int Length(TRO L)
{
	int n = 0;
	TRO Q = L;
	while (Q != NULL)
	{
		n++;
		Q = Q->next;
	}
	return n;
}

//Tim kiem sinh vien theo maSV
TRO Search(TRO L, char *ma)
{
	TRO Q = L;
	while (Q != NULL && strcmp(Q->infor.maSV, ma) != 0)
		Q = Q->next;
	return Q;
}

void ShowStudent(SINHVIEN sv)
{
	cout << "thogn tin sinh vien can tim la: " << endl;
	cout << "\tMa SV: " << sv.maSV << endl;
	cout << "\tHo ten: " << sv.hoTen << endl;
	cout << "\tNam sinh: " << sv.namSinh << endl;
	cout << "\tDiem TK: " << sv.diemTK << endl;
}

int main(int argc, char const *argv[])
{
	TRO L;
	cout << "Nhap danh sach Sinh Vien: " << endl;
	InputList(L);
	cout << "\nDanh sach vua nhap la: " << endl;
	DisplayList(L);
	cout << " Chieu dai cua danh sach la: " << Length(L) << endl;
	char studentcode[10];
	cout << "Nhap maSV can tim: ";
	fflush(stdin);
	gets(studentcode);
	TRO Check = Search(L, studentcode);
	if (Check == NULL)
		cout << "Khong co sinh vien nay!" << endl;
	else
	{
		SINHVIEN sv = Check->infor;
		ShowStudent(sv);
	}
	return 0;
}
