#ifndef MYC_TEST_HELPER_H
#define MYC_TEST_HELPER_H

#ifndef TEST_ASSERT_FAIL

#define TEST_ASSERT_FAIL(T) \
    printf("[ FAIL ] %s: it should pass a test\n", T); return 1;

#endif


#ifndef TEST_ASSERT_TRUE

#define TEST_ASSERT_TRUE(A, T) \
    if (A != 0) { \
        printf("[ PASS ] %s\n", T); \
    } else { \
        printf("[ FAIL ] %s\n", T); return 1; \
    }

#endif


#ifndef TEST_ASSERT_NOT_NULL

#define TEST_ASSERT_NOT_NULL(A, T) \
    if (A != NULL) { \
        printf("[ PASS ] %s\n", T); \
    } else { \
        printf("[ FAIL ] %s\n", T); return 1; \
    }

#endif


#ifndef TEST_ASSERT_LT

#define TEST_ASSERT_LT(A, E, T) \
    if (A < E) { \
        printf("[ PASS ] %s\n", T); \
    } else { \
        printf("[ FAIL ] %s\n", T); return 1; \
    }

#endif


#ifndef TEST_ASSERT_LTE

#define TEST_ASSERT_LTE(A, E, T) \
    if (A <= E) { \
        printf("[ PASS ] %s\n", T); \
    } else { \
        printf("[ FAIL ] %s\n", T); return 1; \
    }

#endif


#ifndef TEST_ASSERT_GT

#define TEST_ASSERT_GT(A, E, T) \
    if (A > E) { \
        printf("[ PASS ] %s\n", T); \
    } else { \
        printf("[ FAIL ] %s\n", T); return 1; \
    }

#endif

#ifndef TEST_ASSERT_GTE

#define TEST_ASSERT_GTE(A, E, T) \
    if (A >= E) { \
        printf("[ PASS ] %s\n", T); \
    } else { \
        printf("[ FAIL ] %s\n", T); return 1; \
    }

#endif



#ifndef TEST_ASSERT_NEQ

#define TEST_ASSERT_NEQ(A, E, T) \
    if (A != E) { \
        printf("[ PASS ] %s\n", T); \
    } else { \
        printf("[ FAIL ] %s\n", T); return 1; \
    }

#endif


#ifndef TEST_ASSERT_EQ

#define TEST_ASSERT_EQ(A, E, T) \
    if (A == E) { \
        printf("[ PASS ] %s\n", T); \
    } else { \
        printf("[ FAIL ] %s\n", T); return 1; \
    }

#endif


#ifndef TEST_ASSERT_STR_EQ

#include "string.h"

#define TEST_ASSERT_STR_EQ(A, E, T) \
    if (strcmp(A, E) == 0) { \
        printf("[ PASS ] %s\n", T); \
    } else { \
        printf("[ FAIL ] %s\n  expected: %s\n  actual: %s\n", T, E, A); return 1; \
    }

#endif


#ifndef TEST_ASSERT_MEM_EQ

#include "string.h"

#define TEST_ASSERT_MEM_EQ(A, E, L, T) \
    if (memcmp(A, E, L) == 0) { \
        printf("[ PASS ] %s\n", T); \
    } else { \
        printf("[ FAIL ] %s\n  expected: %s\n  actual: %s\n", T, E, A); return 1; \
    }

#endif


#ifndef RUN_TEST

#define RUN_TEST(T) \
    printf("\n\n%s\n\n", #T); \
    if ((result = T())) { \
        printf("\n"); \
        printf("result: %d\n", result); \
        return result; \
    } printf("\n"); \

#endif

#endif
