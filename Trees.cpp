// created by : Mohamed Ahmed
#include <bits/stdc++.h>
#include <utility>
using namespace std;

class Student{
private:
    int id;
    double gpa;
    string name,dept;

//______________________________________________________________________________________________________________________

public:

    Student()
    {
        id=0;
        gpa=0.0;
        name = nullptr;
        dept = nullptr;
    };

//______________________________________________________________________________________________________________________

    Student(int id,string name,double gpa,string dept)
    {
        this->id = id;
        this->name = std::move(name);
        this->gpa = gpa;
        this->dept = std::move(dept);
    }

//______________________________________________________________________________________________________________________

    [[nodiscard]] int getId() const
    {
        return this->id;
    }

//______________________________________________________________________________________________________________________

    [[nodiscard]] double getGPA() const{
        return this->gpa;
    }

//______________________________________________________________________________________________________________________

    [[nodiscard]] string getName() const{
        return this->name;
    }

//______________________________________________________________________________________________________________________

    [[nodiscard]] string getDepartment() const{
        return this->dept;
    }

//______________________________________________________________________________________________________________________
    void print () const{
        cout<< "Student's ID : " << this->id<<endl;
        cout<<"Student's Name : " <<this->name<<endl;
        cout<<"Student's GPA : "<< this->gpa<<endl;
        cout<<"Student's Department : "<<this->dept<<endl;
        cout<<"_________________________________________________________________________________________________________\n";
    }

//______________________________________________________________________________________________________________________

};

//======================================================================================================================

class node {
public:
    int key;
    Student* student;
    node* left;
    node* right;
    int height = 1 ;
    node(){};
    node(int id, Student* student) : key(id), student(student), left(nullptr), right(nullptr), height(1) {};
};


//======================================================================================================================

class BST {

private:

    node* root ;

//______________________________________________________________________________________________________________________

    void print(node* Node) {
        if (Node == nullptr) {
            return;
        }

        print(Node->left);
        Node->student->print();
        print(Node->right);
    }

//______________________________________________________________________________________________________________________

    Student* Min_BST_private (node* Node){
        if(root != nullptr)
        {
            if(Node->left != nullptr)
            {
                return (Min_BST_private(Node->left));
            }
        }
        return Node->student;
    }

//______________________________________________________________________________________________________________________

    void Remove ( node* Node , node* compare , bool left){
        if(root != nullptr)
        {
            node* temp;
            int Min_Right;

            // 0 children
            if(compare->left == nullptr and compare->right == nullptr)
            {
                temp = compare;
                if(left)
                {
                    Node->left = nullptr;
                }
                else {
                    Node->right = nullptr;
                }
                delete temp;
            }

                // 1 child
            else if(compare->left != nullptr and compare->right == nullptr)
            {
                temp =compare;
                if(left)
                {
                    Node->left = compare->left;
                }
                else {
                    Node->right = compare->left;
                }
                delete compare;
            }
            else if(compare->left == nullptr and compare->right != nullptr)
            {
                temp =compare;
                if(left)
                {
                    Node->left = compare->right;
                }
                else {
                    Node->right = compare->right;
                }
                delete compare;
            }

                // 2 children.
            else {
                Min_Right = Min_BST_private(compare->right)->getId();
                Student* student = Min_BST_private(compare->right);
                remove_private(Min_Right,compare);
                compare->key = Min_Right;
                compare->student=student;
            }
            cout<<"Student removed successfully!!!\n";
        }
        else
        {
            cout<<"Empty Tree\n";
        }
    }

//______________________________________________________________________________________________________________________

