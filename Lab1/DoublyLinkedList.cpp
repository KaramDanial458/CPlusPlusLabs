#include "DoublyLinkedList.hpp"
#include <stddef.h>
#include <iostream>
#include <string>
using namespace std;
DoublyLinkedList::Node::Node(DataType data)
{
	next = NULL;
	prev = NULL;
	value = data;
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
//	tail_ = NULL;
//	Node *visitor = head_;
//	while (visitor->next != NULL)
//	{
//		visitor = visitor -> next;
//		head_ -> next = NULL;
//		delete(head_);
//		head_ = visitor; 
//	}
//	delete(visitor);
//	head_ = NULL;
//	size_ = 0;
		Node *ptr = head_;
		Node *temp;
		while(ptr != NULL)	
		{
			temp = ptr;		
			ptr = ptr -> next;	
			delete temp;		
		}
		head_ = NULL;
		tail_ = NULL;
}

bool DoublyLinkedList::empty() const
{
	if (size_ == 0)
		return true;
	else
		return false;
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

void DoublyLinkedList::print() const
{
	if (size_ == 0)
		return;
	else if (size_ != 0)
	{
		Node *visitor_ = head_;
		for (int i = 0; i < size_; i++)
		{
			cout << visitor_->value;
			visitor_ = visitor_ -> next;
		}
		return;
	}
}

bool DoublyLinkedList::insert_front(DataType value)
{
	if (size_ == 0)
	{
		Node *first = new Node(value);
		head_ = first;
		tail_ = first;
		size_++;
		return true;
	}
	else
	{
		Node *front = new Node(value);
		head_ -> prev = front;
		front -> next = head_;
		head_ = front;
		front -> prev = NULL;
		size_++;
		return true;
	}
}

bool DoublyLinkedList::remove_front()
{
	if (size_ == 0)
		return false;
	else if (size_ == 1)
	{
		head_ = NULL;
		delete(tail_);
		tail_ = NULL;
		size_--;
		return true;
	}
	else
	{
		Node *temp;
		temp = head_;
		head_ = temp -> next; 
		head_ -> prev = NULL;
		delete(temp);
		size_--;
		return true;
	}
}

bool DoublyLinkedList::insert_back(DataType value)
{
	if (size_ == CAPACITY)
		return false;
	else if (size_ == 0)
	{
		Node *first = new Node (value);
		head_ = first;
		tail_ = first;
		size_++;
		return true;
	}
	else
	{
		Node *addLast = new Node (value); 
		addLast -> prev = tail_;
		tail_ -> next = addLast;
		tail_ = addLast;
		size_++;
		return true;
	}
}

bool DoublyLinkedList::remove_back()
{
	if (size_ == 0)
		return false;
	else if (size_ == 1)
	{
		head_ = NULL;
		delete(tail_);
		tail_ = NULL;
		size_--;
		return true;
	}
	else
	{
		Node *temp;
		temp = tail_;
		tail_ = tail_ -> prev;
		tail_ -> next = NULL;
		temp -> prev = NULL;
		temp -> next = NULL;
		delete(temp);
		size_--;
		return true;
	}
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	if (index > size_)
		return false;
	else if (size_ == 0)
	{
		Node *first = new Node (value);
		head_ = first;
		tail_ = first;
		size_++;
		return true;
	}
	else if (index >= 0 && index <= size_)
	{
		Node *input = new Node (value);
		Node *visitor = head_;
		for (int i = 0; i < index; i++)
		{
			visitor = visitor -> next;
		}
		visitor -> next -> prev = input;
		input -> next = visitor -> next;
		input -> prev = visitor;
		visitor -> next = input;
		size_++;
		return true;
	}
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if (size_ == 0)
		return false;
	else if (size_ == 1)
	{
		head_ = NULL;
		delete(tail_);
		tail_ = NULL;
		size_--;
		return true;
	}
	else
	{
		Node *choose;
		choose = head_;
		for (int i = 0; i < index; i++)
		{
			choose = choose -> next;
		}
		choose -> next -> prev = choose -> prev;
		choose -> prev -> next = choose -> next;
		choose -> next = NULL;
		choose -> prev = NULL;
		delete(choose);
		size_--;
		return true;
	}
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	if (head_ != NULL)
	{
		Node *visitor = head_;
		unsigned int index = 0;
		while (visitor -> next != NULL)
		{
			if (visitor -> value == value)
			{
				return index;
			}
			visitor = visitor -> next;
			index ++;		
		}
		return size_;
	}
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	Node *visitor = head_;
	if (size_ == 0)
	{
		return size_;
	}
	else if (size_ < index)
	{
		return tail_->value;
	}
	else
	{	
		for (int i = 0; i < index; i++)
		{
			visitor = visitor -> next;
		}
		return visitor->value;
	}
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if(index > size_)
	{
		return false;
	}
	if(size_ == 0)
	{
		Node *insert = new Node(value);
		tail_ = NULL;
		delete(head_);
		head_ = insert;
		tail_ = insert;
		return true;
	}
	else
	{
		Node *insert = new Node(value);
		insert -> value = value;
		Node *v1 = head_;
		Node *v2;
		Node *v3;
		
		for (int i = 0; i < index; i++)
		{
			v1 = v1 -> next; 
		}
		v2 = v1 -> next -> next;
		v3 = v1 -> next;
		v2 -> prev = insert;
		insert -> next = v2;
		v1 -> next = insert;
		insert -> prev = v1;
		v3 -> next = NULL;
		v3 -> prev = NULL;
		delete(v3);
		return true;
	}
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	if (size_ == 0)
		return NULL;
	else
	{
		Node *visitor;
		visitor = head_;
		for (int i = 0; i < index; i++)
		{
			visitor = visitor -> next;
		}
		return visitor;
	}
}
bool DoublyLinkedList::full() const
{
	if (size_ == CAPACITY)
		return true;
	else
		return false;
}
