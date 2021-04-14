#include<stdio.h>
#include<stdlib.h>

int Total = 0, TCP = 0, UDP = 0;

struct ethernet{
    unsigned char DSTMAC[6];
    unsigned char SRCMAC[6];
}Ethernet;

struct ipv4{
    unsigned char TotalLength[2];
    unsigned char Protocol[1];
    unsigned char SRCIP[4];
    unsigned char DSTIP[4];
}IPV4;

struct tcpudp{
    unsigned char SRCPort[2];
    unsigned char DSTPort[2];
}TCPUDP;

int main(){

    //open file=====
    FILE *rf;
    rf = fopen("test.out", "rb");

    if(rf == NULL){
        printf("Error.\n");
        return -1;
    }
    //==========

    while(fread(Ethernet.DSTMAC, sizeof(char), 6, rf) != 0){
        //read file=====
        //MAC
        fread(Ethernet.SRCMAC, sizeof(char), 6, rf);
        //Length
        fseek(rf, 4, SEEK_CUR);
        fread(IPV4.TotalLength, sizeof(char), 2, rf);
        int Length = 256*IPV4.TotalLength[0]+IPV4.TotalLength[1]+14;
        //Protocol Type
        fseek(rf, 5, SEEK_CUR);
        fread(IPV4.Protocol, sizeof(char), 1, rf);
        //IP
        fseek(rf, 2, SEEK_CUR);
        fread(IPV4.SRCIP, sizeof(char), 4, rf);
        fread(IPV4.DSTIP, sizeof(char), 4, rf);
        //Port: only TCP &UDP
        if(IPV4.Protocol[0] == 6 || IPV4.Protocol[0] == 17){
            if(IPV4.Protocol[0] == 6) TCP++;
            else UDP++;
            fread(TCPUDP.SRCPort, sizeof(char), 2, rf);
            fread(TCPUDP.DSTPort, sizeof(char), 2, rf);
            fseek(rf, Length-38, SEEK_CUR);
        }
        else fseek(rf, Length-34, SEEK_CUR);
        //==========

        //print out=====
        Total++;
        printf("#%d\n",Total);
        printf("DST MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", Ethernet.DSTMAC[0], Ethernet.DSTMAC[1], Ethernet.DSTMAC[2], Ethernet.DSTMAC[3], Ethernet.DSTMAC[4], Ethernet.DSTMAC[5]);
        printf("SRC MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", Ethernet.SRCMAC[0], Ethernet.SRCMAC[1], Ethernet.SRCMAC[2], Ethernet.SRCMAC[3], Ethernet.SRCMAC[4], Ethernet.SRCMAC[5]);
        printf("Protocol: ");
        if(IPV4.Protocol[0] == 6) printf("TCP\n");
        else if(IPV4.Protocol[0] == 17) printf("UDP\n");
        else printf("ICMP\n");
        printf("SRC IP: %d.%d.%d.%d\n", IPV4.SRCIP[0], IPV4.SRCIP[1], IPV4.SRCIP[2], IPV4.SRCIP[3]);
        printf("DST IP: %d.%d.%d.%d\n", IPV4.DSTIP[0], IPV4.DSTIP[1], IPV4.DSTIP[2], IPV4.DSTIP[3]);
        if(IPV4.Protocol[0] == 6 || IPV4.Protocol[0] == 17){
            printf("SRC Port: %d\n", 256*TCPUDP.SRCPort[0]+TCPUDP.SRCPort[1]);
            printf("DST Port: %d\n", 256*TCPUDP.DSTPort[0]+TCPUDP.DSTPort[1]);
        }
        printf("Packet Length: %d\n\n", Length);
        //==========
    }

    //
    printf("Number of Packet: %d\n", Total);
    printf("Number of TCP: %d\n", TCP);
    printf("Number of UDP: %d\n", UDP);
    printf("Number of ICMP: %d\n", Total-TCP-UDP);
    fclose(rf);
    return 0;
}
