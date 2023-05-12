#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "counting-sort.h"

void CompleteWithSpaces(char* string, int max){
    while(strlen(string) < max)
        strcat(string, " ");
}

int *array_test = NULL;
int *freq_array_test = NULL;
int *position_array_test = NULL;

int *array_test_priority = NULL;
int *freq_array_test_priority = NULL;
int *position_array_test_priority = NULL;
int *key_test_priority = NULL;


char **array_strings = NULL;
int *freq_array_test_string = NULL;
char *key_test = NULL;
char *key_test_2 = NULL;
void setUp(){
    int i, j;

    // Iniciando Array CountingSort Inteiros
    array_test = malloc(7 * sizeof *array_test);
    for(i=8, j=0; j < 7; i--, j++)
        array_test[j] = i;
    freq_array_test = InstantiateFreqArray(8);

    // Iniciando Arrays CountingSort prioridade
    array_test_priority = malloc(8 * sizeof *array_test);
    for(i=8, j=0; j < 6; i--, j++)
        array_test_priority[j] = i;
    array_test_priority[6] = array_test_priority[7] = 2;
    key_test_priority = malloc(7 * sizeof *key_test_priority);
    key_test_priority[0] = 5;
    key_test_priority[1] = 7;
    key_test_priority[2] = 2;
    key_test_priority[3] = 8;
    key_test_priority[4] = 3;
    key_test_priority[5] = 6;
    key_test_priority[6] = 4;
    freq_array_test_priority = InstantiateFreqArray(8);

    // Iniciando Arrays CountingSort Strings e respectivas chaves
    array_strings = malloc(7 * sizeof *array_strings);
    for(i=0; i<7; i++)
        array_strings[i] = malloc(21 * sizeof *array_strings[i]);
    strcpy(array_strings[0], "programar");
    strcpy(array_strings[1], "legal");
    strcpy(array_strings[2], "vamos");
    strcpy(array_strings[3], "eh");
    strcpy(array_strings[4], "futebol");
    strcpy(array_strings[5], "computador");
    strcpy(array_strings[6], "palavra");
    for(i=0; i< 7; i++)
        CompleteWithSpaces(array_strings[i], 10);
    freq_array_test_string = InstantiateFreqArray(26);
    key_test = malloc(27 * sizeof *key_test);
    for(i=0; i<26; i++)
        key_test[i] = 97+i;
    key_test_2 = malloc(27 * sizeof *key_test_2);
    for(i=0, j=25; i<26; i++, j--)
        key_test_2[i] = 97+j;
}
void tearDown(){

}
void testFindMax(){
    TEST_ASSERT_EQUAL(8, FindMax(array_test, 7));
}
void testInstantiateFreqArray(){
    TEST_ASSERT_EQUAL(0, freq_array_test[0]);
    TEST_ASSERT_EQUAL(0, freq_array_test[1]);
    TEST_ASSERT_EQUAL(0, freq_array_test[2]);
    TEST_ASSERT_EQUAL(0, freq_array_test[3]);
    TEST_ASSERT_EQUAL(0, freq_array_test[4]);
    TEST_ASSERT_EQUAL(0, freq_array_test[5]);
    TEST_ASSERT_EQUAL(0, freq_array_test[6]);
    TEST_ASSERT_EQUAL(0, freq_array_test[7]);
    TEST_ASSERT_EQUAL(0, freq_array_test[8]);
}
void testFillFreqArray(){
    FillFreqArray(array_test, 7, freq_array_test);
    TEST_ASSERT_EQUAL(0, freq_array_test[0]);
    TEST_ASSERT_EQUAL(0, freq_array_test[1]);
    TEST_ASSERT_EQUAL(1, freq_array_test[2]);
    TEST_ASSERT_EQUAL(1, freq_array_test[3]);
    TEST_ASSERT_EQUAL(1, freq_array_test[4]);
    TEST_ASSERT_EQUAL(1, freq_array_test[5]);
    TEST_ASSERT_EQUAL(1, freq_array_test[6]);
    TEST_ASSERT_EQUAL(1, freq_array_test[7]);
    TEST_ASSERT_EQUAL(1, freq_array_test[8]);
}
void testInstantiatePositionArray(){
    FillFreqArray(array_test, 7, freq_array_test);
    position_array_test = InstantiatePositionArray(freq_array_test, 8);
    TEST_ASSERT_EQUAL(0, position_array_test[0]);
    TEST_ASSERT_EQUAL(0, position_array_test[1]);
    TEST_ASSERT_EQUAL(1, position_array_test[2]);
    TEST_ASSERT_EQUAL(2, position_array_test[3]);
    TEST_ASSERT_EQUAL(3, position_array_test[4]);
    TEST_ASSERT_EQUAL(4, position_array_test[5]);
    TEST_ASSERT_EQUAL(5, position_array_test[6]);
    TEST_ASSERT_EQUAL(6, position_array_test[7]);
    TEST_ASSERT_EQUAL(7, position_array_test[8]);
}
void testCountingSort(){
    array_test = CountingSort(array_test, 7);
    TEST_ASSERT_EQUAL(2, array_test[0]);
    TEST_ASSERT_EQUAL(3, array_test[1]);
    TEST_ASSERT_EQUAL(4, array_test[2]);
    TEST_ASSERT_EQUAL(5, array_test[3]);
    TEST_ASSERT_EQUAL(6, array_test[4]);
    TEST_ASSERT_EQUAL(7, array_test[5]);
    TEST_ASSERT_EQUAL(8, array_test[6]);
}
void testInstantiatePositionArrayPriority(){
    FillFreqArray(array_test_priority, 8, freq_array_test_priority);
    position_array_test = InstantiatePositionArrayPriority(freq_array_test_priority, 8, key_test_priority, 7);
    TEST_ASSERT_EQUAL(0, position_array_test[0]);
    TEST_ASSERT_EQUAL(0, position_array_test[1]);
    TEST_ASSERT_EQUAL(4, position_array_test[2]);
    TEST_ASSERT_EQUAL(6, position_array_test[3]);
    TEST_ASSERT_EQUAL(8, position_array_test[4]);
    TEST_ASSERT_EQUAL(1, position_array_test[5]);
    TEST_ASSERT_EQUAL(7, position_array_test[6]);
    TEST_ASSERT_EQUAL(2, position_array_test[7]);
    TEST_ASSERT_EQUAL(5, position_array_test[8]);
}
void testCountingSortPriority(){
    array_test_priority = CountingSortPriority(array_test_priority, 8, key_test_priority, 7);
    TEST_ASSERT_EQUAL(5, array_test_priority[0]);
    TEST_ASSERT_EQUAL(7, array_test_priority[1]);
    TEST_ASSERT_EQUAL(2, array_test_priority[2]);
    TEST_ASSERT_EQUAL(2, array_test_priority[3]);
    TEST_ASSERT_EQUAL(8, array_test_priority[4]);
    TEST_ASSERT_EQUAL(3, array_test_priority[5]);
    TEST_ASSERT_EQUAL(6, array_test_priority[6]);
    TEST_ASSERT_EQUAL(4, array_test_priority[7]);
}
void testFillFreqArrayString(){
    FillFreqArrayString(array_strings, 7, 9, freq_array_test_string);
    TEST_ASSERT_EQUAL(6, freq_array_test_string[0]);
    TEST_ASSERT_EQUAL(1, freq_array_test_string[18]);
}
void testCountingSortString(){
    CountingSortString(array_strings, 7, 9, key_test);
    //TEST_ASSERT_EQUAL();
}
int main(void){
    UNITY_BEGIN();
    RUN_TEST(testFindMax);
    RUN_TEST(testInstantiateFreqArray);
    RUN_TEST(testFillFreqArray);
    RUN_TEST(testInstantiatePositionArray);
    RUN_TEST(testCountingSort);
    RUN_TEST(testInstantiatePositionArrayPriority);
    RUN_TEST(testCountingSortPriority);
    RUN_TEST(testFillFreqArrayString);
    UNITY_END();   
    return 0;
}