// Author: OMohammad
// Purpose: Store info in Min/Max Heap


#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <cstring>
#include <string>
#include "Trees.cpp"


using namespace std;
class HeapStudent {
    int id;
    string name;
    double GPA;
    string department;
public:
    HeapStudent(int id, string name, double GPA, string department) :
            id(id), name(name), GPA(GPA), department(department)
    {}
    HeapStudent() {
        id = 0;
        name = "N/A";
        GPA = 0.0;
        department = "N/A";
    }
    void setID(int id) {
        id = id;
    }
    void setName(string name) {
        name = name;
    }
    void setGPA(double GPA) {
        GPA = GPA;
    }
    void setDep(string dep) {
        department = dep;
    }
    int getID() {
        return id;
    }
    double getGPA() {
        return GPA;
    }
    string getName() {
        return name;
    }
    string getDepartment() {
        return department;
    }
};

// return number of students in the file
int students();

// to load students from file
void loadStudents(HeapStudent StudentsList[]);

// heapify Process
void HeapifyMax(HeapStudent studentsList[], int students, int i);

// heapify Process
void HeapifyMin(HeapStudent studentsList[], int students, int i);

// print students
void printStudents(HeapStudent studentsList[], int students);

// sorting in maxHeap
void sortMax(HeapStudent studentsList[], int students, int i);

// sorting in minHeap
void sortMin(HeapStudent studentsList[], int students, int i);

/* add student
* to add student you add to the leave then you reHeapify the tree to in max Heap
* after you insert the student at the end of the array you will check its parent to Heapify the tree again
*/
HeapStudent* addStudent(HeapStudent studentsList[], int students, HeapStudent);
