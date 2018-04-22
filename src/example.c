/*
 * Copyright (c) 2018 Peter Nelson (peter@peterdn.com)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "example/example.h"

example_t * example_new_with_cstr(char *key, char *val) {
    example_t *ret = (example_t *) calloc(1, sizeof(example_t));
    if (!ret) {
        return NULL;
    }

    ret->key_length = strlen(key) + 1;
    ret->val_length = strlen(val) + 1;

    ret->key = (uint8_t *) calloc(ret->key_length, sizeof(char));
    if (!ret->key) {
        goto cleanup_ret;
    }
    strncpy(ret->key, key, ret->key_length);


    ret->val = (uint8_t *) calloc(ret->val_length, sizeof(char));
    if (!ret->val) {
        goto cleanup_key;
    }
    strncpy(ret->val, val, ret->val_length);

    return ret;

cleanup_key:
    free(ret->key);
cleanup_ret:
    free(ret);
    return NULL;
}

void example_print_cstr(example_t *example) {
    printf("key: %s (%lu bytes)\n", example->key, example->key_length);
    printf("val: %s (%lu bytes)\n", example->val, example->val_length);
}

void example_free(example_t *example) {
    if (example != NULL) {
        if (example->key != NULL) {
            free(example->key);
        }
        if (example->val != NULL) {
            free(example->val);
        }
        free(example);
    }
}
