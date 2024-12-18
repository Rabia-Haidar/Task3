#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int marks;

public:
    Student(string name, int marks) : name(name), marks(marks) {}
    string getName() {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }
    int getMarks(){
        return marks;
    }
    void setMarks(int marks) {
        this->marks = marks;
    }
    Student* next;
};

class Stack {
private:
    Student* top_node;

public:
    Stack() : top_node(nullptr) {}

    void push(string name, int marks) {
        Student* new_student = new Student(name, marks);
        new_student->next = top_node;
        top_node = new_student;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to pop." << endl;
            return;
        }
        else{
        Student* temp = top_node;
        top_node = top_node->next;
        delete temp;}
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        else{
        Student* temp = top_node;
        cout << "Current Stack:" << endl;
        while (temp != nullptr) {
            cout << "Name: " << temp->getName() << ", Marks: " << temp->getMarks() << endl;
            temp = temp->next;
        }}
    }
    bool isEmpty() {
        return top_node == nullptr;
    }
    Student* top() {
        return top_node;
    }
    void reverse() {
        Student* prev = nullptr;
        Student* curr = top_node;
        Student* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        top_node = prev;
    }
    void display_top() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot display top students." << endl;
            return;
        }
        reverse();
        Student* current = top_node;
        Student* next_node = nullptr;
        for (Student* i = top_node; i != nullptr; i = i->next) {
            for (next_node = i->next; next_node != nullptr; next_node = next_node->next) {
                if (i->getMarks() < next_node->getMarks()) {
                
                    int temp_marks = i->getMarks();
                    i->setMarks(next_node->getMarks());
                    next_node->setMarks(temp_marks);

                    string temp_name = i->getName();
                    i->setName(next_node->getName());
                    next_node->setName(temp_name);
                }
            }
        }
        cout << "Top 3 Students:" << endl;
        Student* temp = top_node;
        int count = 0;
        while (temp != nullptr && count < 3) {
            cout << "Name: " << temp->getName() << ", Marks: " << temp->getMarks() << endl;
            temp = temp->next; 
            count++;
        }
        reverse();
    }
};

int main() {
    Stack student_stack;
    int choice = 0;

    while (choice != 5) {
        cout << "\n1. Add student" << endl;
        cout << "2. Remove student" << endl;
        cout << "3. Display all students" << endl;
        cout << "4. Display top 3 students" << endl;
        cout << "5. Exit program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore();
            string name;
            int marks;
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Enter student marks: ";
            cin >> marks;
            student_stack.push(name, marks);
            break;
        }
        case 2:
            student_stack.pop();
            break;
        case 3:
            student_stack.display();
            break;
        case 4:
            student_stack.display_top();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
