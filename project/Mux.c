#include <stdio.h>
#include <stdbool.h>

	
	int mux2to1(int input0, int input1, bool sel0) {
	    if (!sel0) return input0;
    		else if (sel0) return input1;
	}
