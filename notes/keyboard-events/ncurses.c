#include <ncurses.h>

int main() {
    // Initialize the screen
    initscr();
    cbreak(); // Disable line buffering
    keypad(stdscr, TRUE); // Enable special keys

    // Print instructions
    printw("Press a key (ESC to exit): ");
    refresh();

    // Wait for a key press
    int ch;
    while ((ch = getch()) != 27) { // 27 is the ASCII code for ESC
	if(ch == 's') printw("\nYou pressed: %c\n", ch);
        refresh();
    }

    // Clean up and exit
    endwin();
    return 0;
}

