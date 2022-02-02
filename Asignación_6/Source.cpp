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

		void printListOrderedInline() {
			int i = 0;
			Node<dataType>* currentNode = sentinel->getPrevious();
			while (currentNode != sentinel) {
				cout << currentNode->getKey();
				currentNode = currentNode->getPrevious();
			}
			cout << endl;
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
			cin >> str;
			for (int i = 0; i < str.length(); i++) {
				int key = (str[i] - '0');
				agregarNodo(key);
			}
		}

		int contarDigitos() {
			int i = 0;
			Node<dataType>* currentNode = sentinel->getPrevious();
			while (currentNode != sentinel) {
				++i;
				currentNode = currentNode->getPrevious();
			}
			return i;
		}

};

void sumarLongs(DoubleLinkedList<int> &l1, DoubleLinkedList<int>& l2) {
	int llevo, anoto;
	int aux1, aux2, auxR;
	bool llevoPendiente = false;
	DoubleLinkedList<int> listaResultado;
	Node<int>* currentN1 = l1.getSentinel()->getPrevious();
	Node<int>* currentN2 = l2.getSentinel()->getPrevious();
	while (currentN2 != l2.getSentinel()) {
		
		auxR = currentN1->getKey() + currentN2->getKey();
		
		if (llevoPendiente) {
			auxR += llevo;
		}

		if (auxR < 10) {
			listaResultado.agregarNodo(auxR);
			llevoPendiente = false;
		}
		else {
			llevoPendiente = true;
			llevo = auxR / 10;
			anoto = auxR % 10;
			listaResultado.agregarNodo(anoto);
		}
		
		currentN1 = currentN1->getPrevious();
		currentN2 = currentN2->getPrevious();
	}

	while (currentN1 != l1.getSentinel()) {
		if (llevoPendiente) {
			auxR = llevo + currentN1->getKey();
		}
		else {
			listaResultado.agregarNodo(currentN1->getKey());
			currentN1 = currentN1->getPrevious();
			continue;
		}

		if (auxR < 10) {
			listaResultado.agregarNodo(auxR);
			llevoPendiente = false;
		}
		else {
			llevoPendiente = true;
			llevo = auxR / 10;
			anoto = auxR % 10;
			listaResultado.agregarNodo(anoto);
		}

		currentN1 = currentN1->getPrevious();
	}

	if (llevoPendiente) {
		listaResultado.agregarNodo(llevo);
	}

	cout << endl << endl << "Result" << endl;
	listaResultado.printListOrderedInline();

}

int main(int args, char* argsv[]) {
	int opc = 1;

	do {
		cout << "Ingrese:" << endl;
		cout << "1 - Para realizar una suma con enteros Long" << endl;
		cout << "0 - Para salir" << endl;
		cin >> opc;

		if (opc == 0) {
			cout << "Hasta Luego... " << endl;
			break;
		}

		if (opc == 1) {
			DoubleLinkedList<int> list1;
			DoubleLinkedList<int> list2;
			cout << endl << "Ingrese el primer operando:" << endl;
			list1.transformStrToList();

			cout << endl << "Ingrese el segundo operando:" << endl;
			list2.transformStrToList();

			if (list1.contarDigitos() >= list2.contarDigitos()) {
				sumarLongs(list1, list2);
				cout << endl;
			}
			else {
				sumarLongs(list2, list1);
				cout << endl;
			}
		}
		else {
			cout << "Error: Opcion invalida... Intente de nuevo" << endl;
		}
	} while (opc != 0 );

	return 0;
}