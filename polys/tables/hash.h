#pragma once
#include <iostream>
#include "table.h"



class HashTable {
private:
    struct Bucket 
    {
        string key;
        Polynomial poly;
        Bucket* next;
    };

    Bucket** table;
    int size;
    int count;
    int operationsCount = 0;

public:
    HashTable(int size) : size(size), count(0) 
    {
        operationsCount++;
        table = new Bucket * [size];
        for (int i = 0; i < size; i++) 
        {
            table[i] = nullptr;
        }
    }

    ~HashTable() 
    {
        for (int i = 0; i < size; i++) 
        {
            Bucket* current = table[i];
            while (current != nullptr) 
            {
                Bucket* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] table;
    }

    int hash(const string& key) 
    {
        operationsCount++;
        int sum = 0;
        for (char c : key) 
        {
            sum += c;
        }
        return sum % size;
    }

    void insert(const string& key, const Polynomial& poly) 
    {
        operationsCount++;
        int index = hash(key); // ��������� ������ ��� ���-�������
        Bucket* current = table[index]; // �������� ������� ������� � bucket
        while (current != nullptr)  // ���� �� ������� ��������� � bucket
        {
            operationsCount++;
            if (current->key == key)  // ���� ���� ��� ����������, ��������� ��������
            {

                current->poly = poly;
                return;
            }
            current = current->next; // ���� � ���������� �������� � �������
        }
        operationsCount++;
        Bucket* newBucket = new Bucket; // ���� ���� �� ������, ������� ����� �������
        newBucket->key = key;
        newBucket->poly = poly;
        newBucket->next = table[index]; // ��������� ����� ������� � ������ �������
        table[index] = newBucket; // ��������� ��������� �� ������ �������
        count++;
        cout << "Insert operation. Number of operations: " << operationsCount << endl;
    }

    Polynomial printByKey(const string& key)
    {
        operationsCount++;
        int index = hash(key);
        Bucket* current = table[index];
        while (current != nullptr) 
        {
            operationsCount++;
            if (current->key == key) 
            {
                return current->poly;
            }
            current = current->next;
        }
        throw "Key not found";
    }

    bool containsKey(const string& key) 
    {
        operationsCount++;
        int index = hash(key);
        Bucket* current = table[index];
        while (current != nullptr) 
        {
            operationsCount++;
            if (current->key == key) 
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void remove(const string& key) 
    {
        operationsCount++;
        int index = hash(key);
        Bucket* current = table[index];
        Bucket* prev = nullptr;
        while (current != nullptr) 
        {
            if (current->key == key) 
            {
                if (prev == nullptr) 
                {
                    table[index] = current->next;
                }
                else 
                {
                    prev->next = current->next;
                }
                delete current;
                cout << "Delete operation. Number of operations: " << operationsCount << endl;
                count--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void printTable() 
    {
        operationsCount += size;
        for (int i = 0; i < size; i++) 
        {
            Bucket* current = table[i];
            cout << "Bucket " << i << ": ";
            while (current != nullptr) 
            {
                cout << current->key << " -> ";
                current->poly.print();
                current = current->next;
            }
            cout << endl;
        }
        cout <<  "Print operation. Number of operations : " << operationsCount << endl;
    }

    int getSize() 
    {
        operationsCount++;
        return count;
    }
    void logOperations()
    {
        cout << "Number of all operations: " << operationsCount << endl;
    }

};