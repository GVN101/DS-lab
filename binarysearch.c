#include<stdio.h>
int binarysearch(int a[],int n,int key)
   {
     int t=0,b=n-1,mid;
     while(t<=b)
        {
         mid=(t+b)/2;
        if(a[mid]==key)
           return (mid+1);
        else if(a[mid]>key)
          b=mid-1;
        else
          t=mid+1;
        }
     return 0;
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
    c=binarysearch(x,n,key);
    if(c==0)
      printf("\nElement not found");
    else
      printf("\nElement found at pos:%d",c);
    printf("\n");
    return 0;
   } 
