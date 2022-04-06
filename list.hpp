template <typename T>
List<T>::List()
{
    head = nullptr;
    tail = nullptr;
    theSize = 0;
}

template <typename T>
List<T>::const_iterator::const_iterator() :current{nullptr} {}

template <typename T>
T & List<T>::const_iterator::retrieve() const
{
    return current->data;
}

template <typename T>
bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const 
{
    return !(*this == rhs);
}

template <typename T>
typename List<T>::iterator & List<T>::iterator::operator++()
{
    this->current = this->current->next;
    return *this;
}

template <typename T>
const T& List<T>::front() const
{
    return *begin();
}

template<typename T>
const T & List<T>::const_iterator::operator*() const
{ 
	return retrieve();		
}

template<typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator++()
{
	current = current->next;
    return *this; 
}

template<typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
{
	const_iterator old = *this;
	++( *this );
    return old;
}

template<typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator--()
{  
	current = current->prev;
    return *this;
}

template<typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
{ 
    const_iterator old = *this;
	--( *this );
    return old;
}

template<typename T>
bool List<T>::const_iterator::operator==(const typename List<T>::const_iterator & rhs) const 
{
	return current == rhs.current;
}

template<typename T>
bool List<T>::const_iterator::operator!=(const typename List<T>::const_iterator & rhs) const
{
	return !( *this == rhs );
}

template<typename T>  
List<T>::const_iterator::const_iterator(typename List<T>::Node* p) : current{p} {}

template<typename T>
const T & List<T>::iterator::operator*() const 
{ 
	return const_iterator::operator*();
}

template<typename T>
List<T>::iterator::iterator() {}

template<typename T>
T & List<T>::iterator::operator*()
{  
	return const_iterator::retrieve(); 
}
 	
template<typename T>
typename List<T>::iterator & List<T>::iterator::operator++() 
{
	this->current = this->current->next;
    return *this;
}

template<typename T>
typename List<T>::iterator List<T>::iterator::operator++(int)
{  
	iterator old = *this;
	++( *this );
    return old;
}

template<typename T>
typename List<T>::iterator & List<T>::iterator::operator--()
{  
	this->current = this->current->prev;
    return *this;
}

template<typename T>
typename List<T>::iterator List<T>::iterator::operator--(int)
{  
	iterator old = *this;
	--( *this );
    return old;
}

template<typename T>
List<T>::iterator::iterator(typename List<T>::Node* p) : List<T>::const_iterator{p} {}

template<typename T>
List<T>::List()
{
	init();
}

template<typename T>
List<T>::List(const List<T> & rhs)
{
	init();
	for( auto & x : rhs )
		push_back( x );
}

template<typename T> // move constructor
List<T>::List( List<T> && rhs ) : theSize(rhs.theSize), head{rhs.head}, tail{rhs.tail}
{
	rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;	
}

template<typename T>
List<T>::List(int num, const T & val) 
{
	init(); int index;
	for(index = 0; index < num; index++)
		push_back(val);
}

template<typename T>
List<T>::List(typename List<T>::const_iterator start, typename List<T>::const_iterator end)
{
	init();
	for(auto itr= start; itr != end; ++itr)
		push_back( *itr );
}

template<typename T> 
List<T>::~List()
{
	clear();
	delete head;
	delete tail;
}

template<typename T>
T & List<T>::iterator::operator*()
{  
	return this->current->data; 
}

template<typename T>
T & List<T>::const_iterator::retrieve() const
{ 
	return current->data;
}

template<typename T>
const T & List<T>::iterator::operator*() const 
{ 
	return this->retrieve(); 
}

template<typename T>
const List<T> & List<T>::operator=(const List<T> & rhs)
{
	List copy = rhs;
	std::swap(*this, cpy);
    return *this;
}

template<typename T>
List<T> & List<T>::operator=(List<T> && rhs) 
{
	init(); 
	*this = std::move( rhs );
    return *this;
}

template<typename T>
int List<T>::size() const  
{
	return theSize;
}

template<typename T> 
bool List<T>::empty() const 
{
	return size() == 0;
}

template<typename T> 
void List<T>::clear()
{
	while(!empty()) 
		pop_back();
}


