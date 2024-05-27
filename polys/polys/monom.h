#pragma once
#include <iostream>
#include "list.h"
#include <cmath>


using namespace std;

struct Monom 
{
    int degree;
    double coeff;
    bool operator<(const Monom& other) const
    {
        if (degree != other.degree)
        {
            return degree < other.degree;
        }
        return coeff < other.coeff;
    }
    bool operator>(const Monom& other) const
    {
        if (degree != other.degree)
        {
            return degree > other.degree;
        }
        return coeff > other.coeff;
    }
    friend ostream& operator<<(ostream& os, const Monom& monom)
    {
        if ((monom.coeff == 1 || monom.coeff == -1) && monom.degree == 0)
            os << monom.coeff;
        else if (monom.coeff != 1 && monom.coeff != -1)
            os << monom.coeff;
        else if (monom.coeff == -1)
            os << "-";

        if (monom.degree / 100 != 0)
            os << "x^" << monom.degree / 100;
        if (monom.degree / 10 % 10 != 0)
        {
            if (monom.degree / 100 == 0)
                os << "y^" << monom.degree / 10;
            else
                os << "y^" << monom.degree / 10 % 10;
        }
        if (monom.degree % 10 != 0)
        {
            if (monom.degree / 100 == 0 && monom.degree / 10 % 10 == 0)
                os << "z^" << monom.degree;
            else
                os << "z^" << monom.degree % 10;
        }
        return os;

    }
    friend istream& operator>>(istream& is, Monom& monom)
    {
        is >> monom.coeff >> monom.degree;
        return is;
    }


    Monom(double coeff, int degree) : coeff(coeff), degree(degree) {}
};


class Polynomial
{
private:
    List<Monom> monoms;
    bool isEqual(const Polynomial& other) const
    {
        Node<Monom>* current1 = monoms.GetHead();
        Node<Monom>* current2 = other.monoms.GetHead();
        while (current1 != nullptr && current2 != nullptr)
        {
            if (current1->data.degree != current2->data.degree || current1->data.coeff != current2->data.coeff)
            {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        return current1 == nullptr && current2 == nullptr;
    }
    void deleteZeroMonoms()
    {
        Node<Monom>* current = monoms.GetHead();
        Node<Monom>* prev = nullptr;
        while (current != nullptr)
        {
            if (current->data.coeff == 0)
            {
                if (prev == nullptr)
                {
                    monoms.pop_list(current);
                    current = monoms.GetHead();
                }
                else
                {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
    void bringSimilarMonoms()
    {
        Node<Monom>* current = monoms.GetHead();
        while (current != nullptr) 
        {
            Node<Monom>* next = current->next;
            while (next != nullptr) 
            {
                if (current->data.degree == next->data.degree) 
                {
                    current->data.coeff += next->data.coeff;
                    monoms.pop_list(next);
                    next = current->next;
                }
                else 
                {
                    next = next->next;
                }
            }
            current = current->next;
        }
        deleteZeroMonoms();
    }


public:
    Polynomial() {}
    void addMonom(double coeff, int degree)
    {
        Monom monom(coeff, degree);
        monoms.push_back(monom);
        sort();
        deleteZeroMonoms();
    }


    void print()
    {

        cout << *this;
    }
    void sort()
    {
        monoms.sort();
    }




    friend ostream& operator<<(ostream& os, const Polynomial& poly)
    {
        Node<Monom>* current = poly.monoms.GetHead();
        while (current != nullptr)
        {
            os << current->data;
            current = current->next;
            if (current != nullptr && current->data.coeff > 0)
            {
                os << " + ";
            }
            if (current != nullptr && current->data.coeff < 0)
            {
                os << " ";
            }
        }
        return os;
    }

    // сложить два многочлена
    Polynomial operator+(const Polynomial& other) const 
    {
        Polynomial result;
        Node<Monom>* current = monoms.GetHead();
        while (current != nullptr) 
        {
            result.addMonom(current->data.coeff, current->data.degree);
            current = current->next;
        }
        current = other.monoms.GetHead();
        while (current != nullptr) 
        {
            result.addMonom(current->data.coeff, current->data.degree);
            current = current->next;
        }
        result.bringSimilarMonoms();
        return result;
    }
    Polynomial operator-(const Polynomial& other) const
    {

        if (isEqual(other))
        {
            return Polynomial();
        }
        Polynomial negatedOther(other);
        negatedOther.negate();
        Polynomial result(*this);
        result = result + negatedOther;
        result.bringSimilarMonoms();
        return result;
    }


   void negate() 
    {
        Polynomial result = Polynomial(*this);
        Node<Monom>* current = monoms.GetHead();

        while (current != nullptr) 
        {
            current->data.coeff = -current->data.coeff;
            current = current->next;
        }
    }


    Polynomial operator*(const int& coeff) const
    {
        Polynomial result = Polynomial(*this);
        result *= coeff;
        return result;
    }
    Polynomial& operator*=(const int& coeff)
    {
        Node<Monom>* current = monoms.GetHead();

        while (current != nullptr)
        {
            current->data.coeff *= coeff;
            current = current->next;
        }

        bringSimilarMonoms();
        deleteZeroMonoms();

        return *this;
    }
    Polynomial& operator*=(const Polynomial& other)
    {
        *this = (*this) * other;
        return *this;
    }
    Polynomial operator*(const Polynomial& other) const
    {
        Polynomial result;
        Node<Monom>* current1 = monoms.GetHead();

        while (current1 != nullptr)
        {
            double coeff1 = current1->data.coeff;
            int degree1 = current1->data.degree;


            Node<Monom>* current2 = other.monoms.GetHead();

            while (current2 != nullptr)
            {
                double coeff2 = current2->data.coeff;
                int degree2 = current2->data.degree;

                // проверка корректности по каждой переменной новой степени
                int sum_units = (degree1 % 10) + (degree2 % 10);
                int sum_tens = ((degree1 / 10) % 10) + ((degree2 / 10) % 10);
                int sum_hundreds = (degree1 / 100) + (degree2 / 100);

                if (sum_units > 9 || sum_tens > 9 || sum_hundreds > 9)
                {
                    throw ("Error: Degree is out of range");
                }
                int newDegree = degree1 + degree2;
                if (newDegree > 999)
                {
                    throw ("Error: Degree of resulting monomial is greater than 999");
                }

                Monom newMonom(coeff1 * coeff2, newDegree);
                result.monoms.push_back(newMonom);

                current2 = current2->next;
            }

            current1 = current1->next;
        }

        result.bringSimilarMonoms();
        result.deleteZeroMonoms();

        return result;
    }
};
