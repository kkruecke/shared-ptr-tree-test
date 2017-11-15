#ifndef node_h_123
#define node_h_123

#include <iostream>
#include <memory>
#include <utility>

template<class Key> class Node;        // fwd ref.

template<class Key> std::shared_ptr<Node<Key>> buildTree(Key k1, Key k2, Key k3); 
template<class Key> void print_tree(const Node<Key>&); 

template<class Key> class Node {

   friend std::shared_ptr<Node<Key>> buildTree<Key>(Key k1, Key k2, Key k3); 

   friend void print_tree<Key>(const Node<Key>&); 

    Key key;

    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

 public:
   Node(Key k) : key{k} {}

   Node(const Node<Key>& ) = default;

   Node(Node<Key>&& ) = default;

   Node<Key>& operator=(const Node<Key>&) = default;
   Node<Key>& operator=(Node<Key>&&) = default;
   
   Key get_key() const noexcept { return key; } 
   
   const std::shared_ptr<Node<Key>> leftChild() const noexcept { return left; } 
   
   const std::shared_ptr<Node<Key>> rightChild() const noexcept { return right; } 
   
   bool isLeaf() const noexcept { return left == nullptr ? true : false; }

  ~Node()
   {
     std::cout << "In ~Node<Key> with key = \n\t" << get_key() << "\n\t and this = " << this << '.' << std::endl;
   }
  
   std::ostream& print(std::ostream& ostr) const noexcept 
   {
      ostr << "Node::i = " << get_key() << std::endl;  
      return ostr;
   }

  
   friend std::ostream& operator<<(std::ostream& ostr, const Node<Key>& node)
   {
       return node.print(ostr);
   }
 
};

#endif
