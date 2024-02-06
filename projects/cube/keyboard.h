#ifndef KEYBOARD__H
#define KEYBOARD__H
#include <termios.h>
#include <unistd.h>


void setNonCanonicalMode();

void resetCanonicalMode();

#endif
