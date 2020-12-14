#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

const char* getHost(){
	char* hostBuffer = malloc(BUFFER_SIZE);
	gethostname(hostBuffer, BUFFER_SIZE);
	return hostBuffer;
}
