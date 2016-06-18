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
         cout << split_dimension << endl;
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
