// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

#include <iostream>
#include <memory>
#include "windows.h"
using namespace std;

void PrintNumber(char* number);
bool Increment(char* number);

void Print1ToN(int n)
{
    if (n <= 0)
        return;

    char *number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!Increment(number))
    {
        PrintNumber(number);
    }

    delete[]number;
}

bool Increment(char* number)
{
    bool isoverflow = false;
    int nTakeover = 0;
    int nlength = strlen(number);

    for(int i = nlength-1; i >= 0; i--)
    {
        int nsum = number[i] - '0' + nTakeover;
        if (i == nlength -1)
            nsum ++;

        if (nsum >= 10)
        {
            if (i==0)
                isoverflow = true;
            else
            {
                nsum -= 10;
                nTakeover = 1;
                number[i] = '0' + nsum;
            }
        }
        else
        {
            number[i] = '0' + nsum;
            break;
        }
    }
    return isoverflow;
}


//=============打印函数==============
void PrintNumber(char* number)
{
    bool isBegin0 = true;
    int nlength = strlen(number);

    for(int i = 0; i < nlength; ++i)
    {
        if(isBegin0 && number[i] != '0')
            isBegin0 = false;

        if(!isBegin0)
        {
            cout << number[i];
        }
    }

    cout << endl;
}

//==============测试函数=======================
int main ()
{
    int n;

    cout << "Input n Plz :";
    cin >> n;
    cout << "Output 1 to max n...: " << endl;
    Print1ToN(n);

    system("pause");
    return 0;
}