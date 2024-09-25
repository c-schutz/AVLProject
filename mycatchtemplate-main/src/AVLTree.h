#ifndef PROJECT1_AVLTREE_H
#define PROJECT1_AVLTREE_H
#include<iostream>
#include<string>

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

    //functions
    void searchID(int ID) {
        //use the ID provided to search for the student within the tree
        //if the ID is found print their name
        //otherwise print unsuccessful
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
                    it->rightNode->height = it->height - 1;//adjust height when placed
                }
                else {
                    it = it->rightNode;
                }
            }
            else {//if ID is less than the current id
                if(it->leftNode == nullptr) {
                    it->leftNode = new TreeNode(NAME, ID);
                    it->leftNode->height = it->height - 1;//adjust height when placed
                }
                else {
                    it = it->leftNode;
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

    void printInOrder(TreeNode* head) {
        //print a comma seperated inorder traversal of the names
        if(head == nullptr) {
            return;
        }
        printInOrder(head->leftNode);
        std::cout << head->name << ", ";
        printInOrder(head->rightNode);
    }

    void printPreOrder(TreeNode* head) {
        //print a comma seperated preorder traversal of the names
        if(head == nullptr) {
            return;
        }
        std::cout << head->name << ", ";
        printPreOrder(head->leftNode);
        printPreOrder(head->rightNode);
    }

    void printPostOrder() {
        //print a comma seperated postorder traversal of the names
        if(head == nullptr) {
            return;
        }
        printPreOrder(head->leftNode);
        printPreOrder(head->rightNode);
        std::cout << head->name << ", ";
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
