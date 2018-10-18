#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stddef.h>
#define N 100
typedef char type;

std::ifstream infile ("Tests/test1.txt");

template <typename T>
int enterBT(T * array, int cur)
{
    char bkt;
    char bkt1;
    char bkt2;
   // std::cout<< cur;
    infile >> array[cur++];
  //  std::cout << array[cur-1];
    infile >> bkt1;  //(
 //   std::cout << bkt1;
    if (bkt1 =='(')
    {
        cur = enterBT(array,cur);
        infile >> bkt; // )
//        std::cout << bkt;
    }
    infile >> bkt2; //(
 //  std::cout << bkt2;
    if (bkt2 =='(' )
    {
        cur = enterBT(array,cur);
        infile >> bkt; //)
     //   std::cout << bkt;
    }
    return cur;
}

int main()
{
    char bkt;
    int len;
    infile >> bkt; //(
  //  std::cout << bkt;
    type mas[N];
    len = enterBT(mas, 0);
    infile >> bkt; //)
//    std::cout << bkt <<std::endl;    
    for (int i=0;i<len;i++)
    {
        for (int j = 0;j<i;j++)
            if (mas[i]==mas[j])
            {
                std::cout << "True";
                return (0);
            }
      //  std::cout << mas[i];
    }
    std::cout << "False";
    return (0);
}
