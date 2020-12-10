#include <sys/sysinfo.h>

int getuptime(){
	struct sysinfo sysinfostruct;
	int min;
	int hour;

	if(! sysinfo (&sysinfostruct)){
		min = (sysinfostruct.uptime / 60) % 60;
		hour = sysinfostruct.uptime / 60 / 60;
	}
	return minsupstruct sysinfo sysinfostruct;
    int min;
    int hour;

    if(! sysinfo (&sysinfostruct)){
        min = (sysinfostruct.uptime / 60) % 60;
        hour = sysinfostruct.uptime / 60 / 60;
    };
}
