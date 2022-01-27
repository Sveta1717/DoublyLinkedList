// DoublyLinkedList.cpp 

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
	{		
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	
	DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& original)
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
		
		Node* temp = original.head;
		
		while (temp != 0)
		{			
			AddToTail(temp->data);
			temp = temp->next;
		}
	}

	DoublyLinkedList::~DoublyLinkedList()
	{
		while (count != 0)
			Clear();
	}

	int DoublyLinkedList::GetCount() const
	{
		return count;
	}

	void DoublyLinkedList::Clear()
	{
		while (head != nullptr)
		{
			DeleteFromHead();
		}
	}

	bool DoublyLinkedList::IsEmpty() const
	{
		return count == 0;
	}

	int DoublyLinkedList::LastIndexOf(int data)
	{
		if (IsEmpty())
		{
			return -1;
		}
		Node* temp = head;
		int i = count;
		while (i > 0)
		{
			if (data == temp->data)
			{
				return i;
			}
			i--;
			temp = temp->next;
		}			
		return -1;
	}

	void DoublyLinkedList::Reverse()
	{			
		Node* current = head;
		Node* next;
		Node* prev = nullptr;
		while (current != 0)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}	
		head = prev;
	}

	void DoublyLinkedList::AddToHead(int data)
	{
		Node* temp = new Node();
		temp->data = data;
		temp->next = head;
		if (IsEmpty())
		{
			tail = temp;
		}
		else
		{
			head->prev = temp;
		}
		head = temp;
		count++;
	}

	void DoublyLinkedList::AddToTail(int data)
	{
		Node* temp = new Node();
		temp->data = data;
		temp->prev = tail;
		if (IsEmpty())
		{
			head = temp;
		}
		else
		{
			tail->next = temp;
		}
		tail = temp;
		count++;
	}

	void  DoublyLinkedList::Insert(int data, int index)
	{
		if (index <= 0)
		{
			AddToHead(data);
			return;
		}
		if (index >= count)
		{
			AddToTail(data);
			return;
		}

		Node* elem = GetNode(index);

		Node* temp = new Node();

		temp->data = data;

		temp->next = elem;
		temp->prev = elem->prev;

		temp->prev->next = temp;
		temp->next->prev = temp;

		count++;
	}

	void  DoublyLinkedList::DeleteFromHead()
	{
		if (IsEmpty())
		{
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
		if (head == nullptr)
		{
			tail = nullptr;
		}
		else
		{
			head->prev = nullptr;
		}
		count--;
	}

	void  DoublyLinkedList::DeleteFromTail()
	{
		if (IsEmpty())
		{
			return;
		}
		Node* temp = tail;
		tail = tail->prev;
		delete temp;
		if (tail == nullptr)
		{
			head = nullptr;
		}
		else
		{
			tail->next = nullptr;
		}
		count--;
	}

	void  DoublyLinkedList::DeleteByIndex(int position)
	{
		if (position == 0)
		{
			DeleteFromHead();
			return;
		}
		if (position == count - 1)
		{
			DeleteFromTail();
			return;
		}
		Node* del = GetNode(position);
		del->prev->next = del->next;
		del->next->prev = del->prev;
		delete del;
		count--;
	}

	ostream& operator << (ostream& os, const DoublyLinkedList& list)
	{
		if (list.count == 0)
		{
			os << "List is empty!";
		}
		else
		{
			DoublyLinkedList::Node* temp = list.head;
			while (temp != nullptr)
			{
				os << temp->data << " ";
				temp = temp->next;
			}
			return os;
		}
	}

	int  DoublyLinkedList::GetElementByIndex(int index)
	{
		if (index < 0 || index >= count)
			throw "Incorrect index";

		Node* temp = head;

		int i = 0;
		while (i < index)
		{
			temp = temp->next;
			i++;
		}

		return temp->data;
	}

	DoublyLinkedList  DoublyLinkedList::MergeWith(const DoublyLinkedList& list)
	{		
		DoublyLinkedList current = *this;

		Node* temp = list.head;

		while (temp != 0)
		{
			current.AddToTail(temp->data);
			temp = temp->next;
		}	
		return current;
	}

	void  DoublyLinkedList::SortAsc()
	{
		Node* current = head;
		int* arr = new int[count];

		for (int i = 0; i < count; i++) {
			arr[i] = current->data;
			current = current->next;
		}
		int tmp = 0;
		for (int i = 0; i < count; i++)
		{
			for (int j = (count - 1); j >= (i + 1); j--)
			{
				if (arr[j] < arr[j - 1])
				{
					tmp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tmp;
				}
			}
		}
		current = head;
		for (int i = 0; i < count; i++)
		{
			current->data = arr[i];
			current = current->next;
		}
		delete[] arr;
	}

	void  DoublyLinkedList::SortDesc()
	{		
		Node* current = head;
		int* arr = new int[count];

		for (int i = 0; i < count; i++) {
			arr[i] = current->data;
			current = current->next;
		}
		int tmp = 0;
		for (int i = 0; i < count; i++)
		{
			for (int j = (count - 1); j >= (i + 1); j--)
			{
				if (arr[j] > arr[j - 1])
				{
					tmp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tmp;
				}
			}
		}
		current = head;
		for (int i = 0; i < count; i++)
		{
			current->data = arr[i];
			current = current->next;
		}
		delete[] arr;
	}

	void  DoublyLinkedList::Shuffle()
	{
		Node* current = head;
		int* arr = new int[count];


		for (int i = 0; i < count; i++) {
			arr[i] = current->data;
			current = current->next;
		}
		random_shuffle(arr, arr + count);
		current = head;
		for (int i = 0; i < count; i++)
		{
			current->data = arr[i];
			current = current->next;
		}
		delete[] arr;
	}

	bool  DoublyLinkedList::Equals(const DoublyLinkedList* list) const
	{
		Node* temp = head;
		Node* temp_list = list->head;
		int i = 0;

		if (count == list->count)
		{
			while (i < count)
			{
				if ((temp->data != temp_list->data))
				{
					return false;
				}
				temp = temp->next;
				temp_list = temp_list->next;
				i++;
			}
		}
		else if (count != list->count)
		{
			return false;
		}

		return true;
	}	

	void  DoublyLinkedList::Print() const
	{			
		if (count == 0)
		{
			cout << "Empty list!\n";
		}
		Node* current = head;		
		while (current->next != 0)
		{
			cout << current->data << ", ";
			current = current->next;
		}
		cout << current->data << " \n";		
	}

	bool DoublyLinkedList::operator == (const DoublyLinkedList& list)
	{		
		if (count != list.count)
			return false;
		Node* temp = head;
		Node* temp_list = list.head;
		
		while (temp != 0)
		{			
			if (temp->data != temp_list->data)
				return false;
			temp = temp->next;
			temp_list = temp_list->next;
		}
		return true;
	}

	bool  DoublyLinkedList::operator != (const DoublyLinkedList& list)
	{		
		return !(*this == list);
	}

	bool  DoublyLinkedList::operator >= (const DoublyLinkedList& list)
	{		
		if (count > list.count)
			return true;
		
			if (*this == list)
				return true;
		return false;
	}

	bool  DoublyLinkedList::operator <= (const DoublyLinkedList& list)
	{	
		if (count < list.count)
			return true;
		
		if (*this == list)
			return true;
		return false;
	}

	bool  DoublyLinkedList::operator > (const DoublyLinkedList& list)
	{
		if (count > list.count)
			return true;
		return false;
	}

	bool  DoublyLinkedList::operator < (const DoublyLinkedList& list)
	{
		if (count < list.count)
			return true;
		return false;
	}		

	DoublyLinkedList& DoublyLinkedList::operator = (const DoublyLinkedList& list)
	{		
		if (this == &list)
			return *this;		
		this->~DoublyLinkedList(); 

		Node* temp = list.head;		
		while (temp != 0)
		{
			AddToTail(temp->data);
			temp = temp->next;
		}
		return *this;
	}

	DoublyLinkedList  DoublyLinkedList::operator + (const DoublyLinkedList& list)
	{		
		DoublyLinkedList current = *this;
		
		Node* temp = list.head;
		
		while (temp != 0)
		{
			current.AddToTail(temp->data);
			temp = temp->next;
		}	
			return current;
	}

