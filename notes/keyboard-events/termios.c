#include <stdio.h>
#include <termios.h>
#include <unistd.h>

// Function to set the terminal to non-canonical mode
void setNonCanonicalMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Turn off canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Function to reset the terminal to canonical mode
void resetCanonicalMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO; // Turn on canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int main() {
    setNonCanonicalMode(); // Set non-canonical mode

    char c;
    printf("Press 'q' to quit\n");

    while (1) {
        read(STDIN_FILENO, &c, 1); // Read one character

        if (c == 'q') {
		printf("action\n"); 
            break; // Exit loop if 'q' is pressed
        }

    }

    resetCanonicalMode(); // Reset to canonical mode before exiting

    return 0;
}

