#include <stdlib.h>
#include <stdio.h>

const char* whoami(){
	char *p = getenv("USER");
    if (p==NULL)
        return "Error";
    return p;
}
