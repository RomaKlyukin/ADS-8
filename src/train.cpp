// Copyright 2021 NNTU-CS
#include "train.h"
Train :: Train():first(nullptr), countOp(0) {}
void Train :: addCage(bool light) {
  Cage* item = new Cage;
  item->next = nullptr;
  item->prev = nullptr;
  Cage* temp;
  item->light = light;
  if (first == nullptr)// добавление первого(начального) э-та
    first = item;
  else {
    if (first->next == nullptr) {// добавление второго э-та
      first->next = item;
      first->prev = item;
      item->prev = first;
      item->next = first;
    } else {// добавление 3-го и последующих э-ов
      temp = first;
      while (temp->next != first) {
        temp = temp->next;
      }
      temp->next = item;
      item->prev = temp;
      item->next = first;
      first->prev  = item;
    }
  }
  countOp = 0;
}
int Train :: getLength() {
  Cage* temp;
  int ctCage;
  countOp = 0;
  first->light = true;
  while (first->light == true) {
    temp = first->next;
    while (temp->light == false) {
      temp = temp->next;
      countOp++;
    }
    countOp++;
    temp->light = false;
    ctCage = 1;
    while (temp->prev != first) {
      temp = temp->prev;
      countOp++;
      ctCage++;
    }
    countOp++;
  }
  return ctCage;
}
int Train :: getOpCount() {
  if (countOp == 0)
    getLength();
  return countOp;
}
