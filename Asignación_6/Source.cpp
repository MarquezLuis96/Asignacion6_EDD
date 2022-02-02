#include <iostream>
#include <cstdlib>


using namespace std;

template <class dataType>
struct Node {
	private:
		Node* previous;
		Node* next;
		dataType key;
	public:
		Node() {
			previous = next = NULL;
		}

		void setKey(dataType newKey) {
			key = newKey;
		}

		dataType getKey() {
			return key;
		}

		void setPrevious(Node<dataType>* previousNode) {
			previous = previousNode;
		}

		Node<dataType>* getPrevious() {
			return previous;
		}

		void setNext(Node<dataType>* nextNode) {
			next = nextNode;
		}

		Node<dataType>* getNext() {
			return next;
		}
};

template <class dataType>
class DoubleLinkedList {
	private:
		Node<dataType>* sentinel;
	public:
		DoubleLinkedList() {
			sentinel = new Node<dataType>;
			sentinel->setNext(sentinel);
			sentinel->setPrevious(sentinel);
		}

		void addNode(Node<dataType>* toAdd) {
			toAdd->setNext(sentinel->getNext());
			sentinel->getNext()->setPrevious(toAdd);
			sentinel->setNext(toAdd);
			toAdd->setPrevious(sentinel);
		}

		Node<dataType>* getSentinel() {
			return sentinel;
		}

		void printList() {
			int i = 0;
			Node<dataType>* currentNode = sentinel->getNext();
			while (currentNode != sentinel) {
				cout << "N" << ++i << " = " << currentNode->getKey() << endl;
				currentNode = currentNode->getNext();
			}

		}

		void printListOrdered() {
			int i = 0;
			Node<dataType>* currentNode = sentinel->getPrevious();
			while (currentNode != sentinel) {
				cout << "N" << ++i << " = " << currentNode->getKey() << endl;
				currentNode = currentNode->getPrevious();
			}

		}

		void agregarNodo(int i) {
			struct Node<int>* p;
			p = (Node<int>*) malloc(sizeof(struct Node<int>));
			p->setKey(i);
			p->setNext(sentinel);
			p->setPrevious(sentinel->getPrevious());
			sentinel->getPrevious()->setNext(p);
			sentinel->setPrevious(p);
		}

		void transformStrToList() {
			string str;
			cout << "Ingrese un numero" << endl;
			cin >> str;
			cout << "El length del numero es de: " << str.length() << endl;
			for (int i = 0; i < str.length(); i++) {
				int key = (str[i] - '0');
				agregarNodo(key);
			}

			printListOrdered();
		}

};

int main(int args, char* argsv[]) {
	DoubleLinkedList<int> list;
	list.transformStrToList();
	/*Node<int> n1, n2, n3, n4, n5, n6;

	n1.setKey(1);
	list.addNode(&n1);

	n2.setKey(2);
	list.addNode(&n2);

	n3.setKey(3);
	list.addNode(&n3);

	list.printListOrdered();*/
	/*n2.setKey(2);
	n3.setKey(3);

	list.addNode(&n1);
	list.addNode(&n2);
	list.addNode(&n3);

	n4.setKey(4);
	n5.setKey(5);
	n6.setKey(6);

	list.addNode(&n4);
	list.addNode(&n5);
	list.addNode(&n6);

	cout << "Printing inverse" << endl;
	list.printList();
	cout << endl;
	cout << endl;
	cout << "Printing in order" << endl;
	list.printListOrdered();
	cout << endl;
	cout << endl;*/

	/*cout << "Start: " << list.getSentinel()->getKey() << endl;
	cout << "N1: " << list.getSentinel()->getNext()->getKey() << endl;
	cout << "N2: " << list.getSentinel()->getNext()->getNext()->getKey() << endl;*/

	/*Node Class Try*/
	 /*Node<int> n1, n2, n3, nNULL;

	 n1.setKey(1);
	 n2.setKey(2);
	 n3.setKey(3);
	 nNULL.setKey(0);

	 n1.setNext(&n2);
	 n2.setNext(&n3);
	 n3.setNext(&nNULL);

	 n1.setPrevious(&nNULL);
	 n2.setPrevious(&n1);
	 n3.setPrevious(&n2);
	 
	 cout << endl;
	 cout << "Taking the key values:" << endl;
	 cout << endl;

	 cout << "Key 1: " << n1.getKey() << endl;
	 cout << "Key 2: " << n2.getKey() << endl;
	 cout << "Key 3: " << n3.getKey() << endl;

	 cout << endl; 
	 cout << "Taking the previous values:" << endl;
	 cout << endl;

	 cout << "Prev 1: " << n1.getPrevious()->getKey() << endl;
	 cout << "Prev 2: " << n2.getPrevious()->getKey() << endl;
	 cout << "Prev 3: " << n3.getPrevious()->getKey() << endl;

	 cout << endl;
	 cout << "Taking the next values" << endl;
	 cout << endl;

	 cout << "Next 1: " << n1.getNext()->getKey() << endl;
	 cout << "Next 2: " << n2.getNext()->getKey() << endl;
	 cout << "Next 3: " << n3.getNext()->getKey() << endl;*/

	return 0;
}