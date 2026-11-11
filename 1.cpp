#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

// Head pointer initialized to NULL
Node* head = nullptr;

// Function to create a new node and add it at the end
void CreateNode(int value)
{
    // Dynamically create a new node
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = nullptr;

    // If the list is empty
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        // Traverse to the last node
        Node* temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        // Add new node at the end
        temp->next = newNode;
    }
}

// Function to display all elements
void Display()
{
    Node* temp = head;

    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "Linked List: ";

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    CreateNode(10);
    CreateNode(20);
    CreateNode(30);
    CreateNode(40);

    Display();

    return 0;
}
