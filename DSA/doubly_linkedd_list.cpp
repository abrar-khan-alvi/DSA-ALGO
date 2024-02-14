#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *prev;
    Node *next;

    Node(int val) {
        this->val = val;
        this->prev = this->next = NULL;
    }
};

void print_doubly_linked_list(Node *head) {
    Node *tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void insert_at_position(Node *&head, int pos, int val) {
    Node *newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    if (pos <= 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node *tmp = head;
    for (int i = 1; i < pos && tmp->next != NULL; i++) {
        tmp = tmp->next;
    }

    newNode->prev = tmp;
    newNode->next = tmp->next;

    if (tmp->next != NULL) {
        tmp->next->prev = newNode;
    }

    tmp->next = newNode;
}

void delete_at_position(Node *&head, int pos) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node *tmp = head;
    for (int i = 0; i < pos && tmp != NULL; i++) {
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        cout << "Invalid position" << endl;
        return;
    }

    if (tmp->prev != NULL) {
        tmp->prev->next = tmp->next;
    } else {
        head = tmp->next;
    }

    if (tmp->next != NULL) {
        tmp->next->prev = tmp->prev;
    }

    delete tmp;
}

void print_reverse_doubly_linked_list(Node *tail) {
    Node *tmp = tail;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

int main() {
    Node *head = NULL;
    int val;

    cout << "Enter values to insert (-1 to stop): ";
    while (true) {
        cin >> val;
        if (val == -1)
            break;
        insert_at_position(head, INT_MAX, val);
    }

    cout << "Doubly Linked List: ";
    print_doubly_linked_list(head);

    while (true) {
        cout << "Enter operation (insert/delete/print/reverse/print_reverse/-1 to exit): ";
        string operation;
        cin >> operation;

        if (operation == "-1")
            break;

        if (operation == "insert") {
            cout << "Enter position and value: ";
            int pos, value;
            cin >> pos >> value;
            insert_at_position(head, pos, value);
        } else if (operation == "delete") {
            cout << "Enter position to delete: ";
            int pos;
            cin >> pos;
            delete_at_position(head, pos);
        } else if (operation == "print") {
            cout << "Doubly Linked List: ";
            print_doubly_linked_list(head);
        } else if (operation == "reverse") {
            cout << "Reversed Doubly Linked List: ";
            print_reverse_doubly_linked_list(head);
        } else if (operation == "print_reverse") {
            cout << "Reversed Doubly Linked List: ";
            print_reverse_doubly_linked_list(head);
        } else {
            cout << "Invalid operation" << endl;
        }
    }

    return 0;
}
