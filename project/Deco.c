
	//int Dec2to4();
	void decoder2to4(bool input1, bool input0, bool *output0, bool *output1, bool *output2) {
    	// Restore it in RA
		*output0 = (!input0 && !input1);
    	// restore in RB
		*output1 = (input0 && !input1);
    	// restore in RO
		*output2 = (!input0 && input1);
    	
	}

