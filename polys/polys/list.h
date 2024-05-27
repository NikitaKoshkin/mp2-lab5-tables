#pragma once
#include<iostream>
#include<vector>


using namespace std;



template <class T>
struct Node
{

	T data;
	Node* prev;
	Node* next;

	Node() : next(nullptr) {}
	Node(T data) : data(data)
	{

		prev = nullptr;
		next = nullptr;
	}
};

template <class T>
class List
{
	Node<T>* head;
	Node<T>* tail;

public:

	List()
	{
		head = nullptr;
		tail = nullptr;
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}


	Node<T>* GetHead() const
	{
		return head;
	}
	Node<T>* GetTail() const
	{
		return tail;
	}
	void push_back(T data)
	{
		Node<T>* ptr = new Node<T>(data);
		ptr->data = data;

		if (head == nullptr)
		{
			head = ptr;
			tail = head;
		}
		else
		{
			tail->next = ptr;
			ptr->prev = tail;
			tail = ptr;
		}
	}

	void print_list() const
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	void clear()
	{
		while (head != nullptr)
		{
			Node<T>* next = head->next;
			delete head;
			head = next;
		}
		tail = nullptr;
	}

	void sort()
	{
		Node<T>* elem1 = head;
		if (elem1 != nullptr)
		{
			while (elem1->next != nullptr)
			{
				Node<T>* elem2 = elem1->next;
				while (elem2 != nullptr)
				{
					if (elem1->data < elem2->data)
					{
						T tmp = elem1->data;
						elem1->data = elem2->data;
						elem2->data = tmp;
					}
					elem2 = elem2->next;
				}
				elem1 = elem1->next;
			}
		}

	}

	void pop_list(Node<T>* node)
	{
		if (node == head)
		{
			head = node->next;
			if (head == nullptr)
			{
				tail = nullptr;
			}
			else
			{
				head->prev = nullptr;
			}
		}
		else if (node == tail)
		{
			tail = node->prev;
			tail->next = nullptr;
		}
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		delete node;
	}
};
