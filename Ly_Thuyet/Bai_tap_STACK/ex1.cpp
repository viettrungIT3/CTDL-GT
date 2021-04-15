#include <bits/stdc++.h>
using namespace std;

// #define Max 6


// struct Stack
// {
// 	Item E[Max];
// 	int top;
// };
// Stack S;

#define Max 100
typedef int Item;

struct Stack
{
    Item E[Max];
    int top;
};
Stack S;

//khởi tạo ngăn xếp rỗng
void InitStack(Stack &S)
{
    S.top = -1;
}

//Khởi tạo ngăn xếp rỗng
int IsEmpty(Stack &S)
{
    return S.top == - 1;
}

//Kiểm tra ngăn xếp đầy
int isFull(Stack &S)
{
    return S.top = Max - 1;
}

//Thêm một phần tử vào đỉnh ngăn xếp
int Push(Stack &S, Item X)
{
    if (isFull(S))
        return 0;
    else
    {
        S.top = S.top + 1;
        S.E[S.top] = X;
        return 1;
    }
}

// Loại bỏ phần tử ở đỉnh ngăn xếp
int Pop(Stack &S, Item &Y)
{
    if (IsEmpty(S))
        return 0;
    else
    {
        Y = S.E[S.top];
        S.top = S.top - 1;
        return 1;
    }
}

//Nhập dữ liệu
void Input(Stack &S)
{
    InitStack(S);
    Item X;
    int i = 1;
    char Check[1];
    S.top = 0;
    do
    {
        cout << "Nhap phan tu thu " << S.top + 1 << " : ";
        cin >> S.E[S.top];
        S.top = S.top + 1;
        // if (Push(S, X))
            i++;
        // cout<<"Do you continue(y/n)? ";
        cout << "Ban muon tiep tuc khong(y/n)? ";
        cin >> Check;
        if (strcmp(Check, "n") == 0)
            break;

    } while (1);
}
//Hiểm thị 
void Output(Stack S)
{
    Stack S1;
    InitStack(S1);
    Item X;
    S1 = S;
    cout<<"S.top = "<<S.top<<endl;
    S.top --;
    // cout << "Mang vua nhap: ";

    while (S.top > -1)
    {
        Pop(S, X);
        cout << X << " ";
    };
}

//Loại bỏ phần tử thứ 2 trong ngăn xếp
void remove2( Stack &S)
{
    Stack S1;
    InitStack(S1);
    Item X;
    do
    {
        Pop(S, X);
        Push(S1, X);
    } while ( S.top > 1);
    do
    {
        Pop(S1, X);
        Push(S, X);
    } while ( S1.top > -1);
}

void addFinal(Stack &S)
{
	Stack S1;
	InitStack(S1);
	Item X, value;
    Item value;
    cout<<"Nhap phan tu muon them vao day ngan xep: ";  cin>>value;
	do
	{
		Pop(S, X);
		Push(S1, X);

	} while (S.top > -1);
	Push(S, value);
	do
	{
		Pop(S1, X);
		Push(S, X);
	} while (S1.top > -1);
}

//Loại bỏ phần tử thứ k trong ngăn xếp
void removeK (Stack &S)
{
    int k;
    do
    {
        cout<<"Nhap k = ";  cin>>k;
    } while ( k <= 0 || k > S.top);
    k---;
    
    Stack S1;
    InitStack(S1);
    Item X;
    do
    {
        Pop(S, X);
        Push(S1, X);
    } while ( S.top > k);
    do
    {
        Pop(S1, X);
        Push(S, X);
    } while ( S1.top > -1);
}

int main(int argc, char const *argv[])
{
    Stack S;
    Input(S);
    // cout<<"Mang vua nhap: ";
    // Output(S);
    remove2(S);
    // cout<<"Mang sau khi xoa phan tu thu 2: ";
    // Output(S);
    
    addFinal( S);
    // cout<<"Mang sau khi them phan tu tren vao day ngan xep: ";
    // Output(S);
    removeK(S);
    // cout<<"Mang sau khi laoi bo phan tu thu k: ";
    // Output(S);
    return 0;
}
