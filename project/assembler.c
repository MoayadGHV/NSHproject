#include <stdio.h>
#include <string.h>
#include <ctype.h>


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

    temp[strcspn(temp, "\n")] = 0;

    if (strcmp(temp, "ra=ra+rb") == 0) {
        fprintf(wfp, "00000000\n");
    } else if (strcmp(temp, "rb=ra+rb") == 0) {
        fprintf(wfp, "00010000\n");
    } else if (strcmp(temp, "ra=ra-rb") == 0) {
        fprintf(wfp, "00000100\n");
    } else if (strcmp(temp, "rb=ra-rb") == 0) {
        fprintf(wfp, "00010100\n");
    } else if (strcmp(temp, "ro=ra") == 0) {
        fprintf(wfp, "00100000\n");
    } else if (strncmp(temp, "ra=", 3) == 0) {
        fprintf(wfp, "00001");
        int num = temp[3] - '0';
        fprintf(wfp, "%03b\n", num);
    } else if (strncmp(temp, "rb=", 3) == 0) {
        fprintf(wfp, "00011");
        int num = temp[3] - '0';
        char binary[4];
        fprintf(wfp, "%03b\n", num);
    } else if (strncmp(temp, "jc=", 3) == 0) {
        fprintf(wfp, "01110");
        int num = temp[3] - '0';
        char binary[4];
        fprintf(wfp, "%03b\n", num);
    } else if (strncmp(temp, "j=", 2) == 0) {
        fprintf(wfp, "10110");
        int num = temp[2] - '0';
        char binary[4];
        fprintf(wfp, "%03b\n", num);
    }
}

int main() {
    char line[20]; // Increased size to accommodate larger lines if needed
    FILE *rfp = fopen("ins.asm", "r+");
    FILE *wfp = fopen("binary.bin", "w+");

    if (rfp == NULL || wfp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read each line, convert to lowercase, and pass to writeBinary
    while (fgets(line, sizeof(line), rfp)) {
        toLowerCase(line); // Convert the line to lowercase
        writeBinary(line, wfp);
    }

    fclose(rfp);
    fclose(wfp);

    return 0;
}
