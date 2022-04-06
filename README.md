Implements a doubly-linked list class template List and its associated iterators, with the same interface and iterator usage as that found in the C++ STL

Member functions of nested const_iterator class:

const_iterator(): default zero-parameter constructor. Set pointer current to nullptr.

operator*(): returns a reference to the corresponding element in the list by calling retrieve() member function.

operator++(), operator++(int), operator--(), operator--(int): prefix and postfix increment and decrement operators.

operator==() and operator!=(): two iterators are equal if they refer to the same element.

retrieve(): return a reference to the corresponding element in the list.

const_iterator(Node *p): one-parameter constructor. Set pointer current to the given node pointer p.

            Member functions of nested iterator class:

iterator(): default zero-parameter constructor.

operator*(): returns a reference to the corresponding element in the list by calling retrieve() member function.

operator++(), operator++(int), operator--(), operator--(int): prefix and postfix increment and decrement operators.

iterator(Node *p): one-parameter constructor.

            Member functions of List class template 

List(): Default zero-parameter constructor. Call init() to initialize list member variables.

List(const List &rhs): Copy constructor. Create the new list using elements in existing list rhs.

List(List &&rhs): move constructor.

List(int num, const T & val = T()): Construct a list with num elements, all initialized with value val.

List(const_iterator start, const_iterator end): construct a List with elements from another list between start and end. Including the element referred to by the start iterator, but not the end iterator, that is [start, end).

List(std::initializer_list<T> iList) : construct a List with elements from the initializer list that is passed in. Note that this will allow declarations like this:
     List<int> myList {2, 4, 6, 8, 10, 12, 14, 16};
~List(): destructor. You should properly reclaim all dynamically allocated memory

operator=(List &rhs): copy assignment operator

operator=(List &&rhs): move assignment operator

operator=(std::initializer_list<T> iList) : assign the initializer list data to be the calling object's new data. Example call:

     list2 = {1, 3, 5, 7, 9, 11, 13, 15};
size(): return the number of elements in the List.

empty(): return true if no element is in the list; otherwise, return false.

clear(): delete all the elements in the list

reverse(): reverse the order of the elements in the list. That is, the original first element becomes the last, while the original last becomes the first.

front() and back(): return reference to the first and last element in the list, respectively.

push_front() and push_back(), insert the new object as the first and last element into the list, respectively; and their move versions.

pop_front() and pop_back(), delete the first and last element in the list, respectively.

remove(const T & val): delete all nodes with value equal to val from the list.

remove_if(PREDICATE pred): delete all nodes for which pred returns true. PREDICATE is a template type, allowing a function object to be passed. (i.e. a true/false condition/function can be passed in via the functor).

print(ostream &os, char ofc = ' '): print all elements in the list, using character ofc as the deliminator between elements in the list.

begin(): return iterator to the first element in the list.

end(): return iterator to the end marker of the list (tail).

insert(iterator itr, const T & val): insert value val ahead of the node referred to by itr; and its move version

erase(iterator itr): delete node referred to by itr. The return value is an iterator to the following node.

erase(iterator start, iterator end): delete all nodes between start and end (including start but not end), that is, all elements in the range [start, end).

init(): initialize the member variables of list.

           Non-class functions 

operator==(const List<T> & lhs, const List<T> & rhs): check if two lists contain the same sequence of elements. Two lists are equal if they have the same number of elements and the elements at the corresponding position are equal.

operator!=(const List<T> & lhs, const List<T> & rhs): opposite of operator==().

operator<<(ostream & os, const List<T> & l): print out all elements in list l by calling List<T>::print() function. 
