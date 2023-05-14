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

//______________________________________________________________________________________________________________________


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
                if(left)
                {
                    Node->left = compare->right;
                }
                else {
                    Node->right = compare->right;
                }
                delete compare;
            }
            else if(compare->left == nullptr and compare->right != nullptr)
            {
                if(left)
                {
                    Node->left = compare->left;
                }
                else {
                    Node->right = compare->left;
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
        cout<<"_____________________________________________Student List________________________________________________";
        print(root);
    }

//______________________________________________________________________________________________________________________
};

//======================================================================================================================

class AVL
{

};

//======================================================================================================================