#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");

    uint8_t buffer[512];
    bool found_jpeg = false;
    FILE *jpeg_file = NULL;
    int file_count = 0;

    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            {
                if (jpeg_file != NULL)
                {
                    fclose(jpeg_file);
                }
            }

            char filename[8];
            sprintf(filename, "%03i.jpg", file_count++);
            jpeg_file = fopen(filename, "w");
            if (jpeg_file == NULL)
            {
                fclose(card);
                fprintf(stderr, "Couldn't create JPEG %s\n", filename);
            }

            fwrite(buffer, 1, 512, jpeg_file);
            found_jpeg = true;
        }
        else
        {
            if (found_jpeg)
            {
                fwrite(buffer, 1, 512, jpeg_file);
            }
        }
    }

    if (jpeg_file != NULL)
    {
        fclose(jpeg_file);
    }

    fclose(card);
}
