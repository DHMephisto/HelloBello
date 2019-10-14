//输出m个数字，输出最小的k个值。（尽量不完全排序的算法）
#include <iostream>
#include <windows.h>
using namespace std;

//交换函数
void swap(int& a, int& b){
	int temp = b;
	b = a;
	a = temp;
}
/*递归构建小根堆，index是第一个非叶子节点的下标*/
void adjust(int a[], int len, int index){
	int left = 2*index + 1;
	int right = 2*index + 2;

	int maxIdx = index;
	if(left<len && a[left] < a[maxIdx])	maxIdx = left;
	if(right<len && a[right] < a[maxIdx])	maxIdx = right;

	if(maxIdx != index)
	{
		swap(a[maxIdx], a[index]);
		adjust(a, len, maxIdx);
	}
}
// 变化后的堆排序（建好堆后直接输出最小值）
void heap_output(int size, int k)
{
    int a[size]={0};
    //输入数组信息；
    cout << "Input numbers: " << endl;
    for (int i = 0; i<size; i++)
    {
        cin >> a[i];
    }
    // 构建小根堆（从最后一个非叶子节点向上）
    for(int i=size/2 - 1; i >= 0; i--)
    {
        adjust(a, size, i);
    }

    // 输出最小值
    cout << "Least number is: " << endl;
    for(int i = size - 1; i >= size-k; i--)
    {
        swap(a[0], a[i]);           // 将当前最大的放置到数组末尾
        cout << a[i] <<" ";
        adjust(a, i, 0);              // 将未完成排序的部分继续进行堆排序
    }
    
}

int main()
{
    int size, k;
    cout << "How many numbers do u have?" <<endl;
    cin >> size;
    cout << "How many numbers do u want?" << endl;
    cin >> k;

    heap_output(size, k);
    system("pause");
    return 0;
}