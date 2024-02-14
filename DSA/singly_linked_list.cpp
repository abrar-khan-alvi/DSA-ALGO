#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void print_linked_list(Node *head) {
    Node *tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int size(Node *head) {
    Node *tmp = head;
    int count = 0;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

void insert_at_position(Node *&head, int pos, int val) {
    if (pos < 0 || pos > size(head)) {
        cout << "Invalid position" << endl;
        return;
    }

    Node *newNode = new Node(val);

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *tmp = head;
    for (int i = 1; i < pos; i++) {
        tmp = tmp->next;
    }

    newNode->next = tmp->next;
    tmp->next = newNode;
}

void insert_at_head(Node *&head, int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_at_tail(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void delete_tail(Node *&head, Node *&tail) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    Node *tmp = head;
    while (tmp->next != tail) {
        tmp = tmp->next;
    }

    delete tail;
    tmp->next = NULL;
    tail = tmp;
}

void delete_at_position(Node *&head, int pos) {
    if (pos < 0 || pos >= size(head)) {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 0) {
        delete_head(head);
        return;
    }

    Node *tmp = head;
    for (int i = 1; i < pos; i++) {
        tmp = tmp->next;
    }

    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
}

void delete_head(Node *&head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int val;

    cout << "Enter values to insert at the tail (-1 to stop): ";
    while (true) {
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(head, tail, val);
    }

    cout << "Linked List: ";
    print_linked_list(head);

    while (true) {
        cout << "Enter operation (insert/delete/print/-1 to exit): ";
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
            cout << "Linked List: ";
            print_linked_list(head);
        } else {
            cout << "Invalid operation" << endl;
        }
    }

    return 0;
}
