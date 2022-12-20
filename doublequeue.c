#include<stdio.h>
#include<math.h>
#define size 50
int f=-1,r=-1,ele,ch,t=0;
int q[size];
void insertf(int ele) 
     {
       if(f==(r+1)%size)
         printf("Queue is full!!");
       else
        {
         if(f==-1)
           f=r=0;
         else
           {
            if(f==0)
              f=size-1;
            else
               f--;
           }
         q[f]=ele;
         t++; 
         display1();
        }  
     }
int deletef() 
     {
       if(f==-1)
        {
         printf("Queue is empty!!\n");
         return -20;
        }
       else
        {
         ele=q[f];
         t--;
         if(f==r)
           f=r=-1;
         else
           {
            f=(f+1)%size;
            return (ele);
           }    
        } 
        display1(); 
       return 0; 
     }
void insertr(int ele) 
     {
       if(f==(r+1)%size)
         printf("Queue is full!!");
       else
        {
         if(f==-1)
           f=0;
         r=(r+1)%size;
         q[r]=ele;
         t++;
         display1();
        }   
     }
int deleter() 
     {
       t--;   
       if(f==r==-1)
        {
         printf("Queue is empty!!\n");
         return -20;
        }
       else
        {
         ele=q[r];
         if(f==r)
           f=r=-1;
         else
           {
            if(r==0)
              r=size-1;
            else
             {
              r--; 
              return (ele);
             } 
           }  
        }  
       return 0; 
     }     
int display1()
   { int c=1;
      for(int j=f;c<=t;j=(j+1)%size,c++)
         printf("%d\t",q[j]);
 
      return 0;
   }       
void main()
   {
    do
     {
      printf("\n1.Insert front\n2.Delete front\n3.Insert rear\n4.Delete rear\n5.display\n6.exit\n");
      printf("Enter your choice:");
      scanf("%d",&ch);
      switch(ch)
        {
         case 1: printf("Enter the element to be pushed:");
                 scanf("%d",&ele);
                 insertf(ele);
                 break;  
         case 2:
                   ele=deletef();
                   if(ele!=-20)
                   printf("The element is:%d\n",ele);
                   display1();
                 break;
         case 3: printf("Enter the element to be pushed:");
                 scanf("%d",&ele);
                 insertr(ele);
                 break;
         case 4: ele=deleter();
                  printf("The element is:%d\n",ele);
                  display1();
                 break;
         case 5: display1();
                 break;
         case 6: printf("Program terminated.\n");
                 break;
         default: printf("\nInvalid choice!!!\n");
        }
      }while(ch!=6);
   }
