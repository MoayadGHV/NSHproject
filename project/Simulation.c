#include <stdio.h>
#include <stdbool.h>
#include "Deco.h"
#include "Mux.h"
#include "instructionMemory.h"
#include "ALU.h"
#include "fetch.h"
#include "extractBits.h"


int main(int argc, char *argv[]){
    
    int ra, rb, ro, imm, muxout, res= 0;
    bool j, c, carry, d0, d1, sreg, s, enA, enB, enO = 0;
    int pc = 0;
    int insructions[9];
    int currentins;

    if (strlen(argv[1]) < 4 || strcmp(argv[1] + strlen(argv[1]) - 4, ".asm") != 0) {
        printf("Error: File must have a .asm extension.\n");
        return 1;
    }

    loadmem(argv[1], insructions);

    while(pc < 16){
        currentins = fetch(insructions, pc);
        extractBits(currentins, &j, &c, &d1, &d0, &sreg, &imm, &s);

        mux2to1(res, imm, sreg, muxout);
        
        decoder2to4(d1, d0, &enA, &enB, &enO);
        if (enA){ra = muxout;}
        if (enB){rb = muxout;}
        if (enO){ro = ra;}
        ALU(s, ra, rb, res, carry);
        if ((carry & c) | j){
            pc = imm;
            continue;
        }


        pc++;
    }





}
