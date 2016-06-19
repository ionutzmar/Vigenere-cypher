/*
    argv[1] is  the key
    use "< inputFile" in the command line to specify the file to be encrypted.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void checkKey(const char *);
int keyLength;

int main(int argc, char const *argv[]) {
    keyLength = strlen(argv[1]);
    checkKey(argv[1]);
    int c, newChar;
    int counter = 0;

    while((c = getc(stdin)) != EOF)
    {
        if (!isalpha(c))
        {
            putc(c, stdout);
            continue;
        }
        if (counter >= keyLength)
            counter = 0;
        c = tolower(c);
        newChar = c + argv[1][counter] - 'a';
        if (newChar > 'z')
            newChar -= 'z' - 'a' + 1;

        putc(newChar, stdout);

        counter++;
    }
    return 0;
}

void checkKey(const char* key)
{
    int i;
    for  (i = 0; i < keyLength; i++)
        if (key[i] < 'a' || key[i] > 'z')
        {
            fprintf(stderr, "The key is not valide! It must contain lower case characters between a and z.\n");
            exit(EXIT_FAILURE);
        }
}
