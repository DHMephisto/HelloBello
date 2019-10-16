//输出斐波那契数列的第n项。
#include <iostream>
#include <cassert>
#include <ctime>
#include <windows.h>

//常见 但计算时间完全不可接受的递归算法。
long long Fib0(unsigned int n)
{
    if (n<=0) return 0;
    if (n == 1) return 1;

    return Fib0(n-1) + Fib0(n-2);
}
//这里因为n是正整数 并且有可能比较大，所以用unsigned int

//O（n）方法，很实用，记录好出现的数字。
long long Fib1(unsigned int n)
{
    if (n<=0) return 0;
    if (n == 1) return 1;

    long long fibN_2 = 0;
    long long fibN_1 = 1;
    long long fibN = 1;
    for(unsigned int i = 2; i < (n+1); ++i)
    {
        fibN = fibN_2 + fibN_1;
        fibN_2 = fibN_1;
        fibN_1 = fibN;
    }
    return fibN;
}

//O(longn)算法，不常用，利用一个数学公式：
//--           --    -    -（n-1)
//|f(n)   f(n-1) |   | 1 1|
//|f(n-1) f(n-2) | = | 1 0|
//--           --    -    -
//左右两边都是矩阵，所以只需求出右矩阵的第一个数就行了。
//但是其实在本题中感受不到和O（n）方法的时间差距。

//2*2矩阵结构体
struct Matrix2By2
{
    Matrix2By2
    (
        long long m00 = 0, 
        long long m01 = 0, 
        long long m10 = 0, 
        long long m11 = 0
    )
    :m_00(m00), m_01(m01), m_10(m10), m_11(m11) 
    {
    }

    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

//矩阵乘法
Matrix2By2 MatrixMultiply
(
    const Matrix2By2& matrix1, 
    const Matrix2By2& matrix2
)
{
    return Matrix2By2(
        matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
        matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
        matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
        matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11);
}

//求前文提到的那个指定矩阵的矩阵的n次方。
Matrix2By2 MatrixPower(unsigned int n)
{
    assert(n > 0); //不满足条件时终止运行。

    Matrix2By2 matrix;
    if(n == 1)
    {
        matrix = Matrix2By2(1, 1, 1, 0);
    }
    else if(n % 2 == 0)    //n为偶数时，等于A（n/2）的平方。
    {
        matrix = MatrixPower(n / 2);   //这里还是用的递归。
        matrix = MatrixMultiply(matrix, matrix);
    }
    else if(n % 2 == 1)    //奇数时向下取偶再乘以下自己。
    {
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
    }

    return matrix; //这里返回的还是一个矩阵。
}

long long Fib2(unsigned int n)
{
    if (n<=0) return 0;
    if (n == 1) return 1;

    Matrix2By2 AimMatrix = MatrixPower(n - 1);
    return AimMatrix.m_00;
}
// ====================测试代码====================
int main()
{
    int md = 0;
    while(md != 1 && md!=2 && md!=3){
        std::cout << "Slect Method you want(1,2,or3):" << std::endl;
        std::cin >> md;
    }

    std::cout << "Input n plz :" << std::endl;
    unsigned int n;
    std::cin >> n;
    clock_t startt, endt;

    if(md == 1){
        startt = clock();
        long long x = Fib0(n);
        endt = clock();
        std::cout << "Result :" << x << std::endl;
        std::cout <<"The run time is: " <<(double)(endt - startt) / CLOCKS_PER_SEC << "s" << std::endl;
    }

    if(md == 2){
        startt = clock();
        long long x = Fib1(n);
        endt = clock();
        std::cout << "Result :" << x << std::endl;
        std::cout <<"The run time is: " <<(double)(endt - startt) / CLOCKS_PER_SEC << "s" << std::endl;
    }

    if(md == 3){
        startt = clock();
        long long x = Fib2(n);
        endt = clock();
        std::cout << "Result :" << x << std::endl;
        std::cout <<"The run time is: " <<(double)(endt - startt) / CLOCKS_PER_SEC << "s" << std::endl;
    }

    system("pause");
    return 0;
}