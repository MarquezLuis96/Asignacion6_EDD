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

		void setKey(dataType key) {
			this->key = key;
		}

		dataType getKey() {
			return this->key;
		}

		void setPrevious(Node previous) {
			this->previous = previous;
		}

		Node getPrevious() {
			return this->previous;
		}

		void setNext(Node next) {
			this->next = next;
		}

		Node getNext() {
			return this->next;
		}
};

int main(int args, char* argsv[]) {
	cout << "Hola Mundo!" << endl;
	return 0;
}