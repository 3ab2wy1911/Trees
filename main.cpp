// created by : Mohamed Ahmed

#include "Header.h"

using namespace std;

BST BST_TREE;
AVL AVL_TREE;


vector<Student> loadStudent ()
{
    vector <Student>  studentsList;
    ifstream file;
    file.open("Students.txt" , ios::app);

    if (!file.is_open()) {
        cout << "Error opening file Students.txt" << endl;
        return studentsList;
    }

    vector<string> lines;
    string line;

    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    auto fileLines = (stoi(lines[0]))*4;

    int id;
    double gpa;
    string name,dept;

    for(int i = 1; i<= fileLines; i+=4) {
        id = stoi(lines[i]);
        name = lines[i+1];
        gpa = stod(lines[i+2]);
        dept = lines[i+3];
        Student student (id, name, gpa, dept);
        studentsList.push_back(student);
    }
    return studentsList;
}

void BST_Menu()
{
    int choice = 1;
    while(choice != 5)
    {
        cout <<
             "1. Add student\n"
             "2. Remove student\n"
             "3. Search student\n"
             "4. Print All (sorted by id)\n"
             "5. Return to main menu\n";
        cin>>choice;
        switch (choice) {
            case 1 :
            {
                string name , dept;
                int id;
                double gpa;
                cout<<"Enter Student's ID:\n";
                cin>>id;
                cout<<"Enter Student's Name:\n";
                cin.ignore();
                getline(cin,name);
                cout<<"Enter Student's GPA:\n";
                cin>>gpa;
                cout<<"Enter Student's Department:\n";
                cin.ignore();
                getline(cin,dept);
                Student student (id,name,gpa,dept);
                BST_TREE.insert(&student);
                break;
            }

            case 2:
            {
                int id;
                cout<<"Enter Student's ID:\n";
                cin>>id;
                BST_TREE.remove(id);
                break;
            }

            case 3:
            {
                int id;
                cout<<"Enter Student's ID:\n";
                cin>>id;
                BST_TREE.search(id);
                break;
            }

            case 4:
            {
                BST_TREE.print();
                break;
            }

            default:;
        }
    }
}

void AVL_Menu()
{
    int choice = 1;
    while(choice != 5)
    {
        cout <<
             "1. Add student\n"
             "2. Remove student\n"
             "3. Search student\n"
             "4. Print All (sorted by id)\n"
             "5. Return to main menu\n";
        cin>>choice;
        switch (choice) {
            case 1 :
            {
                string name , dept;
                int id;
                double gpa;
                cout<<"Enter Student's ID:\n";
                cin>>id;
                cout<<"Enter Student's Name:\n";
                cin.ignore();
                getline(cin,name);
                cout<<"Enter Student's GPA:\n";
                cin>>gpa;
                cout<<"Enter Student's Department:\n";
                cin.ignore();
                getline(cin,dept);
                Student student (id,name,gpa,dept);
                AVL_TREE.insert(&student);
                break;
            }

            case 2:
            {
                int id;
                cout<<"Enter Student's ID:\n";
                cin>>id;
                AVL_TREE.remove(id);
                break;
            }

            case 3:
            {
                int id;
                cout<<"Enter Student's ID:\n";
                cin>>id;
                AVL_TREE.search(id);
                break;
            }

            case 4:
            {
                AVL_TREE.print();
                break;
            }

            default:;
        }
    }
}

void MinHeap_Menu()
{
    int NumberOfStudents = students();
    HeapStudent* StudentsList = new HeapStudent[NumberOfStudents];
    loadStudents(StudentsList);
    while (true) {
        int choice1;
        cout << "Choose one of the following options:\n1 - Add student\n2 - Print All (sorted by gpa)\n3 - Main Menu\n";
        cin >> choice1;
        if (choice1 == 1) {
            string name, department;
            double GPA;
            int id;
            cout << "Enter Student's ID: ";
            cin >> id;
            cout << "\nEnter Student's Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "\nEnter Student's GPA: ";
            cin >> GPA;
            cout << "\nEnter Student's Department: ";
            cin >> department;
            HeapStudent student(id, name, GPA, department);
            StudentsList = addStudent(StudentsList, NumberOfStudents, student);
            NumberOfStudents++;
            sortMin(StudentsList, NumberOfStudents, 0);
            printStudents(StudentsList, NumberOfStudents);
            cout << endl;
        }
        else if (choice1 == 2) {
            sortMin(StudentsList, NumberOfStudents, 0);
            printStudents(StudentsList, NumberOfStudents);
            cout << endl;
        }
        else break;
    }
};


void MaxHeap_Menu(){
    int choice1;
    int NumberOfStudents = students();
    HeapStudent* StudentsList = new HeapStudent[NumberOfStudents];
    loadStudents(StudentsList);
    while (true) {
        cout << "Choose one of the following options:\n1 - Add student\n2 - Print All (sorted by gpa)\n3 - Main Menu\n";
        cin >> choice1;
        if (choice1 == 1) {
            string name, department; double GPA; int id;
            cout << "Enter Student's ID: "; cin >> id;
            cout << "\nEnter Student's Name: "; cin.ignore(); getline(cin, name);
            cout << "\nEnter Student's GPA: "; cin >> GPA;
            cout << "\nEnter Student's Department: "; cin >> department;
            HeapStudent student(id, name, GPA, department);
            StudentsList = addStudent(StudentsList, NumberOfStudents, student);
            NumberOfStudents++;
            sortMax(StudentsList, NumberOfStudents, 0);
            printStudents(StudentsList, NumberOfStudents);
        }
        else if (choice1 == 2) {
            sortMax(StudentsList, NumberOfStudents, 0);
            printStudents(StudentsList, NumberOfStudents);
        }
        else break;
    }
}

void MainMenu () {
    int choice = -1;
    while (choice!=5)
    {
        cout <<
             "Choose Data Structure:\n"
             "1.BST\n"
             "2.AVL\n"
             "3.Min Heap\n"
             "4.Max Heap\n"
             "5.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1 :
                BST_Menu();
                break;
            case 2:
                AVL_Menu();
                break;
            case 3:
                MinHeap_Menu();
                break;
            case 4:
                MaxHeap_Menu();
                break;
            default:;
        }
    }
    cout<<"Sorry to see you out :(\n";
}


int main() {
    vector<Student>Students;
    Students = loadStudent();
    for(auto &i : Students)
    {
        BST_TREE.insert(&i);
        AVL_TREE.insert(&i);
    }
    MainMenu();
}
