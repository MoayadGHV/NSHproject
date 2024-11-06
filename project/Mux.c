#include <stdio.h>
#include <stdbool.h>

	
	void mux2to1(int input0, int input1, bool sel, int out) {
	    if (!sel){ 
			out = input0;
		} else{
			out = input1;
		} 
	}
