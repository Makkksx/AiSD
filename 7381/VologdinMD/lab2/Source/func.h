#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

// Описание структуры Shoulder
typedef struct Shoulder
{
    int length_left;
    int cargo_left;
    int length_right;
    int cargo_right;
    struct Shoulder *left;
    struct Shoulder *right;

}Shoulder;

// Создание структуры Shoulder

Shoulder* createShoulder()
{
    Shoulder* create = (Shoulder*)malloc(sizeof(Shoulder));
    create->length_left = 0;
    create->cargo_left = 0;
    create->length_right = 0;
    create->cargo_right = 0;
    create->left=NULL;
    create->right=NULL;
    return create;
}

void clear(Shoulder *head)
{
    if (!head)
    {
        return;
    }
    if (head->left)
    {
        clear(head->left);
    }
    if (head->right)
    {
        clear(head->right);
    }
    free(head);
    return;
}
