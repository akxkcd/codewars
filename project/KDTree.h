#ifndef __KDTREE_H__
#define __KDTREE_H__
#include <memory>
#include <fstream>
#include <sstream>
#include <deque>
#include "Node.h"


// KDTree class. 
// contains the root of the tree. 
// APIs to build_kdtree, query kdtree, save kdtree and read kdtree. 
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

   // static APIs to allow use of this class without instatiation. 
   static void build_kdtree(const string& inputFileName);
   static KDTree build_kdtree(vector<Point<T> > &points);
   static KDTree make_kdtree(vector<Point<T> > &points);
   // APIs to read, save and query. 
   void query_kdtree(vector<Point<T> > &cur_points, string outputFileName); 
   void query_kdtree(Point<T> &cur_point);
   void query_kdtree(vector<Point<T> >  &cur_points);
   void query_kdtree(Point<T> &cur_point, T& nearest_distance, int &nearest_neighbor);
   void save_kdtree(const string& outputFileName);
   void read_kdtree(const string& inputFileName);
};

template<typename T>
KDTree<T>::KDTree(shared_ptr<Node<T>> cur_node):root(cur_node) {}

template<typename T>
KDTree<T> KDTree<T>::make_kdtree(vector<Point<T> > &points)
{
   if (points.size() == 0) {
      return KDTree(nullptr);
   } else {
      return KDTree(make_shared<TreeNode<T> >(points,0,0));
   }
}

template<typename T>
void KDTree<T>::query_kdtree(Point<T> &cur_point) {
   T nearest_distance = numeric_limits<T>::max();
   int nearest_neighbor;
   query_kdtree(cur_point, nearest_distance, nearest_neighbor);
}

template<typename T>
void KDTree<T>::query_kdtree(vector<Point<T> > &cur_points, string outputFileName) {
   ofstream out_file(outputFileName);
   if (!out_file.good()) {
      cout << "could not open file in save_kdtree " << outputFileName << endl;
      throw "file could not open";
   }
   
   for(int i=0; i<cur_points.size(); i++) {
      T nearest_distance = numeric_limits<T>::max();
      int nearest_neighbor;
      query_kdtree(cur_points[i], nearest_distance, nearest_neighbor);
      out_file << nearest_neighbor << "," << nearest_distance << endl;
      //cout << nearest_neighbor << " " << nearest_distance << endl;
   }
}

template<typename T>
void KDTree<T>::query_kdtree(Point<T> &cur_point, T& nearest_distance, int &nearest_neighbor) {
   nearest_distance = numeric_limits<T>::max();
   root->findNearestNeighbor(cur_point, nearest_distance, nearest_neighbor);
}

template<typename T>
void KDTree<T>::query_kdtree(vector<Point<T> >  &cur_points) {
   for(int i=0; i<cur_points.size(); i++) {
      query_kdtree(cur_points[i]);
   }
}

// This function reads the kdtree from inputFileName
template<typename T>
void KDTree<T>::read_kdtree(const string& inputFileName) {
   ifstream in_file(inputFileName);
   if (!in_file.good()) {
      cout << "could not open file in read_kdtree " << inputFileName << endl;
      throw "file could not open";
   }
   string cur_line;
   bool start = false;
   deque<shared_ptr<Node<T> > > tree_elements;
   while(!in_file.eof()) {
      getline(in_file, cur_line);
      if (cur_line.empty())
         continue;
      istringstream istream(cur_line);
      string nodeType;
      getline(istream, nodeType, ':');
      if(nodeType == "2") {
         string split_dim;
         string split_point;
	 getline(istream, split_dim, ',');
	 getline(istream, split_point, ',');
         T split_pt = stof(split_point);
         TreeNode<T>  cur_node(stoi(split_dim), split_pt);
         if (start == false) {
           start = true;
           cout << "reading and populating kdtree" << endl;
           root = make_shared<TreeNode<T> >(cur_node); 
           tree_elements.push_back(root);
         } else {
           shared_ptr<Node<T> > cur_element;
           cur_element = tree_elements.front();
           if (cur_element == nullptr) {
              cout << "Error: could not find last element" << endl;
           }
           if (cur_element->getLeft() == nullptr) {
              cur_element->setLeft(make_shared<TreeNode<T> > (cur_node));
              tree_elements.push_back(cur_element->getLeft()); 
           } else {
              cur_element->setRight(make_shared<TreeNode<T> > (cur_node));
              tree_elements.push_back(cur_element->getRight()); 
              tree_elements.pop_front();
           } 
         }
      } else if (nodeType == "1") {
	 vector<T> in_points;
         string cur_point;
         string cur_index;
         getline(istream, cur_index, ':');
         while (getline(istream, cur_point, ',')) {
            in_points.emplace_back(stof(cur_point));
         }
         LeafNode<T>  cur_node(in_points);
         cur_node.getPoint().setIndex(stoi(cur_index));
         cur_node.setIndex(stoi(cur_index));
         shared_ptr<Node<T> > cur_element;
         cur_element = tree_elements.front();
         if (cur_element == nullptr) {
            cout << "Error: could not find last element" << endl;
         }
         if (cur_element->getLeft() == nullptr) {
            cur_element->setLeft(make_shared<LeafNode<T> > (cur_node));
            cur_element->getLeft()->getPoint().setIndex(stoi(cur_index));
         } else {
            cur_element->setRight(make_shared<LeafNode<T> > (cur_node));
            cur_element->getRight()->getPoint().setIndex(stoi(cur_index));
            tree_elements.pop_front();
         } 
      }
   }
}

// This functions saves generated kdtree to custom location. 
template<typename T>
void KDTree<T>::save_kdtree(const string& outputFileName) {
   
   ofstream out_file(outputFileName);
   if (!out_file.good()) {
      cout << "could not open file in save_kdtree " << outputFileName << endl;
      throw "file could not open";
   }
   // Traverse the tree BFS and store it in file. 
   typedef decltype (root) root_type;
   deque<shared_ptr<Node<T> > > tree_elements;
   tree_elements.push_back(root);
   while(!tree_elements.empty()) {
      shared_ptr<Node<T> > cur_element = tree_elements.front();
      if (cur_element == nullptr) {
         //cout << "saving of type " << " -1 " << endl; 
      }
      else {
         if (cur_element->getType() == TREE) { 
            tree_elements.push_back(cur_element->getLeft()); 
            tree_elements.push_back(cur_element->getRight());
            //cout << "saving TREE Node" << cur_element->getType() << endl;
            out_file << cur_element->getType() << ":" << cur_element->get_split_dimension() << "," << cur_element->get_split_point() << endl; 
         } else if (cur_element->getType() == LEAF) {
            //cout << "saving LEAF Node" << endl;
            out_file << cur_element->getType() << ":" << cur_element->getPoint().getIndex() << ":" ;
            int point_size = cur_element->getPoint().getDimensionVector().size();
            for (int i=0; i<point_size; i++) {
               if (i==point_size-1)
                  out_file << cur_element->getPoint().getDimensionVector()[i] << endl;
               else
                  out_file << cur_element->getPoint().getDimensionVector()[i] << ",";
            }
         } else {
            cout << "ERROR: Found incompatible node" << endl;
            throw "incompatible node found";
         }
      }
      tree_elements.pop_front();
   }  
}


#endif
