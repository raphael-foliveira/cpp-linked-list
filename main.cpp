#include <iostream>
#include "linked_list.hpp"
using namespace std;

int main() {
    LinkedList list1;
    LinkedList list2;


    for (int i = 0; i < 3; i++) {
        list1.append(new ListNode(3 * (i + 1)));
        list2.append(new ListNode(2 * (i + 1)));
    }

    cout << list1.toString() << "\n";
    cout << "list1 length: " << list1.length() << "\n";
    cout << "list2 length: " << list2.length() << "\n";

    cout << "Popped from list1: " << list1.pop()->getValue() << "\n";

    list2.append(list1);

    cout << list1.length() << "\n";
    cout << list1.toString() << "\n";
    cout << list2.length() << "\n";
    cout << list2.toString() << "\n";
    return 0;
}