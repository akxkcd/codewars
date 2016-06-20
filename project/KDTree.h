#ifndef __KDTREE_H__
#define __KDTREE_H__
#include <memory>
#include <fstream>
#include "Node.h"
#include <deque>

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
   void query_kdtree(Point<T> &cur_point);
   void query_kdtree(vector<Point<T> >  &cur_points);
   void query_kdtree(Point<T> &cur_point, T& nearest_distance, int &nearest_neighbor);
   void save_kdtree(const string& outputFileName);
   void read_kdtree(const string& inputFileName);
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

template<typename T>
void KDTree<T>::query_kdtree(Point<T> &cur_point) {
   T nearest_distance = numeric_limits<T>::max();
   int nearest_neighbor;
   query_kdtree(cur_point, nearest_distance, nearest_neighbor);
   //cout << nearest_neighbor << " " << nearest_distance << endl;
}

template<typename T>
void KDTree<T>::query_kdtree(Point<T> &cur_point, T& nearest_distance, int &nearest_neighbor) {
   nearest_distance = numeric_limits<T>::max();
   root->findNearestNeighbor(cur_point, nearest_distance, nearest_neighbor);
   //cout << nearest_neighbor << " " << nearest_distance << endl;
}

template<typename T>
void KDTree<T>::query_kdtree(vector<Point<T> >  &cur_points) {
   for(int i=0; i<cur_points.size(); i++) {
      query_kdtree(cur_points[i]);
   }
}

template<typename T>
void KDTree<T>::save_kdtree(const string& outputFileName) {
   
   ofstream out_file(outputFileName);
   if (!out_file.good()) {
      cout << "could not open file in save_kdtree " << outputFileName << endl;
      throw "file could not open";
   }
   // Traverse the tree BFS and store it in file. 
   // FIXME:
   typedef decltype (root) root_type;
   deque<shared_ptr<Node<T> > > tree_elements;
   tree_elements.push_back(root);
   while(!tree_elements.empty()) {
      shared_ptr<Node<T> > cur_element = tree_elements.front();
      if (cur_element == nullptr) {
         cout << "saving of type " << " -1 " << endl; 
      }
      else {
         if (cur_element->getType() == TREE) { 
            tree_elements.push_back(cur_element->getLeft()); 
            tree_elements.push_back(cur_element->getRight());
            cout << "saving TREE Node" << cur_element->getType() << endl;
            out_file << cur_element->getType() << "," << cur_element->get_split_point() << "," << cur_element->get_split_dimension() << endl; 
         } else if (cur_element->getType() == LEAF) {
            cout << "saving LEAF Node" << endl;
            out_file << cur_element->getType() << ",";
            for (int i=0; i<cur_element->getPoint().getDimensionVector().size(); i++) {
               out_file << cur_element->getPoint().getDimensionVector()[i] << ",";
            }
            out_file << endl;
         } else {
            cout << "ERROR: Found incompatible node" << endl;
            throw "incompatible node found";
         }
      }
      tree_elements.pop_front();
   }  
}

template<typename T>
void read_kdtree(const string& inputFileName) {

}

#endif
