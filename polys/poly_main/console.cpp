#include <iostream>
#include "list.h"
#include "monom.h"
#include <vector>


int main()
{
    vector<Polynomial> polynomials;

    int choice = -1; // 0 - EXIT

    cout << "Polynomial creation app: " << "\n"
        << "Enter 1 to CREATE a new polynomial:" << "\n"
        << "Enter 2 to PRINT a polynomial:" << "\n"
        << "Enter 3 to ADD polynomials:" << "\n"
        << "Enter 4 to SUBTRACT polynomials:" << "\n"
        << "Enter 5 to MULTIPLY polynomials:" << "\n"
        << "Enter 6 to MULTIPLY a polynomial by a constant:" << "\n"
        << "Enter 7 to CLEAR a polynomial:" << "\n"
        << "Enter 0 to EXIT a program:" << "\n";
    do
    {
        cout << "Select menu mode\n";
        cin >> choice;
        if (choice < 0 || choice > 7)
            cout << "Wrong mode selected\n";
        if (choice == 0)
        {
            cout << "Exit the program.";
            return 0;
        }
        if (choice == 1)
        {
            Polynomial p;
            double coef;
            int deg;

            cout << "Creating the monom: \n";
            cout << "Enter the coefficient: \n";
            cin >> coef;

            int degX;
            cout << "Enter the Degree x (from 0 to 9): \n";
            do
            {
                cin >> degX;
                if (degX < 0 || degX > 9)
                {
                    cout << "Error: Please enter a value between 0 and 9.\n";
                }
            } while (degX < 0 || degX > 9);

            int degY;
            cout << "Enter the Degree y (from 0 to 9): \n";
            do
            {
                cin >> degY;
                if (degY < 0 || degY > 9)
                {
                    cout << "Error: Please enter a value between 0 and 9.\n";
                }
            } while (degY < 0 || degY > 9);

            int degZ;
            cout << "Enter the Degree z (from 0 to 9): \n";
            do
            {
                cin >> degZ;
                if (degZ < 0 || degZ > 9)
                {
                    cout << "Error: Please enter a value between 0 and 9.\n";
                }
            } while (degZ < 0 || degZ > 9);

            cout << "\n";

            deg = degZ + (degY * 10) + (degX * 100);

            p.addMonom(coef, deg);
            p.print();
            cout << "\n";
            polynomials.push_back(p);
        }
        if (choice == 2)
        {
            if (polynomials.empty())
            {
                cout << "Error: There are no polynomials to print.\n";
                continue;
            }
            int index;
            cout << "Enter the number of the polynomial to print: \n";
            cin >> index;
            if (index > 0 && index < polynomials.size() + 1)
            {
                cout << "Printing the polynomial: \n";
                polynomials[index -1].print();
                cout << "\n";
            }
            else
            {
                cout << "Error: Invalid number.\n";
            }
        }
        if (choice == 3)
        {
            if (polynomials.size() < 2)
            {
                cout << "Error: There are not enough polynomials to add.\n";
                continue;
            }
            int i, j;
            cout << "Enter the number of the first polynomial and the second polynomial that you want to add: ";
            cin >> i >> j;
            if ((i > 0 && i < polynomials.size() + 1) && (j > 0 && j < polynomials.size() + 1))
            {
                Polynomial p3 = polynomials[i - 1] + polynomials[j - 1];
                cout << "Adding polynomials: \n";
                p3.print();
                cout << "\n";
                polynomials.push_back(p3);
            }
            else
            {
                cout << "Error: Invalid number.\n";
            }
        }
        if (choice == 4)
        {
            if (polynomials.size() < 2)
            {
                cout << "Error: There are not enough polynomials to subtract.\n";
                continue;
            }
            int i, j;
            cout << "Enter the number of the first polynomial and the second polynomial that you want to subtract: ";
            cin >> i >> j;
            if ((i > 0 && i < polynomials.size() + 1) && (j > 0 && j < polynomials.size() + 1))
            {
                Polynomial p4 = polynomials[i - 1] - polynomials[j - 1];
                cout << "Subtracting polynomials: \n";
                p4.print();
                cout << "\n";
                polynomials.push_back(p4);
            }
            else
            {
                cout << "Error: Invalid number.\n";
            }
        }
        if (choice == 5)
        {
            if (polynomials.size() < 2)
            {
                cout << "Error: There are not enough polynomials to multiply.\n";
                continue;

            }

            int i, j;
            cout << "Enter the number of the first polynomial and the second polynomial that you want to multiplying: ";
            cin >> i >> j;
            if ((i > 0 && i < polynomials.size() + 1) && (j > 0 && j < polynomials.size() + 1))
            {
                Polynomial p5 = polynomials[i - 1] * polynomials[j - 1];
                cout << "Multiplying polynomials: \n";
                p5.print();
                cout << "\n";
                polynomials.push_back(p5);
            }
            else
            {
                cout << "Error: Invalid number.\n";
            }
        }
        if (choice == 6)
        {
            if (polynomials.empty())
            {
                cout << "Error: There are no polynomials to multiply.\n";
                continue;
            }
            double cons;
            cout << "Enter the constant: \n";
            cin >> cons;
            int i;
            cout << "Enter the number of the polynomial you want to multiply by the constant: ";
            cin >> i;
            if (i > 0 && i < polynomials.size() + 1)
            {
                Polynomial p6 = polynomials[i - 1] * cons;
                cout << "Multiplying a polynomial by a constant: \n";
                p6.print();
                cout << "\n";
                polynomials.push_back(p6);
            }
            else
            {
                cout << "Error: Invalid number.\n";
            }
        }
        if (choice == 7)
        {
            if (polynomials.empty())
            {
                cout << "Error: There are no polynomials to delete.\n";
                continue;
            }

            cout << "Current polynomials (from 1 to last): ";
            for (int i = 0; i < polynomials.size(); i++)
            {
                polynomials[i].print();
                cout << "\n";
            }

            int number;
            cout << "Enter the number of the polynomial to delete: ";
            cin >> number;
            int index = number - 1;
            if (index > 0 && index < polynomials.size()+1)
            {
                polynomials.erase(polynomials.begin() + index);
            }
            else
            {
                cout << "Error: Invalid number.\n";
            }
            cout << "Current polynomials (from 1 to last): ";
            for (int i = 0; i < polynomials.size(); i++)
            {
                polynomials[i].print();
                cout << "\n";
            }

        }
    } while (true);
}
