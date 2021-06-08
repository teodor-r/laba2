//
// Created by Timur on 25.04.2021.
//

#ifndef LAB2_VECTOR_LISTSEQ_H
#define LAB2_VECTOR_LISTSEQ_H
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "../sequence.h"
template <class T>
class ListSeq : public sequence <T>
{
protected:
    LinkedList <T> *list;
public:
    //Constructors
    ListSeq ();
    ListSeq (ListSeq <T> *);
    ListSeq (LinkedList <T> *);
    ListSeq (T *, size_t);
    //  Decomposition
    T GetFirst ();
    T GetLast ();
    T Get (size_t, size_t *);
    void Set (size_t, T, size_t *);
    void Resize (size_t);
    size_t GetSize ();
    sequence <T> *GetSubSeq (size_t, size_t, size_t *);
    void Append (T);
    void Prepend (T);
    void Insert (T, size_t, size_t *);
    sequence<T> *Concat (sequence<T> *);
    void Print ();
    void Delete();
    sequence<T> *Copy();
};

#endif //LAB2_VECTOR_LISTSEQ_H
