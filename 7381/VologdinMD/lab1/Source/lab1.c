#include <stdio.h>
#include <stdlib.h>
#define N 4
char arr[N];
void rec(int l, int r)
{
    printf("call rec\n");
    char temp;
    if (l==r)
    {
        printf("Result ");
        for (int i=0;i<N;i++)
            printf("%c ", arr[i]);
        printf("\n");
    }
    else
        for (int i=l-1;i < r;i++)
        {
            if (l-1 != i)
            {
                temp=arr[l-1];
                arr[l-1]=arr[i];
                arr[i]=temp;
            }
            rec(l+1,r);
            if (l-1 != i)
            {
                temp=arr[l-1];
                arr[l-1]=arr[i];
                arr[i]=temp;
            }
        }
    return;
}

int main()
{
    char simv;
    for (int i=0;i<N;i++)
    {
        scanf("%c",&simv);
        if (simv != ' ')
            arr[i] = simv;
        else
            i--;
    }
    printf("\n");
    rec(1,N);
    return 0;
}