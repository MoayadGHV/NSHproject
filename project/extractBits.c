void extractBits(int ins, bool *j, bool *c, bool *d1, bool *d0, bool *sreg, int *imm, bool *s) {
    *j = (ins >> 7) & 1;
    *c = (ins >> 6) & 1;
    *d1 = (ins >> 5) & 1;
    *d0 = (ins >> 4) & 1;
    *sreg = (ins >> 3) & 1;

    if (*sreg || *j || *c) {
        *imm = ins & 0b111; 
        *s = false;
    } else {
        
        *s = (ins >> 2) & 1;
        *imm = 0;
    }
}