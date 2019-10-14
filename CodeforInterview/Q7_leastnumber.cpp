//���m�����֣������С��k��ֵ������������ȫ������㷨��
#include <iostream>
#include <windows.h>
using namespace std;

//��������
void swap(int& a, int& b){
	int temp = b;
	b = a;
	a = temp;
}
/*�ݹ鹹��С���ѣ�index�ǵ�һ����Ҷ�ӽڵ���±�*/
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
// �仯��Ķ����򣨽��öѺ�ֱ�������Сֵ��
void heap_output(int size, int k)
{
    int a[size]={0};
    //����������Ϣ��
    cout << "Input numbers: " << endl;
    for (int i = 0; i<size; i++)
    {
        cin >> a[i];
    }
    // ����С���ѣ������һ����Ҷ�ӽڵ����ϣ�
    for(int i=size/2 - 1; i >= 0; i--)
    {
        adjust(a, size, i);
    }

    // �����Сֵ
    cout << "Least number is: " << endl;
    for(int i = size - 1; i >= size-k; i--)
    {
        swap(a[0], a[i]);           // ����ǰ���ķ��õ�����ĩβ
        cout << a[i] <<" ";
        adjust(a, i, 0);              // ��δ�������Ĳ��ּ������ж�����
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