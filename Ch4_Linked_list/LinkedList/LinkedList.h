#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class LinkedList;

class ListNode{
private:
  int data;
  ListNode* link;
public:
  ListNode():data(0),link(NULL){};
  ListNode(int d):data(d),link(NULL){};

  friend class LinkedList;
};

class LinkedList{
private:
  ListNode* head;
public:
  LinkedList():head(NULL){};
  void PrintList();
  void Push_front(int x);
  void Push_back(int x);
  void Delete(int x);
  void Clear();
  void Reverse();
};

#endif //LINKEDLIST_H

