#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "list.h"

void setUp(){

}
void tearDown(){

}
void testDivideList(){
    List* list = InstantiateList();
    Node* head = InstantiateNode(7);
    Node* no1 = InstantiateNode(6);
    Node* no2 = InstantiateNode(5);
    Node* no3 = InstantiateNode(4);
    PushTail(list, head);
    PushTail(list, no1);
    PushTail(list, no2);
    PushTail(list, no3);
    Node* left_head, *right_head;
    left_head = right_head = NULL;
    DivideList(list->head, &left_head, &right_head);
    TEST_ASSERT_EQUAL(head, left_head);
    TEST_ASSERT_EQUAL(no2, right_head);

}
//void testMergeSort(){
//    TEST_ASSERT_EQUAL(NULL, MergeSort(NULL, 0, 0));
//}
int main(void){
    UNITY_BEGIN();
    RUN_TEST(testDivideList);
    UNITY_END();   
    return 0;
}