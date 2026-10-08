#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool has_cex_ext(const char *fname) 
{
	size_t l = strlen(fname);
	if (l < 5) return false;
	if (fname[l-1] == 'x' && fname[l-2] == 'e' && fname[l-3] == 'c' && fname[l-4] == '.') 
		return true;
	return false;
}

int main(int argc, char *argv[]) 
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <name.cex>\n", argv[0]);
		return 1;
	}

	if (!has_cex_ext(argv[1])) { 
		fprintf(stderr, "Error: file must be in format <name.cex>\n");
		return 1; 
	}
	
	return 0;
}
