#include <stdio.h> 
#include <stdlib.h>
#include "TomlLoader.h"

void load_object(char *object_name, TomlOptions &toml) {

}

char* load_text_file(char* filename) {
    /* declare a file pointer */
    FILE* file_to_compile;
    long numbytes;
    char* buffer;
    errno_t err;

    /* open an existing file for reading */
    err = fopen_s(&file_to_compile, filename, "r");
    if (err == 0) {

        /* quit if the file does not exist */
        if (file_to_compile == NULL) {
            return NULL;
        }

        /* Get the number of bytes */
        fseek(file_to_compile, 0L, SEEK_END);
        numbytes = ftell(file_to_compile);

        /* reset the file position indicator to
        the beginning of the file */
        fseek(file_to_compile, 0L, SEEK_SET);

        /* grab sufficient memory for the
        buffer to hold the text */
        buffer = (char*)calloc(numbytes, sizeof(char));

        /* memory error */
        if (buffer == NULL)
            return NULL;

        /* copy all the text into the buffer */
        fread(buffer, sizeof(char), numbytes, file_to_compile);
        fclose(file_to_compile);

        /* confirm we have read the file by
        outputing it to the console */
        printf("Toml File Contents: \n%s", buffer);

        /* return file contents*/
        return buffer;
    }

    //error loading file
    printf("Unable to load %s\n", filename);
    exit(-1);
}
