#include <bits/stdc++.h>
using namespace std;

//Khai báo cấu trúc DL
struct Node
{
    int key;
    Node *Left, *Right;
};

typedef Node *TRO;

//Tạo cây rỗng
void MakeNull(TRO &Root)
{
    Root = NULL;
}

//Tạo một nút trong cây và đưa địa chỉ vào nut mới tạo
TRO createNode(int key)
{
    TRO p = new Node;
    if (p == NULL)
    {
        return NULL;
        cout << "khong du bo nho" << endl;
    }
    p->key = key;
    p->Left = NULL;
    p->Right = NULL;
    return p;
}

//Chèn một nút vào cây
void InsertNode(TRO &Root, int x)
{
    if (Root == NULL) //cây rỗng
        Root = createNode(x);

    else
    {
        if (Root->key < x)
        {
            if (Root->Right == NULL)
            {
                createNode(x);
            }
            else
            {
                InsertNode(Root->Right, x);
            }
        }
        else if (Root->key > x)
        {
            if (Root->Left == NULL)
            {
                createNode(x);
            }
            else
            {
                InsertNode(Root->Left, x);
            }
        }
        else
            cout << "Nut da ton tai" << endl;
    }
}

//Tạo các nút trong cây
void AddNode(TRO &Root)
{
    char Check[1];
    int key;
    do
    {
        cout << "Nhap key = ";
        cin >> key;
        InsertNode(Root, key);
        cout << "Ban muon tiep tuc khong(y/n)? ";
        cin >> Check;
        if (strcmp(Check, "n") == 0)
            break;
    } while (1);
}

//Tìm nút có giá trị x
TRO SearchNode(TRO Root, int x)
{
    while (1)
    {
        if (Root == NULL)
            return NULL;
        if (Root->key == x)
        {
            return Root;
        }
        else
        {
            if (Root->key < x)
                Root = Root->Right;
            else
                Root = Root->Left;
        }
    }
}
//C2
TRO search(TRO Root, int K)
{
    TRO Q;
    Q = Root;
    while (Q != NULL && Q->key != K)
    {
        if (Q->key > K)
            Q = Q->Left;
        else
            Q = Q->Right;
    }
    return Q;
}

int main(int argc, char const *argv[])
{
    TRO Root;
    MakeNull(Root);
    AddNode(Root);
    int x;
    cout << "Nhap x = ";
    cin >> x;
    // TRO vt1 = SearchNode(Root, x);
    // if ( vt1 == NULL )
    //     cout<<"Khong tim thay"<<endl;
    // else
    //     cout<<"tim đc: "<<vt1->key<<endl;
    
    TRO vt2 = search(Root, x);
    if ( vt2 == NULL )
        cout<<"Khong tim thay"<<endl;
    else
        cout<<"tim đc: "<<vt2->key<<endl;
    
    return 0;
}
