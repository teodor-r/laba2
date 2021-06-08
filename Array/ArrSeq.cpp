//

#include <iostream>
#include "ArrSeq.h"

// Created by Timur on 28.04.2021.

template<class T>
ArrSeq<T>::ArrSeq(DArray<T> *arr)
{
    this->array = arr->CopyDArray();
}

//
template<class T>
ArrSeq<T>::ArrSeq(ArrSeq<T> *arr)
{
    this->array = arr->array->CopyDArray();
}

template<class T>
ArrSeq<T>::ArrSeq() {
    this->array = new DArray<T> ();
}

template<class T>
ArrSeq<T>::ArrSeq(T *data, size_t size)
{
    this->array = new DArray<T> (data, size);
}

template<class T>
T ArrSeq<T>::GetFirst() {
    if (array->get_size())
        return array->get_i(0);
}

template<class T>
T ArrSeq<T>::GetLast() {
    if (array->get_size())
        return array->get_i(array->get_size() - 1);
}

template<class T>
T ArrSeq<T>::Get(size_t index, size_t *checker) {
    *checker = 0;
    if ((index < 0) || (index > array->get_size()))
    {
        *checker = 1;
        //exception;
    }
    return array->get_i(index);
}

template<class T>
size_t ArrSeq<T>::GetSize() {
    return array->get_size();
}

template<class T>
void ArrSeq<T>::Append(T value) {
    array->resize(array->get_size() + 1);
    array->set_i(array->get_size() - 1, value);
}

template<class T>
void ArrSeq<T>::Prepend(T value) {
    array->resize(array->get_size() + 1);
    for (size_t i = 1; i < array->get_size(); i++)
        array->set_i(i, array->get_i(i - 1));
    array->set_i(0, value);
}

template<class T>
void ArrSeq<T>::Insert(T value, size_t index, size_t *checker) {
    if ((index < 0) || (index > array->get_size())) {
        *checker = 1;
        //excepetion
    }
    else {
        this->array->insert(value, index);
    }
}

template<class T>
void ArrSeq<T>::Print() {
    this->array->printArr();
}

template<class T>
sequence<T> *ArrSeq<T>::GetSubSeq(size_t begin, size_t end, size_t *checker) {
    if ((begin < 0) || (begin > end) || (end > this->GetSize() - 1))
    {
        *checker = 1;
        //Exception
    }
    else
    {
        sequence<T> *ans = new ArrSeq<T> (this->array->GetSubArray(begin, end));
        return ans;
    }

}

template<class T>
sequence<T> *ArrSeq<T>::Concat(sequence<T> *second) {
    sequence <T> *ans = new ArrSeq<T> (this->array);
    size_t checker = 0;
    for (size_t i = 0; i < second->GetSize(); i++) {
        ans->Append(second->Get (i, &checker));
    }
    return ans;
}

template<class T>
void ArrSeq<T>::Delete()
{
    this->array->Delete();
}

template<class T>
void ArrSeq<T>::Set(size_t index, T value, size_t *checker)
{
    if ((index < 0) || (index >= GetSize()))
    {
        *checker = 1;
        //Exception
    }
    if (this->GetSize() == 0)
        this->array = new DArray<T> (&value, 1);
    else if (index == 0)
        this->array->set_i(index, value);
}

template<class T>
void ArrSeq<T>::Resize(size_t new_size)
{
    if (new_size > 0)
        this->array->resize(new_size);
}
template<class T>
sequence<T> *ArrSeq<T>::Copy()   {
    size_t checker = 0;
    auto *copy = new ArrSeq<T>();
    for (int i = 0; i < this->GetSize(); i++)
        copy->Append(this->array->get_i(i));
    return copy;
}




