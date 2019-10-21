#include <iostream>
#include <windows.h>
#include <bitset>

using namespace std;

//查 一个整数的二进制表达下的1的个数。

//从右往左一位一位的看是不是1。（与1做位与运算就知道了） 但是该方法不适用于负数。会卡死进入死循环。
int Method1(int n)
{
    int count = 0;
    while(n)
    {
        if(n&1)
            ++count;
        n = n>>1;
    }
    return count;
}

//方法二，上述方法的改进。不右移输入的整数n，左移1。这种算法的缺点是，循环次数一定等于整数二进制的位数。（32位整数需要循环32次）
int Method2(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n&flag)
            count ++;
        
        flag = flag << 1;
    }
    return count;
}

//方法3，最优解。一个整数n，和自己减去1后的(n-1)做位与运算，一定可以把最右边的1变成0
//所以能做几次该运算，变有几个1.
int MethodBest(int n)
{
    int count = 0;
    while(n)
    {
        count ++;
        n = n&(n-1);
    }
    return count;
}

/*=================测试部分===================*/
/* ？？？？？手动输入边界值时（如0x7FFFFFFF）会陷入无限循环。???
int main()
{
    int n;
    int x,y,z;
    while(1)
    {
        cout << "Input number plz." << endl;
        cin >> n;
        //bitset<32> bs(n);
        //cout << "The binary of your number is: " << bs << endl;
        //x = Method1(n);
        //cout << "Method 1:" << x << endl;
        y = Method2(n);
        cout << "Method 2:" << y << endl;
        z = MethodBest(n);
        cout << "Method 3:" << z << endl;
    }
    system("pause");
    return 0;
}
*/
//==============官方测试代码=========================
void Test(int number, unsigned int expected)
{
    int actual = Method2(number);
    if (actual == expected)
        printf("Solution2: Test for %p passed.\n", number);
    else
        printf("Solution2: Test for %p failed.\n", number);

    actual = MethodBest(number);
    if (actual == expected)
        printf("Solution3: Test for %p passed.\n", number);
    else
        printf("Solution3: Test for %p failed.\n", number);

    printf("\n");
}

int main(int argc, char* argv[])
{
    // 输入0，期待的输出是0
    Test(0, 0);

    // 输入1，期待的输出是1
    Test(1, 1);

    // 输入10，期待的输出是2
    Test(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    Test(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test(0xFFFFFFFF, 32);

    // 输入0x80000000（负数），期待的输出是1
    Test(0x80000000, 1);
    system("pause");
    return 0;
}