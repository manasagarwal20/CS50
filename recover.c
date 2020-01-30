#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //ensure correct input
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover <filename>\n");
        return 1;
    }

    // file open
    char *file = argv[1];
    FILE *inputfile = fopen(file, "r");
    if (inputfile == NULL)
    {
        fprintf(stderr, "Can't read file\n");
        return 2;
    }

    //read buffer
    uint8_t buffer[512];
    int filecounter = 0;
    FILE *outfile = NULL;


    while (fread(buffer, 512, 1, inputfile))
    {
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (outfile != NULL)
            {
                fclose(outfile);
            }
            char filename[8];
            sprintf(filename, "%03d.jpg", filecounter);
            outfile = fopen(filename, "w");
            filecounter++;
        }
        if (outfile != NULL)
        {
            fwrite(buffer, 512, 1, outfile);
        }
    }


    if (outfile != NULL)
    {
        fclose(outfile);
    }

    fclose(inputfile);
    return 0;

}
