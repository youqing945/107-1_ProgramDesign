#include<stdio.h>
#include<stdlib.h>
int M,i,j;

//Mode
void b2if(int Q[32]); //32-bit > int & float
void i2b(int Q); //int > 32-bit
void f2b(float Q); //float > 32-bit
void b2llid(long long int Q[64]); //64-bit > int & double
void lli2b(long long int Q); //int > 64-bit
void d2b(double Q); //double > 64-bit

//Print
void printif(int A); //print int float
void printllid(long long int A); //print int double
void print32b(int n,int A[32]); //print 32-bit
void print64b(long long int n,long long int A[64]); //print 64-bit

///////////////////////////////////////////////
///////////////////////////////////////////////
int main(int argc, char *argv[]){
    M=atoi(argv[1]);

    if(M==1){ //32-bit > int & float
        int Q[32];
        for(i=0;i<32;i++)Q[i]=argv[2][i]-48;
        b2if(Q);
    }

    else if(M==2){ //int > 32-bit
        int Q=atoi(argv[2]);
        i2b(Q);
    }

    else if(M==3){ //float > 32-bit
        float Q=atof(argv[2]);
        f2b(Q);
    }

    else if(M==4){ //64-bit > int & double
        long long int Q[64];
        for(i=0;i<64;i++)Q[i]=argv[2][i]-48;
        b2llid(Q);
    }

    else if(M==5){ //int > 64-bit
        long long int Q=atoll(argv[2]);
        lli2b(Q);
    }

    else if(M==6){ //double > 64-bit
        double Q=atof(argv[2]);
        d2b(Q);
    }

    return 0;
}

///////////////////////////////////////////////
///////////////////////////////////////////////
void b2if(int Q[32]){ //32-bit > int & float
    int A=0,n=1;//negative
    if(Q[0]==0)n=0; //positive
    for(i=n;i<32;i++)if(Q[i]==1){
        for(j=0;j<31-i;j++)Q[i]=Q[i]*2;
        A=A+Q[i];
    }
    if(n==1)A=A-2147483648;

    printif(A);
}

void i2b(int Q){ //int > 32-bit
    int A[32]={0},arrow=31,n=0;//positive
    if(Q<0){
        Q=Q+2147483648;
        n=1;//negative
    }
    while(Q!=0){
        A[arrow]=Q%2;
        Q=Q/2;
        arrow--;
    }

    print32b(n,A);
}

void f2b(float Q){ //float > 32-bit
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

    print32b(n,A);
}

void b2llid(long long int Q[64]){ //64-bit > int & double
    long long int A=0,n=1;//negative
    if(Q[0]==0)n=0; //positive
    for(i=n;i<64;i++)if(Q[i]==1){
        for(j=0;j<63-i;j++)Q[i]=Q[i]*2;
        A=A+Q[i];
    }
    if(n==1)A=A-9223372036854775808;

    printllid(A);
}

void lli2b(long long int Q){ //int > 64-bit
    long long int A[64]={0},arrow=63,n=0;//positive
    if(Q<0){
        Q=Q+9223372036854775808;
        n=1;//negative
    }
    while(Q!=0){
        A[arrow]=Q%2;
        Q=Q/2;
        arrow--;
    }

    print64b(n,A);
}

void d2b(double Q){ //double > 64-bit
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

    print64b(n,A);
}

/////////////////////////////////////////
/////////////////////////////////////////
void printif(int A){ //print int float
    printf("integer: %d\n",A);

    float *pA;
    pA=&A;
    printf("float: %f\n",*pA);
}

void printllid(long long int A){ //print int double
    printf("integer: %lld\n",A);

    double *pA;
    pA=&A;
    printf("double: %lf\n",*pA);
}

void print32b(int n,int A[32]){ //print 32-bit
    if(n==0)printf("32-bit: ");
    else printf("32-bit: 1");
    for(i=n;i<32;i++)printf("%d",A[i]);
    printf("\n");
}

void print64b(long long int n,long long int A[64]){ //print 64-bit
    if(n==0)printf("64-bit: ");
    else printf("64-bit: 1");
    for(i=n;i<64;i++)printf("%lld",A[i]);
    printf("\n");
}

