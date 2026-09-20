#pragma once
#include "ListNode.h"
#include <ostream>


template <typename T> class LinkedList {
private:
	listNode<T>* head = nullptr;
	listNode<T>* tail = nullptr;
	int listCount = 0;
public:
	LinkedList();
	void addNode(T item);
	void removeNode(T item);
	bool findNode(T item) const;
	int getSize() const;
	~LinkedList();
	template <typename U>
	friend std::ostream& operator<<(std::ostream& out, const LinkedList<U>& list);
};


