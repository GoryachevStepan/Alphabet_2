#pragma once

bool is_letter(char symbol) {
  return (symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z');
}

char to_lover(char symbol) {
  if (!is_letter(symbol))
    return symbol;
  if (symbol >= 'a' && symbol <= 'z')
    return symbol;
  return symbol - ('A' - 'a');
}

int compare(char* word_1, char* word_2) {
  while (is_letter(*word_1) && to_lover(*word_1) == to_lover(*word_2))
  {
    word_1++;
    word_2++;
  }
  char symbol_1 = to_lover(*word_1), symbol_2 = to_lover(*word_2);
  if (is_letter(symbol_1) && is_letter(symbol_2))
  {
    if (symbol_1 < symbol_2)
    {
      return -1;
    } else {
	    return 1;
	}
  } else if (!is_letter(symbol_1) && is_letter(symbol_2)) {
    return -1;
  }
    else if (is_letter(symbol_1) && !is_letter(symbol_2)) {
    return 1;
  } else {
    return 0;
  }
}