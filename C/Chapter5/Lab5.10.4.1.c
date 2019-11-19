#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int value;
    struct element *next;
} element;
void iteratingOverList(int count, element* elem)
{
    int counter = 0;
    printf("First %d values: \n", count);
    while(counter < count && elem != NULL)
    {
        printf("%d\n", elem->value);
        elem = elem->next;
        counter++;
    }
}
int main()
{

    int values[10] = { 2, 4, 5, 6, 7, 8, 9, 1, 3, 0};
    element* head = (element*)malloc(sizeof(element));
    head->value = values[0];
    element* next1 = (element*)malloc(sizeof(element));
    next1->value = values[1];
    head->next = next1;
    element* next2 = (element*)malloc(sizeof(element));
    next2->value = values[2];
    next1->next = next2;
    element* next3 = (element*)malloc(sizeof(element));
    next3->value = values[3];
    next2->next = next3;
    element* next4 = (element*)malloc(sizeof(element));
    next4->value = values[4];
    next3->next = next4;
    iteratingOverList(5, head);
    element* next5 = (element*)malloc(sizeof(element));
    next5->value = values[5];
    next4->next = next5;
    element* next6 = (element*)malloc(sizeof(element));
    next6->value = values[6];
    next5->next = next6;
    iteratingOverList(7, head);

    return 0;
}
