#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "list_node.hpp"
#include <iostream>
#include <cstring>
#include "./utils.hpp"
using namespace std;

class LinkedList {
    ListNode* head;
    int len;

    ListNode* getLast();

public:
    LinkedList();

    LinkedList(ListNode* head);

    ~LinkedList();

    int length();

    ListNode* getHead();

    void setHead(ListNode* newHead);

    ListNode* get(int index);

    ListNode* operator[](int index);

    void append(ListNode* listNode);

    void append(LinkedList& list);

    void operator+=(LinkedList& list2);

    ListNode* pop();

    const char* toString();
};

#endif