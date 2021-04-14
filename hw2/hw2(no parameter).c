#include<stdio.h>
#include<stdlib.h>

int main(/*int argc, char *argv[]*/){
    int n,p;
    scanf("%d %d",&n,&p); //n:play with //p:position
    //n = atoi(argv[1]);
    //p = atoi(argv[2]);

    printf("You set N = %d, P = %d.\n",n,p);
    int ans[p];
    while(1>0){
        printf("ans: ");
        for(int i=0;i<p;i++)scanf("%d",&ans[i]);
        int check = 1;
        for(int i=0;i<p;i++){
            if(ans[i]>n||ans[i]<1){
                check = 0;
                break;
            }
        }
        if(check==1)break;
        else printf("The answer is illegal, please reset the answer.\n");
    }

    //======================================


    while(1>0){
        int gue[p], ansnum[n+1], guenum[n+1], h=0, x=0;
        for(int i=0;i<n+1;i++){
            ansnum[i]=0;
            guenum[i]=0;
        }
        printf("guess: ");
        for(int i=0;i<p;i++)scanf("%d",&gue[i]);
        //============calculation==========
        for(int i=0;i<p;i++){
            if(gue[i]==ans[i])h++;
            else{
                ansnum[ans[i]]++;
                guenum[gue[i]]++;
            }
        }
        if(h==p){
            printf("%dH 0X\n",h);
            break;
        }
        else{
            for(int i=1;i<n+1;i++){
                if(guenum[i]<ansnum[i])x=x+guenum[i];
                else x=x+ansnum[i];
            }
            printf("%dH %dX\n",h,x);
        }
    }

    return 0;
}
