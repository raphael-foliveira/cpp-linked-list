#include "list_node.h"

class LinkedList {
    ListNode* head;
    int len;

    ListNode* getLast() {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        return current;
    }

public:
    LinkedList() : head(nullptr) {
        len = 0;
    }

    LinkedList(ListNode* head) : head(head) {
        ListNode* current = head;
        while (current != nullptr) {
            len++;
            current = current->getNext();
        }
    }

    ~LinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->getNext();
            delete current;
            current = next;
        }
    }

    int length() {
        return len;
    }

    ListNode* getHead() {
        return head;
    }

    void setHead(ListNode* newHead) {
        head = newHead;
    }

    ListNode* get(int index) {
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

    ListNode* operator[](int index) {
        return get(index);
    }

    void append(ListNode* listNode) {
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

    void append(LinkedList& list) {
        ListNode* listHead = list.getHead();
        ListNode* last = getLast();
        if (listHead == nullptr) {
            return;
        }
        append(listHead);
        list.setHead(nullptr);
    }

    void operator+=(LinkedList& list2) {
        append(list2);
    }

    ListNode* pop() {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->getNext() == nullptr) {
            ListNode* popped = head;
            head = nullptr;
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
};