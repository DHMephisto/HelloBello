//һ����������N������Ҫ��ȥ�������ظ������֡�Ȼ��������Ľ����
#include <iostream>
#include <windows.h>
using namespace std;

void DelRep(int* a, int len){
        //�ҵ����ֵ����Сֵ
        int min = a[0];
        int max = a[0];
        for (int i = 1; i < len; i++){
            if (a[i] < min){
                min = a[i];
            }
            if (a[i] > max){
                max = a[i];
            }
        }
        int lenb = max - min + 1;
        int b[lenb] = {0};
        int lennew;
        for (int j = 0; j < len; j++){
            b[(a[j]-min)]++;
        }
        for (int i = 0; i < lenb; i++){
            if (b[i] > 0) lennew ++;
        }
        int c[lennew] = {0};
        int k = 0;
        for(int i = 0; i < len; i++){
            if(b[(a[i]-min)] != 0){
            c[k] = a[i];
            k++;
            b[(a[i]-min)] = 0;
            }
        }
        for(int i = 0; i < lennew; i++){
            cout << c[i] << " ";
        }
        cout << endl;
        return;
}


int main(){

    int a[10] = {1,2,3,1,5,5,7,3,9,9};
    int len = sizeof(a)/sizeof(a[0]);

    DelRep(a, len);
    system ("pause");
    return 0;
}