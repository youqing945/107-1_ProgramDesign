#include<stdio.h>
#include<string.h>

int F1[10000][5];
int F2[10000][5];
int F3[10000][2];
int F4[10000][2];
int F5[10000][2];
int all=0;
int F[2][6],T;

int i,j,k;

void readfile(){
    FILE *rf;
    rf=fopen("acl1_100.txt","r");
    if(rf==NULL){
        printf("Fail\n");
        exit(1);
    }
    while(fscanf(rf,"@%d.%d.%d.%d/%d ",&F1[all][0],&F1[all][1],&F1[all][2],&F1[all][3],&F1[all][4])!=EOF){
        fscanf(rf,"@%d.%d.%d.%d/%d ",&F1[all][0],&F1[all][1],&F1[all][2],&F1[all][3],&F1[all][4]);
        fscanf(rf,"%d.%d.%d.%d/%d ",&F2[all][0],&F2[all][1],&F2[all][2],&F2[all][3],&F2[all][4]);
        fscanf(rf,"%d : %d ",&F3[all][0],&F3[all][1]);
        fscanf(rf,"%d : %d ",&F4[all][0],&F4[all][1]);
        fscanf(rf,"0x%x/0x%x ",&F5[all][0],&F5[all][1]);
        all++;
    }
    fclose(rf);
    for(i=1;i<=5;i++)F[0][i]=all,F[1][i]=0;
    T=all;
}

void cmp(){
    for(i=0;i<all;i++){
        int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
        if(F1[i][0]==0&&F1[i][1]==0&&F1[i][2]==0&&F1[i][3]==0&&F1[i][4]==0)F[1][1]++;
        if(F2[i][0]==0&&F2[i][1]==0&&F2[i][2]==0&&F2[i][3]==0&&F2[i][4]==0)F[1][2]++;
        if(F3[i][0]==0&&F3[i][1]==65535)F[1][3]++;
        if(F4[i][0]==0&&F4[i][1]==65535)F[1][4]++;
        if(F5[i][0]==0&&F5[i][1]==0)F[1][5]++;
        for(j=0;j<i;j++){
            if(flag1==0)
                if(F1[i][0]==F1[j][0]&&F1[i][1]==F1[j][1]&&F1[i][2]==F1[j][2]&&F1[i][3]==F1[j][3]&&F1[i][4]==F1[j][4])
                    flag1++,F[0][1]--;
            if(flag2==0)
                if(F2[i][0]==F2[j][0]&&F2[i][1]==F2[j][1]&&F2[i][2]==F2[j][2]&&F2[i][3]==F2[j][3]&&F2[i][4]==F2[j][4])
                    flag2++,F[0][2]--;
            if(flag3==0)
                if(F3[i][0]==F3[j][0]&&F3[i][1]==F3[j][1])
                    flag3++,F[0][3]--;
            if(flag3==1)
                if(F3[i][0]==F3[j][0]&&F3[i][1]==F3[j][1]&&F4[i][0]==F4[j][0]&&F4[i][1]==F4[j][1]&&F5[i][0]==F5[j][0]&&F5[i][1]==F5[j][1])
                    flag3++,T--;
            if(flag4==0)
                if(F4[i][0]==F4[j][0]&&F4[i][1]==F4[j][1])
                    flag4++,F[0][4]--;
            if(flag5==0)
                if(F5[i][0]==F5[j][0]&&F5[i][1]==F5[j][1])
                    flag5++,F[0][5]--;
            if(flag1!=0&&flag2!=0&&flag3==2&&flag4!=0&&flag5!=0)break;
        }
    }
}

int main(){

    readfile();

    cmp();

    for(i=0;i<2;i++){
        for(j=1;j<=5;j++)printf("F%d: %d\n",j,F[i][j]);
        printf("\n");
    }
    printf("%d\n\n%d\n",all,T);

    return 0;
}
