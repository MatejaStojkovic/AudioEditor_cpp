#pragma once
#include "MusicSymbol.h"


class Note : public MusicSymbol {
public:
	Note(char chr) : note(chr) {}
	virtual ~Note(){};
	virtual std::string toNote() override;
	virtual std::string toString() override;
	virtual void changeOctave(int step) override;
	virtual int getMaxOctave() override;
	virtual int getMinOctave() override;

	char getNote() { return this->note; };

private:
	char note;
};