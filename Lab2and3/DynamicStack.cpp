#include "DynamicStack.hpp"
#include <iostream>
#include <math.h>
using namespace std;
typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	size_ = 0;
	capacity_ = 16;
	init_capacity_ = 16;
	items_ = new StackItem [16];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	size_ = 0;
	capacity_ = capacity;
	init_capacity_ = capacity;
	items_ = new StackItem [capacity];
}

DynamicStack::~DynamicStack()
{
	if (size_ != 0)
		delete (items_);
}

bool DynamicStack::empty() const
{
	if (size_ == 0)
		return true;
	else
		return false;
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if (size_ == capacity_)
	{
		capacity_ = (capacity_*2);
		StackItem *temp = new StackItem[capacity_];
		for (int i = 0; i < size_; i++)
		{
			temp[i] = items_[i];
		}
		delete(items_);
		items_ = temp;
		temp = NULL;
		items_[size_] = value;
		size_++;
	}
	else if (size_ == 0)
	{
		items_[0] = value;
		size_++;
	}
	else
	{
		items_[size_] = value;
		size_++;
	}
}

StackItem DynamicStack::pop()
{
	if (size_ == 0)
		return EMPTY_STACK;
//	else if (size_ == 1)
//	{
//		StackItem x = items_[0];
//		items_[0] = 0;
//		size_--;
//		return x;
//	}
	else 
	{
		StackItem x = items_[size_-1];
		items_[size_-1] = 0;
		size_--;
		if (size_ <= (capacity_/4) && init_capacity_ <= capacity_/2)
		{
			capacity_ = capacity_/2;
			StackItem *temp = new StackItem [capacity_];
			for (int i = 0; i < size_; i++)
			{
				temp[i] = items_[i];
			}
			delete(items_);
			items_ = temp;
			temp = NULL;
		}
		return x;
	}
}

StackItem DynamicStack::peek() const
{
	if (size_ == 0)
		return EMPTY_STACK;
	else
	{
		StackItem x = items_[size_-1];
		return x;
	}
}

void DynamicStack::print() const
{
	if (size_ >= 0)
	{
		for(int i = 0; i < size_; i++)
		{
			cout << items_[i];
		}
	}
}
