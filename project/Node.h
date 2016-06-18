#ifndef NODE_H
#define NODE_H
#include <memory>
#include "Helper.h"

using namespace std;

template<typename T=float>
class Node : public enable_shared_from_this<Node<T>>
{
public:
   virtual ~Node() = default;
   virtual shared_ptr <Node<T> > left() const 
   {
      return nullptr;
   }
   virtual shared_ptr <Node<T> > right() const 
   {
      return nullptr;
   }
   
};

template<typename T=float>
class TreeNode : public Node<T>
{
private:
   shared_ptr<Node<T> > left;
   shared_ptr<Node<T> > right;
   T split_point;
   int dimension;

public: 
   TreeNode() = default;
   //TreeNode(vector<Point<T>>& points, int cur_depth);
 
   TreeNode(vector<Point<T>>& points, int cur_depth) {
      if (points.size() > 1) {
         int split_dimension = getSplit(points);
      }
   }

   ~TreeNode() = default;
   bool searchNode(const Point<T>& searchPoint) const;
   bool getSplit(vector<Point<T> >& points);

};
/*
//template<typename T>
bool TreeNode<T>::searchNode(const Point<T>& points) const {
   return true;
}
*/
//template<typename T> 

template<typename T>
bool TreeNode<T>::getSplit(vector<Point<T> >& points) {

   return true;   
}

#endif
