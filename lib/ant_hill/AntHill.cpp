#include "AntHill.h"

AntHill::~AntHill() {
    for (auto p : inhabitants) {
        delete p;
    }
    inhabitants.clear();
}
