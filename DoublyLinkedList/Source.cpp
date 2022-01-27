#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main()
{
	srand(time(0));

	//Односвязный список
	/////////////////////

	//SinglyLinkedList sll;
	//SinglyLinkedList sll_1;
	//cout << "count = 0?  " << sll.IsEmpty() << "\n";

	//// вставка в конец списка
	//sll.AddToTail(10);
	//sll.Print();
	//cout << "count = 0?  " << sll.IsEmpty() << "\n";
	//sll.AddToTail(20);
	//sll.AddToTail(30);
	//sll.AddToTail(40);
	//sll.AddToTail(20);
	//sll.Print();
	//cout << "Element 3? " << sll.operator[](3) << "\n";
	//sll.operator=(sll_1);
	//sll.Print();

	//cout << "Last index of 15?: " << sll.LastIndexOf(15) << "\n";
	//cout << "Last index of 20?: " << sll.LastIndexOf(20) << "\n";
	//cout << "Contains 30?: " << sll.Contains(30) << "\n";
	//cout << "Contains 15?: " << sll.Contains(15) << "\n";
	//sll.SortAsc();
	//cout << "Ascending sort: " << sll << "\n";

	//// вставка в начало списка
	//sll.AddToHead(50);
	//sll.AddToHead(60);
	//sll.AddToHead(70);
	//sll.AddToHead(80);
	//sll.Print();

	//cout << "Revers:\n";
	//sll.Reverse();
	//sll.Print();
	//sll.SortDesc();
	//cout << "Descending sort: " << sll << "\n";

	//// перемешать
	//cout << "Shuffle:\n";
	//sll.Shuffle();
	//sll.Print();

	//cout << "List 2 \n";
	//sll_1.AddToHead(15);
	//sll_1.AddToHead(35);
	//sll_1.AddToHead(45);
	//sll_1.AddToHead(5);
	//sll_1.Print();
	//cout << "Equals 1 and 2: " << sll.Equals(&sll_1) << "\n";
	//cout << "Clone 2:\n";
	//sll_1.Clone();
	//sll_1.Print();
	//cout << "Clone 1:\n";
	//sll.ToArray();
	//sll.Print();
	//cout << "Merge 1 with 2:\n";
	//sll.MergeWith(sll_1);
	//sll.Print();
	//sll.operator+(sll_1);
	//sll.Print();
	//// количество элементов, поиск элементов
	//cout << "count: " << sll.GetCount() << "\n";
	//cout << "index of 70: " << sll.IndexOf(70) << ", index of 90: " << sll.IndexOf(90) << "\n";

	//// операторы
	//cout << "< " << sll.operator<(sll_1) << "\n";
	//cout << "> " << sll.operator>(sll_1) << "\n";
	//cout << "<= " << sll.operator<=(sll_1) << "\n";
	//cout << ">= " << sll.operator>=(sll_1) << "\n";
	//cout << "== " << sll.operator==(sll_1) << "\n";
	//cout << "!= " << sll.operator!=(sll_1) << "\n";
	//cout << sll.operator int* () << "\n";

	///*int* arr = (int*)sll;
	//int length = sll.GetCount();
	//for (size_t i = 0; i < length; i++)
	//{
	//	cout << arr[i] << ",";
	//}
	//delete[] arr;*/

	//// вставка по позиции
	//sll.InsertInto(-1, -1);
	//sll.Print();
	//sll.InsertInto(2, 2);
	//sll.Print();
	//sll.InsertInto(22, 22);
	//sll.Print();

	//// замена значения
	//sll.SetAt(0, 55);
	//sll.Print();

	//// удаление с начала списка
	//sll.DeleteFromHead();
	//sll.DeleteFromHead();
	//sll.DeleteFromHead();
	//sll.Print();

	//// удаление с конца списка
	//sll.DeleteFromTail();
	//sll.DeleteFromTail();
	//sll.DeleteFromTail();
	//sll.Print();

	//// удаление по указанному индексу
	//sll.DeleteByIndex(0);
	//sll.DeleteByIndex(1);
	//sll.DeleteByIndex(2);
	//sll.Print();

	//// очистка списка
	//sll.Clear();
	//sll.Print();

//Двусвязный список
///////////////////

DoublyLinkedList dll;
DoublyLinkedList dll_1;

dll.AddToHead(10);
dll.AddToHead(15);
dll.AddToHead(12);
dll.AddToHead(9);
cout << dll;
cout << "\ncount = 0? " << dll.IsEmpty() << "\n";
cout << "Last index of 10: " << dll.LastIndexOf(10) << "\n";
cout << "Revers: \n";
dll.Reverse();
cout << dll << "\n";

dll_1.AddToTail(5);
dll_1.AddToTail(2);
dll_1.AddToTail(1);
cout << dll_1;
cout << "\nMerge 1 with 2: \n";
cout << dll.MergeWith(dll_1) << "\n";
cout << dll.operator+(dll_1) << "\n";
dll.SortAsc();
cout << "Ascending sort: " << dll << "\n";
dll.SortDesc();
cout << "Descending sort: " << dll << "\n";
dll.Shuffle();
cout << "Shuffle: " << dll << "\n";
cout << "Equals 1 and 2: " << dll.Equals(&dll_1) << "\n";
}