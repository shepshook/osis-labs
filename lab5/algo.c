#include "algo.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <pthread.h>

const int MAX_THREADS = 100;

float run_calc_from_dir(char* dirname) {

    pthread_t* threads = malloc(sizeof(pthread_t) * MAX_THREADS);
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    DIR* dir;
    struct dirent* de;
    dir = opendir(dirname);
    float sum = 0;

    int th_count = 0;
    if (dir) {
        while ((de = readdir(dir)) != NULL) {
            if (de->d_type != DT_REG) 
                continue;

            char* filename = malloc(sizeof(char) * 255);
            strcpy(filename, dirname);
            strcat(filename, "/");
            strcat(filename, de->d_name);

            pthread_create(&(threads[th_count++]), &attr, run_calc, filename);
        }

        closedir(dir);
    }

    for (int i = 0; i < th_count; i++) {
        float* res;
        pthread_join(threads[i], &res);
        sum += *res;
    }

    return sum;
}

void* run_calc(void* param) {
    
    char* filename = param;

    FILE* f = fopen(filename, "r");
    // free(filename);
    if (f == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    int op;
    fscanf(f, "%d", &op);

    // start value is 1 if operation is *
    float* result = malloc(sizeof(float));
    *result = op == 2 ? 1 : 0;
    float next;
    while (fscanf(f, "%g", &next) == 1) {
        switch (op) {
            case 1:
                *result += next;
                break;
            case 2:
                *result *= next;
                break;
            case 3:
                *result += next * next;
                break;
            default:
                printf("Unknown operation number: %d", op);
                fclose(f);
                return NULL;
        }
    }
    fclose(f);

    return result;
}