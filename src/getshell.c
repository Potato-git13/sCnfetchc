#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 150

const char* getShell() {
    char *shell = malloc(BUFFER_SIZE);
    char *shellpath = getenv("SHELL");
    char *shellname = strrchr(getenv("SHELL"), '/');

	// if $SHELL doesn't have a '/'
    if(shellname == NULL)
		// Copy the whole thing over
        strncpy(shell, shellpath, BUFFER_SIZE);
    else
		// Copy past the last '/'
        strncpy(shell, shellname + 1, BUFFER_SIZE);

    return shell;
}
