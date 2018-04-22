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

#include <stdio.h>
#include <stdlib.h>

#include "unity_fixture.h"

#include "example/example.h"

static char *key = "test_key";
static char *val = "test_val";
static example_t *example = NULL;

TEST_GROUP(example);

TEST_SETUP(example) {
    example = example_new_with_cstr(key, val);
}

TEST_TEAR_DOWN(example) {
    if (example) {
        example_free(example);
    }
}

TEST(example, test_example_new_with_cstr) {
    TEST_ASSERT_EQUAL_STRING(key, example->key);
    TEST_ASSERT_EQUAL_STRING(val, example->val);
}

TEST_GROUP_RUNNER(example) {
    RUN_TEST_CASE(example, test_example_new_with_cstr);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST_GROUP(example);
    return UNITY_END();
}
