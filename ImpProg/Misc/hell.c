#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *read(char *fileName);
int countLines(char *file);
int charCount(char *file);
int wordCount(char *file);

int main(int argc, char *argv[])
{
	char *file = read(argv[1]);
	int lineCount = countLines(file);
	int chars = charCount(file);
	int words = wordCount(file);
	
	printf("Line count: %d\nCharacter count: %d\nWords: %d\n", lineCount + 1, chars, words);
	
	return 0;
}

char *read(char *fileName)
{
	FILE *file = fopen(fileName, "r");
	
	if (file == NULL)
	{
		printf("Empty file!");
		exit(1);
	}
	
	fseek(file, 0, SEEK_END);
	long fileSize = ftell(file);
	fseek(file, 0, SEEK_SET);
	
	char *fileContents = malloc(fileSize + 1);
	
	fread(fileContents, sizeof(char), fileSize, file);
	fileContents[fileSize + 1] = '\0';
	fclose(file);
	
	return fileContents;
}

int countLines(char *file)
{
	if (file == NULL)
	{
		printf("Empty file!");
		exit(1);
	}
	
	int lines = 0;
	
	for (int i = 0; file[i] != '\0'; i++)
	{
		if (file[i] == '\n')
		{
			lines++;
		}
	}
	
	return lines;
}

int charCount(char *file)
{
	int chars = 0;
	
	if (file == NULL)
	{
		printf("Empty file!");
		exit(1);
	}
	
	for (int i = 0; file[i] != '\0'; i++)
	{
		if (file[i] != '\n')
		{
			chars++;
		}
	}
	
	return chars;
}

int wordCount(char *file)
{
	int words = 0;
	
	if (file == NULL)
	{
		printf("Empty file!");
		exit(1);
	}
	
	for (int i = 0; file[i] != '\0'; i++)
	{
		if (isspace(file[i]) != 0)
		{
			words++;
		}
	}
	
	return words;
}