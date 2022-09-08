/* MIT License (C) Genesis Contributors
 * This file contains different data structures
 * used in the compilation process, which includes
 * Tree and SourceSchema. You are free to use, modify,
 * study them and contribute improvements through pull requests.*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;
struct Leaf {
    Leaf* parent;
    vector<Leaf*> children;
    string content;
};
/// @brief The primary implementation of the tree data structure used 
/// to tokenise the source code into a hierarchical model. This class
/// only supports adding, modifying and searching, but not deleting.
class CompilerTree{ 
    Leaf root;           //Tree is the list of leaves connected with each
    list<Leaf> leaves;  //other through pointers as parent-child relations.
    public:
        CompilerTree(){
            root.parent = nullptr;
            root.content = "";
        }
        void addLeaf(Leaf* parent, string content){
            Leaf leaf;
            leaf.parent = parent;
            leaf.content = content;
            leaves.push_back(leaf);
            parent->children.push_back(&leaf);
        }
        void modifyLeaf(Leaf* leaf, string content){
            leaf->content = content;
        }
        void searchLeaf(Leaf* leaf, string content){
            if (leaf->content == content){
                cout << "Found!" << endl;
            }
            else{
                for (Leaf* child : leaf->children){
                    searchLeaf(child, content);
                }
            }
        }
        /// @brief Searches the node from its parent. 
        /// @return The pointer to the child node if found, otherwise nullptr.
        Leaf* searchChild(Leaf* parent, string content){
            for (Leaf* child : parent->children) if (child->content == content) return child;
            return NULL;
        }
        Leaf* searchParent(Leaf* child, string content){
            if (child->parent->content == content) return child->parent;
            else if (child->parent != &root) return searchParent(child->parent, content);
            else return NULL;
        }
        void showTree(){
            for (Leaf leaf : leaves){
                cout << leaf.content << endl;
            }
        }
};
