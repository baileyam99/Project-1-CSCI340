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
#include <stdbool.h>

// Linked list for data storage
struct Node
{
	int PID;
        int PPID;
	bool PARENT;
        unsigned long VSIZE;
        char NAME[50];
	struct Node *next;
};

// Add new node to linked list
void add(struct Node **head, int pid, int ppid, bool parent, unsigned long vsize, char name[50])
{
	printf("BEGIN SAVE\n");
	// Allocate space for new node
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	printf("SPACE ALLOCATED\n");

	// Add data
	newNode->PID = pid;
	newNode->PPID = ppid;
	newNode->PARENT = parent;
	newNode->VSIZE = vsize;
	strcpy(newNode->NAME, name);
	printf("DATA STORED\n");


	// Make next node null
	newNode->next = NULL;

	// If list is empty
	if (head->next == NULL) { head->next = newNode; }

	// If new node is a child
	else if (parent == false)
	{
		printf("CHILD INSERTED\n");
		// Insert after parent
		struct Node *current = head;
		while (current->PID != ppid) { current = current->next; }
		current->next = newNode;
	}

	else
	{
		printf("PARENT INSERTED\n");
		// Find last node and insert into list
		struct Node *current = head;
		while (current->next != NULL) { current = current->next; }
		current->next = newNode;
	}
	printf("END SAVE\n");
}

// Prints linked list as indented tree
void printList(struct Node **head)
{
	printf("BEGIN PRINT\n");

	// Begin at start of list
	struct Node *current = *head;

	printf("FOUND HEAD NODE\n");

	// Loop to end of list	
	while (current->next != NULL) 
	{
		// If parent
		if (current->PARENT == true) 
		{ 
			// Print normal
			printf("(%d) %s, %lu kb\n", current->PID, current->NAME, current->VSIZE);
		} 
		
		else 
		{
			// Print with indent
			printf("\t(%d) %s, %lu kb\n", current->PID, current->NAME, current->VSIZE);
		}

		current = current->next;
		
	}
	printf("PRINT FINISHED\n");
}

// Main function
int main(int argc, char **argv) 
{
	// Create head node
        struct Node* head = NULL;

	// Allocate space for head node
	head = (struct Node*) malloc(sizeof(struct Node));

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

			printf("\nPATH: %s\n\n",path);


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
				// Add data to linked list with parent identifier
			        add(&head, pid, ppid, true, vsize, name);
				printf("\n------------------PARENT-------------------------------\n\n");

			}

			else
			{

				// Add data to linked list without parent identifier
                                add(&head, pid, ppid, false, vsize, name);
				printf("\n--------------------CHILD-----------------------------\n\n");

			}
		} 
	}

	printf("\n-------------------------------------------------\n\n");

	// Print finished linked list
	printList(&head);

	return 0;	
}
