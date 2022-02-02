#include <iostream>

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

int main(int args, char* argsv[]) {

	 Node<int> n1, n2, n3, nNULL;

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
	 cout << "Next 3: " << n3.getNext()->getKey() << endl;

	return 0;
}