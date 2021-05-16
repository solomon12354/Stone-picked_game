#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define pcWin        1
#define pcLose      -1
#define computer     1
#define human        0


// Return  1: PC will win
//        -1: PC will lose
int PCWillWin(int left,int middle,int right,int player){
    int save;
    int i;
    int PCWinInNextStep[6]={0};
    save=0;

    if(left==0&&middle==0&&right==0){
 //       This judges who picks the last stone is winner.
        if(1 == player){
            return pcWin;
        } else {
            return pcLose;
        }
    }
    // possible cases
    int nextPlayer = human;
    if(computer == player){
        nextPlayer = human;
    } else {
        nextPlayer = computer;
    }

    if(0 <= left-1){
        int l=left-1;
        PCWinInNextStep[0] = PCWillWin(l,middle,right,nextPlayer);
    }

    if(0<= left-2){
        int l2=left-2;
        PCWinInNextStep[1] = PCWillWin(l2,middle,right,nextPlayer);
    }


    if(0 <= middle-1){
        int m=middle-1;
        PCWinInNextStep[2] = PCWillWin(left,m,right,nextPlayer);
    }

    if(0<=middle-2){
        int m2=middle-2;
        PCWinInNextStep[3] = PCWillWin(left,m2,right,nextPlayer);
    }

    if(0<=right-1){
        int r=right-1;
        PCWinInNextStep[4] = PCWillWin(left,middle,r,nextPlayer);
    }

    if(0<=right-2){
        int r2=right-2;
        PCWinInNextStep[5] = PCWillWin(left,middle,r2,nextPlayer);
    }

    if(computer == player){
        for(i=0;i<6;i++){
            if(pcWin == PCWinInNextStep[i]){
                return pcWin;
            }
        }
        return pcLose;
    } else {
        for(i=0;i<6;i++){
            if(pcLose == PCWinInNextStep[i]){
                return pcLose;
            }
        }
        return pcWin;
    }
}
int main(void)
{
    int l;
    int m;
    int r;
    int y;
    int aax[3];
    int number;
    srand(time(NULL));

    int z;
    int x;

    printf("This is a stone game!!!\n");
    while(1){
        for(int i=0;i<3;i++){
            aax[i]=rand()%4+3;
        }
        l=aax[0];
        m=aax[1];
        r=aax[2];

        while(1){
            printf("\n\nThere are %d stones on the left\n",l);
            printf("There are %d stones on the middle\n",m);
            printf("There are %d stones on the right\n",r);
            for(int i=0;i<l;i++){
                printf("*");
            }
            printf("     ");
            for(int i=0;i<m;i++){
                printf("*");
            }
            printf("     ");
            for(int i=0;i<r;i++){
                printf("*");
            }
            printf("\n");
        //  Choose the area you want to pick the stones.
            while(1){
                printf("Which do you want to pick?left,middle or right?\n");
                printf("(Left input 1,middle input 2,right input 3)\n");
                scanf("%d",&x);
                if((x==1&&l==0)||(x==2&&m==0)||(x==3&&r==0)){
                    printf("You can not pick anything!!!!!\n");
                    continue;
                }

                if(x!=1&&x!=2&&x!=3){
                    printf("Error\n");
                    continue;
                }
                break;
            }
        //  The number of the stones you want to pick.
            while(1){
                printf("How many stones do you want to pick?\n");
                scanf("%d",&y);
                printf("\n");

                if(y>2){
                    printf("You don't pick more than 2!!\n");
                    continue;
                }if(y<1){
                    printf("You have to pick unless 1 stone!!\n");
                    continue;
                }
                break;
            }
            if(x==1){
                l=l-y;
            }
            else if(x==2){
                m=m-y;
            }
            else if(x==3){
                r=r-y;
            }
            if(l==0&&m==0&&r==0){
                printf("You win!!!!\n");
                break;
            }
            printf("I am thinking!...\n");

            if(0 <= l-1&&1 == PCWillWin(l-1,m,r,1)){
                    l -= 1;
            }

            else if(0<= l-2&&1 == PCWillWin(l-2,m,r,1)){
                    l-=2;

            }


            else if(0 <= m-1&&1 ==PCWillWin(l,m-1,r,1)){
                    m-=1;

            }

            else if(0<=m-2&&1==PCWillWin(l,m-2,r,1)){
                    m-=2;

            }

            else if(0<=r-1&&1==PCWillWin(l,m,r-1,1)){
                    r-=1;

            }

            else if(0<=r-2&&1==PCWillWin(l,m,r-2,1)){
                    r-=2;

            }


            if(l==0&&m==0&&r==0){
                printf("PC win!!!!\n");
                break;
            }

        }
        printf("\n\nPlay again?(Again input 1,Exit input 2)\n");
        scanf("%d",&z);
        if(z==1){
            continue;
        }
        break;
    }

    return 0;
}
