

#include "menu.h"

using namespace std;
int stoi (char *str)
{
    int ans = 0, i = 0;
    int sign = (str[0] == '-') ? -1: (((str[0] >= '0') && (str[0] <= '9')) ? 1: 0);
    if (sign == 0)
        return -1;
    while (str[i] != '\0')
    {
        if ((str[i] <= '9') && (str[i] >= '0'))
            ans = 10 * ans + str[i] - '0';
        else
            return -1;
        i++;
    }
    return sign * ans;
}



int variable_choise()
{
    while (1)
    {
        std::cout << "What type of data do you wanna use?" << std::endl << "1. Integer" << std::endl << "2. Float" << std::endl << "3. Complex" << std::endl;
        char *c = new char (100);
        std::cin >> c;
        int ans = stoi (c);
        delete c;
        if ((ans > 0) && (ans < 4))
            return ans;
        else
            std::cout << "You entered a wrong number, plaese, try again!" << std::endl;
    }
}

int choise_()
{
    while (1) {
        char *ch = new char (100);
        std::cout << "What do you wanna do?" << std::endl;
        for (size_t i = 0; i < MSGS_SIZE; i++)
            std::cout << MSGS[i] << std::endl;
        std::cin >> ch;
        int choise = stoi(ch);
        delete ch;
        if ((choise >= 0) && (choise < MSGS_SIZE))
            return choise;
        else
            std::cout << "You entered a wrong number, plaese, try again!" << std::endl;
        }
}

bool where_foo (char sign, complex number, complex value)
{
    if (sign == '=')
        return value == number;
    else
    {
        //Exception
    }
}

template <class T>
bool where_foo (char sign, T number, T value)
{
    switch(sign)
    {
        case ('<'):
        {
            if (value < number)
                return true;
            return false;
        }
        case ('='):
        {
            if (value == number)
                return true;
            return false;
        }
        case ('>'):
        {
            if (value > number)
                return true;
            return false;
        }
    }
}

template <class T>
int dialog(int seq)
{
    int choise = choise_();
    while (1)
    switch (choise)
    {
        case(0):
        {
            std::cout << "Good Bye!" << std::endl;
            return 0;
        }
        case(1):
        {
            Polynom<T> *first = PolynomEnter<T>(seq);
            std::cout << "You entered P(x): ";
            first->Print();
            Polynom<T> *second = PolynomEnter<T>(seq);
            std::cout << "You entered S(x): ";
            second->Print();
            std::cout << "Sum of polynoms (P(x) + S(x)): ";
            Polynom<T> *ans = PolynomSum(first, second);
            ans->Print();
            choise = choise_();
            delete first;
            delete second;
            delete ans;
            break;
        }
        case(2):
        {
            Polynom<T> *first = PolynomEnter<T>(seq);
            std::cout << "You entered P(x): ";
            first->Print();
            Polynom<T> *second = PolynomEnter<T>(seq);
            std::cout << "You entered S(x): ";
            second->Print();
            std::cout << "Multiplication of polynoms (P(x) * S(x)): ";
            Polynom<T> *ans = PolynomMult(first, second);
            ans->Print();
            choise = choise_();
            delete first;
            delete second;
            delete ans;
            break;
        }
        case(3):
        {
            Polynom<T> *first = PolynomEnter<T>(seq);
            std::cout << "You entered P(x): ";
            first->Print();
            size_t coef;
            std::cout << "Enter degree q: ";
            std::cin >> coef;
            std::cout << "Polynom's power (P(x) ^ q): ";
            Polynom<T> *ans = PolynomDegree(first, coef);
            ans->Print();
            delete ans;
            choise = choise_();
            break;
        }
        case(4):
        {
            Polynom<T> *first = PolynomEnter<T>(seq);
            std::cout << "You entered P(x): ";
            first->Print();
            Polynom<T> *second = PolynomEnter<T>(seq);
            std::cout << "You entered S(x): ";
            second->Print();
            std::cout << "Composition of polynoms (P(S(X))): ";
            Polynom<T> *ans = PolynomComp(first, second);
            ans->Print();
            delete first;
            delete second;
            delete ans;
            choise = choise_();
            break;
        }
        case(5):
        {
            Polynom<T> *first = PolynomEnter<T>(seq);
            std::cout << "You entered P(x): ";
            first->Print();
            T x;
            std::cout << "Enter value (x) :";
            std::cin >> x;
            std::cout << "P(" << x << ") = " << first->CountValue(x) << std::endl;
            delete first;
            choise = choise_();
            break;
        }
        case(6):
        {
            Polynom<T> *first = PolynomEnter<T>(seq);
            std::cout << "You entered P(x): ";
            first->Print();
            std::cout << "Enter function to filter coefs. Like (<3), (=4), (>-3):";
            char sign;
            T number;
            std::cin >> sign >> number;
            sequence<T> *after_where = Where(sign, number, where_foo, first->GetData(), seq);
            Polynom<T> *rez = new_Polynom(after_where, seq);
            rez->Print();
            delete first;
            delete after_where;
            delete rez;
            choise = choise_();
            break;
        }
        case(7):
        {
            Polynom<T> *first = PolynomEnter<T>(seq);
            std::cout << "You entered P(x): ";
            first->Print();
            Polynom<T> *second = PolynomEnter<T>(seq);
            std::cout << "You entered S(x): ";
            second->Print();
            sequence<T> *ans = first->GetData()->Concat(second->GetData());
            Polynom<T> *answer = new_Polynom(ans, seq);
            answer->Print();
            delete first;
            delete second;
            delete ans;
            delete answer;
            choise = choise_();
            break;
        }
        case(8):
        {
            size_t checker = 0;
            Polynom<T> *first = PolynomEnter<T>(seq);
            std::cout << "You entered P(x): ";
            first->Print();
            size_t begin, end;
            std::cout << "Enter exact scopes of result polynom (from 0 to " << first->Size() - 1 << "): ";
            while (1)
            {
                std::cin >> begin >> end;
                if ((end < begin) || (begin < 0) || (begin >= first->Size()) || (end >= first->Size()))
                    std::cout << "Wrong scopes! Please, try again!" << std::endl;
                else
                    break;
            }
            sequence<T> *ans = first->GetData()->GetSubSeq(begin, end, &checker);
            for (size_t i = 0; i < begin; i++)
                ans->Prepend((T)0.);
            Polynom<T> *answer = new_Polynom(ans, seq);
            delete first;
            delete ans;
            delete answer;
            answer->Print();
            choise = choise_();
            break;
        }
        case(10):
        {

        }
        case (9):
        {
            return variable_choise();
        }
    }
}

template<class T>
sequence<T> *Where(char sign, T number, bool (*foo)(char, T, T), sequence<T> *data, int seq_type)
{
    size_t checker = 0;
    sequence<T> *ans;
    if (seq_type == 1)
        ans = (sequence<T> *) new ListSeq<T> ();
    else
        ans = (sequence<T> *) new ArrSeq<T> ();
    size_t rez_size = 0;
    for (size_t i = 0; i < data->GetSize(); i++)
        if (foo(sign, number, data->Get(i, &checker)) == true)
            ans->Append(data->Get(i, &checker));
        else
            ans->Append((T)0.);
    return ans;
}