#ifndef NODE_H
#define NODE_H
#include <memory>
#include "Helper.h"

using namespace std;
// enum to define different classes. 
enum {NODE=0, LEAF=1, TREE=2};

// Base class container for each node of the tree. 
// Derived class LeafNode and TreeNode are used to create tree. 
