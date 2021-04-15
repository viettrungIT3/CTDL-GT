#include <stdio.h>
struct NODE
{
    int Key;
    NODE *pNext;
};
NODE *CreateNode(int Data)
{
    NODE *pNode;
    pNode = new NODE;
    if (pNode == NULL)
        return NULL;
    pNode->Key = Data;
    pNode->pNext = NULL;
    return pNode;
}
bool AddHead(NODE *&pHead, int Data)
{
    NODE *pNode;
    pNode = CreateNode(Data);
    if (pNode == NULL)
        return false;
    if (pHead == NULL)
        pHead = pNode;
    else
    {
        pNode->pNext = pHead;
        pHead = pNode;
    }
    return true;
}
NODE *GetHead(NODE *&pHead)
{
    if (pHead == NULL)
        return NULL;
    NODE *pResult = pHead;
    pHead = pHead->pNext;
    return pResult;
}
NODE *GetTail(NODE *&pHead)
{
    NODE *pNode;
    if (pHead == NULL) //<1>
    {
        return NULL;
    }
    else if (pHead->pNext == NULL) //<2>
    {
        pNode = pHead;
        pHead = NULL;
        return pNode;
    }
    pNode = pHead;
    while (pNode->pNext->pNext != NULL) //<3>
    {
        pNode = pNode->pNext;
    }
    NODE *pResult = pNode->pNext;
    pNode->pNext = NULL;
    return pResult;
}
void PrintList(NODE *pHead)
{
    NODE *pNode;
    pNode = pHead;
    while (pNode != NULL)
    {
        printf("%5d", pNode->Key);
        pNode = pNode->pNext;
    }
}
int main()
{
    NODE *pHead = NULL;
    int n = 10;
    while (n != 0)
    {
        AddHead(pHead, n);
        n--;
    }
    printf("Danh sach luc dau :\n");
    PrintList(pHead);
    printf("\n");
    NODE *pNode = GetTail(pHead);
    printf("Danh sach sau khi lay phan tu cuoi\n");
    PrintList(pHead);
    if (pNode != NULL) //<4>
        printf("\nGia tri Tail : %d\n", pNode->Key);
    else
        printf("\nNULL\n");
    NODE *pNode2 = GetHead(pHead);
    printf("Danh sach sau khi lay phan tu dau\n");
    PrintList(pHead);
    if (pNode2 != NULL)
        printf("\nGia tri Head : %d\n", pNode2->Key);
    else
        printf("\nNULL\n");
}