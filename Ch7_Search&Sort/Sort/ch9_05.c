/*   Merge Sort algorithm - iteration version  */
#include <stdio.h>
#include <stdlib.h>

void SetData(int x[],int i,int n)
{
    int data[] = {20,24,27,46,57,15,23,29,48,62,65};
    int j;
    for(j=i;j<=n;j++)
       x[j] = data[j-i];
}

void PrintData(int x[],int i,int n)
{
    int j;
    for(j=i;j<=n;j++)
       printf("%2d  ",x[j]);
    printf("\n");
} 

void MergeSort(int x[],int sorted[],int i,int m,int n)
{
    int j,k,a;
    j = m + 1;
    
    for(k=i;i<=m && j<=n;k++)
    {
      if(x[i]<=x[j])
      {
       sorted[k] = x[i];
       i++;
      }
      else
      {
       sorted[k] = x[j];
       j++;
      }
    }
    if(i>m)
      for(a=j;a<=n;a++)
         sorted[k+a-j] = x[a];         /* 補上[j]~x[n] */
    else
      for(a=i;a<=m;a++)
         sorted[k+a-i] = x[a];         /* 補上[i]~x[m] */
}

void MergePass(int x[],int sorted[],int n,int len)
{
    int i,j;
    for(i=0;i<=n-2*len;i=i+2*len)//處理該次Pass中，長度足夠的子串列合併
      MergeSort(x,sorted,i,i+len-1,i+2*len-1);

    if(i+len<n)       //長度不足的子串列合併
      MergeSort(x,sorted,i,i+len-1,n-1);
    else                  
      for(j=i;j<n;j++)      //n為單數，會導致後面有一個落單，故在此處理
         sorted[j] = x[j];
}

int main()
{
    int x[100]={0};
    int sorted[100]={0};
    int len,i,n=7;

    SetData(x,0,6);
    printf("排序前      x[]="); PrintData(x,0,n-1);
    
    for(len=1,i=1;len<n;len=2*len,i++)  //迴圈版的合併排序
    {
      if((i%2)==1)
          MergePass(x,sorted,n,len);
      else
          MergePass(sorted,x,n,len);
    }
    
    printf("排序後 sorted[]="); PrintData(sorted,0,n-1);
    
    system("pause");
    return 0;
}

