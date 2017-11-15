#ifndef level_order_display_h
#define level_order_display__h_

#include <memory>
#include "node.h"

template<class Key>
class levelOrderDisplay  {

  private:
     const Node<Key> *proot;
     int height;
     int current_level;

     std::ostream& ostr;
     int get_tree_height() const noexcept;
      
  public:
    levelOrderDisplay(const std::shared_ptr<Node<Key>>& tree, std::ostream& ostr_lhs ); 
    levelOrderDisplay(const levelOrderDisplay&);
    levelOrderDisplay(levelOrderDisplay&&) = delete;

    virtual ~levelOrderDisplay() = default;  

    // template method, which invokes display methods below.
    void operator()(const Node<Key>& node, int level) noexcept;
    void operator()(const Node<Key>* pnode, int level) noexcept;

    virtual void display_node(std::ostream& ostr, const Node<Key>& node) noexcept; 
    virtual void display_level(std::ostream& ostr,  int level) noexcept;
};

template<class Key> int levelOrderDisplay<Key>::get_tree_height() const noexcept
{
    int height = 0;
  
    for (const Node<Key> *current = proot; current != nullptr; current = current->leftChild().get()) {
        ++height;
    }
    return height;
}

template<class Key>
inline levelOrderDisplay<Key>::levelOrderDisplay(const std::shared_ptr<Node<Key>>& in_tree, std::ostream& ostr_lhs) : proot{in_tree.get()}, ostr{ostr_lhs}
{
   height = get_tree_height();	
   current_level = 0;
}

template<class Key>
inline levelOrderDisplay<Key>::levelOrderDisplay(const levelOrderDisplay& lhs) : proot{lhs.proot}, ostr{lhs.ostr}, height{lhs.height}
{
  current_level = 0;
}

template<class Key> void levelOrderDisplay<Key>::operator()(const Node<Key>& node, int level) noexcept
{
   // Did current_level change?
   if (current_level != level) { 

       current_level = level;

       display_level(ostr, level);       
   }
   
   display_node(ostr, node); 
}

template<class Key> void levelOrderDisplay<Key>::operator()(const Node<Key>* pnode, int level) noexcept
{
   // Did current_level change?
   if (current_level != level) { 

         current_level = level;

         display_level(ostr, level);       
   }
   
   display_node(ostr, *pnode); 
}

// Default implementation that derived class can use if they so desire to display current level of the tree that will next be displayed.
template<class Key>
void levelOrderDisplay<Key>::display_level(std::ostream& ostr, int level) noexcept
{
  ostr << "\n\n" << "current_level = " <<  current_level; 
     
  // Provide some basic spacing to tree appearance.
  std::size_t num = height - current_level + 1;
  
  std::string str( num, ' ');
  
  ostr << str; 
}

// Default implementation streams the node 
template<class Key> inline
void  levelOrderDisplay<Key>::display_node(std::ostream& ostr, const Node<Key>& node) noexcept
{
    if (&node == nullptr) {
        
       ostr << "[nullptr]";   

    } else {
        
      ostr << node.get_key() << std::endl; 
    }
}
#endif