    void remove_private(int id, node* Node){
        if (root != nullptr)
        {
            if(root->key == id)
            {
                node* temp = root;
                int Min_Right;

                // 0 children
                if(root->left == nullptr and root->right == nullptr)
                {
                    root = nullptr;
                    delete temp;
                    cout<<"Student removed successfully!!!\n";
                }
                    // 1 child
                else if(root->left == nullptr and root->right != nullptr)
                {
                    root = root->right;
                    temp-> right = nullptr;
                    delete temp;
                    cout<<"Student removed successfully!!!\n";
                }
                else if(root->left != nullptr and root->right == nullptr) {
                    root = root->left;
                    temp-> left = nullptr;
                    delete temp;
                    cout<<"Student removed successfully!!!\n";
                }

                    // 2 children
                else {
                    Min_Right = Min_BST_private(root->right)->getId();
                    Student* student = Min_BST_private(root->right);
                    remove_private(Min_Right,root);
                    root->key = Min_Right;
                    root->student = student;
                    cout<<"Student removed successfully!!!\n";
                }

            }
            else
            {
                if (id < Node->key and Node->left != nullptr)
                {
                    if(Node->left->key == id)
                        Remove(Node,Node->left,true);
                    else
                        remove_private(id, Node->left);
                }
                else if (id > Node->key and Node->right != nullptr)
                {
                    if(Node->right->key == id)
                        Remove(Node,Node->right,false);
                    else
                        remove_private(id, Node->right);
                }
                else {
                    cout<<"Couldn't find student!!!\n";
                }
            }
        }
        else
        {
            cout <<"Couldn't find student!!! Tree is empty!!!\n";
        }
    }

//______________________________________________________________________________________________________________________

public:

    BST()
    {
        root = nullptr;
    }

//______________________________________________________________________________________________________________________

    void insert(Student* student)
    {
        node *current;  //pointer to traverse the tree
        node *trailCurrent; //pointer behind current
        node *newNode;  //pointer to create the node

        newNode = new node;
        assert(newNode != nullptr);
        newNode->key = student->getId();
        newNode->student = student;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if(root == nullptr)
            root = newNode;
        else
        {
            current = root;

            while(current != nullptr)
            {
                trailCurrent = current;

                if(current->key == student->getId())
                {
                    cout<<"The insert item is already in the list -- ";
                    cout<<"Insertion failed :("<<endl;
                    return;
                }
                else
                if(current->key > student->getId())
                    current = current->left;
                else
                    current = current->right;
            }

            if(trailCurrent->key > student->getId())
                trailCurrent->left = newNode;
            else
                trailCurrent->right = newNode;
        }
    }

//______________________________________________________________________________________________________________________

    void remove(int id)
    {
        remove_private(id,root);
    }

//______________________________________________________________________________________________________________________

    void search(int id)
    {
        node *current = root;

        while(current != nullptr)
        {
            if(current->key == id)
            {
                cout<<"Student found !!!\n";
                current->student->print();
                return;
            }
            else if(current->key > id)
                current = current->left;
            else
                current = current->right;
        }
        cout <<"Couldn't find student :(\n";
    }

//______________________________________________________________________________________________________________________

    void print() {
        cout<<"_____________________________________________Student List________________________________________________\n";
        print(root);
    }

//______________________________________________________________________________________________________________________
};

//======================================================================================================================

class AVL
{
private:

    node* root;

//______________________________________________________________________________________________________________________

    static int getHeight(node* Node) {
        if (Node == nullptr) {
            return 0;
        }
        return Node->height;
    }

//______________________________________________________________________________________________________________________

    static int getBalance(node * n) {
        if (n == nullptr)
            return -1;
        return getHeight(n -> left) - getHeight(n -> right);
    }

//______________________________________________________________________________________________________________________

