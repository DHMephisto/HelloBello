// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。
#include <iostream>
using namespace std;

bool Find(int* matrix, int rows, int columns, int number)
{
	bool found = false;
	if(matrix != nullptr && rows>0 && columns >0)
	{
		int row = 0;
		int col = columns -1;
		while(row<rows && col>=0)
		{
			if(matrix[row*columns + col] == number)
			{
				found = true;
				break;
			}
			else if(matrix[row*columns + col] > number) --col;
			else ++row;
		}
	}
	return found;
}


int main()
{

	//  1   2   8   9
	//  2   4   9   12
	//  4   7   10  13
	//  6   8   11  15
	//int matrix[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int maxrows, maxcolumns;
	int test;
	cout <<"Input maxrows and maxcolumns."<<endl;
	cin >> maxrows;
	cin >> maxcolumns;
	int* pp_arr = new int[maxrows * maxcolumns];
	int (*p)[maxcolumns] = (int(*)[maxcolumns])pp_arr;
	
	cout << "Input your matrix."<<endl;

	for(int i = 0; i < maxrows; i++)
		for(int j = 0; j<maxcolumns; j++)
			cin >> p[i][j];

	cout << "Your matrix is shown as below."<< endl;
	for(int i =0; i<maxrows; i++)
	{	for(int j =0; j< maxcolumns; j++)
		{
			cout << p[i][j];
			cout << "   ";	
		}
		cout << endl;
	}

	cout << "Input the number that u want to find."<<endl;
	cin >> test;
	bool result = Find (pp_arr, 4, 4, test);
	if(result) cout << "Yes"<<endl;
	else cout << "No"<<endl;

	return 0;
}
