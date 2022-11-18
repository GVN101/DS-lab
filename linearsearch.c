#include<stdio.h>
int linearsearch(int a[],int n,int key)
   {
     int c=0;
     for(int i=0;i<n;i++)
        if(a[i]==key)
          {
           c=i+1;
           break;
          }
     return c;
    }       
int read(int a[],int n)
   {
    printf("\nEnter the elements:");
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
    return 0;
   }
int main()
   {
    int x[100],n,key,c;
    printf("enter the number of elements:");
    scanf("%d",&n);
    read(x,n);
    printf("Enter the element to be searched:");
    scanf("%d",&key);
    c=linearsearch(x,n,key);
    if(c==0)
      printf("\nElement not found");
    else
      printf("\nElement found at pos:%d",c);
    printf("\n");
    return 0;
   } 
