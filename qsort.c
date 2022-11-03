#include<stdio.h>
int partition(int a[],int l,int r)
   {
    int i=l+1,j=r,t;
    do
      {
       while(i<r && a[i]<a[l])
           i++;
       while(j>l && a[j]>a[l])
           j--;
       if(i<j)
         {
           t=a[i];
           a[i]=a[j];
           a[j]=t;
         }
      }while(i<j);
    t=a[j];
    a[j]=a[l];
    a[l]=t;
    return (j);
   }
int quicksort(int a[],int l,int r)
   {
    int pos;
    if(l<r)
      {
       pos=partition(a,l,r);
       quicksort(a,l,pos-1);
       quicksort(a,pos+1,r);
       
      }     
    return 0;  
   }
int read(int a[],int n)
   {
    printf("\nEnter the array elements:");
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
    return 0;
   }
int print(int a[],int n)
   {
    printf("The sorted array is:\n");
    for(int i=0;i<n;i++)
       printf("%d   ",a[i]);
    printf("\n");
    return 0;
   }
int main()
   {
    int x[100],n,l=0;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    read(x,n);
    quicksort(x,l,n-1);
    print(x,n);
    return 0;
   }             
               

