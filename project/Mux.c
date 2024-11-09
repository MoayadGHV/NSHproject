#include <stdio.h>
#include <stdbool.h>
#include "Mux.h"
	
	void mux2to1(int input0, int input1, bool sel, int *out) {
	    if (sel == 0){ 
			*out = input0;
		} else if (sel == 1){
			*out = input1;
		} 
	}
