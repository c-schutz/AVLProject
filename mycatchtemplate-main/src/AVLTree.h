#ifndef PROJECT1_AVLTREE_H
#define PROJECT1_AVLTREE_H
#include<iostream>
#include<string>
#include <queue>

struct AVLTree {
    struct TreeNode {
        //Initialize node variables
        TreeNode *leftNode = nullptr;
        TreeNode *rightNode = nullptr;
        std::string name = "";
        int height = -10;
        int id = -1;

        TreeNode(std::string name, int id) {
            this->name = name;
            this->id = id;
        }

        ~TreeNode() {
            delete this;
        }
    };

    //Initialize tree variables
    TreeNode *head = nullptr;

    //Default constructor
    AVLTree() {
    }
    //helper functions
    TreeNode* rightRotation(TreeNode* it){
        TreeNode* sw = it->leftNode;
        TreeNode* temp = sw->rightNode;

        sw->rightNode = it;
        it->leftNode = temp;

        it->height = std::max((it->leftNode != nullptr) ? it->leftNode->height : 0, (it->rightNode != nullptr) ? it->rightNode->height : 0) + 1;
        sw->height = std::max((sw->leftNode != nullptr) ? sw->leftNode->height : 0, (sw->rightNode != nullptr) ? sw->rightNode->height : 0) + 1;

        return sw;
    }

    TreeNode* leftRotation(TreeNode* it){ //it is the root
        TreeNode* sw = it->rightNode;
        TreeNode* temp = sw->leftNode;
        sw->leftNode = it;
        it->rightNode = temp;

        it->height = std::max((it->leftNode != nullptr) ? it->leftNode->height : 0, (it->rightNode != nullptr) ? it->rightNode->height : 0) + 1;
        sw->height = std::max((sw->leftNode != nullptr) ? sw->leftNode->height : 0, (sw->rightNode != nullptr) ? sw->rightNode->height : 0) + 1;

        return sw;
    }

    int balanceFactor(TreeNode* ntb){
        int hl = -10;
        int hr = -10;
        (ntb->leftNode != nullptr) ? hl = ntb->leftNode->height : hl = 0;
        (ntb->rightNode != nullptr) ? hr = ntb->rightNode->height : hr = 0;
        return hl - hr;
    }

    TreeNode* calculateBalance(TreeNode* it){//finds the node that needs to be balanced and returns the node that is imbalanced
        if(it == nullptr) {
            return nullptr;
        }
        calculateBalance(it->leftNode);
        calculateBalance(it->rightNode);

        it->height = std::max((it->leftNode != nullptr) ? it->leftNode->height : -1, (it->rightNode != nullptr) ? it->rightNode->height : -1) + 1;

        if(std::abs(balanceFactor(it)) == 2){
            std::cout << "imbalanced!" << std::endl;
            return it;
        }
        return nullptr;
    }
    void setHeights(TreeNode* it){
        if(it == nullptr) {
            return;
        }
        setHeights(it->leftNode);
        setHeights(it->rightNode);

        it->height = std::max((it->leftNode != nullptr) ? it->leftNode->height : 0, (it->rightNode != nullptr) ? it->rightNode->height : 0) + 1;
        return;
    }

    //functions
    TreeNode* searchID(int ID) {
        //use the ID provided to search for the student within the tree
        //if the ID is found print their name
        //otherwise print unsuccessful
        TreeNode* it = this->head;
        while(true) {
            if(it->id == ID) {//make sure it isn't already in the tree
                std::cout << it->name << std::endl;
                return it;
            }
            if(ID > it->id) {//if ID is greater than the current id
                if(it->rightNode == nullptr) {
                    break;
                }else{
                    it = it->rightNode;
                }
            }
            else {//if ID is less than the current id
                if(it->leftNode == nullptr) {
                    break;
                }else{
                    it = it->leftNode;
                }
            }
        }
        std::cout << "unsuccessful" << std::endl;
        return nullptr;
    }

