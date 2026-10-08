#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lexer.h"

bool has_cex_ext(const char *f_name) 
{
	size_t l = strlen(f_name);
	if (l < 5) return false;
	if (f_name[l-1] == 'x' && f_name[l-2] == 'e' && f_name[l-3] == 'c' && f_name[l-4] == '.') 
		return true;
	return false;
}

char *read_cex_file(const char *f_name) {
	FILE *fp = fopen(f_name, "rb");
	if (!fp) {
		perror("Error opening file");
		return NULL;
	} 

	if (fseek(fp, 0, SEEK_END) != 0) {
		perror("Error seeking to end of file");
		fclose(fp);
		return NULL;
	}	

	long f_len = ftell(fp);
    if (f_len == -1) {
		perror("Error determining size of file");
		fclose(fp);
		return NULL;
	}
	rewind(fp);

	char *buf = malloc(f_len + 1); 
	if (!buf) {
		perror("Error allocating memory for read file buffer");	
		fclose(fp);
		return NULL;
	}

	size_t count_read = fread(buf, 1, f_len, fp); 
	if (count_read < (size_t)f_len) {
		perror("Failed to read file");	
		fclose(fp);
		free(buf);
		return NULL;
	}	
	buf[f_len] = '\0';

	fclose(fp);

	return buf; 
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

	char *buf = read_cex_file(argv[1]);
	if (!buf) return 1;

	Lexer l = lexer_init(buf);
	lexer_free(&l);

	return 0;
}
