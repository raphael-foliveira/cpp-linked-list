#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

class ListNode {
    int value;
    ListNode* next;

public:
    ListNode();

    ListNode(int value);

    ListNode(int value, ListNode* next);

    int getValue();

    void setValue(int newValue);

    ListNode* getNext();

    void setNext(ListNode* newNext);

    const char* toString();
};
#endif