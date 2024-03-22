#include <stdio.h>

#pragma warning(disable : 4996) // required by Visual Studio

int main(void)
{
    FILE* fp1 = NULL; 
    FILE* fpb1 = NULL;

    const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };

    /*Text file open */
    if ((fp1 = fopen("myTextFile.txt", "w")) == NULL) 
    {

        printf("ERROR: File cannot open"); 
        return -1;
    }
    else
    {
        for (int i = 0; i < 2; i++) 
        {
            if (fprintf(fp1, "This is line %d\n", i + 1) < 0) 
            {
                printf("ERROR: Couldn't write to file"); 
                return -1;
            }
        }

        if (fclose(fp1) != 0)
        {
            printf("ERROR: Couldn't close file"); 
            return -1;
        }
    }


    /*Write to binary file */

    if ((fpb1 = fopen("myEvenDataList.data", "wb")) == NULL)
    {
        printf("ERROR: File cannot open");
        return -1;
    }
    else
    {

        for (int i = 0; i < sizeof(kBinaryData) / sizeof(kBinaryData[0]); i++)
        {
            if (kBinaryData[i] % 2 == 0)
            {

                if ((fwrite(&kBinaryData[i], sizeof(unsigned short), 1, fpb1)) < 1)
                {
                    printf("ERROR: fwrite couldn't write to file");
                    return -1;
                }
            }
        }

        if (fclose(fpb1) != 0)
        {
            printf("ERROR: Couldn't close file");
            return -1;
        }
    }

   

	return 0;
}