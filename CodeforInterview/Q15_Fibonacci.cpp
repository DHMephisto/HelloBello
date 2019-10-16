//���쳲��������еĵ�n�
#include <iostream>
#include <cassert>
#include <ctime>
#include <windows.h>

//���� ������ʱ����ȫ���ɽ��ܵĵݹ��㷨��
long long Fib0(unsigned int n)
{
    if (n<=0) return 0;
    if (n == 1) return 1;

    return Fib0(n-1) + Fib0(n-2);
}
//������Ϊn�������� �����п��ܱȽϴ�������unsigned int

//O��n����������ʵ�ã���¼�ó��ֵ����֡�
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

//O(longn)�㷨�������ã�����һ����ѧ��ʽ��
//--           --    -    -��n-1)
//|f(n)   f(n-1) |   | 1 1|
//|f(n-1) f(n-2) | = | 1 0|
//--           --    -    -
//�������߶��Ǿ�������ֻ������Ҿ���ĵ�һ���������ˡ�
//������ʵ�ڱ����и��ܲ�����O��n��������ʱ���ࡣ

//2*2����ṹ��
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

//����˷�
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

//��ǰ���ᵽ���Ǹ�ָ������ľ����n�η���
Matrix2By2 MatrixPower(unsigned int n)
{
    assert(n > 0); //����������ʱ��ֹ���С�

    Matrix2By2 matrix;
    if(n == 1)
    {
        matrix = Matrix2By2(1, 1, 1, 0);
    }
    else if(n % 2 == 0)    //nΪż��ʱ������A��n/2����ƽ����
    {
        matrix = MatrixPower(n / 2);   //���ﻹ���õĵݹ顣
        matrix = MatrixMultiply(matrix, matrix);
    }
    else if(n % 2 == 1)    //����ʱ����ȡż�ٳ������Լ���
    {
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
    }

    return matrix; //���ﷵ�صĻ���һ������
}

long long Fib2(unsigned int n)
{
    if (n<=0) return 0;
    if (n == 1) return 1;

    Matrix2By2 AimMatrix = MatrixPower(n - 1);
    return AimMatrix.m_00;
}
// ====================���Դ���====================
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