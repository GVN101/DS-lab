#include<stdio.h>
#include<stdlib.h>
struct node{
     int coef,expo;
     struct node *link;
    };
struct node *Phead,*Qhead,*Rhead; 
struct node *ReadPoly()
    {
     struct node *new,*ptr,*head=NULL;
     int n,i;
     printf("Enter the number of terms:");
     scanf("%d",&n);
     printf("Enter the coefficients and exponents:\n");
     for(i=0;i<n;i++)
        {
         new=(struct node*)malloc(sizeof(struct node));
         scanf("%d",&new->coef);
         scanf("%d",&new->expo);  
         new->link=NULL;
         if(head==NULL){
            head=new;
            ptr=head;}
         else{
            ptr->link=new;
            ptr=new;}
        }
     return (head);
    }
void DisplayPoly(struct node*head)
    {
     struct node *ptr;
     if(head==NULL)
        printf("Polynomial is empty!!");
     else{
        ptr=head;
        while(ptr->link!=NULL)
           {
            printf("%dx^%d\t",ptr->coef,ptr->expo);
            ptr=ptr->link;
           }
        printf("%dx^%d\n",ptr->coef,ptr->expo);
        }
    }
struct node*AddPoly()
    {
     struct node *new,*P,*Q,*R,*head=NULL;
     P=Phead;
     Q=Qhead;
     while(P!=NULL && Q!=NULL)
         {
          if(P->expo==Q->expo)
             {
              new=(struct node *)malloc(sizeof(struct node));
              new->coef=P->coef+Q->coef;
              new->expo=P->expo;
              new->link=NULL;
              P=P->link;
              Q=Q->link;
             }
          else if(P->expo>Q->expo)
              {
	       new=(struct node *)malloc(sizeof(struct node));
	       new->coef=P->coef;
	       new->expo=P->expo;
	       new->link=NULL;
	       P=P->link;
              }
          else
              {
               new=(struct node *)malloc(sizeof(struct node));
               new->coef=Q->coef;
               new->expo=Q->expo;
               new->link=NULL;
               Q=Q->link;
              }
         if(head==NULL)
              {
               head=new;
               R=head;
              }
         else
               {
                R->link=new;
                R=new;
               }
        }
    while(P!=NULL)
        {
         new=(struct node *)malloc(sizeof(struct node));
         new->coef=P->coef;
         new->expo=P->expo;
         new->link=NULL;
         if(head==NULL)
             {
              head=new;
              R=head;
             }
         else
             {
              R->link=new;
              R=new;
             }
         P=P->link;
        }
    while(Q!=NULL)
        {
         new=(struct node *)malloc(sizeof(struct node));
         new->coef=Q->coef;
         new->expo=Q->expo;
         new->link=NULL;
         if(head==NULL)
             {
              head=new;
              R=head;
             }
         else
             {
              R->link=new;
              R=new;
             }
         Q=Q->link;
        }
    return(head);
   }
void main()
   {
    printf("\nEnter details of first polynomial:\n");
    Phead=ReadPoly();
    printf("\nEnter details of second polynomial:\n");
    Qhead=ReadPoly();
    printf("\nFirst Polynomial:");
    DisplayPoly(Phead);
    printf("\nSecond Polynomial:");
    DisplayPoly(Qhead);
    Rhead=AddPoly();
    printf("\nResultant Polynomial:");
    DisplayPoly(Rhead);
   }
