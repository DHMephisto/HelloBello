// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。
//时间复杂度为O(n)
#include <iostream>
#include <cstring>
using namespace std;

void ReplaceBlank(char str[], int length)
{
	if(str == nullptr && length <= 0)
		return;

	int olen = 0;
	int numofblk = 0;
	int i = 0;
	while(str[i] != '\0')
	{
		++olen;
		if(str[i]==' ')
			++numofblk;

		++i;
	}

	int newlen = olen + numofblk*2;
	if(newlen > length)
		return;

	int indexo = olen;
	int indexnew = newlen;
	while(indexo >=0 && indexnew > indexo)
	{
		if(str[indexo] == ' ')
		{
			str[indexnew --] = '0';
			str[indexnew --] = '2';
			str[indexnew --] = '%';
		}
		else
		{
			str[indexnew--] = str[indexo];
		}
		--indexo;
	}
}


int main()
{
	char str[50] = "Hello world!  I love you! ";
	for(int i=0; i<50; i++){
		cout << str[i];
	}
	cout << endl;
	ReplaceBlank(str, 50);
	        for(int i=0; i<50; i++){
                cout << str[i];
        }
        cout << endl;
	return 0;
}
