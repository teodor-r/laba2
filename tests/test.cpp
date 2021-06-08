//
// Created by kuzin on 05.06.2021.
//

#include "test.h"
#include "../polynom.h"
#include "../complex.h"


void print_result_set(const string &Test, pair<int, int> times) {
    int array_time = times.first;
    int list_time = times.second;
    cout << Test << ":" << endl;

    cout << "Dynamic Array: " << array_time << " microseconds" << endl;
    cout << "Linked list: " << list_time << " microseconds" << endl;
}

template<class T>
pair<T, T> test_create_polynom(int n)
{   size_t checker;
    int array_time, list_time;
    Polynom<T> *p1,*p2;
    p1 = new Polynom<T>(new ListSeq<T>(new LinkedList<T>()));
    auto start_time = chrono::steady_clock::now();
    for (size_t i = 0; i < n; i++) {
        T coef;
        p1->Insert(coef, rand() % 50 , &checker);
    }
    auto end_time = chrono::steady_clock::now();
    list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    p2 = new Polynom<T>(new ArrSeq<T>(new DArray<T>()));
    for (size_t i = 0; i < n; i++) {
        T  coef;
        p2->Insert(coef, rand() % 50 , &checker);
    }
    end_time = chrono::steady_clock::now();
    array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    return {array_time, list_time};
}





template<class T>
pair<int, int> test_sum_polynom(int n)
{
    int array_time, list_time;
    size_t checker;
    Polynom<T> *p1,*p2;
    p1 = new Polynom<T>(new ListSeq<T>(new LinkedList<T>()));
    for (size_t i = 0; i < n; i++) {
        T coef;
        p1->Insert(coef, rand() % 50 , &checker);
    }
    p2 = new Polynom<T>(new ListSeq<T>(new LinkedList<T>()));
    for (size_t i = 0; i < n; i++) {
        T coef;
        p2->Insert(coef, rand() % 50 , &checker);
    }
    auto start_time = chrono::steady_clock::now();
    Polynom<T> p3 = p1 + p2;
    auto end_time = chrono::steady_clock::now();
    list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    Polynom<T> *s1,*s2;
    s1 = new Polynom<T>(new ListSeq<T>(new LinkedList<T>()));
    for (size_t i = 0; i < n; i++) {
        T coef;
        s1->Insert(coef, rand() % 50 , &checker);
    }
    s2 = new Polynom<T>(new ListSeq<T>(new LinkedList<T>()));
    for (size_t i = 0; i < n; i++) {
        T coef;
        s2->Insert(coef, rand() % 50 , &checker);
    }
    start_time = chrono::steady_clock::now();
    Polynom<T> s3 = s1 + s2;
    end_time = chrono::steady_clock::now();
    array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    return {array_time, list_time};
}