// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

//本题最简单的思路自然是，遍历一遍数组就可以找到。
//但此方法完全没有利用题目特性。所以考虑用二分法来做。
//二分法的难点在于多个数字相等的情况。比如{1，0，1，1，1} 或者 {1，1，1，0，1}
//该情况下在二分法第一步便无法判别区间，所以只能遍历。

#include <iostream>
#include <exception>
#include <windows.h>

int FindMin(int*numbers, int left, int right);

int Min(int* numbers, int len)
{
    if(numbers == nullptr || len<=0)
    {
        std::logic_error ex("Invalid input.");
        throw std::exception(ex);
    } 

    int ind_left = 0;
    int ind_right = len - 1;
    int ind_mid = ind_left;
    while(numbers[ind_left] >= numbers[ind_right])
    {
        if (ind_right - ind_left == 1)
        {
            ind_mid = ind_right;
            break;
        }

        ind_mid = (ind_left + ind_right)/2;

        //先考虑最不想遇见的三数相等的情况。
        if(numbers[ind_right] == numbers[ind_left] && numbers[ind_right] == numbers[ind_mid])
        {
            return FindMin(numbers, ind_left, ind_right);
        }

        //常规情况
        if(numbers[ind_mid] >= numbers[ind_left])
        {
            ind_left = ind_mid;
        }else{
            ind_right = ind_mid;
        }
    }

    return numbers[ind_mid];
}

//遍历查找
int FindMin(int* numbers, int left, int right)
{
    int result = numbers[left];
    for(int i = left; i < right; ++i)
    {
        if (numbers[i] < result)
        {
            result = numbers[i];
        }
    }
    return result;
}

int main()
{
    std::cout << "Input array length." << std::endl;
    int len;
    std::cin >> len;
    std::cout << "Input array numbers." << std::endl;
    int numbers[len] = {0};
    for(int i = 0; i < len; ++i)
    {
        std::cin >> numbers[i];
    }
    std::cout << "Your array is: " <<"{";
    for(int i = 0; i < len; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << "}" << std::endl;

    int result = Min(numbers, len);
    std::cout << "Result is: " << result << std::endl;

    system("pause");

    return 0;    
}