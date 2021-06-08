//

#include "polynom.h"
#include "complex.h"
#include "menu.h"

// Created by Timur on 15.05.2021.

template<class T>
Polynom<T>::Polynom(ListSeq<T> *list) {
    this->data = (sequence<T> *) list;
    this->seqtype = 1;
}

template<class T>
Polynom<T>::Polynom(ArrSeq<T> *seq) {
    this->data = (sequence<T> *) seq;
    this->seqtype = 2;
}

template<class T>
Polynom<T> *new_Polynom (int seq)
{
    if (seq == 1)
        return new Polynom<T>(new ListSeq<T>());
    else
        return new Polynom<T>(new ArrSeq<T>());
}



template<class T>
Polynom<T> *new_Polynom(Polynom<T> *pol) {
    if (pol->GetType() == 1)
        return new Polynom<T>(new ListSeq<T>());
    else
        return new Polynom<T>(new ArrSeq<T>());
}

template<class T>
Polynom<T> *new_Polynom(sequence<T> *sequence, int seq) {
    if (seq == 1)
        return new Polynom<T>((ListSeq<T> *) sequence);
    else
        return new Polynom<T>((ArrSeq<T> *) sequence);
}

//

template<class T>
size_t Polynom<T>::Size() {
    return this->data->GetSize();
}

template<>
void Polynom<complex>::Print() {
    size_t checker = 0;
    size_t degree = this->Size();
    if (this->data->GetFirst() != complex (0, 0))
        std::cout << this->data->GetFirst() << " ";
    for (size_t i = 1; i < degree; i++) {
        complex coef = this->data->Get(i, &checker);
        if (coef != 0.) {
            if (coef.imagine == 0) {
                if (coef.real < 0)
                    if (coef == -1.)
                        std::cout << "- x^" << i << " ";
                    else
                        std::cout << "- " << -1 * coef.real << " * x^" << i << " ";
                else if (coef == 1.)
                    std::cout << "+ x^" << i << " ";
                else
                    std::cout << "+ " << coef.real << " * x" << i << " ";
            } else if (coef.real == 0) {
                if (coef.imagine > 0)
                    if (coef.imagine == 1)
                        std::cout << "+ i * x^" << i << " ";
                    else
                        std::cout << "+ " << coef.imagine << "i * x^" << i << " ";
                else if (coef.imagine == -1)
                    std::cout << "- i * x^" << i << " ";
                else
                    std::cout << "- " << -1 * coef.imagine << "i * x^" << i << " ";
            } else if ((coef.real < 0) && (coef.imagine < 0))
                std::cout << "- (" << -1 * coef.real << " + " << -1 * coef.imagine << "i) * x^" << i << " ";
            else
                std::cout << "+ (" << coef << ") * x^" << i << " ";
        }
    }
    std::cout << std::endl;
}

template<class T>
void Polynom<T>::Print() {
    size_t checker = 0;
    size_t degree = this->Size();
    if (this->data->GetFirst() != (T)0.)
        std::cout << this->data->GetFirst() << " ";
    for (size_t i = 1; i < degree; i++) {
        T coef = this->data->Get(i, &checker);
        if (coef != 0) {
            if (coef == -1)
                std::cout << "- x^" << i << " ";
            else if (coef == 1)
                std::cout << "+ x^" << i << " ";
            else if (coef > 0)
                std::cout << "+ " << coef << " * x^" << i << " ";
            else if (coef != 0)
                std::cout << "- " << -1 * coef << " * x^" << i << " ";
        }
    }
    std::cout << std::endl;
}

template<class T>
T Polynom<T>::Get(size_t index, size_t *checker) {
    if ((index >= 0) && (index < this->Size()))
        return this->data->Get(index, checker);
}

template<class T>
T Power(T value, size_t degree) {
    if (degree == 0)
        return 1;
    T tmp = value;
    for (size_t i = 1; i < degree; i++)
        tmp = tmp * value;
    return tmp;
}

template<class T>
Polynom<T> *PolynomEnter(int Seqtype) {
    int dim;
    size_t checker = 0;
    T *data;
    while (1) {
        std::cout << "Enter the dimension of polynom:";
        char *dim_ = new char(100);
        std::cin >> dim_;
        dim = stoi(dim_);
        delete dim_;
        if (dim <= 0)
            std::cout << "You entered a wrond number, please, try again!" << std::endl;
        else
            break;
    }
    Polynom<T> *ans;
    if (Seqtype == 1)
        ans = new Polynom<T>(new ListSeq<T>(new LinkedList<T>()));
    else
        ans = new Polynom<T>(new ArrSeq<T>(new DArray<T>()));
    for (size_t i = 0; i < dim; i++) {
        T coef;
        std::cin >> coef;
        ans->Insert(coef, i, &checker);
    }
    while (ans->Get(ans->Size() - 1, &checker) == (T)0.)
        ans->Resize(ans->Size() - 1);
    return ans;
}

