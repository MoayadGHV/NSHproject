#include <stdio.h>

	//int Dec2to4();
	void decoder2to4(int input0, int input1, int *output0, int *output1, int *output2, int *output3) {
    	// Restore it in RA
		*output0 = (input0 == 0 && input1 == 0);
    	// restore in RB
		*output1 = (input0 == 0 && input1 == 1);
    	// restore in RO
		*output2 = (input0 == 1 && input1 == 0);
    	
	// NOTHING to DO 	
	*output3 = (input0 == 1 && input1 == 1);
	}

