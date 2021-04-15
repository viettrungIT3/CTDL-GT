#include <bits/stdc++.h>
using namespace std;

typedef int Item;

struct Node
{
    Item Infor;
    Node *Next;
};

typedef Node *TRO;
TRO S;

//Khởi tạo ngăn xếp rỗng
void Create(TRO &S)
{
    S = NULL;
}

//Kiểm tra ngăn xếp rỗng
int Empty(TRO S)
{
    return (S == NULL);
}

//Bổ sung một phần tử vào đỉnh ngăn xếp
void Push(TRO &S, Item X)
{
    TRO P;
    P = new Node;
    P->Infor = X;
    P->Next = NULL;
    if (S == NULL)
    {
        S = P;
    }
    else
    {
        P->Next = S;
        S = P;
    }
}

//Lấy ra một phần tử ở đỉnh ngăn xếp
int Pop(TRO &S, Item &X)
{
    TRO P;
    if (Empty(S))
    {
        return 0;
    }
    else
    {
        P = S;
        X = S->Infor;
        S = S->Next;
        delete P;
        return 1;
    }
}

//Nhập DL
void Input(TRO &S)
{
    char Check;
    do
    {
        cout << "input: ";
        Item temp;
        cin >> temp;
        S->Next = S->Next + 1;
        Push(S, temp);
        cout << "Do you continue(y/n)? ";
        do
        {
            cin >> Check;
        } while (Check != 'y' && Check != 'n');
    } while (Check != 'n');
}

void Output(TRO S)
{
    TRO K = S;
    if (Empty(S))
    {
        cout << "no ouput";
    }
    else
    {
        cout << "output: ";
        while ( Empty(K))
        {
            cout << K->Infor << " ";
            K->Next--;
        }
    }
}

int main(int argc, char const *argv[])
{
    TRO S;
    Input( S);
    Output(S);
    return 0;
}
