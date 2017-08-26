/*   Quick Sort algorithm  */
#include <stdio.h>
#include <stdlib.h>

void PrintData(int x[],int a,int b)
{
     int i;
     for(i=0;i<a;i++)
         printf("   ");
     for(i=a;i<=b;i++)
         printf("%3d",x[i]);
     printf("\n");
}

void QuickSort(int x[],int left,int right)
{
    int i,j,temp,K;
    /*在此處可加入列印內容觀察各步驟的變化*/
    printf("left=%2d,right=%2d  ",left,right);
    PrintData(x,left,right);
    if(left<right)
    {
       i = left+1;
       j = right;
       K = x[left];
       do
       {
          while(x[i]<K)//由左向右尋找過大者
             i++;         
          while(x[j]>K)//由右向左尋找過小者
             j--;        
          if(i<j)
          {
             temp = x[i]; x[i] = x[j]; x[j] = temp;
          }
       }while(i<j);
       temp = x[left]; x[left] = x[j]; x[j] = temp;

       QuickSort(x,left,j-1); 
       QuickSort(x,j+1 ,right); 
    }
}

int main()
{
    int x[10] = {30,24,27,16,29,33,25,18,32,35};

    printf("排序前            "); PrintData(x,0,9);
    QuickSort(x,0,9);
    printf("排序後            "); PrintData(x,0,9);    
    system("pause");
    return 0;
}
