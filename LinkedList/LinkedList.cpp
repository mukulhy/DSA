#include <iostream>
#include <vector>
using namespace std;

// Node class to represent each element in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class to handle operations on the linked list
class LinkedList {
private:
    Node* head;  // Pointer to the first node of the linked list

public:
    // Constructor to initialize the linked list
    LinkedList() {
        head = nullptr;
    }

    // Function to return the head pointer (for generic use)
    Node* getHead() {
        return head;
    }

    // Function to create a linked list from an array
    void createFromArray(int arr[], int size) {
        if (size == 0) return; // If array is empty, do nothing

        head = new Node(arr[0]); // Create the head node
        Node* temp = head;

        // Loop through the array and create new nodes
        for (int i = 1; i < size; i++) {
            temp->next = new Node(arr[i]); // Create a new node for each element
            temp = temp->next;             // Move to the next node
        }
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Traversal function for Linked List that takes a head pointer
    vector<int> LLTraversal(Node* head) {
        Node* temp = head;  // Use pointer to traverse the linked list
        vector<int> answer;
        while (temp != nullptr) {
            answer.push_back(temp->data);
            temp = temp->next;  // Move to the next node
        }
        return answer;
    }
};

// Main function to test the linked list creation and traversal
int main() {
    LinkedList list;

    // Create an array to initialize the linked list
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create linked list from array and display it
    list.createFromArray(arr, size);
    cout << "Linked List: ";
    list.display();

    // Get the head of the list and pass it to the traversal function
    Node* head = list.getHead();
    
    // Traverse the linked list and capture the result
    vector<int> traversalResult = list.LLTraversal(head);

    // Display the result of the traversal
    cout << "Traversal result: ";
    for (int data : traversalResult) {
        cout << data << " ";
    }
    cout << endl;

    return 0;
}
