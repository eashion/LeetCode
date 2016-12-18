#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Solution.h"

using namespace std;

int main()
{
    vector<int> lis;
    vector<int> res;
    int target;
    int N;
    Solution s;
    scanf("%d",&target);
    scanf("%d",&N);
    for( int i = 0; i < N; i++ ){
        int a;
        scanf("%d",&a);
        lis.push_back(a);
    }
    res = s.twoSum(lis,target);
    for( int i = 0; i < (int)res.size(); i++ ){
        printf("%d ",res[i]);
    }
    return 0;
}
