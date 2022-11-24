#include <stdlib.h>
#include <stdio.h>
struct node
   {
    int info;
    struct node *link;
   };
struct node *head=NULL;
void display()
   {
    struct node *ptr;
    if(head==NULL)
      printf("List is empty!!");
    else
    {
      ptr=head;
      printf("\nElements are:\n");
      while(ptr!=NULL)
          {
           printf("%d\t",ptr->info);
           ptr=ptr->link;
          }
     }
    }
void insertf(int ele)
    {
     struct node *new;
     new=(struct node *)malloc(sizeof(struct node));
     new->info=ele;
     new->link=head;
     head=new;
     display();
    }
void insertend(int ele)
   {
    struct node *new,*ptr;
    new=(struct node *)malloc(sizeof(struct node));
    new->info=ele;
    new->link=NULL;
    if(head==NULL)
       head=new;
    else
      {
       ptr=head;
       while(ptr->link!=NULL)
           ptr=ptr->link;
       ptr->link=new;
      }
    display();
   }    
void insertafter(int key,int ele)
   {
    struct node *new,*ptr;
    if(head==NULL)
      printf("Insertion is not possible,empty list!!");
    else
     {
      ptr=head;
      while(ptr->info!=key && ptr->link!=NULL)
          ptr=ptr->link;
      if(ptr->info!=key)
          printf("Insertion not possible,element not found!!");
      else
       {
        new=(struct node *)malloc(sizeof(struct node));
        new->info=ele;
        new->link=ptr->link; 
        ptr->link=new;
       }
      }
    display();
   }
void insertbefore(int key,int ele)
   {
    struct node *new,*ptr,*prev=NULL;
        ptr=head;
      while(ptr!=NULL &&  ptr->info!=key  )
          {
           prev=ptr;
           ptr=ptr->link;
          }
      if(ptr==NULL)
          printf("Insertion not possible,element not found!!");
      else
       {printf("Insert after %d   %d!",key,ele);
        new=(struct node *)malloc(sizeof(struct node));
        new->info=ele;
        new->link=ptr;
        if(ptr==head)
           head=new;
        else
           prev->link=new;
       }
      
    display();
   }
void deletefront()
   {
    struct node *temp;
    if(head==NULL)
       printf("Deletion not possible,empty list!!");
    else
       {
        temp=head;
        head=head->link;
        free(temp);
       }
    display();
   }
void deleteend()
    {
     struct node *prev,*curr,*temp;
     if(head==NULL)
         printf("Deletion not possible,empty list!!");
     else if(head->link==NULL)
        {
         temp=head;
         head=NULL;
         free(temp);
        }
     else
        { 
         prev=head;
         curr=head->link;
         while(curr->link!=NULL)
            {
             prev=curr;
             curr=curr->link;
            }
         prev->link=NULL;
         free(curr);
        }
     display();
    }
void deleteany(int key)
    {
     struct node *prev,*curr,*temp;
     if(head==NULL)
        printf("Deletion not possible,empty list!!");
     else if(head->info==key)
        {
         temp=head;
         head=head->link;
         free(temp);
        }
     else
        {
         prev=head;
         curr=head;
         while(curr->info!=key && curr->link!=NULL)
            {
             prev=curr;
             curr=curr->link;
            }
         if(curr->info!=key)
         printf("Deletion is not possible,element not found!!");
     else
         {
          prev->link=curr->link;
          free(curr);
         }
        }
     display();
    }   
void main()
   {
    int ele,ch,key;
    do
     {
      printf("\n1.Insert front\n2.Delete front\n3.Insert end\n4.Delete end\n5.Insert after an element x\n6.Insert before an element x\n7.Delete an element x\n8.Display\n9.Exit\n");
      printf("Enter your choice:");
      scanf("%d",&ch);
      switch(ch)
        {
         case 1: printf("Enter the element to be pushed:");
                 scanf("%d",&ele);
                 insertf(ele);
                 break;  
         case 2: deletefront();
                 break;
         case 3: printf("Enter the element to be pushed:");
                 scanf("%d",&ele);
                 insertend(ele);
                 break;
         case 4: deleteend();
                 break;
         case 5: printf("Enter the element to be pushed:");
                 scanf("%d",&ele);
                 printf("Enter the element after which given element should be pushed:");
                 scanf("%d",&key);
                 insertafter(key,ele);
                 break;
         case 6: printf("Enter the element to be pushed:");
                 scanf("%d",&ele);
                 printf("Enter the element before which given element should be pushed:");
                 scanf("%d",&key);
                 insertbefore(key,ele);
                 break;
         case 7: printf("Enter the element to be deleted:");
                 scanf("%d",&ele);
                 deleteany(ele);
                 break;
         case 8: display();
                 break;
         case 9: printf("Program terminated.\n");
                 break;
         default: printf("\nInvalid choice!!!\n");
        }
      }while(ch!=9);
   }





