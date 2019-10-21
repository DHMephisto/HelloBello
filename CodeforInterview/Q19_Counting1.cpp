#include <iostream>
#include <windows.h>
#include <bitset>

using namespace std;

//�� һ�������Ķ����Ʊ���µ�1�ĸ�����

//��������һλһλ�Ŀ��ǲ���1������1��λ�������֪���ˣ� ���Ǹ÷����������ڸ������Ῠ��������ѭ����
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

//�����������������ĸĽ������������������n������1�������㷨��ȱ���ǣ�ѭ������һ���������������Ƶ�λ������32λ������Ҫѭ��32�Σ�
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

//����3�����Ž⡣һ������n�����Լ���ȥ1���(n-1)��λ�����㣬һ�����԰����ұߵ�1���0
//�����������θ����㣬���м���1.
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

/*=================���Բ���===================*/
/* �����������ֶ�����߽�ֵʱ����0x7FFFFFFF������������ѭ����???
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
//==============�ٷ����Դ���=========================
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
    // ����0���ڴ��������0
    Test(0, 0);

    // ����1���ڴ��������1
    Test(1, 1);

    // ����10���ڴ��������2
    Test(10, 2);

    // ����0x7FFFFFFF���ڴ��������31
    Test(0x7FFFFFFF, 31);

    // ����0xFFFFFFFF�����������ڴ��������32
    Test(0xFFFFFFFF, 32);

    // ����0x80000000�����������ڴ��������1
    Test(0x80000000, 1);
    system("pause");
    return 0;
}