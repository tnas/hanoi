#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <class T>
class Node {

public :
    T data;
    Node<T>* next;
    Node<T>* previous;

    Node(T data);
};

template <class T>
Node<T>::Node(T dataValue)
{
    data = dataValue;
}

#endif // NODE_H_INCLUDED
