#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct Shoulder
{
    int length;
    int cargo;
}Shoulder;

typedef struct Crossbeam
{
    Shoulder left;
    Shoulder right;
}Crossbeam;

void read(Crossbeam *kor1)
{
    printf("Write the length of the left\n");
    scanf("%d",&kor1->left.length);
    printf("Write the weight of right (-1 if Crossbeam)\n");
    scanf("%d",&kor1->left.cargo);

    printf("Write the length of the right\n");
    scanf("%d",&kor1->right.length);
    printf("Write the weight of right (-1 if Crossbeam)\n");
    scanf("%d",&kor1->right.cargo);
}

int balanced(Crossbeam *kor)
{   
    int k1=kor->left.cargo;
    int k2=kor->right.cargo;
    if (kor->left.length < 0 || kor->right.length <0 || (k1<0 && k1 != -1) || (k2<0 && k2 != -1) )
    {
        printf("Incorrect data \n");
        return -1;
    }
    
   
    if (k1 == -1)
    {
        printf("L\n"); 
        Crossbeam *kor2 = (Crossbeam*)malloc(sizeof(Crossbeam));
        read(kor2);
        k1 = balanced(kor2);
        free(kor2);
        if (k1<0)
        {
            printf("Unbalanced \n");
            return -1;
        }
        
    }
    if (k2 == -1)
    {
        printf("R\n");
        Crossbeam *kor3 = (Crossbeam*)malloc(sizeof(Crossbeam));
        read(kor3);
        k2 = balanced(kor3);
        free(kor3);
        if (k2<0)
        {
            printf("Unbalanced \n");
            return -1;
        }
    }
    printf("%d %d\n",k1,k2);
    if (k1 * kor->left.length == k2 * kor->right.length)
    {
        return k1 + k2;
    }
    else 
    {
        printf("Unbalanced \n");
        return -1;
         
    }
}
int main()
{
    Crossbeam* kor1;
    kor1 = (Crossbeam*)malloc(sizeof(Crossbeam));
    read(kor1);

    if (balanced(kor1)>=0)
        printf("True\n");
    else
        printf("False\n");
    free(kor1);
    return 0;
}