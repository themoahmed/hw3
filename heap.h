#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> tree; 
  int m_ary;
  PComparator comp;


};

// Add implementation of member functions here


//constructor
template<typename T, typename PComparator>
Heap<T, PComparator>::Heap(int children, PComparator comparatator){
  m_ary = children;
  comp = comparatator;
}

//destructor
template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){
}




// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Called top on empty stack: stack underflow_error"); //change to "stack underflow_error" if dont pass

  }else {
    return tree[0];
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element



}



template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& obj){
  tree.push_back(obj);
  int tree_size = tree.size()-1;

  std::size_t parent_idx = (tree_size - 1) / 2;
  while(tree_size !=0 && comp(tree[tree_size], tree[parent_idx])){
    std::swap(tree[tree_size], tree[parent_idx]);
    tree_size = parent_idx;
    parent_idx = (tree_size - 1) / 2;
  }
  //pushback
  std::cout << "Tree after pushing: " << obj << std::endl;
    for (const T& elem : tree) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

}


template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
    if(tree.size() == 0){
      return true;
    }else{
      return false;
    }
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
    return tree.size();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("stack underflow error");

  }

  //swap the first element with the last element
  std::swap(tree[0], tree[tree.size()-1]);

  //remove the last element
  tree.pop_back();

  //if its not empty heapify up
  if(!tree.empty()){

    int index = 0;
    while(index < tree.size()){
      std::size_t left_child = index;
      std::size_t right_child;

      for(int i = 1; i<= m_ary; i++){
        right_child = m_ary*index* + 1;

          if(right_child < tree.size()){
            if(comp(tree[right_child], tree[left_child])){
              left_child = right_child;
            }
          }
      }

      if(left_child == index){
        break;
      }

      std::swap(tree[index], tree[left_child]);
      index = left_child;


     std::cout << "Tree after popping: " << std::endl;
    for (const T& elem : tree) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;


    }
  }






}



#endif

