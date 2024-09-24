#ifndef PROJECT1_AVLTREE_H
#define PROJECT1_AVLTREE_H
#include<iostream>
#include<string>

struct AVLTree {
    struct TreeNode{
        //Initialize node variables
        TreeNode* leftNode;
        TreeNode* rightNode;
        std::string name;
        int id;

        TreeNode(std::string name, int id){
            this->name = name;
            this->id = id;
        }
        ~TreeNode(){
            delete this;
        }

    };
    //Initialize tree variables
    TreeNode* head = nullptr;

    //Default constructor
    AVLTree(){

    }

    //functions
    void searchID(int ID){
        //use the ID provided to search for the student within the tree
        //if the ID is found print their name
        //otherwise print unsuccessful
    }
    void insert(std::string NAME, int ID){
        //the id must be unique use searchID
        //add a student object into the tree with the NAME and ID provided
        //then balance the tree and print successful
        //Note NAME will contain the "Caleb Schutz" when passed in
        if(head == nullptr){
            TreeNode* newHead = new TreeNode(NAME, ID);
            head = newHead;
        }

    }
    void remove(int ID){
        //if id doesn't exist within the tree print unsuccessful
        //find and remove the account with the specified ID
        //balance the tree using the INORDER successor if necessary

    }
    void search(std::string NAME){
        /*
         Search for the student in the tree with the specified name, NAME.
         If the student's name was found, print the associated ID.
         If the tree has more than one object with the same NAME, print each ID on a new line with no other spaces and in the same relative order as a pre-order traversal.
         If the name does not exist within the tree, print “unsuccessful.”
         NAME identifier will be surrounded by double quotes for parsing, e.g., "Josh Smith."
        */

    }
    void printInOrder(){
        //print a comma seperated inorder traversal of the names
    }
    void printPreOrder(){
        //print a comma seperated preorder traversal of the names
    }
    void printPostOrder(){
        //print a comma seperated postorder traversal of the names
    }
    void printLevelCount(){
        //print the number of levels that exist in the tree
        //print 0 if the head of the tree is null
    }
    void removeInOrderN(int N){
        // remove the Nth GatorID from the inorder traversal of the tree
        //balance the tree
        // if the removal is successful print successful otherwise print unsuccessful
    }

};


#endif //PROJECT1_AVLTREE_H
