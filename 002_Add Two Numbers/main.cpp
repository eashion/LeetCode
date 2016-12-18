#include <iostream>
#include <bits/stdc++.h>
#include "Solution.h"

using namespace std;

int main(){
    int len1,len2;
    scanf("%d%d",&len1,&len2);
    Solution s;
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(0);
    ListNode* tmp = l1;
    for( int i = 0; i < len1; i++ ){
        scanf("%d",&tmp->val);
        if( i != len1-1 ){
            tmp->next = new ListNode(0);
            tmp = tmp->next;
        }
    }
    tmp = l2;
    for( int i = 0; i < len2; i++ ){
        scanf("%d",&tmp->val);
        if( i != len2-1 ){
            tmp->next = new ListNode(0);
            tmp = tmp->next;
        }
    }
    ListNode* res = s.addTwoNumbers(l1,l2);
    while( res != NULL ){
        printf("%d ",res->val);
        res = res->next;
    }
    return 0;
}
