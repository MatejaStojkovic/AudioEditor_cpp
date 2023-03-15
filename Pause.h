#pragma once
#include "MusicSymbol.h"

class Pause : public MusicSymbol {
public:
	Pause(std::string pause);
	virtual ~Pause() { };
	virtual std::string toNote() override;
	virtual std::string toString() override;
	int getPauseSize() { return this->pauseSize; };
	virtual void changeOctave(int step) override { return; };
	virtual int getMaxOctave() override { return 1; };
	virtual int getMinOctave() override { return 7; };

private:
	std::string data;
	int pauseSize = 0;

};