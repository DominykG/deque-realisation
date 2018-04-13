#include <iostream>

using namespace std;

//----------------------------------------------------------------

struct node {
	int curData;
	node *nextData;
};

//----------------------------------------------------------------

class My_deque {
private:
	node *head, *tail;

public:
	My_deque() {
		head = NULL;
		tail = NULL;
	}

	bool empty() {
		if (head == NULL && tail == NULL) {
			return true;
		} else {
			return false;
		}
	}

	void display() {
		if (empty() == true) {
			cout << "Deque is empty. Try another option.\n";
		} else {
			node *temp = head;
			while (temp != NULL) {
				cout << temp->curData << "  ";
				temp = temp->nextData;
			}
			cout << endl;
		}
	}

	void insert_first(int value) {
		node *temp = new node;
		temp->curData = value;
		if (head == NULL) {
			temp->nextData = NULL;
			head = temp;
			tail = temp;
		} else {
			temp->nextData = head;
			head = temp;
		}
	}

	void insert_last(int value) {
		node *temp = new node;
		temp->curData = value;
		if (head == NULL) {
			temp->nextData = NULL;
			head = temp;
			tail = temp;
		} else {
			node *current = head;
			node *previous = new node;
			while (current->nextData != NULL) {
				previous = current;
				current = current->nextData;
			}
			temp->curData = value;
			previous->nextData = current;
			current->nextData = temp;
			tail = temp;
		}
	}

	void delete_first() {
		if (empty() == true) {
			cout << "Deque is empty. Try another option.\n";
		} else if (tail == head && head->nextData == NULL) {
			head = NULL;
			tail = NULL;
		} else {
			head = head->nextData;
		}
	}

	void delete_last() {
		if (empty() == true) {
			cout << "Deque is empty. Try another option.\n";
		} else if (tail == head && head->nextData == NULL) {
			head = NULL;
			tail = NULL;
		} else {
			node *current = head;
			node *previous = new node;
			while (current->nextData != NULL) {
				previous = current;
				current = current->nextData;
			}
			tail = previous;
			previous->nextData = NULL;
			delete current;
		}
	}

	void print_first_and_last() {
		if (empty() == true) {
			cout << "Deque is empty. Try another option.\n";
		} else {
			cout << "First element: " << head->curData
				 << "\nLast element: " << tail->curData << endl;
		}
	}
};

//----------------------------------------------------------------

void menu();

int main() {
	My_deque md;
	int num;
	int user_choice;

	while (true) {
		cout << endl;
		menu();
		cout << endl;
		cin >> user_choice;
		cout << endl;

		switch (user_choice) {
		case 0:
			return 0;
		case 1:
			if (md.empty() == true) {
				cout << "Deque is empty\n";
			} else {
				cout << "Deque is not empty\n";
			}
			break;
		case 2:
			cin >> num;
			md.insert_first(num);
			break;
		case 3:
			cin >> num;
			md.insert_last(num);
			break;
		case 4:
			md.delete_first();
			break;
		case 5:
			md.delete_last();
			break;
		case 6:
			md.print_first_and_last();
			break;
		case 7:
			md.display();
			break;
		default:
			cout << "Incorrect input. Try again.\n";
			break;
		}
	}
	return 0;
}

void menu() {
	cout << "1. Check if deque is empty\n";
	cout << "2. Append front element\n";
	cout << "3. Append back element\n";
	cout << "4. Delete front element\n";
	cout << "5. Delete back element\n";
	cout << "6. Print first and last element\n";
	cout << "7. Show content\n";
	cout << "0. Close program\n";
}