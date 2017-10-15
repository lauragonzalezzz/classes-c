#pragma once
#include "Node.h"

class ListOfInt
{
private:
	Node* m_head;
	unsigned int m_length;
public:
	ListOfInt();
	~ListOfInt();
	void Add(unsigned int value);
	void Clear();
	unsigned int GetAtPosition(unsigned int position);
	unsigned int GetLength();
	void Remove(unsigned int position);
	void Sort();
private:
	ListOfInt(ListOfInt const&) = delete; // non construction copyable
	void operator=(ListOfInt const&) = delete; // non copyable
};

