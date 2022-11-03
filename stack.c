#include<stdio.h>
#define size 50
int top=0,ele,ch;
int stack[size];
void push(int ele)
    {
     if(top==size)
       printf("Stack is full\n");
     else
       stack[top++]=ele;
    }
int pop()
   {
    if(top==0)
      printf("Stack is empty\n");
    else
      {
       top--;
       ele=stack[top];
       return(ele);
      }
   }
int isempty()
   {
    if(top==0)
      return 1;
    else
      return 0;
   }
int isfull()
  {
   if(top==size)
     return 1;
   else
     return 0;
  }
int peek()
  {
   if(top==0)
     printf("Stack is empty\n");
   else
    {
     ele=stack[top-1];
     return (ele);
    }
  }
void display()
   { 
    if(!isempty==0)
      for(int i=0;i<top;i++)
        printf("%d\n",stack[i]);
   }     
void main()
   {
    do
     {
      printf("\n1.push\n2.pop\n3.peek\n4.isfull\n5.isempty\n6.display stack\n7.exit\n");
      printf("Enter your choice:");
      scanf("%d",&ch);
      switch(ch)
        {
         case 1: printf("enter the element to be pushed:");
                 scanf("%d",&ele);
                 push(ele);
                 break;  
         case 2: ele=pop();
                 printf("The element is:%d",ele);
                 break;
         case 3: ele=peek();
                 printf("The element is:%d",ele);
                 break;
         case 4: if(isfull()==1)
                   printf("Stack is full\n");
                 else
                   printf("Stack is not full\n");
                 break;   
         case 5: if(isempty()==1)
                   printf("Stack is empty\n");
                 else
                   printf("Stack is not empty\n");
                 break;  
         case 6: display();
                 break;
         case 7: break;
         default: printf("\nInvalid choice\n");
        }
      }while(ch!=7);
   }






















                                     
