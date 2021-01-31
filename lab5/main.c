#include <stdio.h>
#include <stdlib.h>
#include "algo.h"

// const int MAX_THREADS = 16;

int main(int argc, char** argv) {
    char* dirname;
    char* result_filename;
    if (argc != 3) {
        printf("%s\n", "Usage: \tthreads <in_dir> <out_file>");
        return 1;
    }

    dirname = argv[1];
    result_filename = argv[2];

    float result = run_calc_from_dir(dirname);

    FILE* out = fopen(result_filename, "w");
    if (out == NULL) {
        printf("Output file cannot be opened: %s", result_filename);
        return 1;
    }

    fprintf(out, "%g\n", result);
    return 0;
}
