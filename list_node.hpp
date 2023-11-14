

class ListNode {
    int value;
    ListNode* next;

public:
    ListNode() : value(0), next(nullptr) {}

    ListNode(int value) : value(value), next(nullptr) {}

    ListNode(int value, ListNode* next) : value(value), next(next) {}

    int getValue() {
        return value;
    }

    void setValue(int newValue) {
        value = newValue;
    }

    ListNode* getNext() {
        return next;
    }

    void setNext(ListNode* newNext) {
        next = newNext;
    }

    const char* toString() {
        char* str = new char[10];
        int b = sprintf(str, "%d", value);
        return str;
    }
};