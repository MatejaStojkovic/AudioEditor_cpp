#include "AudioEditor.h"
#include <string>
#include "Accord.h"
#include "List.h"
#include "Pause.h"
#include <iostream>
constexpr int TAKT = 8;
using std::string;


int AudioEditor::importAudio(std::string audio)
{
    for (int i = 0; i < audio.length(); i++) {

        string str = "";

        static const string provera = "1!2@34$5%6^78*9(0qQwWeErtTyYuiIoOpPasSdDfgGhHjJklLzZxcCvVbBn |[]";

        if (provera.find(audio[i]) == string::npos) return i;

        if (audio[i] == ']') return i;

        if (audio[i] == '[') {

            while (audio[i] != ']') {
                str += audio[i];
                i++;
                if (i >= audio.length()) return i;
            }

            str += ']';

            Accord* accord = new Accord(str);

            list.pushBack(accord);
            continue;
        }

        if (audio[i] == ' ') {
            Pause* pause = new Pause(" ");
            list.pushBack(pause);
            continue;
        }
        
        if (audio[i] == '|') {
            str += audio[i];
            if (audio[i + 1] == '|') {
                str += audio[i];
                i++;
            }
            Pause* pause = new Pause(str);
            list.pushBack(pause);
            continue;
        }

        Note* note = new Note(audio[i]);
        list.pushBack(note);
    }

    return -1;
}

std::string AudioEditor::exportAudio()
{
    std::string str = "";
    Node* curr = list.getHead();
    while (curr != nullptr) {
        str += curr->data->toString();
        curr = curr->next;
    }
    return str;
}

std::string AudioEditor::exportNotes()
{
    std::string str = "";
    Node* curr = list.getHead();
    while (curr != nullptr) {
        if (curr->next != nullptr) {
            if (auto tmp = dynamic_cast<Pause*>(curr->next->data)) {
                int size = tmp->getPauseSize();
                while (size != 1) {
                    str += curr->data->toNote();
                    size--;
                }
            }
        }
        str += curr->data->toNote();
        curr = curr->next;
    }

    int cntNewLine = 0;
    bool accord = false;

    for (int i = 0; i < str.length(); i++) {
        if (!accord) {
            if (cntNewLine == TAKT) {
                cntNewLine = 0;
                str.insert(i, "\n");
            }
            if (('0' <= str[i] && '9' >= str[i]) || str[i] == '_') cntNewLine++;
            if (str[i] == '[') {
                accord = true;
            }
        }
        else {
            if (str[i] == ']') {
                accord = false;
                cntNewLine++;
            }
        }
    }

    return str;
}

void AudioEditor::insertSymbol(std::string symbol, int position)
{
    static const string provera = "1!2@34$5%6^78*9(0qQwWeErtTyYuiIoOpPasSdDfgGhHjJklLzZxcCvVbBn |[]";
    for (int i = 0; i < symbol.size(); i++)
    if (provera.find(symbol[i]) == string::npos) return;

    if (symbol == "|" || symbol == "||" || symbol == " ") {
        Pause* pause = new Pause(symbol);
        list.insert(pause, position);
    }
    else {

        if (symbol[0] == '[' && symbol[symbol.length() - 1] == ']') {
            Accord* accord = new Accord(symbol);
            list.insert(accord, position);
        }
        else {
            Note* note = new Note(symbol[0]);
            list.insert(note, position);
        }
    }
}

void AudioEditor::deleteSymbol(int position)
{
    list.erase(position);
}

void AudioEditor::replaceSymbol(std::string symbol, int position)
{
    list.erase(position);
    insertSymbol(symbol, position);
}

void AudioEditor::changeOctave(int step)
{
    if (list.getMaxOctave() + step >= MAXOCTAVE ||
        list.getMinOctave() + step <= MINOCTAVE) {

        std::cout << "Octave step out of bounds" << std::endl;

        return;
    }

    Node* curr = list.getHead();

    while (curr != nullptr) {
        if (dynamic_cast<Pause*>(curr->data)) {
            curr = curr->next;
            continue;
        }
        curr->data->changeOctave(step);
        curr = curr->next;
    }

    list.incMinOctave(step);
    list.incMaxOctave(step);
}
