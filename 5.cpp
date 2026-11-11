#include <iostream>
#include <string>
using namespace std;

// Node class for student reservation
class Node
{
public:
    int studentID;
    string studentName;
    int priority;
    Node* next;

    Node(int id, string name, int p)
    {
        studentID = id;
        studentName = name;
        priority = p;
        next = nullptr;
    }
};

// Singly Linked List ADT for each book
class ReservationQueue
{
private:
    Node* head;

public:

    ReservationQueue()
    {
        head = nullptr;
    }

    // Add student according to priority
    void AddStudent(int id, string name, int priority)
    {
        Node* newNode = new Node(id, name, priority);

        // Insert at beginning if queue is empty
        // or new student has higher priority
        if (head == nullptr || priority < head->priority)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node* temp = head;

            // Find correct position
            // Equal priorities maintain arrival order
            while (temp->next != nullptr &&
                temp->next->priority <= priority)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Student added successfully!" << endl;
    }

    // Remove student if reservation is cancelled
    void RemoveStudent(int id)
    {
        if (head == nullptr)
        {
            cout << "Reservation list is empty!" << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // If first student matches
        if (head->studentID == id)
        {
            head = head->next;
            delete temp;

            cout << "Reservation cancelled successfully!" << endl;
            return;
        }

        // Search for student
        while (temp != nullptr && temp->studentID != id)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Student not found!" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;

        cout << "Reservation cancelled successfully!" << endl;
    }

    // Update student priority
    void UpdatePriority(int id, int newPriority)
    {
        if (newPriority < 1 || newPriority > 3)
        {
            cout << "Invalid priority!" << endl;
            return;
        }

        if (head == nullptr)
        {
            cout << "Reservation list is empty!" << endl;
            return;
        }

        Node* temp = head;

        // Search for student
        while (temp != nullptr && temp->studentID != id)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Student not found!" << endl;
            return;
        }

        // Store student information
        string name = temp->studentName;

        // Remove old reservation
        RemoveStudent(id);

        // Add again with new priority
        AddStudent(id, name, newPriority);

        cout << "Priority updated successfully!" << endl;
    }

    // Display reservation list
    void Display()
    {
        if (head == nullptr)
        {
            cout << "No students waiting!" << endl;
            return;
        }

        Node* temp = head;

        cout << "\n--- Reservation List ---" << endl;

        while (temp != nullptr)
        {
            cout << "ID: " << temp->studentID
                << " | Name: " << temp->studentName
                << " | Priority: ";

            if (temp->priority == 1)
                cout << "Research";
            else if (temp->priority == 2)
                cout << "Assignment";
            else
                cout << "Casual Reading";

            cout << endl;

            temp = temp->next;
        }
    }

    // Count students
    void CountStudents()
    {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        cout << "Total students waiting: " << count << endl;
    }

    // Automatically serve first student
    void ServeStudent()
    {
        if (head == nullptr)
        {
            cout << "No reservations available!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Book issued to: "
            << temp->studentName
            << " (ID: " << temp->studentID << ")"
            << endl;

        head = head->next;
        delete temp;
    }

    // Destructor
    ~ReservationQueue()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Book class
class Book
{
public:
    int bookID;
    string bookName;
    ReservationQueue queue;

    Book(int id, string name)
    {
        bookID = id;
        bookName = name;
    }
};

// Main function
int main()
{
    // Two books with separate reservation queues
    Book book1(101, "Data Structures");
    Book book2(102, "Database Systems");

    int choice, bookChoice;
    int id, priority;
    string name;

    do
    {
        cout << "\n===== UNIVERSITY LIBRARY SYSTEM =====" << endl;

        cout << "1. Add Student Reservation" << endl;
        cout << "2. Cancel Reservation" << endl;
        cout << "3. Update Student Priority" << endl;
        cout << "4. Display Reservation List" << endl;
        cout << "5. Count Students" << endl;
        cout << "6. Return Book / Serve Next Student" << endl;
        cout << "7. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 6)
        {
            cout << "\nSelect Book:" << endl;
            cout << "1. Data Structures" << endl;
            cout << "2. Database Systems" << endl;
            cout << "Enter book choice: ";
            cin >> bookChoice;

            if (bookChoice != 1 && bookChoice != 2)
            {
                cout << "Invalid book choice!" << endl;
                continue;
            }
        }

        // Select the required book queue
        ReservationQueue* q;

        if (bookChoice == 1)
            q = &book1.queue;
        else
            q = &book2.queue;

        switch (choice)
        {
        case 1:
            cout << "Enter Student ID: ";
            cin >> id;

            cout << "Enter Student Name: ";
            cin >> ws;
            getline(cin, name);

            cout << "Priority:" << endl;
            cout << "1. Research" << endl;
            cout << "2. Assignment" << endl;
            cout << "3. Casual Reading" << endl;

            cout << "Enter priority: ";
            cin >> priority;

            if (priority >= 1 && priority <= 3)
                q->AddStudent(id, name, priority);
            else
                cout << "Invalid priority!" << endl;

            break;

        case 2:
            cout << "Enter Student ID to cancel: ";
            cin >> id;

            q->RemoveStudent(id);
            break;

        case 3:
            cout << "Enter Student ID: ";
            cin >> id;

            cout << "Enter New Priority (1-3): ";
            cin >> priority;

            q->UpdatePriority(id, priority);
            break;

        case 4:
            q->Display();
            break;

        case 5:
            q->CountStudents();
            break;

        case 6:
            q->ServeStudent();
            break;

        case 7:
            cout << "Exiting Library System..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
