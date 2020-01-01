#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

// Node Structure for using in doubly linkedlist
struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	// explicit constructors
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

// Cache class as super class containing virtual(abstract) functions 
class Cache {

protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  
	Node* tail;
	Node* head;
	// virtual functions without body that will be implemented in sub class(es)
	virtual void set(int, int) = 0;
	virtual int get(int) = 0;
};

// LRUCache class inheriting from Cache class, implementing least recently used algorithm for a cache formed by linked list data structure
class LRUCache :public Cache {

	int capacity; // capacity of cache
public:
	LRUCache(int c) :capacity(c) {};

	void set(int k, int v) {

		Node* node;
		if (mp.empty()) {
			node = new Node(k, v);
			head = tail = node;
			mp[k] = node;
			return;
		}
		auto n = mp.find(k);
		if (n != mp.end()) { 
			n->second->value = v;

			if (head == n->second) // recent used node is head of linked list
				return;

			n->second->prev->next = n->second->next;

			if (tail == n->second) // recent used node is tail of linked list
				tail = tail->prev;
			else // recent used node is some where between head and tail
				n->second->next->prev = n->second->prev;

			n->second->next = head;
			n->second->prev = nullptr;
			head->prev = n->second;
			head = n->second;
		}
		else {
			node = new Node(head->prev, head, k, v);
			head->prev = node;
			head = node;
			mp[k] = node;

			if (mp.size() > capacity) {
				tail = tail->prev;
				mp.erase(tail->next->key);
				delete tail->next;
				tail->next = nullptr;
			}
		}
	}
	int get(int k) {
		auto n = mp.find(k);
		if (n != mp.end())
			return n->second->value;
		return -1;
	}
};

int main() {
	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache l(capacity);
	for (i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "get") {
			int key;
			cin >> key;
			cout << l.get(key) << endl;
		}
		else if (command == "set") {
			int key, value;
			cin >> key >> value;
			l.set(key, value);
		}
	}
	return 0;
}
