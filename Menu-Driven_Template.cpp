#include <iostream>
using namespace std;

//Function prototypes
void displayMenu();
int getChoice();

int main(){
  int choice;
  do{
    displayMenu();
    choice = getChoice();
    switch(choice){
      case 1: cout << "you selected func1 \n";
              break;
      case 2: cout << "you selected func2 \n";
              break;
      case 3: cout << "you selected func3 \n";
              break;

    }
  }while(choice != 4);
}

/*************************************
*            displayMenu             *
* This function clears the screen    *
* and then display the menu choices. *
*************************************/
void displayMenu(void){
  //system("cls"); //clear the screen
  cout << "\n ¡iMENU¡j \n";
  cout << "<1> func1\n";
  cout << "<2> func2\n";
  cout << "<3> func3\n";
  cout << "<4> Quit the Program\n\n";
}

/*************************************
*              getChioce             *
* This function inputs, validates,   *
* and returns the user's menu choice.*
*************************************/
int getChoice(){
  int choice;
  cin >> choice;
  while(choice < 1 || choice >4){
    cout << "The only valid choices are 1~4. Please re-enter.";
    cin >> choice;
  }
  return choice;
}
