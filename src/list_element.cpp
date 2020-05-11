#include "list_element.h"
#include <iostream>
#define NULL 0;

using namespace std;

list_element::list_element() {
  data = NULL;
  prev = NULL;
  next = NULL;
}

list_element::list_element(char* word) {
  data = word;
  prev = NULL;
  next = NULL;
}
list_element::~list_element() {}