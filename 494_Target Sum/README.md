**题意：**通过改变加减号得到指定的target；  
**思路：**最直观的思路就是dfs搜索，但是效率并不是很好。看到别人dp的解法十分巧妙。  
*dp解法：因为题目中仅包含正号与负号，所以可以把所有数分为positive和negative。也就得到下面等式：  
sum(P)-sum(N)=target  
sum(P)-sum(N)+sum(P)+sum(N)=target+sum  
2*sum(P)=target+sum  
由此转化为一个01背包问题，在(target<sum) && (target+sum)%2==0 的情况下，求出能组合得到P的次数。
