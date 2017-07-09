#include <stdio.h>
#include <string.h>

struct student {
  char name[20];
  int id;
  char phone[10];
  float grade;
};

typedef struct student Data;

int main(){
  Data john;
  Data *ptr=&john; //宣告結構體指標變數指向john結構體的記憶體空間

  //直接用結構體變數john將資料存入結構成員
  strcpy(john.name,"John Cena");
  john.id=410306;
  strcpy(john.phone,"0987654321");
  john.grade=70;
  //藉由指標間接地將資料存入結構成員
  // strcpy(ptr->name,"John Cena");
  // ptr->id=410306;
  // strcpy(ptr->phone,"0987654321");
  // ptr->grade=70;

  printf("Hi! I'm John\n");
  printf("name  : %s\n",john.name);
  printf("id    : %d\n",john.id);
  printf("phone : %s\n",john.phone);
  printf("grade : %.2f\n",john.grade);

  return 0;
}