#ifndef LSTACK_H_INCLUDED
#define LSTACK_H_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"

using namespace std;

template <class T>
class LStack {
    Node<T>* top;
    int stackSize;

    public :
        LStack();
        ~LStack();
        void push (const T data);
        T pop();
        bool isEmpty();
        T getNodeAt(int position);
        void setNodeSize(int size);
        int getNodeSize();
        int getStackSize();
        string toString();
};

template <class T>
LStack<T>::LStack()
{
    top = nullptr;
    stackSize = 0;
}

template <class T>
LStack<T>::~LStack()
{
    while (!isEmpty())
    {
        pop();
    }
}

template <class T>
void LStack<T>::push(const T data)
{
    Node<T>* element = new Node<T>(data);

    if (top == nullptr)
    {
        top = element;
        top->previous = top->next = nullptr;

    }
    else
    {
        element->previous = top;
        top->next = element;
        top = element;
        top->next = nullptr;
    }

    ++stackSize;
}

template <class T>
T LStack<T>::pop()
{
    if (top == nullptr)
    {
        return nullptr;
    }
    else
    {
        Node<T>* underTop = top->previous;
        T data = top->data;
        delete(top);
        top = underTop;
        if (top != nullptr) top->next = nullptr;
        --stackSize;
        return data;
    }
}

template <class T>
bool LStack<T>::isEmpty()
{
    return top == nullptr;
}

template <class T>
T LStack<T>::getNodeAt(int position)
{
    if (top == nullptr || position > stackSize || position < 1) return "";
    int level = stackSize;

    if (position == level)
    {
        return top->data;
    }
    else
    {
        Node<T>* underTop = top;

        do
        {
            underTop = underTop->previous;
            --level;
        } while (level != position);

        return underTop->data;
    }
}

template <class T>
void LStack<T>::setNodeSize(int size)
{
    if (top != nullptr)
    {
        top->size = size;
    }
}

template <class T>
int LStack<T>::getNodeSize()
{
    if (top != nullptr)
    {
        return top->size;
    }

    return -1;
}

template <class T>
int LStack<T>::getStackSize()
{
    return stackSize;
}

template <class T>
string LStack<T>::toString()
{
    stringstream sstream;
    Node<T>* aux = top;

    while (aux != nullptr)
    {
        sstream << aux->data << endl;
        aux = aux->previous;
    }

    return sstream.str();
}

#endif // LSTACK_H_INCLUDED
