#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the end of the linked list
    void insert(int val) {
        if (!head) {
            head = new Node(val);
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new Node(val);
        }
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to search for a key in the linked list
    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to sort the linked list
    void sort() {
        vector<int> values;
        Node* temp = head;
        while (temp) {
            values.push_back(temp->data);
            temp = temp->next;
        }
        std::sort(values.begin(), values.end());

        temp = head;
        for (int value : values) {
            temp->data = value;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;

    // Insert some elements into the linked list
    list.insert(5);
    list.insert(3);
    list.insert(8);
    list.insert(1);
    list.insert(6);

    cout << "Original linked list:" << endl;
    list.display();

    // Search for an element in the linked list
    int key = 3;
    if (list.search(key)) {
        cout << key << " found in the linked list." << endl;
    } else {
        cout << key << " not found in the linked list." << endl;
    }

    // Sort the linked list
    list.sort();

    cout << "Linked list after sorting:" << endl;
    list.display();

    return 0;
}
