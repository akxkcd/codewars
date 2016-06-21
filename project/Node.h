#ifndef NODE_H
#define NODE_H
#include <memory>
#include "Helper.h"

using namespace std;
// enum to define different classes. 
enum {NODE=0, LEAF=1, TREE=2};

// Base class container for each node of the tree. 
// Derived class LeafNode and TreeNode are used to create tree. 
template<typename T=float>
class Node : public enable_shared_from_this<Node<T>>
{
public:
   Node() = default;
   virtual ~Node() = default;
   virtual shared_ptr <Node<T> > left() const 
   {
      return nullptr;
   }
   virtual shared_ptr <Node<T> > right() const 
   {
      return nullptr;
   }
   virtual int getType() const
   {
      return NODE;
   }
   virtual shared_ptr<Node<T> > getLeft() {return nullptr;}
   virtual void setLeft(shared_ptr<Node<T> > cur_left) {}
   virtual shared_ptr<Node<T> > getRight() {return nullptr;}
   virtual void setRight(shared_ptr<Node<T> > cur_right) {}
   virtual T get_split_point() const {return 0;}
   virtual int get_split_dimension() const {return -1;}
   virtual Point<T> getPoint() {return Point<T>{};}
   virtual void setIndex(int index) {};
   virtual bool findNearestNeighbor(const Point<T> &input_point, T& nearest_distance, int& nearest_neighbor);
};

// Class to contains leafs of the tree.
// It contains point object to recognize the location of this leaf. 
template<typename T=float>
class LeafNode : public Node<T>
{

private:
   Point<T> point;
public:
   // Constructors
   LeafNode() = default;
   LeafNode(const Point<T> &cur_point): point(cur_point) {};
   // Destructor
   ~LeafNode() = default;
   virtual bool findNearestNeighbor(const Point<T> &input_point, T& nearest_distance, int& nearest_neighbor);
   virtual void setIndex(int index) {point.setIndex(index);};
   virtual int getType() const
   {
      return LEAF;
   }
   virtual Point<T> getPoint()
   {
      return point;
   }
};

// Class contains non-leaf nodes of the tree. 
// It contains left, right pointers, and split_point/dimension information
template<typename T=float>
class TreeNode : public Node<T>
{
private:
   shared_ptr<Node<T> > left;
   shared_ptr<Node<T> > right;
   int split_dimension; // Dimension (hyperplane) along which the cut is made. 
   T split_point; // point around which this node divides. 

public: 
   // Constructors
   TreeNode() = default;
   TreeNode(int split_dim, T split_pt): split_dimension(split_dim), split_point(split_pt) {}
   // On passing the points, these constructors create the tree recursively
   TreeNode(vector<Point<T>>& points, int cur_depth);
   TreeNode(vector<Point<T>>& points, int cur_depth, int build_method);
   
   // Default destructor
   ~TreeNode() = default;

   virtual void setLeft(shared_ptr<Node<T> > cur_left) {left = cur_left;}
   virtual void setRight(shared_ptr<Node<T> > cur_right) {right = cur_right;}
   bool searchNode(const Point<T>& searchPoint) const;
   int getSplit(vector<Point<T> >& points);
   bool findNearestNeighbor(const Point<T> &input_point, T& nearest_distance, int& nearest_neighbor);
   virtual shared_ptr<Node<T> > getLeft() {
      return left;
   }
   virtual shared_ptr<Node<T> > getRight() {
      return right;
   }
   virtual T get_split_point() const {
      return split_point;
   }
   virtual int get_split_dimension() const {
      return split_dimension;
   }
   virtual int getType() const
   {
      return TREE;
   }
};

// constructor to build the tree. 
template <typename T>
TreeNode<T>::TreeNode(vector<Point<T>>& points, int cur_depth, int build_method) {
   if (points.size() > 1) {
      split_dimension = getSplit(points);
      int cur_split = split_dimension;
      nth_element(begin(points), begin(points) + points.size() / 2, end(points),
		[cur_split](const Point<T>& left, const Point<T>& right) {
		return left[cur_split] < right[cur_split];
		});
 //use median point as split point
      auto split_pt = points[points.size() / 2];
      split_point = split_pt[split_dimension];

      vector<Point<T> > left_points = {points.begin(), points.begin() + points.size()/2};
      vector<Point<T> > right_points = {points.begin()+points.size()/2, points.end()};
      int num_left = points.size()/2;
      int num_right = points.end() - points.begin() - points.size()/2;
      if (num_left > 1) {
         left = make_shared<TreeNode<T>>(left_points, 0/*FIXME: */);
      }
      else {
         left = make_shared<LeafNode<T>>(left_points[0]); // FIXME
      }

 // split if num_right is greater than one
      if (num_right > 1){
         right = make_shared<TreeNode<T>>(right_points, 0/*FIXME*/);            
      }
      else {
         right = make_shared<LeafNode<T>>(right_points[0]); // FIXME
      }
   }
   
}

