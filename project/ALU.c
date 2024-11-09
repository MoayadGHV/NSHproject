#include <stdbool.h>
#include "ALU.h"

void ALU(bool sel, int num1, int num2, int *res, bool *carry){


    if(!sel){
        *res = num1 + num2;
        if (*res > 15){*carry = true;}
    } else if(sel){

        if (num1 < num2){
            *res = (num1 - num2) + 16;
            *carry = true;
        } else {
            *res = num1 - num2;
        }

    }

}

