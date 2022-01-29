#pragma once

namespace univer {
	struct Student {
		int id;
		char _name[20];
		Student(int id, char const* name); 
	};
	struct NodeList {
	private:
		struct Node {
			Student* data;
			Node* next;
			Node(Student* data);
		};
		Node* head = nullptr;
		Node* tail = nullptr;
	public:
		void addFirst(Student& data);
		void addLast(Student* data);
		void insertAfter(Student* data, int id);
		void insertBefore(Student* data, int id);
		void print();
	};

}