#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

void const random(int* a, int len){
    srand((unsigned)time(NULL));
    int b[len] = {0};
    for(int i=0; i<5; i++){
        int r;
        while(1){
            r = rand() % len;
            if(b[r] == 0) break;
        }

        cout << a[r] << ", ";
        b[r]++;
    }
    cout << "\n";
    return;
}

int main()
{
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int len;
    len = sizeof(a)/sizeof(a[0]);
    
    random(a, len);
    system("pause");
    return 0;
}

