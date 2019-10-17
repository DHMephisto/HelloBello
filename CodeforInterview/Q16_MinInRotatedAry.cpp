// ������11����ת�������С����
// ��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
// ����һ����������������һ����ת�������ת�������СԪ�ء���������
// {3, 4, 5, 1, 2}Ϊ{1, 2, 3, 4, 5}��һ����ת�����������СֵΪ1��

//������򵥵�˼·��Ȼ�ǣ�����һ������Ϳ����ҵ���
//���˷�����ȫû��������Ŀ���ԡ����Կ����ö��ַ�������
//���ַ����ѵ����ڶ��������ȵ����������{1��0��1��1��1} ���� {1��1��1��0��1}
//��������ڶ��ַ���һ�����޷��б����䣬����ֻ�ܱ�����

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

        //�ȿ������������������ȵ������
        if(numbers[ind_right] == numbers[ind_left] && numbers[ind_right] == numbers[ind_mid])
        {
            return FindMin(numbers, ind_left, ind_right);
        }

        //�������
        if(numbers[ind_mid] >= numbers[ind_left])
        {
            ind_left = ind_mid;
        }else{
            ind_right = ind_mid;
        }
    }

    return numbers[ind_mid];
}

//��������
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