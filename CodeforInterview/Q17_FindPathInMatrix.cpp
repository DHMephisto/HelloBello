// ������12�������е�·��
// ��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ�������
// �ַ���·����·�����ԴӾ���������һ��ʼ��ÿһ�������ھ����������ҡ�
// �ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���
// �ø��ӡ������������3��4�ľ����а���һ���ַ�����bfce����·����·���е���
// ĸ���»��߱�������������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ��
// �ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
// A B T G
// C F C S
// J D E H
//���û����㷨���ݹ�ʵ�ִ��롣
//�ٴ�ǿ������������������޸��������������ǰ����const������ͻ���ʹ��ʱ�������⡣

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

bool FindPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, bool* visited, int& pathlen);
//��������pathlen������ֱ��ʹ������ֵ��������Ϊ��pahlen��ͬ���޸�ʹ�á�

bool FindPathInMatrix(const char* matrix, int rows, int cols, const char* str)
{
    if(matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
        return false;
    
    bool* visited = new bool[rows*cols];
    memset(visited, 0, rows*cols); 
    //void *memset(void *s,int c,size_t n);���ѿ����ڴ�ռ� s ���� n ���ֽڵ�ֵ��Ϊֵ c��

    int pathlen = 0;
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            if(FindPathCore(matrix, rows, cols, i, j, str, visited, pathlen))
            {
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}

bool FindPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, bool* visited, int& pathlen)
{
    if(str[pathlen] == '\0')
        return true;
    
    bool haspath = false;
    if(row >=0 && row < rows && col >= 0 && col < cols && !visited[row*cols+col]
        && matrix[row*cols+col] == str[pathlen])
        {
            ++pathlen;
            visited[row*cols+col] = true;

            haspath = FindPathCore(matrix, rows, cols, row+1, col, str, visited, pathlen)
                    ||FindPathCore(matrix, rows, cols, row-1, col, str, visited, pathlen)
                    ||FindPathCore(matrix, rows, cols, row, col+1, str, visited, pathlen)
                    ||FindPathCore(matrix, rows, cols, row, col-1, str, visited, pathlen);

            if(!haspath)
            {
                --pathlen;
                visited[row*cols+col] =false;
            }
        }
        return haspath;
}

// ====================���Դ���====================
void Test(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(FindPathInMatrix(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void Test1()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";

    Test("Test1", (const char*) matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
    const char* matrix = "ABCESFCSADEE";
    const char* str = "SEE";

    Test("Test2", (const char*) matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "ABFB";

    Test("Test3", (const char*) matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";

    Test("Test4", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEM";

    Test("Test5", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEEJIGOEM";

    Test("Test6", (const char*) matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEMS";

    Test("Test7", (const char*) matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAA";

    Test("Test8", (const char*) matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAAA";

    Test("Test9", (const char*) matrix, 3, 4, str, false);
}

//A

//A
void Test10()
{
    const char* matrix = "A";
    const char* str = "A";

    Test("Test10", (const char*) matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
    const char* matrix = "A";
    const char* str = "B";

    Test("Test11", (const char*) matrix, 1, 1, str, false);
}

void Test12()
{
    Test("Test12", nullptr, 0, 0, nullptr, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    system("pause");
    return 0;
}