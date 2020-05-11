#include "list_element.h"
#include <iostream>
#define NULL 0;

using namespace std;

list_element::list_element() {
  data = NULL;
  prev = NULL;
  next = NULL;
}

list_element::list_element(char *word) {
  data = word;
  prev = NULL;
  next = NULL;
}
list_element::~list_element() {}

void write_list(list_element head) {
  list_element *elem = &head;
  while (elem != 0) {
    char *symbol = elem->data;
    while (is_letter(*symbol)) {
      cout << *symbol;
      symbol++; 
    }
    cout << endl;
    elem = elem->next;
  }
}