#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <stdlib.h>
#include <unistd.h>

extern const char* whoami();
extern const char* getDistro();
extern const char* getShell();
extern const char* getHost();

int main(){
	struct sysinfo sysinfostruct;
    int min;
    int hour;

	if(! sysinfo (&sysinfostruct)){
        min = (sysinfostruct.uptime / 60) % 60;
        hour = sysinfostruct.uptime / 60 / 60;
    }
	printf("User   : %s\n", whoami());
	printf("Host   : %s\n", getHost());
	printf("Distro : %s\n", getDistro());
	printf("Uptime : %dh, %dm\n", hour, min);
	printf("Shell  : %s\n", getShell());
	return 0;
}
