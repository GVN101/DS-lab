#include<stdio.h>
#include<math.h>
#define size 50
int f=-1,r=-1,ele,ch;
int q[size];
void insertq(int ele) 
     {
       if(f==(r+1)%size)
         printf("Queue is full!!");
       else
        {
         f=0;
         r=(r+1)%size;
         q[r]=ele;
        }   
     }
int deleteq() 
     {
       if(r==-1)
        {
         printf("Queue is empty!!\n");
         return 0;
        }
       else
        {
         ele=q[f];
         if(f==r)
           f=r=-1;
         else
           {
            f=(f+1)%size;
            return (ele);
           }    
        }  
       return 0; 
     }    
void display()
   { 
    if(r!=-1)
      for(int i=0;i<=r;i++)
        printf("%d\n",q[i]);
   }       
void main()
   {
    do
     {
      printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
      printf("Enter your choice:");
      scanf("%d",&ch);
      switch(ch)
        {
         case 1: printf("Enter the element to be pushed:");
                 scanf("%d",&ele);
                 insertq(ele);
                 break;  
         case 2: ele=deleteq();
                 if(ele==0)
                   printf("\n");
                 else
                  printf("The element is:%d\n",ele);
                 break;
         case 3: display();
                 break;
         case 4: printf("Program terminated.\n");
                 break;
         default: printf("\nInvalid choice!!!\n");
        }
      }while(ch!=4);
   }






















                                     
