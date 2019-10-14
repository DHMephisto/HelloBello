//给定一个数组，求最大的子数组的和。并输出
#include <iostream>
#include <windows.h>
using namespace std;

void GetmaxsumofA(int* a, int size)
{
    if (a == NULL || size < 1) return;

    int max = a[0];
    int sum = a[0];
    int begin = 0;
    int end = 0;

    for(int i=1; i < size; i++)
    {
        if(sum <0)
        {
            sum = a[i];
            begin = i;
        }else
        {
            sum += a[i];
        }

        if(sum > max)
        {
            end = i;
            max = sum;
        }
    }

    cout << "Your array is :" << endl <<"{ ";
    for(int i =0; i<size; i++) cout<<a[i]<<", ";
    cout << "}"<<endl;
    cout <<"Max sum of sub array is :";
    cout << max << endl;
    cout << "The sub array is :"<<endl <<"{ ";
    for(int i =begin; i<end+1; i++) cout<<a[i]<<", ";
    cout << "}"<<endl;
    return;
}

//测试
int main()
{
    int a[] = { 2, 3, -6, 4, 6, 2, -2, 5, -9 };
    int size = sizeof(a) / sizeof(a[0]);
    /*int MAX = GetmaxsumofA(a, size);
    cout << "Your array is :" << endl <<"{ ";
    for(int i =0; i<size; i++) cout<<a[i]<<", ";
    cout << "}"<<endl;
    cout <<"Max sum of sub array is :";
    cout << MAX << endl;*/
    GetmaxsumofA(a, size);

    system("pause");
    return 0;
}