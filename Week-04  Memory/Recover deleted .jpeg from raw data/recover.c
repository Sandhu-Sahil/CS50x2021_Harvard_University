#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
#include <ctype.h>

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover forensicfilename.raw\n");
        return 1;
    }
    
    //
    FILE *raw = fopen(argv[1], "r");
    if (raw == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }
    
    //
    FILE *jpeg;
    BYTE block[512];
    bool foundjpeg = false;
    int readblock;
    int jpegnum = 0;
    
    //
    while (fread(block, sizeof(block), 1, raw) == 1)
    {
        //
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            char filename[8];
            
            //
            sprintf(filename, "%03.3i.jpg", jpegnum);   //important function and also fprintf check them on google 
            
            //
            printf("processing file: %s\n", filename);
            
            //
            if (foundjpeg == true)
            {
                fclose(jpeg);
            }
            else
            {
                foundjpeg = true;
            }
            
            //
            jpeg = fopen(filename, "w");
            fwrite(block, sizeof(block), 1, jpeg);
            
            jpegnum++;
        }
        //
        else
        {
            if (foundjpeg == true)
            {
                //
                fwrite(block, sizeof(block), 1, jpeg);
            }
        }
    }
    
    //
    fclose(raw);
    fclose(jpeg);
}