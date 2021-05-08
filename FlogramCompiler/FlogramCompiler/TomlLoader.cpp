#include "TomlLoader.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

static void error(const char* msg, const char* msg1)
{
    fprintf(stderr, "ERROR: %s%s\n", msg, msg1 ? msg1 : "");
    exit(1);
}

void load_toml_file(TomlOptions& toml, char* filename) {
    FILE* fp;
    char errbuf[200];

    // 1. Read and parse toml file
    errno_t err = fopen_s(&fp, filename, "r");

    if (err != 0) {
        strerror_s(errbuf, 200, errno);
        error("cannot open starting toml file - ", errbuf);
        exit(0);
    }

    toml_table_t* conf = toml_parse_file(fp, errbuf, sizeof(errbuf));

    if (fp != 0) {
        fclose(fp);
    }

    if (!conf) {
        error("cannot parse - ", errbuf);
    }

    initialize_toml(toml, conf);

    return;
}

void initialize_toml(TomlOptions& toml, toml_table_t* conf) {
    initialize_toml_start(toml, conf);
}

void initialize_toml_start(TomlOptions& toml, toml_table_t* conf) {
    strcpy_s(toml.start_object, 1000, "start.flo");
    strcpy_s(toml.start_folder, 1000, ".");
    strcpy_s(toml.start_function, 1000, "start");
    strcpy_s(toml.start_params, 1000, "");

    //[Start]
    toml_table_t* start_info = toml_table_in(conf, "Start");
    if (start_info) {
        //start_object
        toml_datum_t start_object_toml = toml_string_in(start_info, "start_object");
        if (start_object_toml.ok) {
            strcpy_s(toml.start_object, 1000, start_object_toml.u.s);
        }

        //start_folder
        toml_datum_t start_folder_toml = toml_string_in(start_info, "start_folder");
        if (start_folder_toml.ok) {
            strcpy_s(toml.start_folder, 1000, start_folder_toml.u.s);
        }

        //start_function
        toml_datum_t start_function_toml = toml_string_in(start_info, "start_function");
        if (start_function_toml.ok) {
            strcpy_s(toml.start_function, 1000, start_function_toml.u.s);
        }

        //start_function
        toml_datum_t start_params_toml = toml_string_in(start_info, "start_params");
        if (start_params_toml.ok) {
            strcpy_s(toml.start_params, 1000, start_params_toml.u.s);
        }
    }
}

void initialize_toml_libraries(TomlOptions& toml, toml_table_t* conf) {
    
    //[Libraries]
    toml_table_t* start_info = toml_table_in(conf, "Start");
    if (start_info) {
        //start_object
        toml_datum_t start_object_toml = toml_string_in(start_info, "start_object");
        if (start_object_toml.ok) {
            strcpy_s(toml.start_object, 1000, start_object_toml.u.s);
        }

        //start_folder
        toml_datum_t start_folder_toml = toml_string_in(start_info, "start_folder");
        if (start_folder_toml.ok) {
            strcpy_s(toml.start_folder, 1000, start_folder_toml.u.s);
        }

        //start_function
        toml_datum_t start_function_toml = toml_string_in(start_info, "start_function");
        if (start_function_toml.ok) {
            strcpy_s(toml.start_function, 1000, start_function_toml.u.s);
        }

        //start_function
        toml_datum_t start_params_toml = toml_string_in(start_info, "start_params");
        if (start_params_toml.ok) {
            strcpy_s(toml.start_params, 1000, start_params_toml.u.s);
        }
    }
}