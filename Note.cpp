#include "Note.h"
#include <string>
#include "Conversion.h"
using std::string;

std::string Note::toNote()
{
    return conversion(note);
}

std::string Note::toString()
{
    string str = "";
    return str += note;
}

void Note::changeOctave(int step)
{
	string convertedData = conversion(note);

	int last = convertedData.length() - 1;

	if ('0' <= convertedData[last] && '9' >= convertedData[last]) {

		convertedData[last] = convertedData[last] + step;
	}

	note = reverseConversion(convertedData);
}

int Note::getMaxOctave()
{
	string convertedData = conversion(note);

	int last = convertedData.length() - 1;

	if ('0' <= convertedData[last] && '9' >= convertedData[last])
		return convertedData[last] - '0';

	return 1;
}

int Note::getMinOctave()
{
	string convertedData = conversion(note);

	int last = convertedData.length() - 1;

	if ('0' <= convertedData[last] && '9' >= convertedData[last])
		return convertedData[last] - '0';

	return 7;
}