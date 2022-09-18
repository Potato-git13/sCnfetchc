#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <stdlib.h>
#include <unistd.h>

#include "funcdef.h"

int main(){
	struct sysinfo sysinfostruct;
    int min;
    int hour;

	const char *uname = whoami();
	const char *host= getHost();
	int unamehostlen = (int)(strlen(uname) + 1 + strlen(host));
	char *dash = malloc(unamehostlen * sizeof(char *));

	if(!sysinfo(&sysinfostruct)){
        min = (sysinfostruct.uptime / 60) % 60;
        hour = sysinfostruct.uptime / 60 / 60;
    }

	for (int i = 0; i < unamehostlen; i++){
		strcat(dash, "—");
	}

	printf("%s@%s\n", uname, host);
	printf("%s\n", dash);
	printf("OS : %s\n", getDistro());
	printf("Uptime : %dh, %dm\n", hour, min);
	printf("Shell  : %s\n", getShell());
	return 0;
}
