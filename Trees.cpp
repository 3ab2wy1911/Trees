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

    int getHeight(node * Node) {
        if (Node == nullptr)
            return 0;
        else {

            int left = getHeight(Node -> left);
            int right = getHeight(Node -> right);

            if (left > right)
                return (left + 1);
            else return (right + 1);
        }
    }

//______________________________________________________________________________________________________________________

    int getBalance(node * n) {
        if (n == nullptr)
            return -1;
        return getHeight(n -> left) - getHeight(n -> right);
    }

//______________________________________________________________________________________________________________________

    static node * rightRotation(node * n1) {
        node * n2 = n1 -> left;
        node * temp = n2 -> right;

        n2 -> right = n1;
        n1 -> left = temp;

        return n1;
    }

//______________________________________________________________________________________________________________________

    static node * leftRotation(node * n1) {
        node * n2 = n1 -> right;
        node * temp = n2 -> left;

        n2 -> left = n1;
        n1 -> right = temp;

        return n1;
    }

//______________________________________________________________________________________________________________________

    node * insert_private(node * n1, Student* student) {
        node * n2 = new node();
        n2->student = student;
        n2->key = student->getId();
        n2->left = nullptr;
        n2->right = nullptr;

        if (n1 == nullptr) {
            n1 = n2;
            return n1;
        }

        if (n2 -> key < n1 -> key) {
            n1 -> left = insert_private(n1 -> left, student);
        } else if (n2 -> key > n1 -> key) {
            n1 -> right = insert_private(n1 -> right, student);
        } else {
            cout << "Student already in the list !!! Insertion failed\n";
            return n1;
        }

        int balance = getBalance(n1);
        // L&L
        if (balance > 1 && n2 -> key < n1 -> left -> key)
            return rightRotation(n1);

        // R&R
        if (balance < -1 && n2 -> key > n1 -> right -> key)
            return leftRotation(n1);

        // L&R
        if (balance > 1 && n2 -> key > n1 -> left -> key) {
            n1 -> left = leftRotation(n1 -> left);
            return rightRotation(n1);
        }

        // R&L
        if (balance < -1 && n2 -> key < n1 -> right -> key) {
            n1 -> right = rightRotation(n1 -> right);
            return leftRotation(n1);
        }

        return n1;

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
    void remove(int id){};
//______________________________________________________________________________________________________________________

};

//======================================================================================================================