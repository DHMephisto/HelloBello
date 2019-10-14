// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。
#include <iostream>
#include <exception>
#include <stdexcept>
#include <windows.h>
#include <string.h>
#include "Utilities/BinaryTree.h"

BinaryTreeNode* ConstructCore(int* startpreorder, int* endpreorder, int* startinorder, int* endinorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;

    return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

BinaryTreeNode* ConstructCore(int* startpreorder, int* endpreorder, int* startinorder, int* endinorder)
{
    int rootvalue = startpreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootvalue;
    root->m_pLeft = root->m_pRight = nullptr;

    if(startpreorder == endpreorder)
    {
        if(startinorder == endinorder && *startpreorder == *startinorder)
            return root;
        else
        {
            std::logic_error ex("Invalid input.");
            throw std::exception(ex);        
        }
    }
        int* rootinorder = startinorder;
        while(rootinorder <= endinorder && *rootinorder != rootvalue)
            ++ rootinorder;

        if(rootinorder == endinorder && *rootinorder != rootvalue)
        {
            std::logic_error ex2("Invalid input.");
            throw std::exception(ex2);
        }
        int leftlen = rootinorder - startinorder;
        int* leftpreend = startpreorder + leftlen;
        if(leftlen > 0)
        {
            //构建左子树
            root->m_pLeft = ConstructCore(startpreorder +1, leftpreend, startinorder, rootinorder-1);
        }
        if(leftlen < endpreorder - startpreorder)
        {
            //构建右子树
            root->m_pRight = ConstructCore(leftpreend+1, endpreorder, rootinorder+1, endinorder);
        }

        return root;
}

// ====================测试代码====================
void Test(int* preorder, int* inorder, int length)
{
    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);

        DestroyTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
    Test(preorder, inorder, length);
}

int main(){
    Test1();
    system("pause");
    return 0;
}