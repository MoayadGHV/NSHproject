#include <stdio.h>
#include <string.h>
#include <ctype.h>


void rmvSpace(char *str) {
    int i = 0, j = 0;
    while (str[i]) {


        if (!isspace(str[i])) {

            str[j++] = str[i];
        }

        i++;

    }


    str[j] = '\0';
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void intToBinary3Bit(int num, char *binary) {
    for (int i = 2; i >= 0; i--) {
        binary[i] = (num & 1) + '0';
        num >>= 1;
    }
    binary[3] = '\0';
}

void writeBinary(char *temp, FILE *wfp) {
    rmvSpace(temp);
    temp[strcspn(temp, "\n")] = 0;
    int i = 1;
    if (strcmp(temp, "ra=ra+rb") == 0) {
        fprintf(wfp, "00000000\n");
        printf("Line %d: RA=RA+RB\n", i);
        i++;
    } else if (strcmp(temp, "rb=ra+rb") == 0) {
        fprintf(wfp, "00010000\n");
        printf("Line %d: RB=RA+RB\n", i);
        i++;
    } else if (strcmp(temp, "ra=ra-rb") == 0) {
        fprintf(wfp, "00000100\n");
        printf("Line %d: RA=RA-RB\n", i);
        i++;
    } else if (strcmp(temp, "rb=ra-rb") == 0) {
        fprintf(wfp, "00010100\n");
        printf("Line %d: RB=RA-RB\n", i);
        i++;
    } else if (strcmp(temp, "ro=ra") == 0) {
        fprintf(wfp, "00100000\n");
        printf("Line %d: RO=RA\n", i);
        i++;
    } else if (strncmp(temp, "ra=", 3) == 0) {
        fprintf(wfp, "00001");
        int num = temp[3] - '0';
        fprintf(wfp, "%03b\n", num);
        printf("Line %d: RA=%d\n", i, num);
        i++;
    } else if (strncmp(temp, "rb=", 3) == 0) {
        fprintf(wfp, "00011");
        int num = temp[3] - '0';
        fprintf(wfp, "%03b\n", num);
        printf("Line %d: RB=%d\n", i, num);
        i++;
    } else if (strncmp(temp, "jc=", 3) == 0) {
        fprintf(wfp, "01110");
        int num = temp[3] - '0';
        fprintf(wfp, "%03b\n", num);
        printf("Line %d: JC=%d\n", i, num);
        i++;
    } else if (strncmp(temp, "j=", 2) == 0) {
        fprintf(wfp, "10110");
        int num = temp[2] - '0';
        fprintf(wfp, "%03b\n", num);
        printf("Line %d: J=%d\n", i, num);
        i++;
    } else {
        perror("wrong instruction");
    }
    

}

void assemble(char *fn) {
    char line[20]; 
    char name[20];
    char biName[24];
    sscanf(fn, "%[^.]", name); 
    sprintf(biName, "%s.bin", name);

    printf("Reading file:%s\n", fn);

    FILE *rfp = fopen(fn, "r");
    FILE *wfp = fopen(biName, "w+");

    if (rfp == NULL || wfp == NULL) {
        perror("Error opening file.\n");
    }

    
    while (fgets(line, sizeof(line), rfp)) {
        toLowerCase(line);
        writeBinary(line, wfp);
    }

    fclose(rfp);
    fclose(wfp);

    
    sscanf(fn, "%[^.]", name);
    printf("Successfully generated output file: %s.bin\n", name);
}

int main(int argc, char *argv[]){
    if (strlen(argv[1]) < 4 || strcmp(argv[1] + strlen(argv[1]) - 4, ".asm") != 0) {
        printf("Error: File must have a .asm extension.\n");
        return 1;
    }
    printf("Starting Assembler...\n");
    assemble(argv[1]);

    
    return 0;


}
