//
// Created by Timur on 29.05.2021.
//

#ifndef LAB2_VECTOR_MENU_H
#define LAB2_VECTOR_MENU_H
#include <iostream>
#include <stdlib.h>
#include <functional>

int variable_choise();


const char *MSGS[] = {"0. Quit", "1. Sum polynoms", "2. Multiply polynoms", "3. Raise to a degree", "4. Composition",
                      "5. Count a value for entered x", "6. Apply function for polynom's coef", "7. Concat", "8. Get subsequence",
                      "9. Change type of variables", "10. Tests"};
const size_t MSGS_SIZE = (sizeof(MSGS) / sizeof(MSGS[0]));

template <class T>
bool foo (char, float, T);

int stoi (char *);

int choise();

void dialog (int);

template <class T>
sequence<T> *Where(char, T, bool (*)(char, T, T), Polynom<T> *, int);

#endif //LAB2_VECTOR_MENU_H
