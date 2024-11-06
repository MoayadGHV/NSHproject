#include <stdio.h>
#include <stdbool.h>
#include "Deco.c"
#include "Mux.c"
#include "assembler.c"
#include "instructionMemory.c"
#include "ALU.c"
#include "fetch.c"
#include "extractBits.c"


int main(int argc, char *argv[]){
    
    int ra, rb, ro, imm, res= 0;
    bool j, c, carry, d0, d1, sreg, s, enA, enB, enO = 0;
    int pc = 0;
    int insructions[9];
    int currentins;

    if (strlen(argv[1]) < 4 || strcmp(filename + strlen(filename) - 4, ".asm") != 0) {
        printf("Error: File must have a .asm extension.\n");
        return 1;
    }

    loadmem(argv[1], insructions);

    while(pc < 16){
        currentins = fetch(insructions, pc);
        extractBits(currentins, &j, &c, &d1, &d0, &sreg, &imm, &s);

        int muxtemp = mux2to1(res, imm, sreg);
        decoder2to4(d1, d0, &enA, &enB, &enO);
        if (enA){ra = imm;}
        if (enB){rb = imm;}
        if (enO){ro = ra;}
        ALU(s, ra, rb, res, carry);
        if ((carry & c) | j){
            pc = imm;
            continue;
        }


        pc++;
    }





}