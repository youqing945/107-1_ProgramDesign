#include<stdio.h>
#include<stdlib.h>
int i,j,k,l;
int n,m,d,finaln=0;

int bucket_union();
int new_mapping();
void fprint_result();
//============
int main(int argc, char *argv[]){
    n=atoi(argv[1]); //num of buck
    m=atoi(argv[2]); //max num of int
    d=atoi(argv[3]); //int range 0 to d-1
    srand(atoi(argv[4]));
    //-----
    int bef[n][m],befnum[n],aft[n][m],aftnum[n];
    int index[n];
    for(i=0;i<n;i++)index[i]=i;
    //-----
    //make random table
    for(i=0;i<n;i++){
        befnum[i]=rand()%(m-1)+1;
        aftnum[i]=befnum[i];
        for(j=0;j<befnum[i];j++){
            bef[i][j]=rand()%d;
            aft[i][j]=bef[i][j];
        }
    }

    //calculate
    finaln=new_mapping(aft,aftnum,index);
    //print to file
    fprint_result(bef,befnum,aft,aftnum);

    return 0;
}

//============
int bucket_union(int b){
    return b;
}

int new_mapping(int aft[n][m],int aftnum[n],int index[n]){
    for(i=0;i<n;i++){ //compressing row
        int comp[i+1][m],compnum[i+1];
        for(j=0;j<i+1;j++)compnum[j]=-1;
        for(j=0;j<i;j++){
            int temp[aftnum[j]],diff[m],diffnum=0;
            for(k=0;k<aftnum[j];k++)temp[k]=aft[j][k];
            for(k=0;k<aftnum[i];k++){
                int flag=0;
                for(l=0;l<aftnum[j];l++){
                    if(aft[i][k]==temp[l]){
                        temp[l]=-1;
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    diff[diffnum]=aft[i][k];
                    diffnum++;
                }
            }
            if(diffnum+aftnum[j]<=m){
                for(k=0;k<diffnum;k++)comp[j][k]=diff[k];
                compnum[j]=diffnum;
            }
        }
        int small=-1;
        for(j=0;j<i;j++){
            if(compnum[j]!=-1){
                small=j;
                break;
            }
        }
        if(small!=-1){
            for(j=small;j<i;j++)if(compnum[j]!=-1&&compnum[j]<compnum[small])small=j;
            for(j=aftnum[small];j<aftnum[small]+compnum[small];j++)aft[small][j]=comp[small][j-aftnum[small]];
            aftnum[small]=aftnum[small]+compnum[small];
            for(j=0;j<aftnum[i];j++)aft[i][j]=-1;
            aftnum[i]=0;
            index[i]=bucket_union(small);
        }
    }
    int bucnum=0;
    for(i=0;i<n;i++){
        if(aftnum[i]==0){
            bucnum=i;
            break;
        }
    }
    return bucnum;
}

void fprint_result(int bef[n][m],int befnum[n],int aft[n][m],int aftnum[n]){
    FILE * pfile;
    pfile=fopen("hw5.out","w");
    char word1[10];
    sprintf(word1,"%d\n\n",finaln);
    fputs(word1,pfile);
    for(i=0;i<n;i++){
        char word2[10];
        sprintf(word2,"%d /",i);
        fputs(word2,pfile);
        for(j=0;j<befnum[i];j++){
            sprintf(word2," %d",bef[i][j]);
            fputs(word2,pfile);
        }
        fputs("\n",pfile);
    }
    fputs("\n",pfile);
    for(i=0;i<finaln;i++){
        char word2[10];
        sprintf(word2,"%d /",i);
        fputs(word2,pfile);
        for(j=0;j<aftnum[i];j++){
            sprintf(word2," %d",aft[i][j]);
            fputs(word2,pfile);
        }
        fputs("\n",pfile);
    }
    fclose(pfile);
}

