#include "stdafx.h"
#include "ListOfInt.h"
#include <assert.h>

ListOfInt::ListOfInt()
{
	m_head = NULL;
	m_length = 0;
}

ListOfInt::~ListOfInt()
{
}

void ListOfInt::Add(unsigned int value)
{
	Node* temp = new Node();
	temp->value = value;
	temp->next = NULL;

	if (m_head == NULL)
	{
		m_head = temp;
	}
	else
	{
		Node* current = m_head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = temp;
	}
	m_length++;
}

void ListOfInt::Clear()
{
	while (m_head->next != NULL)
	{
		Node* previous = m_head;
		Node* current = m_head->next;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}
		previous->next = NULL;
		delete current;
		m_length--;
	}	delete m_head;	m_head = NULL;	m_length = 0;
}

unsigned int ListOfInt::GetAtPosition(unsigned int position)
{
	assert(position < m_length);

	Node* current = m_head;
	unsigned int count = 0;
	while (count != position)
	{
		current = current->next;
		count++;
	}

	return current->value;
}

unsigned int ListOfInt::GetLength()
{
	return m_length;
}

void ListOfInt::Remove(unsigned int position)
{
	assert(position < m_length);
	Node* toDelete;
	Node* previous;
	Node* current;
	unsigned int count = 1;

	if (position == 0)
	{
		toDelete = m_head;
		m_head = m_head->next;
	}
	else
	{
		previous = m_head;
		current = m_head->next;
		while (count != position)
		{
			previous = current;
			current = current->next;
			count++;
		}
		if (current->next == NULL)
		{
			toDelete = current;
			previous->next = NULL;
		}
		else
		{
			toDelete = current;
			previous->next = current->next;
		}
	}

	delete toDelete;
	return;
}

void ListOfInt::Sort()
{
	Node* current;
	Node* nextNode;
	Node* prevNode;
	bool swaps = true;

	while (swaps)
	{
		current = m_head;
		nextNode = current->next;
		prevNode = NULL;
		swaps = false;
		while (current->next != NULL)
		{
			if (current->value > nextNode->value)
			{
				if (current == m_head)
				{
					current->next = nextNode->next;
					nextNode->next = current;
					m_head = nextNode;
				}
				else
				{
					prevNode->next = nextNode;
					current->next = nextNode->next;
					nextNode->next = current;
				}
				swaps = true;
			}

			if (current->next != NULL)
			{
				prevNode = current;
				current = current->next;
				nextNode = current->next;
			}
		}
	}
}