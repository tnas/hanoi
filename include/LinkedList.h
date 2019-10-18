#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

using namespace std;

template <class T>
class LinkedList {
    Node<T>* last;
    Node<T>* first;
    int listSize;

    public :
        LinkedList();
        ~LinkedList();
        void add (const T data);
        T removeLast();
        bool isEmpty();
};


template <class T>
LinkedList<T>::LinkedList()
{
    last = first = nullptr;
    listSize = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    while (!isEmpty())
    {
        removeLast();
    }
}

template <class T>
void LinkedList<T>::add(const T data)
{
    Node<T>* element = new Node<T>(data);

    if (last == first)
    {
        last = element;
        first = element;
        last->previous = last->next = nullptr;

    }
    else
    {
        last->next = element;
        element->previous = last;
        last = element;
        last->next = nullptr;
    }

    ++stackSize;
}

template <class T>
T LinkedList<T>::removeLast()
{
    if (last == first)
    {
        return nullptr;
    }
    else
    {
        Node<T>* previousElement = last->previous;
        T data = last->data;
        delete(last);
        last = previousElement;
        if (last != nullptr) last->next = nullptr;
        --stackSize;
        return data;
    }
}

template <class T>
bool LStack<T>::isEmpty()
{
    return last == first;
}


#endif // LINKEDLIST_H_INCLUDED
