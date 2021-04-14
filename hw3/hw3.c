#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    int M=atoi(argv[1]),i,j;
    if(M==1){ //32-bit > int & float
        int Q[32],A=0,n=1;//n:positive=0 or negative=1
        for(i=0;i<32;i++)Q[i]=argv[2][i]-48;

        //===int===
        if(Q[0]==0)n=0; //positive
        for(i=n;i<32;i++)if(Q[i]==1){
            for(j=0;j<31-i;j++)Q[i]=Q[i]*2;
            A=A+Q[i];
        }
        if(n==1)A=A-2147483648;
        printf("integer: %d\n",A);
        //===float===
        float *pA;
        pA=&A;
        printf("float: %f\n",*pA);
    }
    ///////////////////////////////////////////
    else if(M==2){ //int > 32-bit
        int Q=atoi(argv[2]),A[32]={0},arrow=31,n=0;//positive
        if(Q<0){
            Q=Q+2147483648;
            n=1;//negative
        }
        while(Q!=0){
                A[arrow]=Q%2;
                Q=Q/2;
                arrow--;
        }
        if(n==0)printf("32-bit: ");
        else printf("32-bit: 1");
        for(i=n;i<32;i++)printf("%d",A[i]);
        printf("\n");
    }
    ///////////////////////////////////////////
    else if(M==3){ //float > 32-bit
        float Q=atof(argv[2]);

        int *pQ;
        pQ=&Q;
        int Q1=*pQ;
        //======
        int A[32]={0},arrow=31,n=0;//positive

        if(Q1<0){
            Q1=Q1+2147483648;
            n=1;//negative
        }
        while(Q1!=0){
            A[arrow]=Q1%2;
            Q1=Q1/2;
            arrow--;
        }
        if(n==0)printf("32-bit: ");
        else printf("32-bit: 1");
        for(i=n;i<32;i++)printf("%d",A[i]);
        printf("\n");
    }
    ///////////////////////////////////////////
    else if(M==4){ //64-bit > int & double
        long long int Q[64],A=0,n=1;//negative
        for(i=0;i<64;i++)Q[i]=argv[2][i]-48;

        //===int===
        if(Q[0]==0)n=0; //positive
        for(i=n;i<64;i++)if(Q[i]==1){
            for(j=0;j<63-i;j++)Q[i]=Q[i]*2;
            A=A+Q[i];
        }
        if(n==1)A=A-9223372036854775808;
        printf("integer: %lld\n",A);
        //===double===
        double *pA;
        pA=&A;
        printf("double: %lf\n",*pA);
    }
    ///////////////////////////////////////////
    else if(M==5){ //int > 64-bit
        long long int Q=atoll(argv[2]),A[64]={0},arrow=63,n=0;//positive
        if(Q<0){
            Q=Q+9223372036854775808;
            n=1;//negative
        }
        while(Q!=0){
                A[arrow]=Q%2;
                Q=Q/2;
                arrow--;
        }
        if(n==0)printf("64-bit: ");
        else printf("64-bit: 1");
        for(i=n;i<64;i++)printf("%lld",A[i]);
        printf("\n");
    }
    ///////////////////////////////////////////
    else if(M==6){ //double > 64-bit
        double Q=atof(argv[2]);

        long long int *pQ;
        pQ=&Q;
        long long int Q1=*pQ;
        //======
        long long int A[64]={0},arrow=63,n=0;//positive

        if(Q1<0){
            Q1=Q1+9223372036854775808;
            n=1;//negative
        }
        while(Q1!=0){
            A[arrow]=Q1%2;
            Q1=Q1/2;
            arrow--;
        }
        if(n==0)printf("64-bit: ");
        else printf("64-bit: 1");
        for(i=n;i<64;i++)printf("%lld",A[i]);
        printf("\n");
    }

    return 0;
}