template<class T>
Polynom<T> *PolynomSum(Polynom<T> *first, Polynom<T> *second) {
    size_t checker;
    Polynom<T> *ans = new_Polynom(first);
    ans->Resize(first->Size() > second->Size() ? first->Size() : second->Size());
    Polynom<T> *minimumPol = first->Size() < second->Size() ? first : second;
    Polynom<T> *maxPol = first->Size() < second->Size() ? second : first;
    for (size_t i = 0; i < minimumPol->Size(); i++)
        ans->Set(i, first->Get(i, &checker) + second->Get(i, &checker), &checker);
    for (size_t i = minimumPol->Size(); i < ans->Size(); i++)
        ans->Set(i, maxPol->Get(i, &checker), &checker);
    return ans;
}

template<class T, class P>
Polynom<T> *PolynomScalarMult(Polynom<T> *pol, P scalar) {
    Polynom<T> *ans = new_Polynom(pol);
    ans->Resize(pol->Size());
    size_t checker = 0;
    for (size_t i = 0; i < pol->Size(); i++)
        ans->Set(i, pol->Get(i, &checker) * scalar, &checker);
    return ans;
}

template<class T>
Polynom<T> *PolynomMult(Polynom<T> *first, Polynom<T> *second) {
    Polynom<T> *ans = new_Polynom(first);
    size_t checker = 0;
    ans->Resize(first->Size() + second->Size() - 1);
    for (size_t i = 0; i < first->Size(); i++) {
        for (size_t j = 0; j < second->Size(); j++) {
            size_t now_degree = i + j;
            T coef = first->Get(i, &checker) * second->Get(j, &checker);
            ans->Set(now_degree, ans->Get(now_degree, &checker) + coef, &checker);
        }
    }
    return ans;
}

template<class T>
Polynom<T> *PolynomDegree(Polynom<T> *pol, size_t degree) {
    Polynom<T> *ans = pol, *temp = pol;
    if (degree < 0) {
        //Exception
    }
    if (degree == 0) {
        T q[] = {(T) 1.};
        if (pol->GetType() == 1)
            return new Polynom<T>(new ListSeq<T>(q, 1));
        else
            return new Polynom<T>(new ArrSeq<T>(q, 1));
    }
    if (degree == 1) {
        if (pol->GetType() == 1)
            return new Polynom<T>(new ListSeq<T>((ListSeq<T> *) pol->GetData()));
        else
            return new Polynom<T>(new ArrSeq<T>((ArrSeq<T> *) pol->GetData()));
    }
    for (size_t i = 2; i <= degree; i++) {
        ans = PolynomMult(ans, pol);
    }
    return ans;
}

template<class T>
Polynom<T> *PolynomComp(Polynom<T> *first, Polynom<T> *second) {
    size_t checker = 0;
    Polynom<T> *ans = new_Polynom(first);
    for (size_t now_degree = 0; now_degree < first->Size(); now_degree++) {
        T coef = first->Get(now_degree, &checker);
        ans = PolynomSum(ans, PolynomScalarMult(PolynomDegree(second, now_degree), coef));
    }

    return ans;
}

template<class T>
T Polynom<T>::CountValue(T x) {
    size_t checker = 0;
    T ans = 0;
    for (size_t i = 0; i < this->Size(); i++)
        ans = ans + (this->data->Get(i, &checker)) * Power(x, i);
    return ans;
}

template<class T>
int Polynom<T>::GetType() {
    return seqtype;
}

template<class T>
sequence<T> *Polynom<T>::GetData() {
    return this->data;
}

template<class T>
void Polynom<T>::Set(size_t index, T value, size_t *checker) {
    this->GetData()->Set(index, value, checker);
}

template<class T>
void Polynom<T>::Resize(size_t new_size) {
    this->GetData()->Resize(new_size);
}

template<class T>
Polynom<T>::Polynom(T *data, int SeqType) {
    this->seqtype = SeqType;
    if (SeqType == 1)
        this->data = new ListSeq<T>(data, sizeof(data) / sizeof(T));
    else
        this->data = new ArrSeq<T>(data, sizeof(data) / sizeof(T));
}

template<class T>
void Polynom<T>::Insert(T value, size_t index, size_t *checker) {
    this->GetData()->Insert(value, index, checker);
}

