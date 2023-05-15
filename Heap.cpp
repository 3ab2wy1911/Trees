// Author: OMohammad
// Purpose: Store info in Min/Max Heap
#include "Header.h"

// to return the number of students
int students(){
    ifstream file;
    file.open("Students.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error opening file Students.txt" << endl;
        return 0;
    }
    string line;
    while (getline(file, line)) {
        file.close();
        return stoi(line);
    }
    return 0;
}

// to load the students from the table
void loadStudents(HeapStudent StudentsList[]){
    ifstream file;
    file.open("Students.txt", ios::app);

    if (!file.is_open()) {
        cout << "Error opening file Students.txt" << endl;
        return;
    }
    vector<string> lines; string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    auto fileLines = (stoi(lines[0])) * 4 + 2;
    string id, name, gpa, dept;
    int item = 0;
    for (int i = 1; i < fileLines - 4; i += 4) {
        id = lines[i];
        name = lines[i + 1];
        gpa = lines[i + 2];
        dept = lines[i + 3];
        HeapStudent student(stoi(id), name, stod(gpa), dept);
        StudentsList[item] = student;

        item++;
    }
}

// heapify Process
void HeapifyMax(HeapStudent studentsList[], int students, int i){
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if (left < students and studentsList[largest].getGPA() < studentsList[left].getGPA()) {
        largest = left;
    }
    if (right < students and studentsList[largest].getGPA() < studentsList[right].getGPA()) {
        largest = right;
    }
    if (largest != i) {
        swap(studentsList[largest], studentsList[i]);
        HeapifyMax(studentsList, students, largest);
    }
}

// print students in ascending order
void printStudents(HeapStudent studentsList[], int students) {
    cout << "Print " << students << " Students\n";
    for (int i = 0; i < students; i++) {
        cout << "[" <<
             studentsList[i].getID() << ", " <<
             studentsList[i].getName() << ", " <<
             studentsList[i].getGPA() << ", " <<
             studentsList[i].getDepartment()
             << "]" << endl;
    }
}

// sorting the students by GPA (ascending)
void sortMax(HeapStudent studentsList[], int students, int i) {
    for (int i = students / 2 - 1; i >= 0; i--) {
        HeapifyMax(studentsList, students, i);
    }
    cout << endl;
    for (int i = students - 1; i >= 0; i--) {
        swap(studentsList[0], studentsList[i]);
        HeapifyMax(studentsList, i, 0);
    }

}

// add student
HeapStudent* addStudent(HeapStudent studentsList[], int students, HeapStudent st) {
    students++;
    HeapStudent* newStudentsList = new HeapStudent[students];
    for (int i = 0; i < students - 1; i++) {
        newStudentsList[i] = studentsList[i];
    }
    newStudentsList[students - 1] = st;
    delete[] studentsList;
    studentsList = newStudentsList;
    return studentsList;
}

// heapify Process
void HeapifyMin(HeapStudent studentsList[], int students, int i) {
    int smallest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if (left < students and studentsList[smallest].getGPA() > studentsList[left].getGPA()) {
        smallest = left;
    }
    if (right < students and studentsList[smallest].getGPA() > studentsList[right].getGPA()) {
        smallest = right;
    }
    if (smallest != i) {
        swap(studentsList[smallest], studentsList[i]);
        HeapifyMin(studentsList, students, smallest);
    }
}

// sorting the students by GPA (descending)
void sortMin(HeapStudent studentsList[], int students, int i) {
    for (int i = students / 2 - 1; i >= 0; i--) {
        HeapifyMin(studentsList, students, i);
    }
    cout << endl;
    for (int i = students - 1; i >= 0; i--) {
        swap(studentsList[0], studentsList[i]);
        HeapifyMin(studentsList, i, 0);
    }

}
