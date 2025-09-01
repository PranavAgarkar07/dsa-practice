#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

struct node
{
    int p;
    int d;
    struct node *next;
};

struct node *ins(struct node *, int, int);
struct node *del(struct node *);
void display(struct node *);

void main()
{
    struct node *s;
    s = NULL;
    int ch, item, pr;
    while (1)
    {
        pf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice: ");
        sf("%d", &ch);
        switch (ch)
        {
        case 1:
            pf("\nEnter element to be addsed: ");
            sf("%d", &item);
            sf("%d", &pr);
            s = ins(s, item, pr);
            break;
        case 2:
            s = del(s);
            break;
        case 3:
            display(s);
            break;
        case 4:
            exit(1);
        default:
            pf("\nWrong choice");
        }
    }
}

struct node *ins(struct node *s, int item, int pr)
{
    struct node *temp, *ptemp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->p = pr;
    temp->d = item;
    if (s == NULL || (pr < s->p))
    {
        temp->next = s;
        s = temp;
        return s;
    }
    ptemp = s;
    while ((ptemp->next) != NULL && (ptemp->next)->p <= pr)
        ptemp = ptemp->next;
    temp->next = ptemp->next;
    ptemp->next = temp;
    return s;
};

struct node *del(struct node *s)
{
    struct node *temp;
    if (s == NULL)
    {
        pf("\nQueue underflow");
        return s;
    }
    temp = s;
    pf("\n%d deleted", temp->d);
    s = s->next;
    free(temp);
    return s;
};

void display(struct node *s)
{
    struct node *ptr;
    ptr = s;
    if (ptr == NULL)
    {
        pf("\nQueue is empty");
        return;
    }
    pf("\n Element in Queue are:\n");
    pf("\n Priority \t Data");
    while (ptr != NULL)
    {
        pf("\n%d\t\t%d", ptr->p, ptr->d);
        ptr = ptr->next;
    }
}
