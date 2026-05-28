#include <iostream>
#include <limits>
#include <string>
#include "StudyPlanner.h"

using namespace std;

void displayMenu();
int getMenuChoice();

int main()
{
    StudyPlanner planner;
    int choice;

    do
    {
        displayMenu();
        choice = getMenuChoice();

        string title;
        string dueDate;

        switch (choice)
        {
        case 1:
            cout << "Enter assignment title: ";
            getline(cin, title);

            cout << "Enter due date: ";
            getline(cin, dueDate);

            planner.addTask(title, dueDate);
            cout << "Assignment added." << endl;
            break;

        case 2:
            cout << "Enter assignment title to search: ";
            getline(cin, title);

            if (planner.searchTask(title))
                cout << "Assignment found." << endl;
            else
                cout << "Assignment not found." << endl;
            break;

        case 3:
            cout << "Enter assignment title to mark complete: ";
            getline(cin, title);

            planner.markComplete(title);
            break;

        case 4:
            cout << "Enter assignment title to remove: ";
            getline(cin, title);

            planner.remove(title);
            break;

        case 5:
            cout << "\nAssignments:\n";
            planner.displayInorder();
            break;

        case 6:
            cout << "Exiting Study Planner..." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter 1-6." << endl;
        }

        cout << endl;

    } while (choice != 6);

    return 0;
}

void displayMenu()
{
    cout << "==============================" << endl;
    cout << "        STUDY PLANNER          " << endl;
    cout << "       by: Group Flowers          " << endl;
    cout << "==============================" << endl;
    cout << "1. Add assignment" << endl;
    cout << "2. Search for assignment" << endl;
    cout << "3. Mark assignment complete" << endl;
    cout << "4. Remove assignment" << endl;
    cout << "5. Display assignments" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int getMenuChoice()
{
    int choice;

    while (!(cin >> choice))
    {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}
