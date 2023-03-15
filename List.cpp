#include "List.h"
//#include <crtdbg.h> 
//#define _CRTDBG_MAP_ALLOC 
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

List::~List() {

	while (head != nullptr) {
		Node* tmp = head;
		head = head->next;
		delete tmp->data;
		delete tmp;
	}

	maxOctave = MINOCTAVE;
	minOctave = MAXOCTAVE;
	tail = nullptr;

}

void List::pushFront(MusicSymbol* data)
{

	auto newNode = new Node(data);

	if (head != nullptr) {
		head->prev = newNode;
		newNode->next = head;
	}

	updateOctave(data);

	if (head == nullptr) {
		tail = newNode;
	}

	head = newNode;

}

void List::pushBack(MusicSymbol* data)
{
	auto newNode = new Node(data);

	if (tail != nullptr) {
		tail->next = newNode;
		newNode->prev = tail;
	}

	updateOctave(data);

	if (tail == nullptr) head = newNode;

	tail = newNode;
}

void List::insert(MusicSymbol* data, int pos){

	if (pos < 0) return;

	if (pos == 0) {
		pushFront(data);
		return;
	}

	Node* newNode = new Node(data);

	Node* curr = head;

	for (int i = 0; i < pos; i++) {
		if (curr == nullptr) return;
		curr = curr->next;
	}

	updateOctave(data);

	curr->prev->next = newNode;
	newNode->prev = curr->prev;
	curr->prev = newNode;
	newNode->next = curr;

}

void List::erase(int pos)
{
	Node* curr = head;
	if (pos < 0) return;

	for (int i = 0; i < pos; i++) {
		curr = curr->next;
		if (curr == nullptr) return;
	}

	Node* tmp = head;

	while (tmp != nullptr) {
		updateOctave(tmp->data);
		tmp = tmp->next;
	}

	//if (curr == nullptr) return;

	if (curr->prev != nullptr && curr->next != nullptr) {
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
	}
	else if (curr->prev == nullptr && curr->next != nullptr) {
		head = curr->next;
		curr->next->prev = nullptr;
	}
	else if (curr->next == nullptr && curr->prev != nullptr) {
		tail = curr->prev;
		curr->prev->next = nullptr;
	}

	delete curr->data;
	delete curr;
}

void List::updateOctave(MusicSymbol* data)
{
	if (data->getMaxOctave() > maxOctave) {
		maxOctave = data->getMaxOctave();
	}

	if (data->getMinOctave() < minOctave) {
		minOctave = data->getMinOctave();
	}
}

void List::changeOctave(int step)
{
	Node* curr = head;

	while (curr != nullptr) {

		curr->data->changeOctave(step);

		curr = curr->next;
	}

}
