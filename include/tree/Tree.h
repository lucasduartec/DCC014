/**************************************************************************************************
 * Implementation of the TAD Tree
 **************************************************************************************************/

#include "TreeNode.h"
#include <iostream>

using namespace std;

class Tree
{
    // attributes
private:
    TreeNode *root;

public:
    // Constructor
    Tree();

    // Destructor
    ~Tree();

    void insert(TreeNode *node);
    void remove(TreeNode *node);
    void clearTree();
};

// Construtor
Tree::Tree()
{
    this->root = nullptr;
}

// Destrutor
Tree::~Tree()
{
    this->root = nullptr;
}

void Tree::clearTree()
{
    this->root = nullptr;
}
