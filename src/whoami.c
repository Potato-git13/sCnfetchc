#include <stdlib.h>
#include <stdio.h>

const char* whoami()
{
	char *p=getenv("USER");
    if(p==NULL) printf("Error");
    return p;
}
