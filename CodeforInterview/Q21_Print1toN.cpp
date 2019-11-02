// ������17����ӡ1������nλ��
// ��Ŀ����������n����˳���ӡ����1����nλʮ����������������3����
// ��ӡ��1��2��3һֱ������3λ����999��

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


//=============��ӡ����==============
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

//==============���Ժ���=======================
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