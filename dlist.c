#include <stdio.h>
#include <stdlib.h>
struct node
  {
   int data;
   struct node *prev,*next;
  };
struct node *head=NULL;
void display()
   {
    struct node *ptr;
    if(head==NULL)
        printf("\nLinked list is empty");
    else
      {
       ptr=head;
       printf("\nLinked list elements are:");
       while(ptr!=NULL)
          {
           printf("\t%d",ptr->data);
           ptr=ptr->next;
          }
      }
    } 
void insertfront(int x)
    {
     struct node *new; 
     new=(struct node *)malloc(sizeof(struct node));
     new->data=x;
     new->prev=new->next=NULL;
     if(head==NULL)
        head=new;
     else
        {
         new->next=head;
         head->prev=new;
         head=new;
        }
     display();
    }
void insertend(int x)
   {
    struct node *new,*ptr;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=x;
    new->prev=new->next=NULL;
    if(head==NULL)
       head=new;
    else
      {
       ptr=head;
       while(ptr->next!=NULL)
          ptr=ptr->next;
       ptr->next=new;
       new->prev=ptr;
      }
    display();
   }
void insertafter(int key,int x)
    {
     struct node *new,*ptr;
     if(head==NULL)
        printf("Insertion is not possible,empty list!!");
     else
        {
         ptr=head;
         while(ptr->data!=key && ptr->next!=NULL)
             ptr=ptr->next;
         if(ptr->data!=key)
             printf("Insertion not possible,element not found!!");
         else
            {
             new=(struct node *)malloc(sizeof(struct node));
             new->data=x;
             new->prev=ptr;
             new->next=ptr->next;
             if(new->next!=NULL)
                new->next->prev=new;
             ptr->next=new;
            }
        }
     display();
    }
void insertbefore(int key,int x)
    {
     struct node *new,*ptr;
     ptr=head;
     while(ptr->data!=key && ptr!=NULL)
         ptr=ptr->next;
     if(ptr==NULL)
         printf("Node not found");
     else
        {
         new=(struct node *)malloc(sizeof(struct node));
         new->data=x;
         new->prev=ptr->prev;
         new->next=ptr; 
        }
     if(ptr->prev==NULL)
        head=new;
     else 
        {
         ptr->prev->next=new;
         ptr->prev=new;
        }
     display();
    }                   
void deletefront()
   {
    struct node *temp;
    if(head==NULL)
    printf("Deletion not possible");
    else if(head->next==NULL)
       {
        temp=head;
        head=NULL;
        free(temp);
       }
    else
        {
         head=head->next;
         free(head->prev);
         head->prev=NULL;
        }
    display();
   }
void deleteend()
    {
     struct node *ptr,*temp;
     if(head==NULL)
     printf("Deletion not possible");
     else if(head->next==NULL)
        {
         temp=head;
         head=NULL;
         free(temp);
        }
     else
        {
         ptr=head;
         while(ptr->next!=NULL)
             ptr=ptr->next;
         ptr->prev->next=NULL;
         free(ptr);
        }
     display();
    }
void deleteany(int pos)
    {
     int i=1;
     struct node *temp;
     temp=head;
     while(i<pos)
        {
         temp=temp->next;
         i++;
        }
     temp->prev->next=temp->next;
     temp->next->prev=temp->prev;
     free(temp);
     display();
    }
void search(int key)
    {
     int count=1;
     struct node *ptr;
     if(head==NULL)
         printf("Key not found");
     else
        {
         ptr=head;
         while(ptr->data!=key && ptr->next!=NULL)
            {
             ptr=ptr->next;
             count++;
            }
         if(ptr->data=key)
            printf("Key is found at %d",count);
         else
            printf("Key not found");
        }
    }    
void main()
    {
     int ch,x,key,pos;
     do
       {
        printf("\n1.Insert front\n2.Insert end\n3.Insert after\n4.Insert Before\n5.Delete front\n6.Delete end\n7.Delete any\n8.Display\n9.Search\n10.Exit\n");
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
           {
            case 1 : printf("Enter new data:");
                     scanf("%d",&x);
                     insertfront(x);
                     break;
            case 2 : printf("Enter new data:");
                     scanf("%d",&x);
                     insertend(x);
                     break;
            case 3 : if(head==NULL)
                        printf("List is empty!!");
                     else{
                          printf("Enter the element after which insertion should take place:");
                          scanf("%d",&key);
                          printf("Enter new data:");
                          scanf("%d",&x);
                          insertafter(key,x);}
                     break;
            case 4 : if(head==NULL)
                        printf("List is empty");
                     else{
                        printf("Enter the element before which insertion should take place:");
                        scanf("%d",&key);
                        printf("Enter new data:");
                        scanf("%d",&x);
                        insertbefore(key,x);}
                     break;
            case 5 : deletefront();
                     break;
            case 6 : deleteend();
                     break;
            case 7 : printf("Enter position of node to be deleted:");
                     scanf("%d",&pos);
                     deleteany(pos);
                     break;
            case 8 : display();
                     break;
            case 9 : printf("Enter the key to be searched:");
                     scanf("%d",&key);
                     search(key);
                     break;
            case 10 : printf("Program terminated successfully\n");
                     break;
            default: printf("Invalid choice!!");
           }
        }while(ch!=10);
    }

