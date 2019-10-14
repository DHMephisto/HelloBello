//为下面的类型添加赋值运算符函数
#include <iostream>
#include <cstring>
#include <cstdio>
#include <windows.h>

class CMystring
{
public:
    CMystring(char* pData = nullptr);
    CMystring(const CMystring& str);
    ~CMystring(void);
    
    CMystring& operator = (const CMystring& str);

    void Print();

private:
    char* m_pData;
};

CMystring::CMystring(char* pData){
    if(pData == nullptr){
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length+1];
        strcpy(m_pData, pData);
    }
    
}

CMystring::CMystring(const CMystring& str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length+1];
    strcpy(m_pData, str.m_pData);
}

CMystring::~CMystring()
{
    delete[] m_pData;
}
/*//Method 1, 分配内存之前释放了m_pData的内存，如果此时内存不足将导致new char抛出异常。
CMystring& CMystring::operator = (const CMystring& str)
{
    if(this == &str)
        return *this;

    delete[] m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData, str.m_pData);

    return *this;
}*/
//Better method.
CMystring& CMystring::operator = (const CMystring& str)
{
    if(this != &str)
    {
        CMystring strTemp(str);
        char* ptemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = ptemp;
    }
    return *this;
}


//=====================*测试部分*================================
void CMystring::Print()
{
    printf("%s", m_pData);
}

void Test1()
{
    printf("Test1 begins:\n");
    char* text = "Hello world!";

    CMystring str1(text);
    CMystring str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);
    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

//赋值给自己
void Test2()
{
    printf("Test2 begins:\n");

    char* text = "Hello world";

    CMystring str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    CMystring str1(text);
    CMystring str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    system("pause");
    return 0;
}