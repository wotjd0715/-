#include <cstdio>
int testcase;
int day;
int data[100000];
int ans=0;
int bignum1_index=0;
int bignum2_index=0;
int x=0;

int main(){
    scanf("%d",&testcase);
    for(int b=0; b<testcase; b++){
        scanf("%d",&day);
        for(int c=0; c<day; c++){
            scanf("%d", &data[c]);
            data[c+1] = 0;
        }
        while((x+1)!=day){
            for(int d=x+1; d<day+1; d++){
                if(data[d-1]>data[d]){
                    if(bignum1_index==0){
                        bignum1_index = d-1; // ÀÎµ¦½º ÀúÀå
                    }
                    else{
                        bignum2_index = d-1;
                        if(data[bignum1_index]<data[bignum2_index]){
                            bignum1_index = bignum2_index;
                        }
                    }
                }
            }
            for(int i=x+1; i<bignum1_index+1; i++){
                ans += data[bignum1_index] - data[i-1];
            }
            x = bignum1_index;
            bignum1_index = 0;
        }

        printf("#%d %d",b+1, ans);
    }
}
