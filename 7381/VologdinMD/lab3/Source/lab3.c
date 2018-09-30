#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

struct node
{
    char value;
    struct node *next;
};
struct Stack
{
    struct node *head;
    int size;
};
struct Stack init()
{
    struct Stack stack = {NULL, 0};
    return stack;
}
void push(struct Stack *stk, char simv)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->value = simv;
    node->next = stk->head;
    stk->head = node;
    stk->size++;
}
char pop(struct Stack *stk)
{
    struct node *node = stk->head;
    stk->head = stk->head->next;
    char res = node->value;
    free(node);
    stk->size--;
    return res;
}
char top(struct Stack *stk)
{
    return (stk->head ? stk->head->value : 0);
}
int IsEmpty(struct Stack *stk)
{
    return (!stk->size);
}
int isopen(char bkt)
{
    return (bkt == '(' || bkt == '[' || bkt == '{');
}
int isclose(char bkt)
{
     return (bkt == ')' || bkt == ']' || bkt == '}');
}
int isbkt(char bkt)
{
    return (isopen(bkt) || isclose(bkt));
}

int main()
{
    struct Stack stack = init();
    char str[500];
    fgets(str,500,stdin);
    for (int i=0; i<strlen(str);i++)
    {
        char c = str[i];
        if (isbkt(c))
        {
            if (isopen(c))
            {
                push(&stack,c);
            }
            else
            {
                if (!IsEmpty(&stack))
                    switch (top(&stack))
                    {
                        case '(':
                            if (c == ')')
                                pop(&stack);
                            else
                            {
                                printf("%d - wrong position\n",i);
                                return 0;
                            }
                            break;
                         case '[':
                            if (c == ']')
                                pop(&stack);
                            else
                            {
                                printf("%d - wrong position\n",i);
                                return 0;
                            }
                            break;
                        case '{':
                            if (c == '}')
                                pop(&stack);
                            else
                            {
                                printf("%d - wrong position\n",i);
                                return 0;
                            }
                            break;
                        default:
                            printf("%d - wrong position\n",i);
                            return 0;
                    }
                else
                {
                    printf("%d - wrong position",i);
                    return 0;
                }
            }
        }
    }
    printf("%s", IsEmpty(&stack) ? "correct" : "wrong, there are not enough closing brackets at the end\n");
    return 0;
}
