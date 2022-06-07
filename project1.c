/* Alex Bailey & Janae Dorsey
 * Crosby
 * CSCI 340
 * 8 February 2022
 *
 * PROJECT 1
 *
 * We certify that this work is a collaborative effort between us and only us
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <regex.h>
#include <string.h>

// Main function
int main(int argc, char **argv) 
{

	// Create pointer for directory
	struct dirent *dirEntry;
	DIR *dirRead = opendir("/proc");

	// Initialize  regex for identifying PIDs
	regex_t regex;
	int regVal;

	// Open proc directory
	while ((dirEntry = readdir(dirRead)) != NULL)
	{
		// Get line
		char *line = dirEntry->d_name;

		// Determine if line contains number
        	regVal = regcomp(&regex, "[0-9+]", 0);
        	regVal = regexec(&regex, line, 0, NULL, 0);

		// If contains number
		if (regVal == 0)
		{
			// Concatinate PID to file path
			char path[50];
			char stat[50];

			strcpy(path, "/proc/");
			strcpy(stat, "/stat");
			
			strcat(path, line);
			strcat(path, stat);

			// Initialize variables
			int pid;
			int ppid;
			unsigned long vsize;
			char name[50];

			// Initialize variables for unused info
			unsigned long lu;
			unsigned long long llu;
			unsigned int u;
			long ld;
			char c;
			int d;

			// File pointer
			FILE *filePointer;

			// Open file
			filePointer = fopen(path, "r");

                        // Scan file for info
                        fscanf(filePointer, "%d %s %c %d %d %d %d %d %u %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %llu %lu %ld %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %d %d %u %u %llu %lu %ld %lu %lu %lu %lu %lu %lu %lu %d", &pid, name, &c, &ppid, &d, &d, &d, &d, &u, &lu, &lu, &lu, &lu, &lu, &lu, &ld, &ld, &ld, &ld, &ld, &ld, &llu, &vsize, &ld, &lu, &lu, &lu, &lu, &lu, &lu,&lu, &lu, &lu, &lu, &lu, &lu, &lu, &d, &d, &u, &u, &llu, &lu, &ld, &lu, &lu, &lu, &lu, &lu, &lu, &lu, &d);


			// Close file
			fclose(filePointer);	

			// If parent process
			if (ppid == 0)
			{
			        // Print info normal 	
				printf("(%d) %s, %lu kb\n", pid, name, vsize);
			}

			else
			{
				// Print info indented
				printf("\t(%d), [%d], %s, %lu kb\n", pid, ppid, name, vsize);
			}
		} 
	}

	return 0;	
}
