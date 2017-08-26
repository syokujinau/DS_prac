#include <stdio.h>
#include <stdlib.h>

void SetData(int x[],int i,int n)
{
    int data[]={20,24,27,46,57,15,23,29,48,62,65};//包含2段已排序子序列
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

void MergeSort(int x[],int sorted[],int i,int m,int n){
//修改參數，使得該函式的功能改為將x[i]~x[m]、x[m+1]~x[n]合併排序到sorted[i]~sorted[n]
    int j,k,a;
    j = m + 1;
    
    for(k=i;i<=m && j<=n;k++)//陣列分成2段子序列，所以迴圈條件也修正
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
    if(i>m)//陣列分成2段子序列，故修正為i>m
      for(a=j;a<=n;a++)
         sorted[k+a-j] = x[a];         /* 補上[j]~x[n] */
    else
      for(a=i;a<=m;a++)
         sorted[k+a-i] = x[a];         /* 補上[i]~x[m] */
}

int main()
{
    int x[100]={0};
    int sorted[100]={0};

    SetData(x,15,25);
    printf("排序前      x[15:19]="); PrintData(x,15,19);
    printf("排序前      x[20:25]=                    ");
    PrintData(x,20,25);
    
    MergeSort(x,sorted,15,19,25);//呼叫時輸入正確的索引位置
    
    printf("排序後 sorted[15:25]="); PrintData(sorted,15,25);
    system("pause");
    return 0;
}
