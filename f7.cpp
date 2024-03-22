#include <stdio.h>

#pragma warning(disable : 4996) // required by Visual Studio

int main(void)
{
    FILE* fp1 = NULL; // File pointer for text file

    const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };

    /*Text file open */
    if ((fp1 = fopen("myTextFile.txt", "w")) == NULL) // Open file and check for error
    {

        printf("ERROR: File cannot open"); // Print error message and exit if file failed to open
        return -1;
    }
    else
    {
        for (int i = 0; i < 2; i++) // Loop to write in file
        {
            if (fprintf(fp1, "This is line %d\n", i + 1) < 0) // Write file and check for error simultaneously
            {
                printf("ERROR: Couldn't write to file"); // If error in writing to file, print error message and exit code
                return -1;
            }
        }

        if (fclose(fp1) != 0)
        {
            printf("ERROR: Couldn't close file"); // Print error message and exit if file failed to close
            return -1;
        }
    }

	return 0;
}