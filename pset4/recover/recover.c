#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>



int main(int argc, char *argv[])
{

    //Jpeg No.
    int jn = 0;
    //File Name
    char filename[8];
    FILE *img = NULL;
    bool injpg = false;


    //Usage Corrections
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //Open file for read only
    FILE *file = fopen(argv[1], "r");

    //a buffer(middle) file to copy from the memory card
    unsigned char buffer[512];

    while (fread(buffer, 512, 1, file) == 1)
    {
        //read into buffer 512 bytes <<
       

        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (injpg == true)
            {
                // We found the start of a new pic so close out current picture
                fclose(img);
            }
            else
            injpg = true;


            sprintf(filename, "%03i.jpg", jn);
            img = fopen(filename, "w");
            
            jn++;

        }
        if(injpg == true)
        {
            fwrite(buffer, 512, 1, img);
        }
    }

    fclose(img);
    fclose(file);
    
}
