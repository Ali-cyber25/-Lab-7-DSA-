#include <iostream>
#include <string>
using namespace std;

// Node class
class Node
{
public:
    int patientID;
    string patientName;
    Node* next;
};

// Head pointer
Node* head = nullptr;

// Add patient at the end
void AddPatient(int id, string name)
{
    Node* newNode = new Node();

    newNode->patientID = id;
    newNode->patientName = name;
    newNode->next = nullptr;

    // If queue is empty
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        // Traverse to the last node
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Patient added successfully!" << endl;
}

// Remove patient by ID
void RemovePatient(int id)
{
    if (head == nullptr)
    {
        cout << "No patients in the queue!" << endl;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // If first patient matches
    if (head->patientID == id)
    {
        head = head->next;
        delete temp;

        cout << "Patient removed successfully!" << endl;
        return;
    }

    // Search for patient
    while (temp != nullptr && temp->patientID != id)
    {
        prev = temp;
        temp = temp->next;
    }

    // Patient not found
    if (temp == nullptr)
    {
        cout << "Patient ID not found!" << endl;
        return;
    }

    // Remove patient
    prev->next = temp->next;
    delete temp;

    cout << "Patient removed successfully!" << endl;
}

// Display all patients
void DisplayPatients()
{
    if (head == nullptr)
    {
        cout << "No patients waiting!" << endl;
        return;
    }

    Node* temp = head;

    cout << "\n--- Patient Waiting List ---" << endl;

    while (temp != nullptr)
    {
        cout << "Patient ID: " << temp->patientID
            << " | Name: " << temp->patientName << endl;

        temp = temp->next;
    }
}

// Count total patients
void CountPatients()
{
    int count = 0;
    Node* temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    cout << "Total patients waiting: " << count << endl;
}

// Main function
int main()
{
    int choice, id;
    string name;

    do
    {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add New Patient" << endl;
        cout << "2. Remove Patient (Cancel Appointment)" << endl;
        cout << "3. Display Patient List" << endl;
        cout << "4. Count Total Patients" << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Patient ID: ";
            cin >> id;

            cout << "Enter Patient Name: ";
            cin >> ws;
            getline(cin, name);

            AddPatient(id, name);
            break;

        case 2:
            cout << "Enter Patient ID to remove: ";
            cin >> id;

            RemovePatient(id);
            break;

        case 3:
            DisplayPatients();
            break;

        case 4:
            CountPatients();
            break;

        case 5:
            cout << "Exiting Hospital Management System..."
                << endl;
            break;

        default:
            cout << "Invalid choice! Please try again."
                << endl;
        }

    } while (choice != 5);

    // Free remaining memory
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
