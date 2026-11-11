#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Singly Linked List ADT
class SinglyLinkedList
{
private:
    Node* head;

public:

    // Constructor
    SinglyLinkedList()
    {
        head = nullptr;
    }

    // Insert at beginning
    void InsertBeginning(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        cout << value << " inserted at beginning." << endl;
    }

    // Insert at end
    void InsertEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << value << " inserted at end." << endl;
    }

    // Delete node by value
    void DeleteNode(int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // If first node contains the value
        if (head->data == value)
        {
            head = head->next;
            delete temp;

            cout << value << " deleted successfully." << endl;
            return;
        }

        // Search for the value
        while (temp != nullptr && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }

        // Value not found
        if (temp == nullptr)
        {
            cout << "Value not found!" << endl;
            return;
        }

        // Delete the node
        prev->next = temp->next;
        delete temp;

        cout << value << " deleted successfully." << endl;
    }

    // Traverse and display
    void Display()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Linked List: ";

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Destructor
    ~SinglyLinkedList()
    {
        Node* temp;

        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function
int main()
{
    SinglyLinkedList list;

    list.InsertBeginning(20);
    list.InsertBeginning(10);

    list.InsertEnd(30);
    list.InsertEnd(40);

    cout << "\nAfter insertion:" << endl;
    list.Display();

    cout << "\nAfter deleting 20:" << endl;
    list.DeleteNode(20);
    list.Display();

    return 0;
}
