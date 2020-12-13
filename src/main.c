#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

extern const char* whoami();
extern const char* getDistro();
extern const char* getShell();

int main(){
	char hostBuffer[256];
	struct sysinfo sysinfostruct;
    int min;
    int hour;

	// Get the host name; store it in hostBuffer
    gethostname(hostBuffer, sizeof(hostBuffer));
	
	if(! sysinfo (&sysinfostruct)){
        min = (sysinfostruct.uptime / 60) % 60;
        hour = sysinfostruct.uptime / 60 / 60;
    }

	printf("\n");
	printf("User   : %s\n", whoami());
	printf("Host   : %s\n", hostBuffer);
	printf("Distro : %s\n", getDistro());
	printf("Uptime : %dh, %dm\n", hour, min);
	printf("Shell  : %s\n", getShell());
	printf("\n");
	return 0;
}
