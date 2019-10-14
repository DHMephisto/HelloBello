//找出输入字符串的最长不重复子串，并输出。
#include <iostream>
#include <cassert>
#include <string>
#include <windows.h>
using namespace std;

void UnreSubstr(const char* str){
    int sublen = 0;
    int templen = 0;
    int maxlenfrom = 0;
    int templenfrom = 0;
    assert(str != NULL);
    int len = strlen(str);
    int indexmemo[256];
    for(int i =0; i<256; i++) indexmemo[i] = -1;
    
    for(int i = 0; i < len; i++){
        if(indexmemo[str[i]] == -1){
            templen++;
            indexmemo[str[i]] = i;
        }
        else{
            if(templen > sublen){
            maxlenfrom = templenfrom;
            sublen = templen;
            }

            templenfrom = indexmemo[str[i]] + 1;
            templen = i - templenfrom + 1;
            for(int j = 0; j < templenfrom; j++){
                indexmemo[str[j]] = -1;
            }
            for(int k = templenfrom; k < (i+1); k++){
                indexmemo[str[k]] = k;
            }
            }
    }
    
    if (templen > sublen){ //针对最长子串在结尾的修正。
        sublen = templen;
        maxlenfrom = templenfrom;
        }
    

    cout << "The longest substring is: ";
    for (int k = maxlenfrom; k<(maxlenfrom+sublen); k++){
    cout << str[k];
    }
    cout << endl;
    cout << "The lenth of this substring is: " << sublen << endl;
    return;
    }


int main(){
    string str;
    cout << "Type your string plz." << endl;
    getline(cin,str);
    char* p = new char[str.length() + 1];
    strcpy(p, str.c_str());
    UnreSubstr(p);
    system("pause");
    return 0;
}