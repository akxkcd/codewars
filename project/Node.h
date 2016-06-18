#ifndef NODE_H
#define NODE_H

template<typename T>
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

template<typename T>
class TreeNode : public Node<T>
{
private:
   shared_ptr<Node<T> > left;
   shared_ptr<Node<T> > right;
   T split_point;
   int dimension;

public: 
   TreeNode() = default;
   ~TreeNode() = default;
   bool searchNode(const Point<T>& searchPoint) const;

};
#endif
