#pragma once
#include <string>

class MusicSymbol {
public:
	virtual ~MusicSymbol(){ };
	virtual std::string toNote() = 0;
	virtual std::string toString() = 0;
	virtual void changeOctave(int step) = 0;
	virtual int getMaxOctave() = 0;
	virtual int getMinOctave() = 0;

private:


};

