#include <stdbool.h>


void ALU(bool sel, int num1, int num2, int res, bool carry){


    if(!sel){
        res = num1 + num2;
        if (res > 7){carry == 1;}
    } else if(sel){

        if (num1 < num2){
            res = (num1 - num2) + 8;
            carry = 1;
        } else {
            res = num1 - num2;
        }

    }

}

