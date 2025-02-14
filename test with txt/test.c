#include <stdio.h>
#include <stdlib.h> // For atoi()

int main()
{
    FILE *fp_write, *fp_read;
    int a = 0, b = 0, c = 0;

    // 1. Write Data to File
    fp_write = fopen("people.txt", "w"); // "w" to overwrite if file exists

    if (fp_write == NULL)
    {
        perror("Error opening file for writing");
        return 1; // Indicate an error
    }

    for (int i = 0; i < 10; i++)
    {
        a++;
        b++;
        c++;                                         // More concise increment
        printf("a = %d\tb = %d\tc = %d\n", a, b, c); // Printing to console
        fprintf(fp_write, "%d,%d,%d\n", a, b, c);    // Printing to file
        fflush(fp_write);                            // Important for immediate writing
    }

    fclose(fp_write); // Close the file after writing

    // 2. Read Data from File
    fp_read = fopen("people.txt", "r");

    if (fp_read == NULL)
    {
        perror("Error opening file for reading");
        return 1; // Indicate an error
    }

    // Method 2: fgets and sscanf (more robust)
    char line[100];

    printf("\nReading data from file:\n"); // Separate the output

    while (fgets(line, sizeof(line), fp_read) != NULL)
    {
        if (sscanf(line, "%d,%d,%d", &a, &b, &c) == 3)
        {
            printf("a = %d\tb = %d\tc = %d\n", a, b, c);
        }
        else
        {
            fprintf(stderr, "Error: Invalid line format: %s", line);
        }
    }

    fclose(fp_read);
    return 0;
}