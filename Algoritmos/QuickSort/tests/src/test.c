#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "quick-sort.h"

void setUp(){
}
void tearDown(){

}
void testMedian(){
    int array[] = {5, 7, 3, 9, 4};
    TEST_ASSERT_EQUAL(2, MedianOfThree(array, 0, 4));
    TEST_ASSERT_EQUAL(4, array[2]);
    //TEST_ASSERT_EQUAL(2, MedianOfThree(2, 1, 20));
    //TEST_ASSERT_EQUAL(20, MedianOfThree(1, 25, 20));
    //TEST_ASSERT_EQUAL(5, MedianOfThree(5, 5, 5));
    //TEST_ASSERT_EQUAL(6, MedianOfThree(20, 6, 1));
}
void testPartition(){
    int array[] = {5, 7, 3, 9, 4};
    TEST_ASSERT_EQUAL(1, Partition(array, 0, 4));
    TEST_ASSERT_EQUAL(array[0], 3);
    TEST_ASSERT_EQUAL(array[1], 4);
    TEST_ASSERT_EQUAL(array[2], 5);
    TEST_ASSERT_EQUAL(array[3], 9);
    TEST_ASSERT_EQUAL(array[4], 7);
}
void testOptimizedPartition(){
    int array[] = {19, 42, 20, 57, 53};
    TEST_ASSERT_EQUAL(1, OptimizedPartition(array, 0, 4));
    TEST_ASSERT_EQUAL(array[0], 19);
    TEST_ASSERT_EQUAL(array[1], 20);
    TEST_ASSERT_EQUAL(array[2], 57);
    TEST_ASSERT_EQUAL(array[3], 42);
    TEST_ASSERT_EQUAL(array[4], 53);
}
int main(void){
    UNITY_BEGIN();
    RUN_TEST(testPartition);
    RUN_TEST(testOptimizedPartition);
    RUN_TEST(testMedian);
    UNITY_END();   
    return 0;
}