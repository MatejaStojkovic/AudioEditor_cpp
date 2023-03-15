#pragma once
#include <string>
#include "List.h"

class AudioEditor {
public:
	int importAudio(std::string audio);
	std::string exportAudio();
	std::string exportNotes();

	void insertSymbol(std::string symbol, int position);
	void deleteSymbol(int position);
	void replaceSymbol(std::string symbol, int position);
	void changeOctave(int step);

private:
	List list;

};