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
   int split_dimension;

public: 
   TreeNode() = default;
   //TreeNode(vector<Point<T>>& points, int cur_depth);
 
   TreeNode(vector<Point<T>>& points, int cur_depth) {
      if (points.size() > 1) {
         split_dimension = getSplit(points);
         cout << split_dimension << endl;
         int cur_split = split_dimension;
         nth_element(begin(points), begin(points) + points.size() / 2, end(points),
                        [cur_split](const auto& left, const auto& right) {
                        return left[cur_split] < right[cur_split];
                        });
         //use median point as split point
         auto split_pt = points[points.size() / 2];
         split_point = split_pt[split_dimension];

         //auto left = vector<Point<T>>(begin(points), begin(points) + points.size() / 2);
         //auto right = vector<Point<T>>(begin(points) + points.size() / 2, end(points));
         int num_left = points.size()/2;
         int num_right = points.end() - points.begin() - points.size()/2;
         // split if size if greater than 1.
         if (num_left > 1) {
            vector<Point<T> > left_points = {points.begin(), points.begin() + points.size()/2};
            left = make_shared<TreeNode<T>>(left_points, 0);
            //left = make_shared<TreeNode<T>>(vector<Point<T>>(begin(points), begin(points) + points.size() / 2), 0);
         }
         else {//only 1 point create a leaf node to store the point
            //left_ = make_shared<Point_Node<T>>(left[0]); // FIXME
         }
        
         // split if num_right is greater than one
         if (num_right > 1){
             vector<Point<T> > right_points = {points.begin()+points.size()/2, points.end()};
             right = make_shared<TreeNode<T>>(right_points, 0);            
             //right = make_shared<TreeNode<T>>(vector<Point<T>>(begin(points) + points.size() / 2, end(points)), 0);            
         }
         else {
             //right = make_shared<TreeNode<T>>(right[0]); // FIXME
         }
               /* 
                */

      }
   }

   ~TreeNode() = default;
   bool searchNode(const Point<T>& searchPoint) const;
   
   int getSplit(vector<Point<T> >& points);

};
/*
//template<typename T>
bool TreeNode<T>::searchNode(const Point<T>& points) const {
   return true;
}
*/
//template<typename T> 

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
      cout << maxElement << " " << minElement << endl;
   }
   return splitIndex;
/*
//FIXME: cleanup 
   if (list_points.size() > 1) {
                //get number of dimensions -- assumes all the features has same dimensions
                int N = list_points[0].getFeautureVector().size();
                double currentMax = std::numeric_limits<T>::min();
                for (int i = 0; i < N; ++i) {
                        auto min_max_result = std::minmax_element(begin(list_points), end(list_points),
                                [i](const auto& left, const auto& right) {
                                return left[i] < right[i];  }
                        );
                        if (currentMax < (*min_max_result.second)[i] - (*min_max_result.first)[i]) {
                                currentMax = (*min_max_result.second)[i] - (*min_max_result.first)[i];
                                split_dimension_ = i;
                        }
                }
        }
        return split_dimension_;
*/
   return true;   
}

#endif
