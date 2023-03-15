#pragma once
#include "MusicSymbol.h"
constexpr int MAXOCTAVE = 7;
constexpr int MINOCTAVE = 1;

struct Node {
	Node(MusicSymbol* symbol) : data(symbol) {};
	MusicSymbol* data;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class List {
public:
	~List();

	void pushFront(MusicSymbol* data);
	void pushBack(MusicSymbol* data);

	Node* getHead() { return head; };
	Node* getTail() { return tail; };
	void setHead(Node* head) { this->head = head; };
	void setTail(Node* tail) { this->tail = tail; };

	void insert(MusicSymbol* data, int pos);
	void erase(int pos);

	void updateOctave(MusicSymbol* data);
	void changeOctave(int step);
	int getMaxOctave() { return maxOctave; };
	int getMinOctave() { return minOctave; };

	void incMinOctave(int inc) { minOctave += inc; };
	void incMaxOctave(int inc) { maxOctave += inc; };


private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int maxOctave = 1;
	int minOctave = 7;
};