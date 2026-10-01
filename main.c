#include "file_loader.h"
#include "lexer.h"
#include "status.h"
#include <stdio.h>


int main(void) {
    Status status = NO_ERROR;
    FileString test_file;
    TokenPointer tokenpointer;
    size_t line_count = 0;
    size_t i = 0;

    status = load_file_to_memory("test.txt", &test_file);
    if (status != NO_ERROR) {
        status_print(status);
        return 1;
    }

    for (i = 0; i < 5; i++) {
        tokenpointer = lexer_scan(&test_file, &line_count);
        printf("%d \n", tokenpointer.token);
        printf("%ld, %ld \n", tokenpointer.start, tokenpointer.len);
    }

    return 0;
}
