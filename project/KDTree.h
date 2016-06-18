#ifndef __KDTREE_H__
#define __KDTREE_H__
#include<memory>
#include "Node.h"

template<typename T=float>
class KDTree {
private:
   shared_ptr<Node<T> > root;

public:
   // constructor
   KDTree() = default;
   KDTree(shared_ptr<Node<T> > cur_node);

   // destructor
   ~KDTree() = default; 

   static void build_kdtree(const string& inputFileName);
   static void query_kdtree(const string& inputFileName, const string& outputFileName);
   static KDTree build_kdtree(vector<Point<T> > &points);
   static KDTree make_kdtree(vector<Point<T> > &points);
//   void build_kdtree(vector<Point<T> > &points);
/* {
      return ;
   }*/
};

template<typename T>
KDTree<T>::KDTree(shared_ptr<Node<T>> cur_node):root(cur_node) {}

template<typename T>
KDTree<T> KDTree<T>::make_kdtree(vector<Point<T> > &points)
{
   if (points.size() == 0) {
      return KDTree(nullptr);
   } else {
      //TreeNode<T> cur_node(points,0);
      //return KDTree(cur_node);
      return KDTree(make_shared<TreeNode<T> >(points,0));
   }
}

#endif
