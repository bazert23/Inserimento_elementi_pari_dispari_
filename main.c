#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// servono per definire la lista
typedef struct node* link;
struct node {int val; link next;};

// le 3 funzioni necessarie al problema
link Inserimentoinlistaordinata(link h,int val);
link NewNode(int val,link next);
void listTravR(link h);
#define  N 6



int main() {
    int i;
    setbuf(stdout,0);
   int v[N]={1,7,8,3,4,5};

   // inizialmente le due liste non puntano a niente

   //lista numeri pari
    link head_pari= NULL;
   //lista numeri dispari
   link head_dispari=NULL;


   for(i=0;i<N;i++)
   {
       if (v[i]%2==0)
       { // se e' pari inserisco in lista pari
          head_pari=Inserimentoinlistaordinata(head_pari,v[i]);//inserimento in lista ordinata pari
       }
       else
       {    // se e' dispati in lista dispari
           head_dispari=Inserimentoinlistaordinata(head_dispari,v[i]);//inserimento in lista ordinata disapri
       }


   }
    listTravR(head_pari);
    listTravR(head_dispari);
    return 0;
}

link Inserimentoinlistaordinata(link h,int val)
{
    link x,p; // due puntatori con cui scorro la lista
    if(h==NULL ||( (h->val) > val)) // se e' vuota o il primo elemento e' maggiore dell'attuale inserimento in testa
    {
        return NewNode(val,h);
    }
    for(x=h->next,p=h; // scorro: ho due puntatori: uno punta al prossimo, uno a NULL
        x!=NULL &&  ( val > (h->val));
        // finchè non sono alla fine e il prossimo e'
        // Null e quello che ho e' maggiore del valore in lista vado avanti
        p=x,x=x->next); // ad  ogni iterazione assegno p a quello di prima e mando avanti x
    p->next=NewNode(val,x); //  sono arrivato alla posizione in cui inserire : il prossimo rispetto a quello che vedo prima
    return h;


    return h;
}

link NewNode(int val,link next)
{
    link x=malloc(sizeof *x);
    if(x==NULL)
        return NULL;
    else
    {
        x->val=val;
        x->next=next;
    }
    return x;
}
void listTravR(link h)
{
    if(h==NULL) {
        printf("\n Fine Lista \n");
        return;
    }

        printf("%d",h->val);
        listTravR(h->next);


}