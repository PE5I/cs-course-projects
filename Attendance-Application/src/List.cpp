#include "List.h"
#include "ListNode.h"

ListNode * List::createNode(StudentData record) {
	ListNode *new_node = new ListNode;

	new_node->set_date_absence(); // default: 0000-00-00
	new_node->set_absences(); // default: 0
	new_node->set_class_credits(record.class_credits);
	new_node->set_level(record.student_level);
	new_node->set_record_number(record.record_number);
	new_node->set_student_email(record.student_email);
	new_node->set_student_id(record.student_id);
	new_node->set_student_major(record.student_major);
	new_node->set_student_name(record.student_name);

	new_node->set_next(nullptr);

	return new_node;
}

bool List::insertFront(List &master, StudentData record) {
	ListNode *new_data = nullptr;
	new_data = createNode(record);
	bool success = false;

	if(new_data) {
		if(head == nullptr) { // list is empty
			head = new_data;
			head->set_next(nullptr);
			success = true;
		} else {
			ListNode * temp; 
			temp = head;
			head = new_data;
			head->set_next(temp);
			success = true;
		}
	} else {
		success = false;
		cout << "Memory was not allocated for new node\n";
	}

	return success;
}

void List::printList() {
	ListNode *traversal = head;

	while(traversal) {
		cout << traversal->get_record_number()
			<< ","
			<< traversal->get_student_id()
			<< ","
			<< traversal->get_student_name()
			<< ","
			<< traversal->get_student_email()
			<< ","
			<< traversal->get_class_credits()
			<< ","
			<< traversal->get_student_major()
			<< ","
			<< traversal->get_student_level()
			<< endl;

		traversal = traversal->getNext();
	}
}