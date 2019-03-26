#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char out[256];
	// Check for valid option
	if(strcmp("-d", argv[1]) && strcmp("-b", argv[1]) && strcmp("-f", argv[1])) {
		printf("ERROR: Invalid Option\n");
	}	

	while(fgets(out, 256, stdin) != NULL) { // Loop through standard input
		// Check for directories
		if(!strcmp("-d", argv[1]) && strstr(out, "directories") != NULL ) {
			printf("%s\n", out);	
			break;
		// Check for files
		} else if(!strcmp("-f", argv[1]) && strstr(out, "files") != NULL) {
			printf("%s\n", out);	
			break;

		// Check for bytes			
		} else if(!strcmp("-b", argv[1]) && strstr(out, "bytes") != NULL) {
			printf("%s\n", out);	
			break;
		} 
	}
}

