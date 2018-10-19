#include <iostream>
#include <fstream>
#include <cstdlib>
#define N 100
typedef char type;

template <typename T>
int enterBT(T * array, int cur)
{
    char bkt;
    char bkt1;
    char bkt2;
    std::cin >> array[cur++];
    std::cout << array[cur-1] << std::endl;
    std::cin >> bkt1;  // '('
    if (bkt1 =='(')
    {
        cur = enterBT(array,cur);
        std::cin >> bkt; // ')'
    }
    std::cin >> bkt2; // '('
    if (bkt2 =='(' )
    {
        cur = enterBT(array,cur);
        std::cin >> bkt; // ')'
    }
    return cur;
}

int main()
{
    char bkt;
    int len;
    std::cin >> bkt; // '('
    type mas[N];
    len = enterBT(mas, 0);
    std::cin >> bkt; // ')'
    for (int i=0;i<len;i++)
    {
        for (int j = 0;j<i;j++)
            if (mas[i]==mas[j])
            {
                std::cout << "True, duplicate element is " << mas[i] << std::endl;
                return (0);
            }
    }
    std::cout << "False" << std::endl;
    return (0);
}
