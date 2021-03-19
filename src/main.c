#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h>

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
    char ch;
    FILE *fp;
    // Read mode
    fp= fopen("src/icon", "r");

    if (fp == NULL)
    {
        // Fail / Error
        printf("Error: Could not open the file\n");
     } else {
        while((ch = fgetc(fp)) != EOF)
            // Print out all of the characters in a file
            printf("\033[0;32m%c", ch);

        fclose(fp);
        printf("\n");
    }
    printf("\033[0m");
	printf("User   : %s\n", whoami());
	printf("Host   : %s\n", getHost());
	printf("Distro : %s\n", getDistro());
	printf("Uptime : %dh, %dm\n", hour, min);
	printf("Shell  : %s\n", getShell());
	printf("\n");
	return 0;
}
