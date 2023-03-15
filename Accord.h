#pragma once
#include "MusicSymbol.h"
#include "List.h"
#include "Note.h"

class Accord : public MusicSymbol {
public:
	Accord(std::string str);
	virtual ~Accord();
	virtual std::string toNote() override; // vraca akord u notama
	virtual std::string toString() override; // vraca akord u charovima
	void addNote(Note* note) { notes.pushBack(note); };
	virtual void changeOctave(int step) override;
	virtual int getMaxOctave() override { return notes.getMaxOctave(); };
	virtual int getMinOctave() override { return notes.getMinOctave(); };

private:
	List notes;

};