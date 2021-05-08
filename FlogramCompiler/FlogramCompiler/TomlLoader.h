
#pragma once
#define string_max_size 1000

#include "toml.h"

struct TomlOptions {
    //Initialize Variables to defaults
    char start_toml[string_max_size];
    char start_object[string_max_size];
    char start_folder[string_max_size];
    char start_function[string_max_size];
    char start_params[string_max_size];


};

void load_toml_file(TomlOptions& toml, char* filename);
void initialize_toml(TomlOptions& toml, toml_table_t* conf);

void initialize_toml_start(TomlOptions& toml, toml_table_t* conf);