    static node* rightRotation(node* y) {
        node* x = y->left;
        node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

//______________________________________________________________________________________________________________________

    static node* leftRotation(node* x) {
        node* y = x->right;
        node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }


//______________________________________________________________________________________________________________________

    node * insert_private(node * n1, Student* student) {
        if (n1 == nullptr) {
            return new node(student->getId(), student);
        }

        if (student->getId() < n1->key) {
            n1->left = insert_private(n1->left, student);
        }

        else if (student->getId() > n1->key) {
            n1->right = insert_private(n1->right, student);
        }

        else {
            cout << "The Student is already in the list -- Insertion failed :(" << endl;
            return n1;
        }

        // Update height of the ancestor node
        n1->height = 1 + max(getHeight(n1->left), getHeight(n1->right));

        // Check balance factor
        int balanceFactor = getBalance(n1);

        // Left Left Case
        if (balanceFactor > 1 && student->getId() < n1->left->key) {
            return rightRotation(n1);
        }

        // Right Right Case
        if (balanceFactor < -1 && student->getId() > n1->right->key) {
            return leftRotation(n1);
        }

        // Left Right Case
        if (balanceFactor > 1 && student->getId() > n1->left->key) {
            n1->left = leftRotation(n1->left);
            return rightRotation(n1);
        }

        // Right Left Case
        if (balanceFactor < -1 && student->getId() < n1->right->key) {
            n1->right = rightRotation(n1->right);
            return leftRotation(n1);
        }

        return n1;

    }

//______________________________________________________________________________________________________________________
    node* deleteStudent(node* Node, int id) {
        if (Node == nullptr) {
            cout << "Tree is empty\n";
            return Node;
        }

        if (id < Node->key) {
            Node->left = deleteStudent(Node->left, id);
        }
        else if (id > Node->key) {
            Node->right = deleteStudent(Node->right, id);
        }
        else {
            if (Node->left == nullptr && Node->right == nullptr) {
                delete Node;
                Node = nullptr;
            }
            else if (Node->left == nullptr) {
                node* temp = Node;
                Node = Node->right;
                delete temp;
            }
            else if (Node->right == nullptr) {
                node* temp = Node;
                Node = Node->left;
                delete temp;
            }
            else {
                node* pre = Node->left;
                while (pre->right != nullptr) {
                    pre = pre->right;
                }

                Node->key = pre->key;
                Node->student = pre->student;

                Node->left = deleteStudent(Node->left, pre->key);
            }
        }

        if (Node == nullptr) {
            return Node;
        }

        Node->height = 1 + max(getHeight(Node->left), getHeight(Node->right));
        int balance = getBalance(Node);

        if (balance > 1 && getBalance(Node->left) >= 0) {
            return rightRotation(Node);
        }

        if (balance > 1 && getBalance(Node->left) < 0) {
            Node->left = leftRotation(Node->left);
            return rightRotation(Node);
        }

        if (balance < -1 && getBalance(Node->right) <= 0) {
            return leftRotation(Node);
        }

        if (balance < -1 && getBalance(Node->right) > 0) {
            Node->right = rightRotation(Node->right);
            return leftRotation(Node);
        }

        return Node;
    }

//______________________________________________________________________________________________________________________

    void print(node* Node) {
        if (Node == nullptr) {
            return;
        }

        print(Node->left);
        Node->student->print();
        print(Node->right);
    }

//______________________________________________________________________________________________________________________

public:

    AVL() : root(nullptr){};

//______________________________________________________________________________________________________________________

    void insert(Student* student)
    {
        root = insert_private(root,student);
    }

//______________________________________________________________________________________________________________________

    void search(int id)
    {
        node *current = root;

        while(current != nullptr)
        {
            if(current->key == id)
            {
                cout<<"Student found !!!\n";
                current->student->print();
                return;
            }
            else if(current->key > id)
                current = current->left;
            else
                current = current->right;
        }
        cout <<"Couldn't find student :(\n";
    }
//______________________________________________________________________________________________________________________

    void print() {
        cout<<"_____________________________________________Student List________________________________________________\n";
        print(root);
    }

//______________________________________________________________________________________________________________________

    void remove (int id)
    {
        deleteStudent(root,id);
    }
//______________________________________________________________________________________________________________________

};

//======================================================================================================================