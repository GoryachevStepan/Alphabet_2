#define CTEST_MAIN

#include <stest.h>
#include "Kurs_Prog.cpp"
#include "text.cpp"
#include "list_element.cpp"
#include <string>
#include <stdfio.h>

CTEST(Is_letter, test_with_good_symbol)	
{			
  ASSERT_EQUA(is_letter('a'), true);
  ASSERT_EQUA(is_letter('b'), true);
  ASSERT_EQUA(is_letter('c'), true);
  ASSERT_EQUA(is_letter('&'), false);
  ASSERT_EQUA(is_letter('?'), false);
  ASSERT_EQUA(is_letter('@'), false);
}

CTEST(to_lover, lowercase_character_conversion)
{
  ASSERT_EQUA(to_lover('A'), 'a');
  ASSERT_EQUA(to_lover('B'), 'b');
  ASSERT_EQUA(to_lover('C'), 'c');
  ASSERT_EQUA(to_lover('D'), 'd');
  ASSERT_EQUA(to_lover('E'), 'e');
  ASSERT_EQUA(to_lover('F'), 'f');
}

CTEST(try_read_data, does_the_file_open)
{
  const string a = "C://Alphabet_2/README.md";
  string b = "";
  ASSERT_EQUA(try_read_data(b,a), true);
}

CTEST(try_read_data, is_the_file_read_correctly)
{
  const string a = "C://Alphabet_2/src/.txt";
  string b = "";
  string c = "aa bb cc ee aa ";
  try_read_data(b, a);
  ASSERT_EQUA(b, c);
}

CTEST(compare, string_comparison)
{
  ASSERT_EQUA(compare("aa", "aa"), 0);
  ASSERT_EQUA(compare("aa", "aaa"), -1);
  ASSERT_EQUA(compare("aaa", "aa"), 1);
  ASSERT_EQUA(compare("Aa", "aa"), 0);
  ASSERT_EQUA(compare("aa", "Aa"), 0);
  ASSERT_EQUA(compare("ab", "aa"), 1);
  ASSERT_EQUA(compare("aa", "ab"), -1);
  ASSERT_EQUA(compare("abb", "aaa"), 1);
  ASSERT_EQUA(compare("aaa", "abb"), -1);
}

CTEST(string_parse_to_sort_list_test)
{
  string bufer = "bb aa ";
  list_element head;
  parse(bufer, head);
  ASSERT_EQUA(*head.data,'a');
  ASSERT_EQUA(*(head.next->data), 'b');
}

CTEST(add_to_list_test)
{
  string bufer = "cc aa bb ";
  list_element head;
  add_to_list(&bufer[0], head);
  ASSERT_EQUA(*head.data, 'c');
  add_to_list(&bufer[3], head);
  ASSERT_EQUA(*head.data, 'a');
  add_to_list(&bufer[6], head);
  ASSERT_EQUA(*(head.next->data), 'b');
}

int main(int argc, const char *argv[])
{
    return ctest_main(argc, argv);
}

