#pragma once
#include <iostream>
#include <string>
#include "table.h"


using namespace std;

// Неупорядоченная таблица
class UnorderedTable 
{
private:
    // Связанный список для хранения пар ключ-значение
    Node<Entry>* table;

    // Подсчет кол-во операций для полинома
    int operationsCount;
public:
    UnorderedTable() 
    {
        table = nullptr;
        operationsCount = 0;
    }

    ~UnorderedTable() 
    {
        Node<Entry>* current = table;
        while (current != nullptr) 
        {
            Node<Entry>* next = current->next;
            delete current;
            current = next;
        }
    }

    // Вставка в таблицу
    void insert(const string& key, const Polynomial& poly)  //передаем на вход полином и присваиваем ему новое значение ключа
    {
        operationsCount++;
        Node<Entry>* newNode = new Node<Entry>; 
        newNode->data.key = key;
        newNode->data.poly = poly;
        newNode->next = table;
        table = newNode;
        cout << "Insert operation. Number of operations: " << operationsCount << endl;
    }
    // Вывод по ключу
    void printByKey(const string& key) 
    {
        operationsCount++;
        Node<Entry>* current = table;
        while (current != nullptr) 
        {
            if (current->data.key == key) 
            {
                cout << "Key: " << current->data.key << ", Polynomial: ";
                current->data.poly.print();
                cout << endl;
                cout << "Get operation. Number of operations: " << operationsCount << endl;
                return;
            }
            current = current->next;
        }
        throw "Polynomial not found";
    }

    // Вывод всей таблицы
    void printTable() 
    {
        operationsCount++;
        // создаем текущий указатель
        Node<Entry>* current = table;
        while (current != nullptr) //пока не дойдем до нулевого значения
        {
            cout << "Key: " << current->data.key << ", Polynomial: ";
            current->data.poly.print();
            cout << endl;
            current = current->next;
        }
        cout << "Get operation. Number of operations: " << operationsCount << endl;
    }

    // Удаление по ключу
    void remove(const string& key) 
    {
        operationsCount++;
        Node<Entry>* current = table;
        Node<Entry>* prev = table;
        while (current != nullptr) 
        {
            if (current->data.key == key) 
            {
                if (prev == current)
                {
                    table = current->next;
                }
                else 
                {
                    prev->next = current->next;
                }
                delete current;
                cout << "Delete operation. Number of operations: " << operationsCount << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        throw "Polynomial not found";
    }

    // Поиск по ключу
    Polynomial findByKey(const string& key) 
    {
        operationsCount++;
        Node<Entry>* current = table;
        while (current != nullptr) 
        {
            if (current->data.key == key) 
            {
                cout << "Get operation. Number of operations: " << operationsCount << endl;
                return current->data.poly;
            }
            current = current->next;
        }
        throw "Polynomial not found";
    }

    // Вывод количества операций отдельно
    void logOperations()
    {
        cout << "Number of operations: " << operationsCount << endl;
    }
};