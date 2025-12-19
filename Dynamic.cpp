#include <iostream>
#include <string>

using namespace std;

struct UserRecord {
    string name;
    string phone;
    string email;
    UserRecord* next;
};

class DataController {
private:
    UserRecord* head;

public:
    DataController() { head = nullptr; }

    // Updated to accept 'e' for email
    void addUserRecord(string n, string p, string e) {
        UserRecord* newNode = new UserRecord;
        newNode->name = n;
        newNode->phone = p;
        newNode->email = e; // Fixed: was 'm', now correctly uses 'e'
        newNode->next = head;
        head = newNode;
        cout << "System: Record added to heap memory.\n";
    }

    void displayAll() {
        UserRecord* temp = head;
        if (temp == nullptr) {
            cout << "No records found.\n";
            return;
        }
        while (temp != nullptr) {
            cout << "Name: " << temp->name << " | Phone: " << temp->phone << " | Email: " << temp->email << endl;
            temp = temp->next;
        }
    }

    ~DataController() {
        UserRecord* current = head;
        while (current != nullptr) {
            UserRecord* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        cout << "System: Memory cleared successfully.\n";
    }
};

int main() {
    DataController cm;
    int choice;
    string name, phone, email;

    cout << "=== Memory-Managed Data System ===\n";

    while (true) {
        cout << "\n1. Add Record\n2. Display All\n3. Exit\nChoice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input Error. Use numbers 1-3.\n";
            continue;
         } 

        if (choice == 1) {
            cout << "Enter Name: ";
            cin.ignore(); 
            getline(cin, name);
            cout << "Enter Phone: ";
            getline(cin, phone);
            cout << "Enter Email: ";
            getline(cin, email);
            // Passed all three strings to the function
            cm.addUserRecord(name, phone, email);
        } 
        else if (choice == 2) {
            cout << "\n--- Current Records ---\n";
            cm.displayAll();
        } 
        else if (choice == 3) {
            cout << "Exiting and deallocating memory...\n";
            break;
        } 
        else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}