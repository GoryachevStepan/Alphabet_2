#pragma once

class list_element
{
public:
    char* data;
    list_element* prev, * next;
    list_element();
    list_element(char*);
    ~list_element();
};