    void insert(std::string NAME, int ID) {
        //the id must be unique use searchID
        //add a student object into the tree with the NAME and ID provided
        //then balance the tree and print successful
        //Note NAME will contain the "Caleb Schutz" when passed in
        TreeNode* it = head;
        if (head == nullptr) {
            TreeNode *newHead = new TreeNode(NAME, ID);
            newHead->height = 0;
            head = newHead;
            return;
        }
        while(true) {
            if(it->id == ID) {//make sure it isn't already in the tree
                std::cout << "unsuccessful (id is already in list)" << std::endl;
                break;
            }
            if(ID > it->id) {//if ID is greater than the current id
                if(it->rightNode == nullptr) {
                    it->rightNode = new TreeNode(NAME, ID);
                    break;
                }
                else {
                    it = it->rightNode;
                }
            }
            else {//if ID is less than the current id
                if(it->leftNode == nullptr) {
                    it->leftNode = new TreeNode(NAME, ID);
                    break;
                }
                else {
                    it = it->leftNode;
                }
            }
        }

        //calculate if there is an imbalance and then get that and the previous node
        TreeNode* result = calculateBalance(this->head);
        if(result == nullptr){
            return;
        }
        if(result->id == this->head->id){
            int parentFactor = balanceFactor(result);
            int childFactor = 0;
            if(parentFactor == 2){//tree is left heavy, check left child
                childFactor = balanceFactor(result->leftNode);
                switch(childFactor){
                    case 1:
                        //do right rotation
                        this->head = rightRotation(result);
                        break;
                    case -1:
                        //do left rotation, right rotation
                        this->head = leftRotation(result);
                        this->head = rightRotation(result);
                        break;
                }
            }else{//tree is right heavy, check right child
                childFactor = balanceFactor(result->rightNode);
                switch(childFactor){
                    case -1:
                        //do left rotation
                        this->head = leftRotation(result);
                        break;
                    case 1:
                        //do right rotation, left rotation
                        this->head = rightRotation(result);
                        this->head = leftRotation(result);
                        break;
                }
            }
        }
        else{
            TreeNode* parent = nullptr;
            TreeNode* current = this->head;

            while(true){
                parent = current;
                if(result->id > current->id) {//if ID is greater than the current id
                    current = current->rightNode;
                }
                else {//if ID is less than the current id
                    current = current->leftNode;
                }
                if(current->id == result->id) {//make sure it isn't already in the tree
                    break;
                }
            }

            int parentFactor = balanceFactor(result);
            int childFactor = 0;
            if(parentFactor == 2){//tree is left heavy, check left child
                childFactor = balanceFactor(result->leftNode);
                switch(childFactor){
                    case 1:
                        //do right rotation
                        parent->leftNode = rightRotation(result);
                        break;
                    case -1:
                        //do left rotation, right rotation
                        parent-> leftNode = leftRotation(result);
                        parent-> leftNode = rightRotation(result);
                        break;
                }
            }else{//tree is right heavy, check right child
                childFactor = balanceFactor(result->rightNode);
                switch(childFactor){
                    case -1:
                        //do left rotation
                        parent-> rightNode = leftRotation(result);
                        break;
                    case 1:
                        //do right rotation, left rotation
                        parent-> rightNode = rightRotation(result);
                        parent-> rightNode = leftRotation(result);
                        break;
                }
            }
        }
    }

    void remove(int ID) {
        //if id doesn't exist within the tree print unsuccessful
        //find and remove the account with the specified ID
        //balance the tree using the INORDER successor if necessary
    }

    void search(std::string NAME) {
        /*
         Search for the student in the tree with the specified name, NAME.
         If the student's name was found, print the associated ID.
         If the tree has more than one object with the same NAME, print each ID on a new line with no other spaces and in the same relative order as a pre-order traversal.
         If the name does not exist within the tree, print “unsuccessful.”
         NAME identifier will be surrounded by double quotes for parsing, e.g., "Josh Smith."
        */
    }

    void printInOrder(TreeNode* it) {
        //print a comma seperated inorder traversal of the names
        if(it == nullptr) {
            return;
        }
        printInOrder(it->leftNode);
        std::cout << it->name << balanceFactor(it) << ", ";
        printInOrder(it->rightNode);
    }

    void printPreOrder(TreeNode* it) {
        //print a comma seperated preorder traversal of the names
        if(it == nullptr) {
            return;
        }
        std::cout << it->name << ", ";
        printPreOrder(it->leftNode);
        printPreOrder(it->rightNode);
    }

    void printPostOrder(TreeNode* it) {
        //print a comma seperated postorder traversal of the names
        if(it == nullptr) {
            return;
        }
        printPostOrder(it->leftNode);
        printPostOrder(it->rightNode);
        std::cout << it->name << ", ";
    }

    void printLevelCount() {
        //print the number of levels that exist in the tree
        //print 0 if the head of the tree is null
    }

    void removeInOrderN(int N) {
        // remove the Nth GatorID from the inorder traversal of the tree
        //balance the tree
        // if the removal is successful print successful otherwise print unsuccessful
    }
};


#endif //PROJECT1_AVLTREE_H
