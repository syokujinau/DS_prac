struct s{
  int i;
  int *p;  //結構體成員包含指標 用來指向int型態的記憶體空間
};

struct sr{ //用結構體實作Linked-list需使用self-reference 
  int data; 
  struct sr *p;  //結構體成員包含指標 用來指向其他結構體的記憶體空間
};

void setup() {
  Serial.begin(9600);

    /****************Test1**************/
  int num = 100;
  struct s s1;
  s1.i = 10;
  s1.p = &num;   //結構體中的指標指向num的int型態記憶體空間

  Serial.println("s1.i = "+ (String)s1.i);
  Serial.print("s1.p = ");
  Serial.print((long)s1.p,HEX);
  Serial.print(";   &num = ");
  Serial.println((long)&num,HEX);
  Serial.print("*(s1.p) = ");
  Serial.print(*(s1.p));
  Serial.print(";  num = ");
  Serial.println(num);
  /*************Test1 END*************/
  Serial.println("****************");
  /****************Test2**************/
  struct sr sr1,sr2; //宣告結構體變數sr1指向sr2
  sr1.data = 10;     //sr1的成員data，用來存放資料
  sr1.p = &sr2;      //sr1的指標成員p，用來指向sr2結構體的記憶體空間
  sr2.data = 20;     //sr2的成員data，用來存放資料
  sr2.p = NULL;      //sr2的指標成員p指向NULL，完成單向鏈結串列

  Serial.print("sr1.data = ");
  Serial.println(sr1.data);
  Serial.print("sr1.p    = ");
  Serial.print((long)sr1.p,HEX);
  Serial.print(";  &sr2     = ");
  Serial.println((long)&sr2,HEX);
  Serial.print("sr2.data = ");
  Serial.println(sr2.data);
  Serial.print("sr2.p    = ");
  Serial.print((long)sr2.p,HEX);
//  printf("sr2.p    = %0X\n", sr2.p);
  /*************Test2 END*************/
}

void loop() {
  

}
