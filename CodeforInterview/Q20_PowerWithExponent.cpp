#include <iostream>
#include <windows.h>

using namespace std;

double Power(double base, int exponent)
{
    if(exponent == 0) return 1.0;

    if(exponent == 1) return base;

    int flag = 0;
    if(exponent < 0)
    {
        flag = 1;
        exponent *= -1;
    }

    double result = Power(base, exponent >> 1);

    result *= result;

    if(exponent & 0x1 == 1)
    {
        result *= base;
    }

    if(flag == 1)
    {
        result = 1/result;
    }
    

    return result;
}

int main()
{
    double base;
    int exp;
    cout << "Input base and exponent :" << endl;
    cin >> base;
    cin >> exp;
    double result = Power(base, exp);
    cout << "Result is :" << result << endl;

    system("pause");
    return 0;
}