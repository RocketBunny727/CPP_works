#include "header.h"
#include <fstream>

int main() {

	fibheap* heapOne = create_heap();
	fibheap* heapTwo = create_heap();

	ifstream fileOne("dataOne.txt");
	ifstream fileTwo("dataTwo.txt");

	if (!fileOne.is_open() || !fileTwo.is_open()) {
		cout << "Error opening file" << endl;
		return 1;
	}

	int key;
	char value[50];

	while (!fileOne.eof()) {
		fileOne >> key >> value;
		fib_insert(heapOne, key, value);
	}
	fileOne.close();

	while (!fileTwo.eof()) {
		fileTwo >> key >> value;
		fib_insert(heapTwo, key, value);
	}
	fileTwo.close();

	fibheap* unity = fib_union(heapOne, heapTwo);
	Node* node;

	int menuSelect = 0;
	while (menuSelect != 5) {
		cout << "[1] Minimum key Unity Heap" << endl;
		cout << "[2] Remove min-key from unity heap" << endl;
		cout << "[3] Add key-value to unity heap" << endl;
		cout << "[4] Decrease" << endl;
		cout << "[5] Exit" << endl;
		cout << endl;

		cout << "$UserInput---> ";
		cin >> menuSelect;
		cout << endl;

		switch (menuSelect) {
		case 1:
			cout << "[Min-key] " << fib_min(unity)->key << endl;
			cout << endl;
			break;
		case 2:
			unity = fib_delete_min(unity);
			cout << "[Delete min-key] ---> ok !" << endl;
			cout << "[Default key unity heap] " << fib_min(unity)->key << endl;
			cout << endl;
			break;
		case 3:
			cout << "[Key] ";
			cin >> key;
			cout << "[Value] ";
			cin >> value;
			node = fib_insert(unity, key, value);
			cout << "[Unity heap key after add] " << fib_min(unity)->key << endl;
			cout << endl;
			break;
		case 4:
			cout << "[Search node]" << endl;

			cout << "[Key] ";
			cin >> key;

			node = heap_lookup(unity->min, key);

			// не вводить число для нового значения узла больше текущего
			// пример: 10 > 7 => узел не поменяется, ошибка
			int newkey;
			cout << "[NewKey] ";
			cin >> newkey;
			
			if (node != NULL) {
				unity = fib_decrease_key(unity, node, newkey);
				cout << "[Unity heap Decrease key] " << fib_min(unity)->key << endl;
			}
			else {
				cout << "[Key was not found in the heap]" << endl;
			}
			cout << endl;

			break;
		case 5:
			cout << "( Goodbye !)" << endl;
			cout << endl;
			break;

		default:
			break;
		}
	}

	delete(unity);

	return 0;
}