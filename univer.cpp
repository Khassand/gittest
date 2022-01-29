#include "stdafx.h"
#include "univer.h"
#include <string>
#include <iostream>
univer::Student::Student(int id, char const* name) {
	this->id = id;
	strcpy_s(_name, name);
}
void univer::NodeList::addFirst(Student& data) {
	Node* node = new Node(&data);
	if (head == nullptr) { head = node; tail = node; }
	else {
		node->next = head;
		head = node;
	}
}

void univer::NodeList::addLast(Student* data) {
	Node* node = new Node(data);
	if (head == nullptr) { head = node; tail = node; }
	else {
		/*Node* iter = head;
		while (iter->next != nullptr) {
			iter = iter->next;
		}
		iter->next = node;*/
		tail->next = node;
		tail = node;
	}
}

void univer::NodeList::insertAfter(Student * data, int id)
{
	Node* node = new Node(data);
	if (head == nullptr) { head = node; tail = node; }
	else {
		Node* iter = head;
		while (iter != nullptr) {
			if (iter->data->id == id)
			{
				node->next = iter->next;
				iter->next = node;
				return;
			}
			iter = iter->next;
		}
	}
}

void univer::NodeList::insertBefore(Student * data, int id)
{
	Node* node = new Node(data);
	if (head == nullptr) { head = node; tail = node; }
	else {
		Node* iter = head;
		Node* prev = nullptr;
		while (iter != nullptr) {
			if (iter->data->id == id)
			{
				node->next = iter;
				prev->next = node;
				return;
			}
			prev = iter;
			iter = iter->next;
		}
	}
}

void univer::NodeList::print()
{
	Node* iter = head;
	while (iter != nullptr) {
		std::cout << iter->data->id << std::endl;
		std::cout << iter->data->_name << std::endl;
		iter = iter->next;
	}
}

univer::NodeList::Node::Node(Student* data)
{
	this->data = data;
}
