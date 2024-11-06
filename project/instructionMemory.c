#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void loadmem(char *filename, char instructions[][9]){

    FILE *rfp = fopen(filename, "r");
    

    for (int i = 0; i < 16; i++){
        fgets(instructions[i], 16, rfp);
        instructions[i][strcspn(instructions[i], "\n")] = '\0';
    }

}

int main(){
    char instructions[16][9];

    loadmem("binary.bin", instructions);
    for (int i = 0; i < 16; i++){
        printf("%s\n", instructions[i]);
    }
    
}
