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

    // Delete head of the Linked List
    Node* deleteHead() {
        if (head == nullptr) {
            // List is empty, nothing to delete
            return nullptr;
        }
    
        Node* temp = head;    // Store the current head
        head = head->next;    // Move head to the next node
        delete temp;          // Free the memory of the old head
        return head;          // Return the new head
    }

    // Delete tail of the Linked List
    void deleteTail() {
        if (head == nullptr) {
            // List is empty, nothing to delete
            return;
        }

        // If there's only one node
        if (head->next == nullptr) {
            delete head;  // Delete the only node
            head = nullptr;  // Set head to nullptr, list becomes empty
            return;
        }

        // Traverse to the second-to-last node
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        // Delete the last node and set the second-to-last node's next to nullptr
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete kth element in the Linked List
    void deleteKthElement(int k) {
        if (k <= 0 || head == nullptr) {
            // Invalid position or list is empty
            return;
        }
    
        if (k == 1) {
            // If k is 1, delete the head
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
    
        Node* temp = head;
        // Traverse to the (k-1)th node
        for (int i = 1; i < k - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
    
        // If temp is nullptr or temp->next is nullptr, k is out of bounds
        if (temp == nullptr || temp->next == nullptr) {
            return;
        }
    
        // Store the k-th node and adjust pointers
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
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

    // Delete the head and update the head pointer
    head = list.deleteHead();
    // Display the updated linked list
    cout << "Updated Linked List after deleting head: ";
    list.display();
    // Delete the head and update the head pointer
    list.deleteTail();
    // Display the updated linked list
    cout << "Updated Linked List after deleting tail: ";
    list.display();

    cout << endl;

    int k = 3;
    list.deleteKthElement(k);
    cout << "Updated Linked List after deleting " << k << "-th element: ";
    list.display();

    cout << endl;
    return 0;
}
