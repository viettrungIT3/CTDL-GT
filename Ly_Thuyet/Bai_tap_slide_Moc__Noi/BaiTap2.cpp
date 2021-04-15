#include <bits/stdc++.h>

using namespace std;

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

void InitializeListNull(TRO &L)
{
	L = NULL;
}

int isEmpty(TRO L)
{
	return L == NULL;
}

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

void OutputStudent(SINHVIEN &sv)
{
	cout << setw(10) << sv.maSV;
	cout << setw(30) << sv.hoTen;
	cout << setw(10) << sv.namSinh;
	cout << setw(10) << sv.diemTK << endl;
}

void InputList(TRO &L)
{
	InitializeListNull(L);
	SINHVIEN X;
	TRO Q, P;
	int n;
	cout << "Nhap moi n phan tu cho danh sach:" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{

		cout << "Nhap sinh vien thu " << i << ": " << endl;
		InputStudent(X);
		P = new Node;
		P->infor = X;
		P->next = NULL;
		if (L == NULL)
			L = P;
		else
			Q->next = P;
		Q = P;
	}
}

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

void Display65(TRO L)
{
	TRO Q = L;
	while (Q != NULL)
	{
		if (Q->infor.diemTK >= 6.5)
			output(Q->infor);
		Q = Q->next;
	}
}

void Insert(TRO L, int k)
{
	TRO Q = L;
	SINHVIEN sv;
	int count = 1;
	cout << "Nhap thong tin SV can chen:";
	InputStudent(sv);
	while (Q != NULL && k > count)
	{
		Q = Q->next;
		count++;
	}
	TRO P;
	P = new Node;
	P->infor = sv;
	P->next = Q->next;
	Q->next = P;
}

int main()
{
	InputList(L);
	cout << "Danh sach vua nhap:" << endl;
	DisplayList(L);
	cout << "Danh sach SV co diem TK tu 6.5 tro len:" << endl;
	Display65(L);
	cout << "Chen mot SV vao danh sach:" << endl;
	int k;
	cout << "Nhap vi tri can chen:" << endl;
	cin >> k;
	Insert(L, k);
	cout << "Danh sach sau khi chen:" << endl;
	DisplayList(L);
}
