#include <stdio.h>
#include <stdbool.h>
#include "Deco.c"
#include "Mux.c"
#include "assembler.c"
#include "instructionMemory.c"
#include "ALU.c"
#include "fetch.c"


int main(){
    int ra, rb, ro, imm, res= 0;
    bool j, c, carry, d0, d1, sreg, s, enA, enB, enO = 0;
    int pc = 0;
    char *insructions[9];//[9];
    char *currentins;
    char *immtemp;

    assemble();
    loadmem("binary.bin", insructions);

    while(pc < 16){
        currentins = fetch(insructions, pc);
        j = (bool)currentins[0]; c = (bool)currentins[1];
        d1 = (bool)currentins[2]; d0 = (bool)currentins[3];
        sreg = (bool)currentins[4];
        if (sreg || j || c){
            immtemp = &currentins[5];
            imm = strtol(immtemp, NULL, 2);
        } else {
            s = currentins[5];
        }

        int muxtemp = mux2to1(res, imm, sreg);
        decoder2to4(d1, d0, enA, enB, enO);
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