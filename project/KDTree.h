#ifndef __KDTREE_H__
#define __KDTREE_H__
//#include<memory>
#include "Node.h"

template<typename T=float>
class KDTree {
private:
   shared_ptr<Node<T> > root;

public:
   // constructor
   KDTree() = default;
   KDTree(shared_ptr<Node<T> > root);

   // destructor
   ~KDTree() = default; 

   static void build_kdtree(const string& inputFileName);
   static void query_kdtree(const string& inputFileName, const string& outputFileName);
   void build_kdtree(vector<Point<T> > &points);
};

#endif
