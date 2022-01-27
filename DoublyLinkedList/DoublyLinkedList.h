#pragma once
#include "Library.h"

class DoublyLinkedList
{
public:
	struct Node
	{
		int data = 0;
		Node* next = nullptr;
		Node* prev = nullptr;
	};

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int count = 0;

public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& original);
	~DoublyLinkedList();
	int GetCount() const;
	void Clear();
	bool IsEmpty() const;
	int LastIndexOf(int data);
	void Reverse();
	void AddToHead(int data);
	void AddToTail(int data);

private:
	Node* GetNode(int index)
	{
		if (index < 0 || index >= count) {
			return nullptr;
		}
		if (index == 0)
		{
			return head;
		}
		if (index == count - 1)
		{
			return tail;
		}

		Node* temp;
		int i = index;
		if (index <= count / 2) // если элемент находится в левой половине списка, то бежим слева направо
		{
			temp = head->next;
			while (--i)
			{
				temp = temp->next; // перемещаем указатель на следующий элемент
			}
		}
		else
		{
			temp = tail->prev;
			while (++i != count - 1)
			{
				temp = temp->prev;
			}
		}
		return temp;
	}


public:
	void Insert(int data, int index);
	void DeleteFromHead();
	void DeleteFromTail();
	void DeleteByIndex(int position);
	friend ostream& operator << (ostream& os, const DoublyLinkedList& list);
	int GetElementByIndex(int index);	
	DoublyLinkedList MergeWith(const DoublyLinkedList& list);
	void SortAsc();
	void SortDesc();
	void Shuffle();
	bool Equals(const DoublyLinkedList* list) const;
	void Print() const;
	bool operator == (const DoublyLinkedList& list);
	bool operator != (const DoublyLinkedList& list);
	bool operator >= (const DoublyLinkedList& list);
	bool operator <= (const DoublyLinkedList& list);
	bool operator > (const DoublyLinkedList& list);
	bool operator < (const DoublyLinkedList& list);
	DoublyLinkedList& operator = (const DoublyLinkedList& list);
	DoublyLinkedList operator + (const DoublyLinkedList& list);	
};
