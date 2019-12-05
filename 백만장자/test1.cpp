#include<cstdio>
int test;
int day;
int cost[100];
int profit;
int check;
int highest;
int start;
int main()
{
   scanf("%d",&test);
   for(int i =1; i <= test; i++){
    scanf("%d",&day);
        for(int i=0; i<day; i++){
        scanf("%d",&cost[i]);
        }
        check =0;
        highest=0;
        profit = 0;
        while(true){
            for(int i=highest; i<day-1; i++){
                if(cost[highest]<cost[i+1]){
                highest=i+1;
                }
            }
            if(check==highest){
                break;
            }
            for(int i = check; i< highest; i++){
                profit += cost[highest]-cost[i];
            }
            highest = highest + 1;
            check = highest;
        }
   printf("#%d %d\n",i,profit);
   }

}
