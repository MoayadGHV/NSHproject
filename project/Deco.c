#include <stdbool.h>
#include "Deco.h"


	
	void decoder2to4(bool input1, bool input0, bool *output0, bool *output1, bool *output2) {
    	
		if (input0 == 0 && input1 == 0 ){
			*output0 = 1;
			*output1 = 0;
			*output2 = 0;
		} else if (input0 == 1 && input1 == 0){
			*output0 = 0;
			*output1 = 1;
			*output2 = 0;
		}	else if (input0 == 0 && input1 == 1){
			*output0 = 0;
			*output1 = 0;
			*output2 = 1;
		}

    	
	}

