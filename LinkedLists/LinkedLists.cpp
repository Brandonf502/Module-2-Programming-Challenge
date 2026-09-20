#include "LinkedList.h"
#include <vector>
#include <algorithm>

//This page includes definitions of all methods available for LinkedList()
template <typename T> LinkedList<T>::LinkedList() {}

// Destructor method. Start at head, save next pointer, delete current pointer. if finished quit.
template <typename T> LinkedList<T>::~LinkedList() {
	listNode<T>* currentNode = head;
	listNode<T>* nextNode = nullptr;
	bool finished = currentNode == nullptr;

	while (!finished) {
		nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
		if (nextNode == nullptr) {
			finished = true;
		}
	}
}

//Add Nodes, if no head or tail exist this node becomes head and tail(handle list size = 0)
//else append newNode to end of list. Update counter once for every completed loop.
template <typename T> void LinkedList<T>::addNode(T item) {
	listNode<T>* newNode = new listNode<T>;
	newNode->data = item;

	if (!head && !tail) {
		head = newNode;
		tail = newNode;
	}

	else if (head) {
		tail->next = newNode;
		tail = newNode;
	}
	listCount += 1;
}

//Method to find a Node if it exists return true. Otherwisef return false
template <typename T> bool LinkedList<T>::findNode(T item) const {
	listNode<T>* currentNode = head;
	while (currentNode) {
		if (currentNode->data == item) {
			return true;
		}

		else {
			currentNode = currentNode->next;
		}
	}
	return false;
}

//Remove Node. 
template <typename T> void LinkedList<T>::removeNode(T item) {
	listNode<T>* removeThis = nullptr;
	listNode<T>* lastNode = nullptr;
	listNode<T>* currentNode = head;
	
	
	//raise flags to check later after loops
	bool isHead = false;
	bool isTail = false;

	//As long as removeThis pointer is null AND currentNode is not null(meaning the list is not ran out)....
	while (!removeThis && currentNode) {
		//until the data in currentNode equals the number desired to remove. Check whether it is the head or tail.
		if (currentNode->data == item) {
			removeThis = currentNode;
			isHead = (removeThis == head);
			isTail = (removeThis == tail);
		}
		//otherwise move to the next node.
		else if (currentNode->data != item) {
			lastNode = currentNode;
			currentNode = currentNode->next;
		}
	}


	//check desired number was available to remove
	if (!removeThis) {
		return;
	}

	//Special case to Remove the Head.
	if (removeThis && isHead) {
		head = removeThis->next;
		if (head == nullptr) {
			tail = nullptr;
		}
	}
	//Specail case to remove the Tail.
	else if (removeThis && isTail) {
		lastNode->next = nullptr;
		tail = lastNode;
	}
	//Special case to remove anything in between.
	else {
		lastNode->next = removeThis->next;
	}

	listCount -= 1;
	delete removeThis;
}

//Return List Size
template <typename T> int LinkedList<T>::getSize() const {
	return listCount;
}

//Show the list
template <typename U>std::ostream& operator<<(std::ostream& out, const LinkedList<U>& list) {
	int nodeData;
	int count = 0;
	listNode<U>* node = list.head;
	while (count < list.listCount) {
		nodeData = node->data;
		out << nodeData;

		if (node->next) {
			out << ", ";
		}

		node = node->next;
		count += 1;
	}
	return out;
}


//Instantiate each method as int.
template LinkedList<int>::LinkedList();
template LinkedList<int>::~LinkedList();
template void LinkedList<int>::addNode(int);
template void LinkedList<int>::removeNode(int);
template bool LinkedList<int>::findNode(int) const;
template int LinkedList<int>::getSize()  const;
template std::ostream& operator<<(std::ostream&, const LinkedList<int>&);
