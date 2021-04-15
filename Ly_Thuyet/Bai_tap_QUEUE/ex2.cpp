#include <bits/stdc++.h>
using namespace std;

#define MAX 100
typedef int Item;

struct Queue
{
    int front;
    int rear;
    Item E[MAX];
};

Queue Q;

//Khởi tạo hàng đợi rỗng
void initQueue(Queue &Q)
{
    Q.front = 0;
    Q.rear = -1;
}

//Kiểm tra hàng đợi rỗng
int isEmpty(Queue Q)
{
    return Q.rear == -1;
}

//Kiểm tra hàng đợi đầy
int isFull(Queue Q)
{
    return Q.rear = MAX - 1;
}

//Bổ sung một phần tử vào cuối hàng đợi
int addFinal(Queue &Q, Item X)
{
    if (isFull(Q))
        return 0;
    else
    {
        Q.rear++;
        Q.E[Q.rear] = X;
        return 1;
    }
}

//Loại một phần tử ở đầu hàng đợi
int removeQ(Queue &Q, Item &X)
{
    if (isEmpty(Q))
        return 0;
    else
    {
        X = Q.E[Q.front];
        if (Q.front == Q.rear)
            initQueue(Q);
        else
            Q.front = Q.front + 1;
        return 1;
    }
}

//input data
void Input(Queue &Q)
{
    initQueue(Q);
    char Check[1];
    int i = 1;
    Q.front = Q.rear = 5;
    do
    {
        cout << "input: ";
        cin >> Q.E[Q.rear];
        cout << "Do you continue(y/n)? ";
        cin >> Check;
        if (strcmp(Check, "n") == 0)
            break;
        Q.rear++;

    } while (1);
}

//output data
void Output(Queue Q)
{
    cout << "output: ";
    for (int i = Q.front; i <= Q.rear; i++)
    {
        cout << Q.E[i] << " ";
    }
}

//Bổ sung một phần tử vào đầu hàng
int addFirst(Queue &Q, Item X)
{
    if (Q.front == 0)
    {
        cout << "Error";
        return 0;
    }
    else if (isEmpty(Q))
    {
        Q.front++;
        Q.rear = Q.front;
        Q.E[Q.front] = X;
        return 1;
    }

    else
    {
        // Q.front = Q.front -1;
        // Q.E[Q.front] = X;
        Queue Q1;
        initQueue(Q1);
        Q1.rear++;
        Q1.E[Q1.front] = X;
        for (int i = Q.front; i <= Q.rear; i++)
        {
            Q1.rear++;
            Q1.E[Q1.rear] = Q.E[i];
        }
        initQueue(Q);
        Q = Q1;
        return 1;
    }
}

//bổ sung một phần tử vào sau phần tử thứ 3 tính từ đầu hàng
int add3(Queue &Q, Item X)
{
    int count = Q.front + 3;
    if (isFull(Q) || count > Q.rear)
        return 0;
    else if (count = Q.rear)
    {
        addFinal(Q, X);
        return 1;
    }
    else
    {
        Queue Q1;
        initQueue(Q1);
        for (int i = Q.front; i <= count; i++)
        {
            Q1.rear++;
            Q1.E[Q1.rear] = Q.E[i];
        }
        Q1.rear++;
        Q1.E[Q1.rear] = X;
        for (int i = count + 1; i <= Q.rear; i++)
        {
            Q1.rear++;
            Q1.E[Q1.rear] = Q.E[i];
        }
        initQueue(Q);
        Q = Q1;
        return 1;
    }
}

//loại bỏ phần tử thứ k trong hàng đợi.
int removeK( Queue &Q)
{
    int k;
    Item X;
    int count = Q.rear - Q.front + 1;
    cout<<"Enter k ( 1<=k<="<<count-1<<") to remove: "; 
    do
    {
        cin>>k;
        if ( k <= 0 || k >= count )
            cout<<"Error position. Retry: "<<endl;
    } while ( k <= 0 || k >= count );
    if ( k == 1)
    {
        removeQ(Q, X);
    }
    else
    {
        Queue Q1;
        initQueue(Q1);
        for (int i = Q.front; i <= Q.rear; i++)
        {
            if (i == k + Q.front)
            {
                i++;
            }
            Q1.rear++;
            Q1.E[Q1.rear] = Q.E[i];
        }
        initQueue(Q);
        Q = Q1;
    }
    
    
}

int main(int argc, char const *argv[])
{
    Queue Q;
    Input(Q);
    // addFirst(Q, 3);
    add3(Q, 3);
    removeK(Q);
    return 0;
}
