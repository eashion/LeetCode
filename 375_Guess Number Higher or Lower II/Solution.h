public class Solution {
    public int getMoneyAmount(int n) {
        int[][] dp = new int[n+1][n+1];
        return getCost(dp,1,n);
    }
    int getCost(int[][] dp,int s,int e){
        if( s >= e ){
            return 0;
        }
        if( dp[s][e] != 0 ){
            return dp[s][e];
        }
        int res = Integer.MAX_VALUE;
        for( int i = s; i <= e; i++ ){
            int tmp = i + Math.max(getCost(dp,s,i-1),getCost(dp,i+1,e));
            res = Math.min(res,tmp);
        }
        return dp[s][e] = res;
    }
}
