#pragma once
#include <iostream>
#include "table.h"
#include <string>
#include "table.h"

using namespace std;

class OrderedTable 
{
private:
    Node<Entry>* table;
    int operationsCount;

public:
    OrderedTable() 
    {
        table = nullptr;
        operationsCount = 0;
    }

    ~OrderedTable() 
    {
        Node<Entry>* current = table;
        while (current != nullptr) 
        {
            Node<Entry>* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(const string& key, const Polynomial& poly) 
    {
        operationsCount++;
        Node<Entry>* newNode = new Node<Entry>;
        newNode->data.key = key;
        newNode->data.poly = poly;

        if (table == nullptr || key < table->data.key) 
        {
            newNode->next = table;
            table = newNode;
        }
        else 
        {
            Node<Entry>* current = table;
            while (current->next != nullptr && key > current->next->data.key) 
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        cout << "Insert operation. Number of operations: " << operationsCount << endl;
    }

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

    void printTable() 
    {
        operationsCount++;
        Node<Entry>* current = table;
        while (current != nullptr) 
        {
            cout << "Key: " << current->data.key << ", Polynomial: ";
            current->data.poly.print();
            cout << endl;
            current = current->next;
        }
        cout << "Print operation. Number of operations: " << operationsCount << endl;
    }

    void remove(const string& key) 
    {
        operationsCount++;
        Node<Entry>* current = table;
        Node<Entry>* previous = table;
        while (current != nullptr) {
            if (current->data.key == key) 
            {
                if (previous == current) 
                {
                    table = current->next;
                }
                else {
                    previous->next = current->next;
                }
                Node<Entry>* nodeToDelete = current;
                current = current->next;
                delete nodeToDelete;
                cout << "Delete operation. Number of operations: " << operationsCount << endl;
                reorderTable(table);
                return;
            }
            previous = current;
            current = current->next;
        }
        throw "Polynomial not found";
    }

    void reorderTable(Node<Entry>* node) 
    {
        operationsCount++;
        if (node == nullptr) {
            return;
        }

        Node<Entry>* minNode = node;
        Node<Entry>* minNodePrevious = nullptr;
        Node<Entry>* current = node->next;

        while (current != nullptr) {
            if (current->data.key < minNode->data.key) {
                minNode = current;
                minNodePrevious = node;
            }
            current = current->next;
        }

        if (minNodePrevious != nullptr) {
            minNodePrevious->next = minNode->next;
        }
        else {
            Node<Entry>* temp = minNode->next;
            delete minNode;
            minNode = temp;
            table = minNode;
        }

        Node<Entry>* newNode = new Node<Entry>;
        newNode->data.key = node->data.key;
        newNode->data.poly = node->data.poly;
        newNode->next = minNode;
        node = newNode;

        reorderTable(node->next);
    }

    Polynomial findByKey(const string& key) 
    {
        operationsCount++;
        Node<Entry>* current = table;
        while (current != nullptr) 
        {
            if (current->data.key == key) 
            {
                cout << "Find operation. Number of operations: " << operationsCount << endl;
                return current->data.poly;
            }
            current = current->next;
        }
        throw "Polynomial not found";
    }
    void logOperations()
    {
        cout << "Number of all operations: " << operationsCount << endl;
    }
};
