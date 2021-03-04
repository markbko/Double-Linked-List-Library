template <class T>
void List<T>::init(){
	theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;	
}

template <class T>
List<T>::List(){
    init();
}

template <class T>
List<T>::~List(){
    if(empty() == false)
		clear();
    delete head;
    delete tail;
}

bool search(const T& x)  
{  
    Node* current = head;
    while (current != NULL)  
    {  
        if (current->key == x)
        {
            return true;
        }  
        current = current->next;  
    }  
    return false;  
}  