#include <cstdio>

//x,y에 1000씩 더하기
int testcase;
int atom;
int coun=0;
int t;
int x;
int y;
int result;
int ma[2004][2004][2];
int main()
{
scanf("%d",&testcase);//get testcase
scanf("%d",&atom);//get number of atoms

int info[atom][2];//[each number of atoms][0=x,1=y]

for(int test=0; test<testcase; test++){
    for(int a =0; a <atom; a++){//get atoms info
        scanf("%d+1001 %d+1001",&x,&y);
        scanf("%d %d",&ma[x][y][0],&ma[x][y][1]);
    }
    for(int i=0; i<2005; i++){ //make atom's info as matrix
        for(int j=0; j <2005;j++){
        if(ma[i][j][1]!=0){
            info[coun][0]=i; info[coun][1]=j;
            coun++;
        }
    }}

    for(t=1; t<2002; t++){//loop until atoms go to the end of the range
        for(int a =0; a <atom; a++){//check all atoms
                /*each atom has their direction and position. we choose one main atom and check
                when they will conflict at first it will conflict with 1 distance atom has reverse direction
                 if it dose not conflict, plus 1 distance to main atom  as its direction and its around atom
                 has other direction at one time repeat it until find when main atom conflict. if the atom conflict
                 remove two at atom array and repeat to all atom array. the number of conflict is the total energy */
            if((ma[info[a][0]][info[a][1]][0]==0) && (ma[info[a][0]][info[a][1]+(2*(t-1)+1)][1]!=0)){
                    result += ma[info[a][0]][info[a][1]][1] + ma[info[a][0]][info[a][1]+(2*(t-1)+1)][1];
                    ma[info[a][0]][info[a][1]][1],ma[info[a][0]][info[a][1]+(2*(t-1)+1)][1] =0;
            }
            else if(ma[info[a][0]][info[a][1]][0]==0 && ma[info[a][0]-t][info[a][1]+t][1]!=0 ||
                     ma[info[a][0]][info[a][1]+2*t][1]!=0 ||  ma[info[a][0]+t][info[a][1]+t][1]!=0){
                            result += ma[info[a][0]][info[a][1]][0] + ma[info[a][0]-t][info[a][1]+t][1] +
                     ma[info[a][0]][info[a][1]+2*t][1] + ma[info[a][0]+t][info[a][1]+t][1];
                     ma[info[a][0]][info[a][1]][0],ma[info[a][0]-t][info[a][1]+t][1],
                     ma[info[a][0]][info[a][1]+2*t][1] , ma[info[a][0]+t][info[a][1]+t][1] = 0;
            }
            if(ma[info[a][0]][info[a][1]][0]==1 && ma[info[a][0]][info[a][1]-(2*(t-1)+1)][1]!=0){
                    result += ma[info[a][0]][info[a][1]][1] + ma[info[a][0]][info[a][1]-(2*(t-1)+1)][1];
                    ma[info[a][0]][info[a][1]][1],ma[info[a][0]][info[a][1]-(2*(t-1)+1)][1] =0;
            }
            else if(ma[info[a][0]][info[a][1]][0]==1 && ma[info[a][0]-t][info[a][1]-t][1]!=0 ||
                     ma[info[a][0]][info[a][1]-2*t][1]!=0 ||  ma[info[a][0]+t][info[a][1]-t][1]!=0){
                            result += ma[info[a][0]][info[a][1]][0] + ma[info[a][0]-t][info[a][1]-t][1] +
                     ma[info[a][0]][info[a][1]-2*t][1] + ma[info[a][0]+t][info[a][1]-t][1];
                     ma[info[a][0]][info[a][1]][0],ma[info[a][0]-t][info[a][1]-t][1],
                     ma[info[a][0]][info[a][1]-2*t][1] , ma[info[a][0]+t][info[a][1]-t][1] = 0;
            }
            if(ma[info[a][0]][info[a][1]][0]==2 && ma[info[a][0]-(2*(t-1)+1)][info[a][1]][1]!=0){
                    result += ma[info[a][0]][info[a][1]][1] + ma[info[a][0]-(2*(t-1)+1)][info[a][1]][1];
                    ma[info[a][0]][info[a][1]][1],ma[info[a][0]-(2*(t-1)+1)][info[a][1]][1] =0;
            }
            else if(ma[info[a][0]][info[a][1]][0]==2 && ma[info[a][0]-t][info[a][1]-t][1]!=0 ||
                     ma[info[a][0]-2*t][info[a][1]][1]!=0 ||  ma[info[a][0]-t][info[a][1]+t][1]!=0){
                            result += ma[info[a][0]][info[a][1]][0] + ma[info[a][0]-t][info[a][1]-t][1] +
                     ma[info[a][0]-2*t][info[a][1]][1] + ma[info[a][0]-t][info[a][1]+t][1];
                     ma[info[a][0]][info[a][1]][0],ma[info[a][0]-t][info[a][1]-t][1],
                     ma[info[a][0]-2*t][info[a][1]][1] , ma[info[a][0]-t][info[a][1]+t][1] = 0;
            }
            if(ma[info[a][0]][info[a][1]][0]==4 && ma[info[a][0]+(2*(t-1)+1)][info[a][1]][1]!=0){
                    result += ma[info[a][0]][info[a][1]][1] + ma[info[a][0]+(2*(t-1)+1)][info[a][1]][1];
                    ma[info[a][0]][info[a][1]][1],ma[info[a][0]+(2*(t-1)+1)][info[a][1]][1] =0;
            }
            else if(ma[info[a][0]][info[a][1]][0]==4 && ma[info[a][0]+t][info[a][1]-t][1]!=0 ||
                     ma[info[a][0]+2*t][info[a][1]][1]!=0 ||  ma[info[a][0]+t][info[a][1]+t][1]!=0){
                            result += ma[info[a][0]][info[a][1]][0] + ma[info[a][0]+t][info[a][1]-t][1] +
                     ma[info[a][0]+2*t][info[a][1]][1] + ma[info[a][0]+t][info[a][1]+t][1];
                     ma[info[a][0]][info[a][1]][0],ma[info[a][0]+t][info[a][1]-t][1],
                     ma[info[a][0]+2*t][info[a][1]][1] , ma[info[a][0]+t][info[a][1]+t][1] = 0;
            }
        }
    }
printf("#%d %d",test+1,result);
result = 0;
}
}