// Constructor to build the tree. 
template <typename T>
TreeNode<T>::TreeNode(vector<Point<T>>& points, int cur_depth) {
   if (points.size() > 1) {
      split_dimension = getSplit(points);
      int cur_split = split_dimension;
      nth_element(begin(points), begin(points) + points.size() / 2, end(points),
		[cur_split](const Point<T>& left, const Point<T>& right) {
		return left[cur_split] < right[cur_split];
		});
 //use median point as split point
      auto split_pt = points[points.size() / 2];
      split_point = split_pt[split_dimension];

      vector<Point<T> > left_points = {points.begin(), points.begin() + points.size()/2};
      vector<Point<T> > right_points = {points.begin()+points.size()/2, points.end()};
      int num_left = points.size()/2;
      int num_right = points.end() - points.begin() - points.size()/2;
 // split if size if greater than 1.
      if (num_left > 1) {
         left = make_shared<TreeNode<T>>(left_points, 0/*FIXME: */);
      }
      else {//only 1 point create a leaf node to store the point
         left = make_shared<LeafNode<T>>(left_points[0]); // FIXME
      }

 // split if num_right is greater than one
      if (num_right > 1){
         right = make_shared<TreeNode<T>>(right_points, 0/*FIXME*/);            
      }
      else {
         right = make_shared<LeafNode<T>>(right_points[0]); // FIXME
      }
   }
}

// Function to find the hyperplace along which this TreeNode will cut. 
template<typename T>
int TreeNode<T>::getSplit(vector<Point<T> >& points) {
   if (points.size() == 0) {
      return -1;
   }
   int dim = points[0].getDimensionVector().size();
   T maxDiff = 0;
   int splitIndex = 0;
 
   for (int i=0; i<dim; i++) {
      T minElement = numeric_limits<T>::max();
      T maxElement = numeric_limits<T>::min();
      for(int j=0; j<points.size(); j++) {
         minElement = min(minElement, points[j].getDimensionVector()[i]);
         maxElement = max(maxElement, points[j].getDimensionVector()[i]);
            
      }
      if ((maxElement-minElement) > maxDiff) {
         maxDiff = (maxElement-minElement);
         splitIndex = i;
      }
   }
   return splitIndex;
}

// Function to find nearest neighbor of input_point. 
// Returns nearest distance and index of the neighbor. 
template<typename T>
bool TreeNode<T>::findNearestNeighbor(const Point<T> &input_point, T& nearest_distance, int& nearest_neighbor) {
   bool found = false;
   shared_ptr<Node<T> > ignored_branch;
   //cout << "searching around " << split_point << endl; 
   if (input_point[split_dimension] < split_point) {
      ignored_branch = right;
      left->findNearestNeighbor(input_point, nearest_distance, nearest_neighbor);
   } else {
      ignored_branch = left;
      right->findNearestNeighbor(input_point, nearest_distance, nearest_neighbor);
   }
   if (fabs(input_point[split_dimension] - split_point) < nearest_distance) {
      ignored_branch->findNearestNeighbor(input_point, nearest_distance, nearest_neighbor); 
   }
   return found;
}

// Function to find nearest neighbor. 
// It simply finds the distance from this point. 
template<typename T>
bool LeafNode<T>::findNearestNeighbor(const Point<T> &input_point, T& nearest_distance, int& nearest_neighbor) {
   bool found = false;
   T LeafDistance = point.getDistance(input_point);
   if (LeafDistance < nearest_distance) {
      nearest_distance = LeafDistance;
      nearest_neighbor = point.getIndex(); 
   }
   return found;
}

// Function in base class which is over-written by derived classes. 
template<typename T>
bool Node<T>::findNearestNeighbor(const Point<T> &input_point, T& nearest_distance, int& nearest_neighbor) {
   return false;
}

#endif
