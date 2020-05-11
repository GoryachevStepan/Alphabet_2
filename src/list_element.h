#pragma once

class list_element {
public:
  char *data;
  list_element *prev, *next;
  list_element();
  list_element(char *);
  ~list_element();
};

void write_list(list_element head) {
  list_element *elem = &head;
  while (elem != 0) {
    char *symbol = elem->data;
    while (is_letter( *symbol)) {
      cout << *symbol;
      symbol++; 
    }
    cout << endl;
    elem = elem->next;
  }
}