#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void loadmem(char *filename, int *instructions){
    char text[sizeof(instructions)+1];
    FILE *rfp = fopen(filename, "r");
    int i = 0;
   
    while(fgets(text, sizeof(text), rfp)){
     
        if (text[0] == '\n'){continue;}
        instructions[i] = (int) strtol(text, NULL, 2);
        i++;
        }
}


int main(){
    int instructions[16];

    loadmem("binary.bin", instructions);
    // for (int i = 0; i < 9; i++){
    //     printf("%d\n", instructions[i]);
    // }
    
}
