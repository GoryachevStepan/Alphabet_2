#include "list_element.h"
#include "text.h"
#include <fstream>
#include <iostream>
#include <string>

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

void add_to_list(char *word, list_element &head) {
  if (head.data == NULL) {
    list_element *elem = new list_element(word);
    head = *elem;
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
    } else {
      elem->prev->next = new_elem;
      new_elem->prev = elem->prev;
      new_elem->next = elem;
      elem->prev = new_elem;
    }
  }
}

void parse(string &bufer, list_element &head) {
  bool new_word = true;
  char *symbol = &bufer[0];
  while (*symbol != 0) {
    if (!is_letter(*symbol)) {
      new_word = true;
    } else if (is_letter(*symbol) && new_word) {
      add_to_list(symbol, head);
      new_word = false;
    }
    symbol++;
  }
}

void alphabet() {
  string a;
  list_element head;
  string file_name;
  string bufer = "";
  cout << "Введите путь к файлу: ";
  cin >> a;
  file_name = a;
  if (!try_read_data(bufer, file_name)) {
    cout << "Извините, произошла ошибка при чтении файла" << endl;
    system("pause");
    return;
  }
  parse(bufer, head);
  write_list(head);
}

int main() {
  setlocale(LC_ALL, "Rus");
  while (1) {
    system("cls");
    cout << "Выберите необходимое действие" << endl;
    cout << "1 - Вывести содержимое текстового файла в алфавитном порядке"
         << endl;
    cout << "2 - Выход" << endl;
    cout << "Введите число: ";
    int n;
    cin >> n;
    switch (n) {
    case 1:
      alphabet();
      break;
    case 2:
      return 0;
      break;
    default:
      cout << "Некорректный ввод" << endl;
      system("pause");
    }
  }
}
