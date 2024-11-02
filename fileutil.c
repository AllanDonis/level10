#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// variable for reallocation
	int capacity = 5;
	*size = 0;

	// Allocate memory for an array of strings (arr).
	char ** arr = malloc(capacity * sizeof(char *));

	// Read the file line by line.
	char string[300];

	while(fgets(string,sizeof(string),in) != NULL){

    //   Trim newline.
		char *nl = strchr(string,'\n');
        if(nl) *nl = '\0';

	//   Expand array if necessary (realloc).
		if (*size >= capacity){

			capacity += capacity; 
			char **largerarr = realloc(arr,capacity * sizeof(char *));
			arr = largerarr;
			printf("Array extended\n");
		}
	//   Allocate memory for the string (str).
		char * str = malloc((strlen(string)+1) * sizeof(char));

	//   Copy each line into the string (use strcpy).
		strcpy(str,string);

	//   Attach the string to the large array (assignment =).
		arr[*size] = str;

	// The size should be the number of entries in the array.
		(*size)++;	
	}

    // Close the file.
	fclose(in);
	
	// Return pointer to the array of strings.
	return arr;
}

char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an 2D array, using COLS as the width.
	// Read the file line by line into a buffer.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Copy each line from the buffer into the array (use strcpy).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array.
	return NULL;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{
	for (int i = 0; i < size; i++) {

        if (strstr(lines[i], target) != 0) {
            return lines[i]; // Return the index where the string was found
        }
    }
	return NULL; 
}

char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
    
    return NULL;
}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{
	for(int i = 0; i < size; i++){
		free(arr[i]);
	}
}

void free2D(char (*arr)[COLS])
{

}