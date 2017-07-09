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
  Data *ptr=&john;

  strcpy(ptr->name,"John Cena");
  ptr->id=410306;
  strcpy(ptr->phone,"0987654321");
  ptr->grade=70;

  printf("Hi! I'm John\n");
  printf("name  : %s\n",john.name);
  printf("id    : %d\n",john.id);
  printf("phone : %s\n",john.phone);
  printf("grade : %.2f\n",john.grade);

  return 0;
}