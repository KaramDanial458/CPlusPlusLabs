#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"
using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	size_ = 0;
	head_ = 0;
	tail_ = 0;
	capacity_ = 16;
	items_ = new QueueItem [16];
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	size_ = 0;
	head_ = 0;
	tail_ = 0;
	capacity_ = capacity;
	items_ = new QueueItem [capacity];
}

CircularQueue::~CircularQueue()
{
	if (items_ != NULL)
		delete(items_);
}

bool CircularQueue::empty() const
{    
	if (size_ == 0)
		return true;
	else 
		return false;
}

bool CircularQueue::full() const
{
	if (size_ == capacity_)
		return true;
	else
		return false;
}

int CircularQueue::size() const
{  
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
	if (size_ == capacity_)
		return false;
	else if (size_ == 0)
	{
		head_ = 0;
		items_[head_] = value;
		tail_ = 1;
		size_++;
		return true;
	}
	else
	{
		items_[tail_] = value;
		tail_ = (tail_+1)%capacity_;
		size_++;
		return true;
	}
}

QueueItem CircularQueue::dequeue()
{
	if (size_ == 0)
		return EMPTY_QUEUE;
	else if (size_ == 1)
	{
		int x = items_[head_];
		items_[head_] = 0;
		head_ = tail_;
		size_--;
		return x;
	}
	else
	{
		int x = items_[head_];
		items_[head_] = 0;
		head_ = (head_+1)%capacity_;
		size_--;
		return x;
	}
}

QueueItem CircularQueue::peek() const
{
	if (size_ == 0)
		return EMPTY_QUEUE;
	else
		return items_[head_];
}

void CircularQueue::print() const
{
	if (size_ > 0)
	{
		for (int i = 0; i < size_; i++)
		{
			cout << items_[i];
		}
	}
}
