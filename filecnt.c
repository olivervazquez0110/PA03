#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Another random comment
void recCount(char *, int *, int *, int *);

// Random Comment
int main(int argc, char *argv[]) {
	int numDir = 0, numFiles = 0, numBytes = 0;
	
	// Check number of arguments
	if(argc < 2) return 0;
	
	// Recursive count function
	recCount(argv[1], &numDir, &numFiles, &numBytes);
	
	// Print statements
	printf("The total number of directories in directory %s is: %i\n", argv[1], numDir);
	printf("The total number of files in directory %s is: %i\n", argv[1], numFiles);
	printf("The total number of bytes occupied by all files in directory %s is: %i\n", argv[1], numBytes);
	
	return 0;
}

// Recursive function to count num of directories, files and bytes of files
void recCount(char *pathName, int *numDir, int *numFiles, int *numBytes) {
	DIR *dir = opendir(pathName); // Open directory
	char nextPath[256]; // Name for nextpath
	struct dirent *d; // Struct for directory variables
	struct stat s; // Struct for file stuff
	
	// If dir null return
	if(!dir) { return; }  // Base case
	
	// Loop through directories
	while((d=readdir(dir)) != NULL) {
	// Create new path name for next directory
		strcpy(nextPath, pathName);
		strcat(nextPath, "/");
		strcat(nextPath, d->d_name);
		
		if(d->d_type == DT_REG) { // File
			(*numFiles)++; // Increment count of files
			stat(nextPath, &s);
			(*numBytes) += s.st_size; // Sum of total bytes
		} else if(d->d_type == DT_DIR && strcmp(d->d_name, ".") != 0  && strcmp(d->d_name, "..") != 0) { // Directory
			(*numDir)++; // Increment count of dirs
			
			// Recursive call to next directory
			recCount(nextPath, numDir, numFiles, numBytes);
		}
	}
	// Close directory
	closedir(dir);
}
