#include <stdio.h>
#include <stdlib.h>
#define N 4
char a[N];
void rec(int l, int r)
{
    char v;
    if (l==r)
    {
        for (int i=0;i<N;i++)
            printf("%c ", a[i]);
        printf("\n");
    }
    else
        for (int i=l-1;i < r;i++)
        {
            v=a[l-1];
            a[l-1]=a[i];
            a[i]=v;
            rec(l+1,r);
            v=a[l-1];
            a[l-1]=a[i];
            a[i]=v;
        }
    return;

}

int main()
{
    char c;
    for (int i=0;i<N;i++)
    {
        scanf("%c",&c);
        if (c != ' ')
            a[i] = c;
        else
            i--;
    }

    rec(1,N);
    return 0;
}