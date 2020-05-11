#include <iostream>
#include <string>
#include <fstream>
#include "list_element.h"

using namespace std;

bool try_read_data(string &bufer, string file_name) {
  ifstream input(file_name);
  if (input.is_open()) {
    string line;
    while (getline(input, line)) {
      bufer += line + " ";
     }
  } else {
     input.close();
    return false;
  }
  input.close();
  return true;
}

void add_to_list(char *word, list_element &head, list_element &tail) {
  if (head.data == NULL) {
    list_element *elem = new list_element(word);
    head = *elem;
    tail = head;
  } else {
    list_element *new_elem = new list_element(word);
    list_element *elem = &head;
    while (compare(elem->data, word) == -1) {
      if (elem->next == NULL)
        break;
      elem = elem->next;
     }
	if (elem == &head && compare(elem->data, word) >= 0) {
      new_elem->next = elem->next;
      elem->next = new_elem;
      if (new_elem->next != NULL)
        new_elem->next->prev = new_elem;
      new_elem->prev = elem;
      new_elem->data = elem->data;
      elem->data = word;
    } else if (elem->next == NULL && compare(elem->data, word) == -1) {
      new_elem->prev = elem;
      new_elem->next = NULL;
      elem->next = new_elem;
      tail = *new_elem;
    } else {
      elem->prev->next = new_elem;
      new_elem->prev = elem->prev;
      new_elem->next = elem;
      elem->prev = new_elem;
     }
  }
}

void parse(string &bufer, list_element &head, list_element &tail) {
  bool new_word = true;
  char *symbol = &bufer[0];
  while (*symbol != 0) {
    if (!is_letter(*symbol)) {
      new_word = true;
    } else if (is_letter(*symbol) && new_word) {
      add_to_list(symbol, head, tail);
      new_word = false;
     }
    symbol++;
  }
}

int main() {
  string a;
  list_element head;
  list element tail;
  string file_name;
  string bufer = "";
  cout << "Enter file path: ";
  cout << endl;
  cin >> a;
  file_name = a;
  if (!try_read_data(bufer, file_name)) {
    cout << "Error read data";
  }
}
