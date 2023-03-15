#include "Accord.h"
#include "List.h"
#include "Note.h"
#include <string>

Accord::Accord(std::string str)
{
	if (str[0] != '[') return;

	int i = 1;

	while (str[i] != ']') {
		Note* note = new Note(str[i]);
		addNote(note);
		i++;
		if (i >= str.length()) return;
	}
}

Accord::~Accord()
{
	while (notes.getHead() != nullptr) {
		Node* tmp = notes.getHead();
		notes.setHead(notes.getHead()->next);
		delete tmp->data;
		delete tmp;
	}
}

std::string Accord::toString() {

	std::string str = "[";

	Node* curr = notes.getHead();

	while (curr != nullptr) {
		str += curr->data->toString();

		curr = curr->next;
	}

	str += ']';

	return str;
}

std::string Accord::toNote()
{
	std::string strCpy = "[";

	std::string pause = "";

	Node* curr = notes.getHead();

	while (curr != nullptr) {
		strCpy += curr->data->toNote();

		curr = curr->next;
	}

	strCpy += ']';

	return strCpy;
}

void Accord::changeOctave(int step)
{
	Node* curr = notes.getHead();

	while (curr != nullptr) {
		curr->data->changeOctave(step);
		curr = curr->next;
	}
}
