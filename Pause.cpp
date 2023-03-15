#include "Pause.h"
#include <string>

Pause::Pause(std::string pause) {
    if (pause == " ") pauseSize = 1;
    else pauseSize = pause.length() * 2;
}

std::string Pause::toNote(){
    if (data == " ") return "_";
    std::string str = "";
    int size = pauseSize;
    while (size != 1) {
        str += "__";
        size /= 2;
    }

    return str;
}

std::string Pause::toString() {
    if (data == " ") return data;
    std::string str = "";
    int size = pauseSize;
    while (size != 1) {
        str += "|";
        size /= 2;
    }

    return str;
}
