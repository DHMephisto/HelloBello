#include <iostream>
#include <vector>
#include <string>

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

//基数排序
//违反常理，为减少容器个数，从个位开始排序。

/*求数据的最大位数，决定排序次数*/
int maxbit(int data[], int n){
	int d = 1;
	int p = 10;
	for(int i = 0; i < n; i++){
		while(data[i] >= p)
		{
			p *= 10;
			d++;
		}
	}
	return d;
}
/*函数主体*/
void RadixSort(int data[], int n){
	int d = maxbit(data, n);
	int tmp[n];
	int count[10];
	int i, j, k;
	int radix = 1;
	for(i=1; i <= d; i++){
		for(j=0; j<10; j++){
			count[j] = 0;
		}
		for(j=0; j<n; j++){
			k = (data[j]/radix)%10;
			count[k]++;
		}
		for(j=1; j<10; j++){
                        count[j]=count[j-1]+count[j];
                }
		for(j=n-1; j>=0; j--){
			k = (data[j]/radix)%10;
			tmp[count[k]-1]=data[j];
			count[k]--;	
		}
		for(j=0; j<n; j++){
			data[j] = tmp[j];
		}
		radix = radix*10;
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

	string name;


	/*Using different methods to solve problem.*/

	//insert_sort(a,num); name = "insert";
	
	//heap_sort(a, num); name = "heap";

	//quick_sort(a, 0, num-1); name = "quick";
    
    	//CoutSort(a, num); name = "Cout";
	
	RadixSort(a, num); name = "Radix";

	cout << "After " << name << " sort: "<< endl;
	for(int i =0; i<num; i++){
		cout << a[i] <<" ";
	}
	cout << endl;


	return 0;
}

