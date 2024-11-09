#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Deco.h"
#include "Mux.h"
#include "instructionMemory.h"
#include "ALU.h"
#include "fetch.h"
#include "extractBits.h"


int main(int argc, char *argv[]){
    
    int ra= 0, rb= 0, ro= 0, imm= 0, muxout= 0, res= 0;
    bool j= 0, c= 0, carry= 0, d0= 0, d1= 0, sreg= 0, s= 0, enA= 0, enB= 0, enO = 0;
    int pc = 0;
    int insructions[9];
    int currentins;
    char mode;
    bool flag;
    int inscount = 1;
    if (strlen(argv[1]) < 4 || strcmp(argv[1] + strlen(argv[1]) - 4, ".bin") != 0) {
        printf("Error: File must have a .bin extension.\n");
        return 1;
    }

    loadmem(argv[1], insructions);

    printf("Select one of the following modes\n");
    printf("R - Run in continuous mode\n");
    printf("S - Run step-by-step\n");
    printf("Select mode: ");
    scanf(" %c", &mode);
    getchar();
    if (mode != 's' && mode != 'S' && mode != 'r' && mode != 'R'){
        printf("wrong mode\n");
        return 1;
    }


    while(pc < 16){
        
        enA= 0; 
        enB= 0;
        enO = 0;
        currentins = fetch(insructions, pc);
        printf("%08b\n", currentins);
        extractBits(currentins, &j, &c, &d1, &d0, &sreg, &imm, &s);
        printf("%d\n", imm);
        decoder2to4(d1, d0, &enA, &enB, &enO);
        ALU(s, ra, rb, &res, &carry);
        printf("%d\n", res);
        mux2to1(res, imm, sreg, &muxout);
        printf("%d\n", muxout);
        

        printf("ra= %d, rb = %d, ro= %d\n", ra, rb, ro);
        if (enA){
            ra = muxout; 
            if(sreg == 1 && (mode == 's' || mode == 'S')){
                printf("instruction %d: RA = %d\t [press anything to continue]", inscount, muxout);
                getchar();
            } else if ((s == 0 && j == 0 && c == 0) && (mode == 's' || mode == 'S')){
                printf("instruction %d: RA = RA + RB\t [press anything to continue]", inscount);
                getchar();
            } else if ((s == 1 && j == 0 && c == 0) && (mode == 's' || mode == 'S')) {
                printf("instruction %d: RA = RA - RB\t [press anything to continue]", inscount);
                getchar();
            }
            
        }

        if (enB){
            rb = muxout; 
            if(sreg == 1 && (mode == 's' || mode == 'S')){
                printf("instruction %d: RB = %d\t [press anything to continue]", inscount, muxout);
                getchar();
            } else if ((s == 0 && j == 0 && c == 0) && (mode == 's' || mode == 'S')){
                printf("instruction %d: RB = RA + RB\t [press anything to continue]", inscount);
                getchar();
            } else if ((s == 1 && j == 0 && c == 0) && (mode == 's' || mode == 'S')){
                printf("instruction %d: RB = RA - RB\t [press anything to continue]", inscount);
                getchar();
            }
        }

        if (enO){
            ro = ra;
            if (mode == 's' || mode == 'S'){
                printf("instruction %d: RO = RA -> RO = %d\t [press anything to continue]", inscount, muxout);
                getchar();
            } else if(mode == 'r' || mode == 'R'){
                printf("R0 = %d\n", ro);
            }
            
        }
        
        
        if ((flag && c) || j){
            pc = imm;
            if (j && (mode == 's' || mode == 'S')){
                printf("instruction %d: J= %d\t [press anything to continue]", inscount, muxout);
                getchar();
            } else if ((flag && c) && (mode == 's' || mode == 'S')){
                printf("instruction %d: JC= %d\t [press anything to continue]", inscount, muxout);
                getchar();
            }
            continue;
        }
        inscount++;

        pc++;
        flag = carry;
    }
     printf("program finished");





}