template<typename T>
void List<T>::reverse()
{
	if(!empty())
	{
		auto current_ptr=head;
		while(current_ptr != nullptr)
		{
			std::swap(current_ptr->next, current_ptr->prev);
			current_ptr=current_ptr->prev;
		}
	}
	std::swap(head, tail);
}

template<typename T>
T & List<T>::front()
{
	return *begin();
}

template<typename T> 
const T & List<T>::front() const
{
	return *begin();  
}

template<typename T>
T & List<T>::back()
{
	return *(--end());  
}

template<typename T>
const T & List<T>::back() const 
{
	return *(--end());  
}

template<typename T>
void List<T>::push_front( T && val) 
{  
	insert(begin(), std::move( val));
}

template<typename T>
void List<T>::push_front(const T & val)
{  
	insert(begin(), val);
}

template<typename T>
void List<T>::push_back(T && val)
{  
	insert(end(), std::move( val));
}

template<typename T>
void List<T>::push_back(const T & val)
{  
	insert(end(), val);  
}

template<typename T>
void List<T>::pop_front()
{  
	erase(begin());
}

template<typename T>
void List<T>::pop_back()  
{ 
	erase(--end());
}

template<typename T>
void List<T>::remove(const T & val)
{  
	for(auto itr = begin(); itr != end(); ++itr)
	{
        if (*itr == val)
        {
            erase(itr);
        }
	}
}

template<typename T>
typename List<T>::iterator List<T>::begin()
{  
	if(!empty())
	{
		typename List<T>::iterator itr{head->next};
		return itr;
	}
}

template<typename T>
typename List<T>::const_iterator List<T>::begin() const
{
	if(!empty())
	{
		typename List<T>::const_iterator const_itr{head->next};
		return const_itr;
	}
}

template<typename T>
typename List<T>::iterator List<T>::end() 
{  
	typename List<T>::iterator itr{ tail };
	return itr;
}
template<typename T>
typename List<T>::const_iterator List<T>::end() const
{
	typename List<T>::const_iterator const_itr{tail};
	return const_itr;
}
template<typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator itr, const T & val)
{ 
	itr.assertIsValid( );
	if( itr.theList != this ) throw IteratorMismatchException{ };
	Node *p = itr.current;
    theSize++;
    return { *this, p->prev = p->prev->next = new Node{ val, p->prev, p } };
}

template<typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator itr, T && val)
{  
	Node *p = itr.current;
	theSize++;
	return { p->prev = p->prev->next = new Node{ std::move( val ), p->prev, p } };
}

template<typename T>
typename List<T>::iterator List<T>::erase(typename List<T>::iterator start, typename List<T>::iterator end)
{
	for( iterator itr = from; itr != to; )
		itr = erase( itr );
	return to;
}
template<typename T>
void List<T>::init()
{  
	theSize = 0;
	head = new Node;
    tail = new Node;
	head->next = tail;
    tail->prev = head;
}

template<typename T>
typename List<T>::iterator List<T>::erase(typename List<T>::iterator itr)
{  
	Node *p = itr.current;
	iterator retVal{ p->next };
	p->prev->next = p->next;
    p->next->prev = p->prev;
	p->next->prev = p->prev; 
	delete p;
    theSize--;
    return retVal;
}

template<typename T>
bool operator!=(const List<T> & lhs, const List<T> & rhs)
{
	return !(lhs == rhs);
}

template<typename T>
bool operator==(const List<T> & lhs, const List<T> & rhs)
{
	bool flag = true;
	if( lhs.size() == rhs.size())
	{
		auto rhs_itr = rhs.begin();
		for(auto lhs_itr=lhs.begin(); lhs_itr !=lhs.end(); ++lhs_itr)
		{
			if(*lhs_itr != *rhs_itr) 
			   flag = false; break;
			++rhs_itr;
		}
		return flag;
	}
	else
		return false;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, const List<T> & l)
{
	l.print(os);
    return os;
}

template<typename T>
void List<T>::print(std::ostream & os, char ofc) const 
{
	for(auto itr = begin(); itr != end(); ++itr)
		os << *itr << ofc;
}