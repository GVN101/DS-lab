#include<stdio.h>
void simplemerge(int a[],int f,int s,int t)
    {
      int i=f,j=s,k=0,temp[100];
      while(i<s && j<=t)
          {
           if(a[i]<a[j])
             temp[k++]=a[i++];
           else 
             temp[k++]=a[j++];
          }
      while(i<s)
           temp[k++]=a[i++];
      while(j<=t)
           temp[k++]=a[i++];
      for(int i=f,k=0;i<=t;)
         a[i++]=temp[k++];
      }
void merge_sort(int a[],int l,int r)
    {
     int mid;
     if(l<r)
       {
        mid=(l+r)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        simplemerge(a,l,mid+1,r);
       }
    }
int main()
  {
   int x[100],n,m;
   printf("enter the number of elements in the array:");
   scanf("%d",&n);
   printf("enter the elements of the array:");
   for(int i=0;i<n;i++)       
       scanf("%d",&x[i]);
   merge_sort(x,0,(n-1));
   printf("sorted array is:");
   for(int i=0;i<n;i++)       
       printf("%d\t",x[i]);
   printf("\n");
   return 0;
  }    
