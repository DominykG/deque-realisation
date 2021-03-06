#include <iostream>

using namespace std;

//----------------------------------------------------------------

struct node {// mazgo struktura
	int curData;// strukturos reiksme
	node *nextData;// nuoroda i sekanti elementa
};

//----------------------------------------------------------------

class My_deque {
private:
	node *head, *tail; // rodykles i pirma ir paskutini deko elementus

public:
	My_deque() {
		head = NULL;
		tail = NULL;
	}

	~My_deque() {
	}

	bool empty() {
		if (head == NULL && tail == NULL) {
			return true;
		} else {
			return false;
		}
	}

	void display() {
		if (empty() == true) { // patikrinimas ar dekas tuscias
			cout << "Deque is currently empty.\n";
		} else {
			node *temp = head; // sukuriama laikina rodykle rodanti i pirma elementa
			cout << "----------CONTENT----------\n";
			while (temp != NULL) {
			  // ciklas kartojamas iki tol kol laikina rodykle rodo ne i NULL
				cout << temp->curData << "  ";
				temp = temp->nextData; // rodykle perkeliama i sekanti elementa
			}
			cout << "\n---------------------------\n";
		}
	}

	void insert_first(int value) {
		node *temp = new node; // sukuriama nauja laikina rodykle
		temp->curData = value; // strukturos reiksmei priliginamas ivestas elementas
		if (head == NULL) {
			temp->nextData = NULL;
			head = temp; // jeigu pirmo elemento neegzistuoja => paskutinio neegzistuoja
			tail = temp; // sukuriamas pirmo ir paskutinio elemento rodykles
		} else {
			temp->nextData = head; // sukuriama rodykle pries pirma elementa
			head = temp; // pirmas elementas perkeliamas i laikinos rodykles vieta
		}
		display();
	}

	void insert_last(int value) {
		node *temp = new node; // sukuriama nauja laikina rodykle
		temp->curData = value; // strukturos reiksmei priliginamas ivestas elementas
		if (head == NULL) {
			temp->nextData = NULL;
			head = temp; // jeigu pirmo elemento neegzistuoja => paskutinio neegzistuoja
			tail = temp; // sukuriamas pirmo ir paskutinio elemento rodykles
		} else {
			node *current = head; // sukuriama nauja rodykle rodanti i ziurima elementa
			while (current->nextData != NULL) {
			  // ciklas kartojamas kol sekancio po rodykles elemento reiksme ne NULL
				current = current->nextData; // rodykle perkialiama i sekanti elementa
			}
			current->nextData = temp; // po paskutinio elemento sukuriamas naujas
			tail = temp; // paskutinio elemento rodykle perkialiama toliau
		}
		display();
	}

	void delete_first() {
		if (empty() == true) { // patikrinimas ar dekas tuscias
			cout << "Deque is currently empty.\n";
		} else if (tail == head && head->nextData == NULL) {
		  // patikrinama ar pirmo ir paskutinio elemento rodykles rodo i ta pati elementa
			head = NULL;
			tail = NULL;
		} else {
		  node *temp = head; // sukuriama nauja laikina rodykle rodanti i pirma elementa
			head = head->nextData; // pirmo elemento rodykle perkialiama i antra elementa
			delete temp; // naikinama laikina rodykle
			display();
		}
	}

	void delete_last() {
		if (empty() == true) { // patikrinimas ar dekas tuscias
			cout << "Deque is currently empty.\n";
		} else if (tail == head && head->nextData == NULL) {
		  // patikrinama ar pirmo ir paskutinio elemento rodykles rodo i ta pati elementa
			head = NULL;
			tail = NULL;
		} else {
			node *current = head; // sukuriama nauja rodykle rodanti i ziurima elementa
			node *previous = new node;  // sukuriama nauja rodykle rodanti i pries tai einanti elementa
			while (current->nextData != NULL) {
			  // ciklas kartojamas kol sekancio po rodykles elemento reiksme ne NULL
				previous = current; // praejusio elemento rodykle perkialiama elementu toliau
				current = current->nextData; // ziurimo elemento rodykle perkialiama elementu toliau
			}
			tail = previous; // paskutinio elemento rodykle perkialiama i pries einanti elementa
			previous->nextData = NULL;
			delete current;
			display();
		}
	}

	void print_first_and_last() {
		if (empty() == true) {
			cout << "Deque is currently empty.\n";
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
		// case 7:
		// md.display();
		// break;
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
	cout << "3. Append last element\n";
	cout << "4. Delete front element\n";
	cout << "5. Delete last element\n";
	cout << "6. Print first and last element\n";
	// cout << "7. Show content\n";
	cout << "0. Close program\n";
}
