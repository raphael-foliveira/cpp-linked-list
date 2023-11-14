#include <iostream>
#include "linked_list.hpp"
using namespace std;

int main() {
    LinkedList list1;
    LinkedList list2;

    cout << list1.pop() << "\n";

    for (int i = 0; i < 1500; i++) {
        list1.append(new ListNode(3 * (i + 1)));
        list2.append(new ListNode(2 * (i + 1)));
    }

    cout << "list1 length: " << list1.length() << "\n";
    cout << "list2 length: " << list2.length() << "\n";

    ListNode* someElement = list1.get(15);
    if (someElement != nullptr) {
        cout << someElement->getValue() << "\n";
    }
    cout << "Popped: " << list1.pop()->getValue() << "\n";

    list2.append(list1);

    cout << list1.length() << "\n";
    cout << list2.length() << "\n";
    cout << list2.toString() << "\n";
    return 0;
}