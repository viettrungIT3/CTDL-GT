#include <bits/stdc++.h>

using namespace std;

#define Max 6
struct Stack
{
	int E[Max];
	int top;
};
Stack S;
void create(Stack &S)
{
	S.top = -1;
}
int Empty(Stack S)
{
	return (S.top == -1);
}
int Full(Stack S)
{
	return (S.top == Max - 1);
}
int Push(Stack &S, int X)
{
	if (Full(S))
		return 0;
	else
	{
		S.top = S.top + 1;
		S.E[S.top] = X;
		return 1;
	}
}
int Pop(Stack &S, int &X)
{
	if (Empty(S))
		return 0;
	else
	{
		X = S.E[S.top];
		S.top = S.top - 1;
		return 1;
	}
}
void NhapDS(Stack &S)
{
	create(S);
	int i = 1, X;
	do
	{
		cout << "Moi nhap phan tu thu " << i << " : ";
		cin >> X;
		if (Push(S, X))
			i++;
	} while (i < 6);
}
void delete2(Stack &S)
{
	int X;
	Stack S1;
	create(S1);
	do
	{
		Pop(S, X);
		Push(S1, X);

	} while (S.top > 1);
	Pop(S, X);
	do
	{
		Pop(S1, X);
		Push(S, X);
	} while (S1.top > -1);
}
void addFinal(Stack &S, int A6)
{
	int X;
	Stack S1;
	create(S1);
	do
	{
		Pop(S, X);
		Push(S1, X);

	} while (S.top > -1);
	Push(S, A6);
	do
	{
		Pop(S1, X);
		Push(S, X);
	} while (S1.top > -1);
}
void deleteK(Stack &S)
{
	int k;
	do
	{
		cout << "Nhap vao k ( k>0 & k<5 ) : ";
		cin >> k;
	} while (k <= 0 || k >= 5);

	int X;
	Stack S1;
	create(S1);
	do
	{
		Pop(S, X);
		Push(S1, X);

	} while (S.top > k - 1);
	Pop(S, X);
	do
	{
		Pop(S1, X);
		Push(S, X);
	} while (S1.top > -1);
}
int main()
{
	Stack S;
	NhapDS(S);
	delete2(S);
	addFinal(S, 9);
	deleteK(S);
}