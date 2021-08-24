// .cpp files contain code definitions for methods that have been declared
// in the according .hpp file. The skeleton has been set up here for you.
// That is, the methods have been initiated, and your mission, should you 
// choose to accept it (which you should for marks), is to fill in each method
// with the appropriate code.
//
// A note about the "::" syntax: generally, this means "the thing on the right
// belongs to the thing on the left." So, SequentialList::empty() means the method
// empty() belongs to the class SequentialList. This allows empty() to access (and
// potentially change) the member variables in class SequentialList.
#include <iostream>
#include <string>
#include <math.h>
#include <stddef.h>
#include "SequentialList.hpp"
using namespace std;
// This is the constructor.
SequentialList::SequentialList(unsigned int cap)
{
	size_= 0;
	capacity_= cap;
	data_ = new DataType [cap];
}

SequentialList::~SequentialList()
{
	if (data_ != NULL)
		delete (data_);
}

bool SequentialList::empty() const
{ 
	if (size_== 0)
	{
		return true;
	}
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::full() const
{
	if (size_ == capacity_)
	{
		return true;
	}
	else
		return false;
}

void SequentialList::print() const
{
	for (int i = 0; i < capacity_; i++)
	{
		cout << data_[i] << endl;
	}
}

// NOTE on inserts: do NOT grow the array if we reach capacity. Simply return false.
bool SequentialList::insert_front(DataType val)
{
	if (data_ == NULL)
	{
		data_[0] = val;
		return true;
	}
	else if (size_ == capacity_)
		return false;
	else
	{
		for (int i = size_ - 1; i >= 0; i--)
		{
			data_[i+1] = data_[i];
		}
		data_[0] = val;
		size_++;
		return true;
	}
}

bool SequentialList::remove_front()
{
	if (data_ == NULL)
		return false;
	else
	{
		data_[0] = 0;
		size_--;
		return true;
	}
}

bool SequentialList::insert_back(DataType val)
{
	if (data_ == NULL)
		data_[0] = val;
	else if (size_ == capacity_)
		return false;
	else
	{
		data_[size_] = val;
		size_++;
		return true;
	}
}

bool SequentialList::remove_back()
{
	if(size_ != 0)
	{
		data_[size_-1] = 0;
		size_--;
		return true;
	}
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if (size_ == capacity_ || index > capacity_)
		return false;
	else if (data_[index] == 0)
	{	
		data_[index] = val;
		return true;
	}
	if (data_[index] != 0)
	{
		DataType *temp = data_;
		data_ = new DataType [capacity_*2];
		for (int i = 0; i < index-1; i++)
		{
			data_[i] = temp[i];
		}
		data_[index] = val;
		for (int j = index+1; j < size_; j++)
		{
			data_[j] = temp[j]; 	
		}		
		delete(temp);
		return true;	
	}
}

bool SequentialList::remove(unsigned int index)
{
	if (data_[index] = 0)
		return false;
	else
	{
		data_[index] = 0;
		return true;
	}
}

unsigned int SequentialList::search(DataType val) const
{
	for (int i = 0; i < size_; i++)
	{
		if (data_[i] == val)
		{
			return i;
		}
	}
	return size_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if ( index >= size_ )
		return size_;
	else
		return data_[index];
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	data_[index] = val;
	return true;
}
