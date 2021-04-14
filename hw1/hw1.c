#include <stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  int num1, denom1, num2, denom2, result_num, result_denom;

  num1 = atoi(argv[1]);
  denom1 = atoi(argv[2]);
  num2 = atoi(argv[3]);
  denom2 = atoi(argv[4]);

  result_num = num1 * denom2 + num2 *denom1;
  result_denom = denom1 * denom2;

  int A = result_num,B = result_denom;
  for(A=A,B=B; A!=0&&B!=0; A+=0,B+=0){
    if(A>B) A = A%B;
    else B=B%A;
  }

  if(A==0) printf("%d/%d\n",result_num/B, result_denom/B);
  else printf("%d/%d\n",result_num/A,result_denom/A);

  return 0;
}

