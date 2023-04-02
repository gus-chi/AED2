#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "merge-sort.h"

void setUp(){

}
void tearDown(){

}
void testMergeSort(){
    TEST_ASSERT_EQUAL(NULL, MergeSort(NULL, 0, 0));
}
int main(void){
    UNITY_BEGIN();
    RUN_TEST(testMergeSort);
    UNITY_END();   
    return 0;
}