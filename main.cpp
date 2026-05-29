#include <iostream>
#include <limits>
#include <string>
#include "StudyPlanner.h"

using namespace std;

void displayMenu();
int getMenuChoice();
void automaticTests();

int main()
{
    automaticTests();

    cout << "\n";
    cout << "Press Enter to continue to main menu...";
    cin.get();

    StudyPlanner planner;
    int choice;

    do
    {
        cout << "\n";
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
            cout << "Add assignment request completed." << endl;
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
            cout << "\nAssignments Inorder:\n";
            planner.displayInorder();
            break;

        case 6:
            cout << "\nAssignments Preorder:\n";
            planner.displayPreorder();
            break;

        case 7:
            cout << "\nAssignments Postorder:\n";
            planner.displayPostorder();
            break;

        case 8:
            cout << "Planner:" << endl;
            planner.printPlanner();
            break;

        case 9:
            cout << "Exiting Study Planner. Good luck studying!" << endl;
            break;

        default:
            cout << "Invalid choice. Please enter 1-9." << endl;
        }

        cout << endl;

    } while (choice != 9);

    return 0;
}
void automaticTests()
{
    cout << "==============================" << endl;
    cout << "      AUTOMATIC TESTS         " << endl;
    cout << "==============================" << endl;

    cout << "\n------------------------------" << endl;
    cout << "Test 1: Remove leaf node" << endl;
    cout << "\------------------------------" << endl;
    

    StudyPlanner leafTest;
    leafTest.addTask("CMPR 131", "05/30/2026");
    leafTest.addTask("CMPR 154", "05/30/2026");
    leafTest.addTask("Math 287", "06/04/2026");

    cout << "Before removing leaf node Math 287:" << endl;
    leafTest.displayInorder();

    cout << "Removing Math 287..." << endl;
    leafTest.remove("Math 287");

    cout << "After removing Math 287:" << endl;
    leafTest.displayInorder();

    cout << "\n------------------------------" << endl;
    cout << "Test 2: Remove node with one child" << endl;
    cout << "\------------------------------" << endl;
    

    StudyPlanner oneNode;
    oneNode.addTask("CMPR 131", "05/30/2026");
    oneNode.addTask("CMPR 154", "05/30/2026");
    oneNode.addTask("KIN 124", "05/30/2026");

    cout << "Before removing one-child node CMPR 154:" << endl;
    oneNode.displayInorder();

    cout << "Removing CMPR 154..." << endl;
    oneNode.remove("CMPR 154");

    cout << "After removing CMPR 154:" << endl;
    oneNode.displayInorder();

    cout << "\n------------------------------" << endl;
    cout << "Test 3: Remove node with two children" << endl;
    cout << "\------------------------------" << endl;

    StudyPlanner twoNode;
    twoNode.addTask("Math 287", "05/31/2026");
    twoNode.addTask("CMPR 154", "05/30/2026");
    twoNode.addTask("Phy 150B", "06/04/2026");
    twoNode.addTask("CMPR 131", "05/30/2026");
    twoNode.addTask("KIN 124", "05/31/2026");
    
    
    cout << "Before removing two-children node Math 287:" << endl;
    twoNode.displayInorder();

    cout << "Removing Math 287..." << endl;
    twoNode.remove("Math 287");

    cout << "After removing Math 287:" << endl;
    twoNode.displayInorder();

    cout << "\n------------------------------" << endl;
    cout << "Test 4: Remove missing task" << endl;
    cout << "\------------------------------" << endl;

    StudyPlanner missingTask;
    missingTask.addTask("Math 287", "06/04/2026");
    missingTask.addTask("Phys", "06/02/2026");

    cout << "Before trying to remove Chemistry:" << endl;
    missingTask.displayInorder();

    cout << "Removing Chemistry" << endl;
    missingTask.remove("Chemistry");

    cout << "After attempting to remove Chemistry:" << endl;
    missingTask.displayInorder();

    cout << "\n------------------------------" << endl;
    cout << "Test 5: Add duplicate task" << endl;
    cout << "\------------------------------" << endl;

    StudyPlanner duplicateTest;
    duplicateTest.addTask("CMPR 131", "05/30/2026");
    duplicateTest.addTask("CMPR 131", "05/30/2026");

    cout << "Attempting to add duplicate CMPR 131..." << endl;
    duplicateTest.displayInorder();

    cout << "\nAll automatic tests have been completed succesfully." << endl;

    cout << "==============================" << endl;
    cout << "     END OF AUTOMATIC TESTS     " << endl;
    cout << "==============================" << endl;
}

void displayMenu()
{
    cout << "==============================" << endl;
    cout << "        STUDY PLANNER         " << endl;
    cout << "       by: Group Flowers      " << endl;
    cout << "==============================" << endl;
    cout << "    1. Add assignment" << endl;
    cout << "    2. Search for assignment" << endl;
    cout << "    3. Mark assignment complete" << endl;
    cout << "    4. Remove assignment" << endl;
    cout << "    5. Display assignments inorder" << endl;
    cout << "    6. Display assignments preorder" << endl;
    cout << "    7. Display assignments postorder" << endl;
    cout << "    8. Print planner" << endl;
    cout << "    9. Exit" << endl;
    cout << "==============================" << endl;
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
