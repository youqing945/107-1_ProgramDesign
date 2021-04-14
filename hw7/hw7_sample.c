///////////////////////////////////////////////////////////////////////////////
//
// File: hw7_sample.c
// Author: Yu-Hung, Lin & Huai-Mao, Ko
// Description: An example of reading a binary file using fread, and parse some fields
// Date: 2018/12/05
//
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // ref: http://pubs.opengroup.org/onlinepubs/009695399/basedefs/stdint.h.html

int main(int argc,char *argv[])
{
   FILE *fp;
   unsigned char mac[6] = "";
   unsigned char IP[4] = "";
   unsigned char port[2] = "";
   int i;

   if(argc != 2) {
      printf("usage: ./hw7.sample input.out\n");
      return -1;
   }
   /* open a file as a binary file */
   fp = fopen(argv[1], "rb");

   if(!fp) {
      printf("Can't open file.\n");
      return -1;
   }

   // ref: https://www.cnblogs.com/oomusou/archive/2011/10/27/readnbyte.html
   // read MAC address
   fread(mac, sizeof(char), 6, fp);
   printf("SRC MAC: ");
   for(i=0; i<5; i++) {
      printf("%02x:", mac[i]);
   }
   printf("%02x\n", mac[5]);

   // read IP address and transfer
   printf("SRC IP: ");
   fread(IP, sizeof(char), 4, fp);
   for(i=0; i<3; i++) {
      printf("%d.", IP[i]);
   }
   printf("%d\n", IP[i]);

    // read Port number and transfer
   fread(port, sizeof(char), 2, fp);
   printf("SRC Port: %d\n", 256*port[0]+port[1]);

   fclose(fp);

   return 0;
}
