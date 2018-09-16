#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 4

void rec(int l, int r, char *arr)
{
    for (int i=0;i<l-1;i++)
    	printf("    ");
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
            rec(l+1,r,arr);
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
    char arr[N];
    char simv;
    for (int i=0;i<N;i++)
    {
        scanf("%c",&simv);
        if (!isspace(simv))
        {
            arr[i] = simv;
            for (int j=0;j<i;j++)
                if (arr[i]==arr[j])
                {
                    printf("Sorry,you have the same symbols, try another\n");
                    i--;
                }
        }
        else
            i--;
    }
    printf("\n");
    rec(1,N,arr);
    return 0;
}