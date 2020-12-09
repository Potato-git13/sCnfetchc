#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern const char* whoami();
extern const char* getDistro();

int main(){
	printf("User   : %s\n", whoami());

    char hostBuffer[256];

    gethostname(hostBuffer, sizeof(hostBuffer));
	printf("Host   : %s\n", hostBuffer);
	printf("Distro : %s\n", getDistro());
	return 0;
}
