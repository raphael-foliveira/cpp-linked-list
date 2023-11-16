#include <stdio.h>
#include "list_node.hpp"


ListNode::ListNode() : value(0), next(nullptr) {}

ListNode::ListNode(int value) : value(value), next(nullptr) {}

ListNode::ListNode(int value, ListNode* next) : value(value), next(next) {}

int ListNode::getValue() {
    return value;
}

void ListNode::setValue(int newValue) {
    value = newValue;
}

ListNode* ListNode::getNext() {
    return next;
}

void ListNode::setNext(ListNode* newNext) {
    next = newNext;
}

const char* ListNode::toString() {
    char* str = new char[10];
    int b = sprintf(str, "%d", value);
    return str;
}