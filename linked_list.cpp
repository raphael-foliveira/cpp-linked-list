#include "list_node.hpp"
#include "linked_list.hpp"
#include <iostream>
#include <cstring>
#include "./utils.hpp"
using namespace std;

ListNode* LinkedList::getLast() {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* current = head;
    while (current->getNext() != nullptr) {
        current = current->getNext();
    }
    return current;
}

LinkedList::LinkedList() : head(nullptr) {
    len = 0;
}

LinkedList::LinkedList(ListNode* head) : head(head) {
    ListNode* current = head;
    while (current != nullptr) {
        len++;
        current = current->getNext();
    }
}

LinkedList::~LinkedList() {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->getNext();
        delete current;
        current = next;
    }
}

int LinkedList::length() {
    return len;
}

ListNode* LinkedList::getHead() {
    return head;
}

void LinkedList::setHead(ListNode* newHead) {
    head = newHead;
    ListNode* current = head;
    while (current != nullptr) {
        len++;
        current = current->getNext();
    }
}

ListNode* LinkedList::get(int index) {
    if (index < 0) {
        return get(length() + index);
    }
    if (index >= len) {
        return nullptr;
    }
    ListNode* current = head;
    for (int i = 0; i < index; i++) {
        if (current == nullptr) {
            return nullptr;
        }
        current = current->getNext();
    }
    return current;
}

ListNode* LinkedList::operator[](int index) {
    return get(index);
}

void LinkedList::append(ListNode* listNode) {
    if (head == nullptr) {
        len++;
        head = listNode;
        return;
    }
    ListNode* current = getLast();
    current->setNext(listNode);
    while (current->getNext() != nullptr) {
        current = current->getNext();
        len++;
    }
}

void LinkedList::append(LinkedList& list) {
    ListNode* listHead = list.getHead();
    ListNode* last = getLast();
    if (listHead == nullptr) {
        return;
    }
    append(listHead);
    list.setHead(nullptr);
    list.len = 0;
}

void LinkedList::operator+=(LinkedList& list2) {
    append(list2);
}

ListNode* LinkedList::pop() {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->getNext() == nullptr) {
        ListNode* popped = head;
        head = nullptr;
        len--;
        return popped;
    }
    ListNode* current = head;
    while (current->getNext()->getNext() != nullptr) {
        current = current->getNext();
    }
    ListNode* popped = current->getNext();
    current->setNext(nullptr);
    len--;
    return popped;
}

const char* LinkedList::toString() {
    const char* result = "";
    ListNode* current = head;
    result = concatenate(result, "[");
    while (current != nullptr) {
        const char* currentValueStr = current->toString();
        result = concatenate(result, currentValueStr);
        if (current->getNext() != nullptr) {
            result = concatenate(result, ", ");
        }
        current = current->getNext();
    }
    result = concatenate(result, "]");
    return result;
}

