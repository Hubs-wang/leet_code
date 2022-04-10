#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int date;
    struct node *next;
}Lnode;

Lnode *init_circl_link(int num)
{
    Lnode *head, *tmp, *node;
    int i;

    head = tmp = node = NULL;
    for(i = 0; i < num; i++)
    {
        node = (Lnode *)malloc(sizeof(Lnode));
        node->date = i;
        node->next = NULL;
        if(head == NULL)
        {
            head = tmp = node;
        }
        else
        {
            tmp->next = node;
            tmp = node;
        }
    }
    tmp->next = head;

    return head;
}

void find_node(Lnode *head, int k, int m)
{
    Lnode *p, *q;
    int i, ret;

    if(head == NULL)
        return;
    
    p = head;
    while(p->date != k)
        p = p->next;
    
    while(p->next != p)
    {
        for(i = 0; i < m; i++)
        {
            q = p;
            p = p->next;
        }
        ret = p->date;
        q->next = p->next;
        printf("chu quan number:%d\n", ret);
        free(p);
        p = q->next;
    }
    


}
int main()
{
    Lnode *link;

    link = init_circl_link(10);
    find_node(link, 1, 5);

    system("pause");
    return 0;

}