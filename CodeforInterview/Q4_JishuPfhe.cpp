//求一百以内的所有奇数的平方和
#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;


void Solution(){
    int temp = 0;
    for(int i = 1; i < 101; i++){
        if(i%2 != 0){
            temp += i*i;
        }
    }
    cout << "1^2+2^2+...+99^2 = " << temp <<endl;
    return;
}


int main(){
    Solution();
    system("pause");
    return 0;
}