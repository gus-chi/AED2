#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "quick-sort.h"

void setUp(){
}
void tearDown(){

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
int main(void){
    UNITY_BEGIN();
    RUN_TEST(testPartition);
    UNITY_END();   
    return 0;
}