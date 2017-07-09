#include <stdio.h>
#include <stdlib.h>

struct s{
	int i;
	int *p;  //結構體成員包含指標 用來指向int型態的記憶體空間
};

struct sr{ //用結構體實作Linked-list需使用self-reference 
	int data; 
	struct sr *p;  //結構體成員包含指標 用來指向其他結構體的記憶體空間
};

int main(void){

	/****************Test1**************/
	int num = 100;
	struct s s1;
	s1.i = 10;
	s1.p = &num;   //結構體中的指標指向num的int型態記憶體空間

	printf("s1.i = %d\n",s1.i);
	printf("s1.p = %0X ; &num = %0X\n",s1.p,&num);
	printf("*(s1.p) = %d\n\n", *(s1.p));
	/*************Test1 END*************/
	/****************Test2**************/
	struct sr sr1,sr2; //宣告結構體變數sr1指向sr2
	sr1.data = 10;     //sr1的成員data，用來存放資料
	sr1.p = &sr2;      //sr1的指標成員p，用來指向sr2結構體的記憶體空間
	sr2.data = 20;     //sr2的成員data，用來存放資料
	sr2.p = NULL;      //sr2的指標成員p指向NULL，完成單向鏈結串列
	
	printf("sr1.data = %d\n",sr1.data);
	printf("sr1.p    = %0X\n", sr1.p);
	printf("&sr2     = %0X\n", &sr2);
	printf("sr2.data = %d\n",sr2.data);
	printf("sr2.p    = %0X\n", sr2.p);
	/*************Test2 END*************/
	return 0;
}

/*result:
sr1.data = 10
sr1.p    = 6913AA30
&sr2     = 6913AA30
sr2.data = 20
sr2.p    = 0
*/