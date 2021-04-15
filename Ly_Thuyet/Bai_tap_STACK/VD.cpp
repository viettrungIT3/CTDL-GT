#include <bits/stdc++.h>
using namespace std;

//Khai báo cấu trúc dữ liệu
#define MAX 32 // số nguyên có kích thước 4 bytes
typedef int Item;

struct Stack
{
    Item E[MAX];
    int top;
};

//Khai báo các phép toán ngăn xếp

// Khởi tạo ngăn xếp rỗng
void Initialize(Stack S)
{
    S.top = -1;
}

//Kiểm tra danh sách rỗng
int isEmpty(Stack S)
{
    return (S.top == -1);
}

int isFull(Stack S)
{
    return (S.top = MAX - 1);
}

//Thêm phần tử X và đỉnh của ngăn xếp
int Push(Stack &S, Item X)
{
    if (isFull(S))
    {
        return 0;
    }
    else
    {
        S.top = S.top + 1;
        S.E[S.top] = X;
        return 1;
    }
}

//Loại bỏ phần tử ở đỉnh ngăn xêp
int Pop(Stack &S, Item Y)
{
    if (isEmpty(S))
    {
        return 0;
    }
    else
    {
        Y = S.E[S.top];
        S.top = S.top - 1;
        return 1;
    }
}

//Hàm chuyển đổi số thập phân sang số nhị phân
void Change10to2(unsigned long N, Stack &S)
{
    Initialize(S);
    while (N > 0 && Push(S, N % 2))
    {
        N = N / 2;
    }
}

//Hàm hiểm thị mã nhị phân
void Show2(Stack S)
{
    int R;
    // cout << "Ma nhi phan la: ";
    while (Pop(S, R))
    {
        cout << R;
    }
}
void display(Stack S)
{
    Item Y;
    while (Pop(S, Y))
    {
        cout << Y << " ";
    }
}

int main(int argc, char const *argv[])
{
    unsigned long N;
    Stack S;
    Initialize(S);
    cout << "Nhap N: ";
    cin >> N;
    Change10to2(N, S);
    cout << "Ma nhi phan la: ";
    display(S);
    Show2(S);
    return 0;
}
