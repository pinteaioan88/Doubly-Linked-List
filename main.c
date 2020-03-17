#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
    int key;
    int nr_aparitii;
    struct nod *next,*prev;
}tip_nod;

typedef struct
{
    tip_nod *head;
}tip_head;

tip_head* makenull(tip_head *H)
{
    H=(tip_head*)malloc(sizeof(tip_head));
    H->head=(tip_nod*)malloc(sizeof(tip_nod));
    H->head=NULL;
    return H;
}

tip_nod* init_nod(int x)
{
    tip_nod *e;
    e=(tip_nod*)malloc(sizeof(tip_nod));
    e->key=x;
    e->nr_aparitii=1;
    e->next=e->prev=NULL;
    return e;
}
void insert(tip_head *H,tip_nod *x)
{
    tip_nod *p;
    int gasit=0;
    if(H->head==NULL)
    {
        H->head=x;
        return;
    }
    p=H->head;
    while(p!=NULL)
    {

        if (p->key==x->key)
        {
            p->nr_aparitii++;
            gasit =1;
            break;
        }
        else
            p=p->next;
    }
    if (gasit==0)
    {
        H->head->prev = x;
        x->next = H->head;
        H->head = x;
    }


}
void print(tip_head *H)
{
    tip_nod *n;
    n=H->head;
    printf("elementele listei sunt: \n");
    while(n!=NULL)
    {
        printf("%d aparitii %d  \n",n->key,n->nr_aparitii);
        n=n->next;
    }
}


int main()
{
    int key,i,n;
    tip_head *H;
    tip_nod *x;

    H=makenull(H);

    printf("n=");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("introduceti un element : ");
        scanf("%d",&key);
        x=init_nod(key);
        insert(H,x);

    }
    print(H);

    return 0;
}
