/*
    author Alek Presley
    filename: BinaryTree.h
    purpose: binary tree
*/
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "Pokemon.h"
using namespace std;

template <typename T>
class BinaryTree{
    private:
        struct TreeNode{
            T value; //value
            TreeNode* left; //left child
            TreeNode* right; //right child
        };
        TreeNode* root;

        /*
            Function Name: insert
            Purpose:insert accepts a TreeNode pointer and a pointer to a node,
            The function inserts the node into the tree pointed to by  *the TreeNode pointer.
        */
        void insert(TreeNode *&nodePtr, TreeNode *&newNode){
            if(nodePtr == nullptr){
                nodePtr = newNode;//insert the node.
            }                
            else if(newNode->value < nodePtr->value){
                insert(nodePtr->left, newNode);//search the left branch 
            }
            else{
                insert(nodePtr->right, newNode); //search the right branch
            }
        }
        /*
            Function Name: destroySubTree
            Purpose:It deletes all nodes in the tree.               
        */
        void destroySubTree(TreeNode *nodePtr){
            if(nodePtr){
                if(nodePtr->left){ //destroy left
                    destroySubTree(nodePtr->left);
                }
                if(nodePtr->right){ //destroy right
                    destroySubTree(nodePtr->right);
                }

                delete nodePtr;
            }
        }
        /*
            Function Name: displayInOrder
            Purpose: display in the inorder format           
        */
        void displayInOrder(TreeNode *nodePtr){
            if(nodePtr != NULL){
                displayInOrder(nodePtr->left); 
                cout << nodePtr->value;
                displayInOrder(nodePtr->right);
            }
        }
    public:
        //constructor
        BinaryTree(){
            root = NULL;
        }
        //destructor -calls destroysubtree
        ~BinaryTree(){
            destroySubTree(root);
        }
        /*
            Function Name: insertNode
            purpose insert the value that was passed in the binary tree.
        */
        void insertNode(T item){
            TreeNode *newNode = nullptr;	//pointer to a new node.

            //create a new node and store num in it.
            newNode = new TreeNode;
            newNode->value = item; 
            newNode->left = newNode->right = nullptr;
            
            //insert the node.
            insert(root, newNode);
        }
        /*
            Function Name: displayInOrder
            purpose: display in order 
        */
        void displayInOrder(){
            displayInOrder(root);

        }
        /*
            Function Name: searchNode
            purpose:  searchNode determines if a value is present in the tree.
            the function returns true Otherwise, it returns false.
        */
        bool searchNode(T item){
            TreeNode *nodePtr = root; //root of the tree
            while(nodePtr != NULL){  //while the tree isn't null
                if(nodePtr->value == item){
                    return true;
                }
                else if(item < nodePtr->value){
                    nodePtr = nodePtr->left;                    
                }
                else{
                  nodePtr = nodePtr->right;  
                }
            }
            return false;
        }
};










#endif