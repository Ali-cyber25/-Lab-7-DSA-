#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node* next;
};

// Head pointer
Node* head = nullptr;

// Insert node at specific position
void Insert(int value, int position)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    // Insert at beginning
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        cout << "Node inserted successfully!" << endl;
        return;
    }

    Node* temp = head;

    // Traverse to the previous position
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted successfully!" << endl;
}

// Delete node at specific position
void Delete(int position)
{
    if (head == nullptr || position <= 0)
    {
        cout << "List is empty or invalid position!" << endl;
        return;
    }

    Node* temp = head;

    // Delete first node
    if (position == 1)
    {
        head = head->next;
        delete temp;

        cout << "Node deleted successfully!" << endl;
        return;
    }

    Node* prev = nullptr;

    for (int i = 1; i < position && temp != nullptr; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Node deleted successfully!" << endl;
}

// Search for an element
void Search(int value)
{
    Node* temp = head;
    int position = 1;

    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            cout << "Element found at position "
                << position << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Element not found!" << endl;
}

// Count total number of nodes
void Count()
{
    Node* temp = head;
    int count = 0;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    cout << "Total number of nodes: " << count << endl;
}

// Display linked list
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

// Main function
int main()
{
    int choice, value, position;

    do
    {
        cout << "\n===== SINGLY LINKED LIST =====" << endl;
        cout << "1. Insert at specific position" << endl;
        cout << "2. Delete at specific position" << endl;
        cout << "3. Search an element" << endl;
        cout << "4. Count total nodes" << endl;
        cout << "5. Display list" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            Insert(value, position);
            break;

        case 2:
            cout << "Enter position to delete: ";
            cin >> position;

            Delete(position);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;

            Search(value);
            break;

        case 4:
            Count();
            break;

        case 5:
            Display();
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
