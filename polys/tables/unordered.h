#pragma once
#include <iostream>
#include <string>
#include "table.h"


using namespace std;

// ��������������� �������
class UnorderedTable 
{
private:
    // ��������� ������ ��� �������� ��� ����-��������
    Node<Entry>* table;

    // ������� ���-�� �������� ��� ��������
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

    // ������� � �������
    void insert(const string& key, const Polynomial& poly)  //�������� �� ���� ������� � ����������� ��� ����� �������� �����
    {
        operationsCount++;
        Node<Entry>* newNode = new Node<Entry>; 
        newNode->data.key = key;
        newNode->data.poly = poly;
        newNode->next = table;
        table = newNode;
        cout << "Insert operation. Number of operations: " << operationsCount << endl;
    }
    // ����� �� �����
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

    // ����� ���� �������
    void printTable() 
    {
        operationsCount++;
        // ������� ������� ���������
        Node<Entry>* current = table;
        while (current != nullptr) //���� �� ������ �� �������� ��������
        {
            cout << "Key: " << current->data.key << ", Polynomial: ";
            current->data.poly.print();
            cout << endl;
            current = current->next;
        }
        cout << "Get operation. Number of operations: " << operationsCount << endl;
    }

    // �������� �� �����
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

    // ����� �� �����
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

    // ����� ���������� �������� ��������
    void logOperations()
    {
        cout << "Number of operations: " << operationsCount << endl;
    }
};