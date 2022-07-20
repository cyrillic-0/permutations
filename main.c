#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int factorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}


void num_increment(int * arr, int size) {
    int reset_inc = size-1;
    arr[size-1]++;
    while (reset_inc) {
        if (arr[reset_inc] == size) {
            arr[reset_inc] = 0;
            arr[reset_inc-1]++;
        }
        reset_inc--;
    }
}


bool is_unique(int * arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                continue;
            }
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true;
}


char ** permutations(const char * str, int * ret_size) {
    int len = strlen(str);
    int perms = factorial(len);
    int * indices = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        indices[i] = 0;
    }

    char ** ret = (char **)malloc(sizeof(char *) * perms);
    for (int i = 0; i < perms; i++) {
        ret[i] = (char *)malloc(len);
    }

    for (int i = 0; i < perms;) {
        if (is_unique(indices, len)) {
            for (int j = 0; j < len; j++) {
                ret[i][j] = str[indices[j]];
            }
            i++;
        }
        num_increment(indices, len);
    }

    free(indices);
    *ret_size = perms;
    return ret;
}




int main() {
    char text[256];
    for (int i = 0; i < 256; i++) {
        text[i] = 0;
    }
    printf("Enter text(max. 256 characters): ");
    scanf("%s", &text);
    int sz = 0;

    char ** prms = permutations(text, &sz);
    for (int i = 0; i < sz; i++) {
        printf("%s\n", prms[i]);
    } 

    for (int i = 0; i < sz; i++) {
        free(prms[i]);
    }
    free(prms);
    return 0;
}
