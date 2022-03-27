#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}list_node;

list_node *init_list(int num)
{
    int i;
    list_node *head = NULL;
    list_node *node = NULL;
    list_node *tmp = NULL;

    for(i = 0; i < num; i++)
    {
        node = (list_node *)malloc(sizeof(list_node));
        node->data = i;
        node->next = NULL;

        if(head == NULL)
        {
            head = node;
            tmp = node;
        }
        else
        {
            tmp->next = node;
            tmp = node;
        }
    }

    return head;
}

list_node * link_reversal(list_node * head)
{
    list_node *p, *q, *tmp;

    if(head == NULL) 
        return NULL;

    p = head;
    q = p->next;
    while(q != NULL)
    {
        tmp = q->next;
        q->next = p;
        p = q;
        q = tmp;
    }
    head->next = NULL;

    return p;
}

void list_print(list_node * head)
{
    list_node * tmp = head;

    do
    {
        printf("date:%d\n", tmp->data);
        tmp = tmp->next;
    }while(tmp->next != NULL);
}

int main()
{
    list_node *head = NULL;
    list_node *new_head = NULL;

    head = init_list(10);
    new_head = link_reversal(head);
    list_print(new_head);

    system("pause");
    return 0;
}