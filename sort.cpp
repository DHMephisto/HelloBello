#include <iostream>
#include <vector>

using namespace std;
//交换函数
void swap(int& a, int& b){
	int temp = b;
	b = a;
	a = temp;
}




//插入法
void insert_sort(int a[], int len){
	int i,j,temp;
	for(i=1; i<len; i++){
		temp = a[i];
		for(j = i-1; j>=0 && a[j] > temp; j--){
			a[j+1] = a[j];
		}
		a[j+1] = temp;
	}
}


//堆排序
/*递归构建大根堆，index是第一个非叶子节点的下标*/
void adjust(int a[], int len, int index){
	int left = 2*index + 1;
	int right = 2*index + 2;

	int maxIdx = index;
	if(left<len && a[left] > a[maxIdx])	maxIdx = left;
	if(right<len && a[right] > a[maxIdx])	maxIdx = right;

	if(maxIdx != index)
	{
		swap(a[maxIdx], a[index]);
		adjust(a, len, maxIdx);
	}
}

// 堆排序主体
void heap_sort(int a[], int size)
{
    // 构建大根堆（从最后一个非叶子节点向上）
    for(int i=size/2 - 1; i >= 0; i--)
    {
        adjust(a, size, i);
    }

    // 调整大根堆
    for(int i = size - 1; i >= 1; i--)
    {
        swap(a[0], a[i]);           // 将当前最大的放置到数组末尾
        adjust(a, i, 0);              // 将未完成排序的部分继续进行堆排序
    }
}



//快速排序
void quick_sort(int a[], int Begin, int End){
	if(Begin >= End){
		return;
	}

	int temp = a[Begin];
	int left = Begin;
	int right = End;

	//递归检索把值分大小放在initial两侧
	while(left < right){
		while(a[right] >= temp && left < right){
			right --;
		}

		if(left < right){
			a[left] = a[right];
			left ++;
		}

		while(a[left] <= temp && left < right){
			left ++;
		}
		if(left < right){
			a[right] = a[left];
			right --;
		}
	}

	a[left] = temp;

	quick_sort(a, Begin, left-1);
	quick_sort(a, left+1, End);
}


//计数排序
void CoutSort(int* data, int len){
	
	if(len < 0) return;

	//确定最大值
	int max = data[0];
	int min = data[0];
	for (int i=1; i < len; i++){
		if(data[i] > max) max=data[i];
		if(data[i] < min) min=data[i];
	}
    int d = max - min;
    
    //创建统计数组
    int* coutData = new int[d + 1];
    for (int i = 0; i <= d; i++)
        coutData[i] = 0;
    for (int i=0; i<len; i++)
        ++coutData[data[i] - min];
    for (int i =1; i<=d; i++)
        coutData[i] += coutData[i - 1];
    
    //倒序遍历原始数组 找到元素正确位置 输出到结果数组
    int* sorted = new int[len];
    for (int i = len-1; i>=0; i--){
        sorted[coutData[data[i]-min] - 1] = data[i];
        coutData[data[i]-min]--;
    }
    //让原数组等于结果数组
    for (int i = 0; i<len; i++){
        data[i] = sorted[i];
    }
    return;
}



int main(){
	int a[] =  {23, 3, 5, 2, 45, 7, 3, 234, 78, 786};
	cout << "Before sort:" <<endl;
	int num = sizeof(a)/sizeof(a[0]);
	cout << "len = " << num << endl;
	for(int i=0; i<num; i++){
		cout << a[i] << " ";
	}
	cout << endl;


	//Using different methods to solve problem.

	//insert_sort(a,num);
	
	//heap_sort(a, num);

	//quick_sort(a, 0, num-1);
    
    CoutSort(a, num);

	cout << "After sort: "<< endl;
	for(int i =0; i<num; i++){
		cout << a[i] <<" ";
	}
	cout << endl;


	return 0;
}

