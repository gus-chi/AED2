#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "unity.h"
#include "heap-sort.h"

// Array para testar BuildMaxHeap Normal

int * array = NULL;
int *array_copy = NULL;

// Array para testar Build MaxHeap Prioridade

int *array_test_priority = NULL;
int *array_key = NULL;

// Array para testar Build MaxHeapString

char** string = NULL;
char** string2 = NULL;

char *p1 = NULL;
char *p2 = NULL;

char *palavra1 = NULL;
char *palavra2 = NULL;
char *palavra3 = NULL;
char *palavra4 = NULL;
char *palavra5 = NULL;
char *palavra6 = NULL;

char *string_key = NULL;
char *string_key2 = NULL;

void setUp(){
    // Build MaxHeap
    array = malloc(6*sizeof *array);
    array[0] = 1; 
    array[1] = 2;
    array[2] = 4;
    array[3] = 7;
    array[4] = 5;
    array[5] = 10;
    array_copy = malloc(6*sizeof *array_copy);
    array_copy[0] = 1; 
    array_copy[1] = 2;
    array_copy[2] = 4;
    array_copy[3] = 7;
    array_copy[4] = 5;
    array_copy[5] = 10;
    
    // Build MaxHeapPriority

    array_test_priority = malloc(7*sizeof *array_test_priority);
    array_test_priority[0] = 10;
    array_test_priority[1] = 7;
    array_test_priority[2] = 4;
    array_test_priority[3] = 2;
    array_test_priority[4] = 1;
    array_test_priority[5] = 4;
    array_test_priority[6] = 4;
    array_key = malloc(7*sizeof *array_key);
    array_key[0] = 1;
    array_key[1] = 2;
    array_key[2] = 4;
    array_key[3] = 7;
    array_key[4] = 5;
    array_key[5] = 10;

    // Build MaxHeap String

    string = malloc(2* sizeof *string);
    string[0] = malloc(4* sizeof **string);
    string[1] = malloc(5* sizeof **string);
    strcpy(string[0], "paz");
    strcpy(string[1], "amor");

    string_key = malloc(7*sizeof *string_key);
    strcpy(string_key, "pzmora");
    
    // Build MaxHeap String 2

    string2 = malloc(6*sizeof *string2);
    string2[0] = malloc(7*sizeof **string);
    string2[1] = malloc(5*sizeof **string);
    string2[2] = malloc(8*sizeof **string);
    string2[3] = malloc(6*sizeof **string);
    string2[4] = malloc(8*sizeof **string);
    string2[5] = malloc(8*sizeof **string);
    strcpy(string2[0], "banana");
    strcpy(string2[1], "maca");
    strcpy(string2[2], "laranja");
    strcpy(string2[3], "limao");
    strcpy(string2[4], "acerola");
    strcpy(string2[5], "morango");
    string_key2 = malloc(14*sizeof *string_key2);
    strcpy(string_key2, "lanmcreogjitb");
}
void tearDown(){
    free(array);   
}
void testSwap(){
    Swap(array, 0, 5);
    TEST_ASSERT_EQUAL(10, array[0]);
    TEST_ASSERT_EQUAL(1, array[5]);
}
void testSwapString(){
    SwapString(string, 0, 1);
    TEST_ASSERT_EQUAL(1, !strcmp("amor", string[0]));
    TEST_ASSERT_EQUAL(1, !strcmp("paz", string[1]));
}
void testPriority(){
    TEST_ASSERT_EQUAL(4,FirstPriority(array_key, 4, 4, 6));
    TEST_ASSERT_EQUAL(4,FirstPriority(array_key, 4, 7, 6));
    TEST_ASSERT_EQUAL(1,FirstPriority(array_key, 1, 10, 6));
}
void testStringPriority(){
    TEST_ASSERT_EQUAL('p',StringPriority(string_key, 'p', 'z', 7));
    TEST_ASSERT_EQUAL('m', StringPriority(string_key, 'm', 'a', 7));
}
void testBuildMaxHeap(){
    BuildMaxHeap(array, 5);
    TEST_ASSERT_EQUAL(10, array[0]);
    TEST_ASSERT_EQUAL(7, array[1]);
    TEST_ASSERT_EQUAL(4, array[2]);
    TEST_ASSERT_EQUAL(2, array[3]);
    TEST_ASSERT_EQUAL(5, array[4]);
    TEST_ASSERT_EQUAL(1, array[5]);
}
void testMaxHeapfy(){
    MaxHeapfy(array_copy, 5, 0);
    TEST_ASSERT_EQUAL(4, array_copy[0]);
    TEST_ASSERT_EQUAL(10, array_copy[2]);
    TEST_ASSERT_EQUAL(1, array_copy[5]);
    MaxHeapfy(array, 5, 2);
    TEST_ASSERT_EQUAL(10, array[2]);
    TEST_ASSERT_EQUAL(4, array[5]);

}
void testBuildMaxHeapPriority(){
    BuildMaxHeapPriority(array_test_priority, 6, array_key,7);
    TEST_ASSERT_EQUAL(1, array_test_priority[0]);
    TEST_ASSERT_EQUAL(2, array_test_priority[1]);
    TEST_ASSERT_EQUAL(4, array_test_priority[2]);
    TEST_ASSERT_EQUAL(10, array_test_priority[3]);
    TEST_ASSERT_EQUAL(7, array_test_priority[4]);
    TEST_ASSERT_EQUAL(4, array_test_priority[5]);
    TEST_ASSERT_EQUAL(4, array_test_priority[6]);
}
void testMaxHeapfy2(){
    MaxHeapfy2(array_test_priority, 6, 2, array_key, 7);
    TEST_ASSERT_EQUAL(4, array_test_priority[2]);
    TEST_ASSERT_EQUAL(4, array_test_priority[5]);
    TEST_ASSERT_EQUAL(4, array_test_priority[6]);
    MaxHeapfy2(array_test_priority, 6, 1, array_key, 7);
    TEST_ASSERT_EQUAL(1, array_test_priority[1]);
    TEST_ASSERT_EQUAL(2, array_test_priority[3]);
    TEST_ASSERT_EQUAL(7, array_test_priority[4]);
    MaxHeapfy2(array_test_priority, 6, 0, array_key, 7);
    TEST_ASSERT_EQUAL(1, array_test_priority[0]);
    TEST_ASSERT_EQUAL(2, array_test_priority[1]);
    TEST_ASSERT_EQUAL(4, array_test_priority[2]);
    TEST_ASSERT_EQUAL(10, array_test_priority[3]);
    TEST_ASSERT_EQUAL(7, array_test_priority[4]);
    TEST_ASSERT_EQUAL(4, array_test_priority[5]);
    TEST_ASSERT_EQUAL(4, array_test_priority[6]);
}
void testBuildMaxHeapString(){
    BuildMaxHeapString(string, 1, string_key, 7);
    TEST_ASSERT_EQUAL(1, !strcmp("paz", string[0]));
    TEST_ASSERT_EQUAL(1, !strcmp("amor", string[1]));
    BuildMaxHeapString(string2, 5, string_key2, 14);
    TEST_ASSERT_EQUAL(1, !strcmp("laranja", string2[0]));
    TEST_ASSERT_EQUAL(1, !strcmp("limao", string2[1]));
    TEST_ASSERT_EQUAL(1, !strcmp("morango", string2[2]));
    TEST_ASSERT_EQUAL(1, !strcmp("maca", string2[3]));
    TEST_ASSERT_EQUAL(1, !strcmp("acerola", string2[4]));
    TEST_ASSERT_EQUAL(1, !strcmp("banana", string2[5]));
}
void testHeapExtractMax(){
    int v = 5;
    BuildMaxHeapString(string2, v, string_key2, 14);
    TEST_ASSERT_EQUAL(1, !strcmp("laranja", HeapExtractMax(string2, &v, string_key2, 14)));
    TEST_ASSERT_EQUAL(1, !strcmp("limao", HeapExtractMax(string2, &v, string_key2, 14)));
    TEST_ASSERT_EQUAL(1, !strcmp("acerola", HeapExtractMax(string2, &v, string_key2, 14)));
    TEST_ASSERT_EQUAL(1, !strcmp("maca", HeapExtractMax(string2, &v, string_key2, 14)));
    TEST_ASSERT_EQUAL(1, !strcmp("morango", HeapExtractMax(string2, &v, string_key2, 14)));
    TEST_ASSERT_EQUAL(1, !strcmp("banana", HeapExtractMax(string2, &v, string_key2, 14)));

}
int main(void){
    UNITY_BEGIN();
    RUN_TEST(testSwap);
    RUN_TEST(testSwapString);
    RUN_TEST(testPriority);
    RUN_TEST(testStringPriority);
    RUN_TEST(testMaxHeapfy);
    RUN_TEST(testBuildMaxHeap);
    RUN_TEST(testBuildMaxHeapPriority);
    RUN_TEST(testMaxHeapfy2);
    RUN_TEST(testBuildMaxHeapString);
    RUN_TEST(testHeapExtractMax);
    UNITY_END();   
    return 0;
}