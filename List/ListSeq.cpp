//
// Created by Timur on 25.04.2021.
//

#include "ListSeq.h"


template<class T>
ListSeq<T>::ListSeq()
{
    this->list = new LinkedList<T> ();
}

template<class T>
ListSeq<T>::ListSeq(ListSeq<T> *List)
{
    this->list = List->list->CopyLinkedList();
}

template<class T>
ListSeq<T>::ListSeq(LinkedList<T> *List)
{
    this->list = List->CopyLinkedList();
}

template<class T>
ListSeq<T>::ListSeq(T *data, size_t size)
{
    this->list = new LinkedList<T> (data, size);
}

template<class T>
T ListSeq<T>::GetFirst() {
    //if (this->GetSize())
        return this->list->get_first();
    //else
    //Exception
}

template<class T>
T ListSeq<T>::GetLast() {
    if (this->GetSize())
        return this->list->get_last();
    //else
    //Exception
}

template<class T>
T ListSeq<T>::Get(size_t index, size_t *checker) {
    *checker = 0;
    if ((index < 0) || (index >= this->GetSize()))
    {
        *checker = 1;
        //Exception
    }
    else
    {
        *checker = 0;
        return this->list->get_i(index);
    }
}

template<class T>
size_t ListSeq<T>::GetSize() {
    return this->list->get_size();
}
/*
template<class T>
sequence <T> *ListSeq<T>::GetSubSeq(size_t beg, size_t end, size_t *checker) {
    *checker = 0;
    if ((beg < 0) || (beg >= this->GetSize()) || (end < 0) || (end >= this->GetSize()))
    {
        *checker = 1;
        //Exception;
    }
    else
    {
        *checker = 0;
        auto ans = new ListSeq<T>;
        ans->list = this->list->get_sublist(beg, end);
        return (sequence<T> *) ans;
    }
}*/

template<class T>
void ListSeq<T>::Append(T item) {
    list->append(item);
}

template<class T>
void ListSeq<T>::Prepend(T item) {
    list->prepend(item);
}

template<class T>
void ListSeq<T>::Insert(T item, size_t index, size_t *checker) {
    *checker = 0;
    if ((index < 0) || (index > this->GetSize()))
    {
        *checker = 1;
        //Exception
    }
    else
        this->list->insert(index, item);
}

template<class T>
sequence <T> *ListSeq<T>::Concat(sequence<T> *list2) {

    size_t checker = 0;
    sequence <T> *ans = new ListSeq<T> (this->list);
    for (size_t i = 0; i < list2->GetSize(); i++)
        ans->Append(list2->Get(i, &checker));
    return ans;
}

template <class T>
void ListSeq<T>::Print ()
{
    (this->list)->printList();
}

template<class T>
sequence<T> *ListSeq<T>::GetSubSeq(size_t begin, size_t end, size_t *checker) {
    if ((begin < 0) || (begin > end) || (end > this->GetSize() -1))
    {
        *checker = 1;
        //Exception
    }
    else
    {
        sequence<T> *ans = new ListSeq<T> (this->list->get_sublist(begin, end));
        return ans;
    }
}

template<class T>
void ListSeq<T>::Set(size_t index, T value, size_t *checker)
{
    if ((index < 0) || (index >= GetSize()))
    {
        *checker = 1;
        //Exception
    }
    else
        this->list->set_i(index, value);
}

template<class T>
void ListSeq<T>::Resize(size_t new_size)
{
    if (new_size > 0)
        this->list->resize(new_size);
}

template<class T>
void ListSeq<T>::Delete()
{
    this->list->DeleteLinkedList();
    free(this);
}

template<class T>
sequence<T> *ListSeq<T>::Copy()   {
    size_t checker = 0;
    sequence<T> *copy = new ListSeq<T>();
    for (int i = 0; i < this->GetSize(); i++)
        copy->Append(this->list->get_i(i));
    return copy;
}
