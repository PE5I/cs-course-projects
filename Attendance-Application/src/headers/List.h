#pragma once

#include "pa7.h"
#include "ListNode.h"

class List {
private:
	ListNode *head;
	void recursive_destruct(ListNode *temp) {
		if(temp->getNext()) {
			recursive_destruct(temp->getNext());
			delete temp;
		}
		head = nullptr;
	} 
public:
	// constructor
	List() {
		head = nullptr;
	}

	~List() {
		//list_destruct();
		//	head = nullptr;
		//cout << "destructor called!\n";
	}

	void list_destruct() {
		recursive_destruct(head);	
	}

	// getters
	ListNode * getHead() { return head; }

	// setters
	void set_head(ListNode *new_head) {
		head = new_head;
	}

	ListNode * createNode(StudentData record);
	bool insertFront(List &master, StudentData record);

	void printList();
};
