// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。

#include <iostream>
using namespace std;

//方法一：时间效率优先。
int getDuplication1(const int* numbers, int length)
{
	int* temp = new int[length-1];
	for(int i =0; i<length-1; i++){
		temp[i] = -1;
	}

	for (int i=0; i<length; i++){
		if (temp[numbers[i]] == -1)
		{
			temp[numbers[i]] = 0;
		}
		if (temp[numbers[i]] == 0)
		{
			return numbers[i];
		}
	}
	delete[] temp;
	return -1;
}

//空间效率优先。二分法。
int countRange(const int* numbers, int length, int start, int end)
{
	if(numbers == nullptr) return 0;

	int count = 0;
	for(int i=0; i<length; i++)
	{
		if (numbers[i] >= start && numbers[i] <= end)
			++count;
	}
	return count;
}

int getDuplication2(const int* numbers, int length)
{
	if(numbers == nullptr || length <= 0) return -1;

	int start = 1;
	int end = length - 1;
	while(end >= start)
	{
		int middle = ((end - start)>>1) + start;
		int count = countRange(numbers, length, start, middle);
		if (end == start)
		{
			if(count > 1) return start;
			else break;
		}

		if(count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	}
	return -1;
}

// ====================测试代码====================
int main(){
	int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int result = getDuplication2(numbers, 8);
	if(result == -1) cout<<"None."<<endl;
	else cout << result<<endl;
}
