#pragma once
#include <iostream>
struct School{
    string name;
    string address;
    string city;
    string state;
    string country;
    School* next;
};
class SchoolList {

    School* head;

    School schools;

public: SchoolList() : head(NULL){};

    void insertFirst(School* school) {
        //insertFirst(School school): Insert a new school at the beginning of the list.
        school->next = head;
        head = school;
    }
    void insertLast(School* school) {
        //insertLast(School school): Insert a new school at the end of the list.
        school->next = head;
        head = school;
        while(school->next)
        {
            school = school->next;
        }
    }
    void deleteByName(string name) {
        //deleteByName(string name): Delete a school School by its name.
        if (head->name == name)
        {
            head = head->next;
            cout << name << " successfully deleted" << endl;
            return;
        }

        School* temp = head->next;
        School* last = head;
        while (temp->next)
        {
            if (temp->name == name)
            {
                last->next = temp->next;
                cout << name << " successfully deleted" << endl;
                return;
            }
            last = temp;
            temp = temp->next;
        }
    }
    void findByName(string name) {
        //findByName(string name): Search for a school by its name and return the school information.
        School* temp = head;
        while (temp->next)
        {
            if (temp->name == name) {
                cout << temp->name << ", " << temp->address << ", " << temp->city << ", " << temp->state << ", " << temp->country << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "No such item" << endl;

    }
    void display() {
        //display(): Print the list of schools.
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        School* temp = head;
        while (temp->next)
        {
            cout << temp->name << ", " << temp->address << ", " << temp->city << ", " << temp->state << ", " << temp->country << endl;
            temp = temp->next;
        }
    }
};