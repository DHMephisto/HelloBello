#include <iostream>
#include <stack>
#include "Utilities/List.h"
#include <windows.h>
using namespace std;

void PLR(ListNode* pHead)
{
    stack<ListNode*> nodes;

    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode -> m_pNext;
    }
    while(!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }
}

// ====================²âÊÔ´úÂë====================
void Test(ListNode* pHead)
{
    PrintList(pHead);
    PLR(pHead);
    printf("\n");
    //PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}
int main(int argc, char* argv[])
{
    Test1();
    system("pause");

    return 0;
}