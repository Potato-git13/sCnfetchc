#include <stdio.h>
#include <string.h>

const char* getDistro(){
	int lineNumber = 4;

	static const char filename[] = "/etc/os-release";
	FILE *file = fopen(filename, "r");
	int count = 0;
	if ( file != NULL )
	{
    	static char line[256];
		char *p = line;
    	while (fgets(line, sizeof(line), file) != NULL) /* read a line */
    	{
        	if (count == lineNumber)
        	{
            	//use line or in a function return it
            	//in case of a return first close the file with "fclose(file);"
				// Remove 13 chars
				memcpy(line, line+13, sizeof(line));
				p = line;
            	p[strlen(p)-2] = 0;
				fclose(file);
				return line;
        	}
       		 else
        	{
            	count++;
        	}
    	}
    		fclose(file);
		}
	else
	{
    	//file doesn't exist
	}
	return "shit";
}
