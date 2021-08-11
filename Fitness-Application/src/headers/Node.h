#pragma once

#include "pa5.h"
#include "DietPlans.h"


class ListNode
{
//	private:
		ListNode *next;
		DietPlan data;
	public:
//		DietPlan data;
//		ListNode *next;
		ListNode(); // constructor
//		void createNode(DietPlan input_data);
//		void display();
};

class List
{
	private:
		ListNode *head, *tail;
	public:
		// constructor-slash-instantiator
		List() { head=NULL; tail=NULL; }

		void createNode(DietPlan input_data);
		void display();
};
