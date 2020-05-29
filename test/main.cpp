#include "../src/main.cpp"
#include "../src/text.cpp"
#include "../src/list_element.cpp"
#include "C:/Alphabet_2/thirdparty/googletest/include/gtest/gtest.h"
#include <string>

TEST(Is_letter_test, Test_with_good_symbol)
{
   EXPECT_EQ(is_letter('a'), true);
   EXPECT_EQ(is_letter('b'), true);
   EXPECT_EQ(is_letter('c'), true);
   EXPECT_EQ(is_letter('&'), false);
   EXPECT_EQ(is_letter('?'), false);
   EXPECT_EQ(is_letter('@'), false);
}

TEST(To_lover_test, Сorrect_case_change)
{
    EXPECT_EQ(to_lover('A'), 'a');
    EXPECT_EQ(to_lover('B'), 'b');
    EXPECT_EQ(to_lover('C'), 'c');
    EXPECT_EQ(to_lover('D'), 'd');
    EXPECT_EQ(to_lover('E'), 'e');
    EXPECT_EQ(to_lover('F'), 'f');
}

TEST(Try_read_data_test, Does_the_file_open
{
    const string a = "C://Alphabet_2/src/.txt";
    string b = "aa bb cc ee aa ";
    EXPECT_EQ(try_read_data(b,a), true);
}

TEST(Try_read_data_test, Is_the_file_read_correctly)
{
    const string a = "C://Alphabet_2/src/.txt";
    string b = "";
    string c = "aa bb cc ee aa ";
    try_read_data(b, a);
    EXPECT_EQ(b, c);
}

TEST(Parse_test, String_parse_to_sort_list_test)
{
    string bufer = "bb aa ";
    list_element head;
    parse(bufer, head);
    EXPECT_EQ(*head.data,'a');
    EXPECT_EQ(*(head.next->data), 'b');
}

TEST(Add_to_list_test, Is_the_number_of_words_correct)
{
    string bufer = "cc aa bb ";
    list_element head;
    add_to_list(&bufer[0], head);
    EXPECT_EQ(*head.data, 'c');
    add_to_list(&bufer[3], head);
    EXPECT_EQ(*head.data, 'a');
    add_to_list(&bufer[6], head);
    EXPECT_EQ(*(head.next->data), 'b');
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}