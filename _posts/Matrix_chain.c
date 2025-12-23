#include <stdio.h>
#include <stdlib.h>

void Result_Print(int s[6][6],int i,int j){
    if(i >= j || j-i == 1)
        return;

    int k = s[i][j];
    printf("在[%d,%d]中应该选择%d断开\n",i,j,k);
    Result_Print(s,i,k);
    Result_Print(s,k+1,j);
}


int main(){
    int N = 6;

    int p[7]={5,10,3,12,5,50,6};
    int c[N][N];
    int s[N][N];

    for(int i = 0;i<N;i++){
        c[i][i] = 0;
    }

    for(int l = 2;l<7;l++){
        for(int i =0;i<N-l+1;i++){
            int j = i+l-1;
            int min = p[i]*p[i+1]*p[j+1] + c[i+1][j];
            s[i][j] = i+1;
            for(int k = i;k<j;k++){
                int temp = p[i]*p[k+1]*p[j+1] + c[i][k]+c[k+1][j];
                
                if(temp < min){
                    min = temp;
                    s[i][j] = k;
                } 
            }
            c[i][j] = min;
        }
    }


    printf("%d \n",c[0][5]);

    for(int i = 0;i<N;i++){
        for(int j = i+1;j<N;j++){
            if(j<i){
                printf("0 ");
            }
            else{
                printf("%d ",s[i][j]);
            }
        }
        printf("\n");
    }

    //Result_Print(s,0,5);
    return 0;
}