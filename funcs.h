#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "math.h"

void printString(char string1[]){/*printing the string*/
    char c;
    c = string1[0];
    int i=0;
    while ( c != '\0'){
        c = string1[i];
        printf("%c",c);
        i++;
    }

}/*works*/
void printFile(char name_of_file[]) {
    FILE *fptr;/*pointer to file input*/
    char c1;
    fptr = fopen(name_of_file, "r");/*open communication with file*/
    if (fptr == NULL) /*check if file opens*/    {
        printf("\nfile would not open for some reason %s", name_of_file);
    }
    /* If unable to create temporary file */
    printf("\nPrinting file:");//standard output
    printString(name_of_file);/*printing file name*/
    printf("\n");//spacing:
    while((c1 = fgetc(fptr)) != EOF) {

        printf("%c",c1);
    }
    fclose(fptr);/*closing communication*/
}/*works*/
void indexPrintFile(char name_of_file[]) {
    printFile(name_of_file);
    int index=0;
    FILE *fptr;/*pointer to file input*/
    char c1;
    fptr = fopen(name_of_file, "r");/*open communication with file*/
    if (fptr == NULL) /*check if file opens*/    {
        printf("\nfile would not open for some reason %s", name_of_file);
    }
    /* If unable to create temporary file */
    printf("\nPrinting file:");//standard output
    printString(name_of_file);/*printing file name*/
    printf("\n");//spacing:
    while((c1 = fgetc(fptr)) != EOF) {

        printf("%i'%c',",index,c1);
        index++;
    }
    fclose(fptr);/*closing communication*/
}/*works*/
FILE* createCopyFile(char name_of_file[],char name_of_new_file[]) {
    FILE *fptr;/*pointer to file input*/
    FILE *result_file;/*pointer to temp-middle file*/
    char c1;
    fptr = fopen(name_of_file, "r");/*open communication with file*/
    if (fptr == NULL) /*check if file opens*/
    {
        printf("\nfile would not open for some reason %s", name_of_file);

    }
    result_file = fopen(name_of_new_file,"w");
    /* If unable to create temporary file */
    if (result_file == NULL)
    {
        printf("cant open file");
        fclose(fptr);
        exit(EXIT_FAILURE);
    }
    printf("\n\n");//spacing:
    while((c1 = fgetc(fptr)) != EOF) {

        fputc(c1, result_file);
    }
    fclose(fptr);/*closing communication with file*/
    fclose(result_file);/*closing communication with file*/
    return result_file;
}/*works*/
void printFile1() {
    FILE *fptr;/*pointer to file input*/

    char name_of_file[FILESIZE];
    printf("Enter path of file to print: ");
    fptr = fopen(name_of_file, "r");/*open communication with file*/
    scanf("%s", name_of_file);//file from input
    if (fptr == NULL) /*check if file opens*/
    {
        printf("\nfile would not open for some reason %s", name_of_file);

    }
    printf("\nPrinting file:");//standard output
    printString(name_of_file);
    printf("\n\n");//spacing:
    fclose(fptr);/*closing communication with file*/
}/*works*/
void perfectSpaces(char name_of_file[]) {
    char temp[FILESIZE]= "temp";
    FILE *fptr;/*pointer to file input*/
    FILE *result_file;/*pointer to temp-middle file*/
    int spaceFlag = 0;
    char c1;
    fptr = fopen(name_of_file, "r");/*open communication with file*/
    if (fptr == NULL) /*check if file opens*/    {
        printf("\nfile would not open for some reason %s", name_of_file);

    }
    result_file = fopen(temp, "w");
    /* If unable to create temporary file */
    if (result_file == NULL)    {
        printf("cant open file");
        fclose(fptr);
        exit(EXIT_FAILURE);
    }
    while((c1 = fgetc(fptr)) != EOF) {
        if(spaceFlag==0 || c1 != ' '){
            fputc(c1, result_file);
        }
        if(c1 == ' ' || c1 == ',' || c1 == ':'){
            spaceFlag = 1;
        }
        else{
            spaceFlag=0;
        }
    }
    fclose(fptr);/*closing communication with file*/
    fclose(result_file);/*closing communication with file*/
    remove(name_of_file);
    rename(temp,name_of_file);
}/*works*/
void deleteIndex(char name_of_file[], int i, int j) {
    char temp[] = "temp";
    FILE *fptr;/*pointer to file input*/
    FILE *result_file;/*pointer to temp-middle file*/
    int index = 0;
    char c1;
    fptr = fopen(name_of_file, "r");/*open communication with file*/
    if (fptr == NULL) /*check if file opens*/    {
        printf("\nfile would not open for some reason %s", name_of_file);

    }
    result_file = fopen(temp, "w");
    /* If unable to create temporary file */
    if (result_file == NULL)    {
        printf("cant open file");
        fclose(fptr);
        exit(EXIT_FAILURE);
    }
    while((c1 = fgetc(fptr)) != EOF) {
        if(!(index >= i &&  index < j))
            fputc(c1, result_file);
        index++;
    }
    fclose(fptr);/*closing communication with file*/
    fclose(result_file);/*closing communication with file*/
    remove(name_of_file);
    rename(temp,name_of_file);
}
void copyIndexes(char name_of_file[],char toBeCopied[], int i, int j) {
    int index = 0,index2=0;
    FILE *fptr;/*pointer to file input*/
    char c1;
    fptr = fopen(name_of_file, "r");/*open communication with file*/
    if (fptr == NULL) /*check if file opens*/    {
        printf("\nfile would not open for some reason %s", name_of_file);

    }


    while((c1 = fgetc(fptr)) != EOF) {
        if(index >= i &&  index+1 < j) {
            toBeCopied[index2] = c1;
            toBeCopied[index2 + 1] = '\0';
            index2++;
        }
        index++;
    }
    fclose(fptr);/*closing communication with file*/
}
int length(char arr[]) {
    int length = 0;
    while (arr[length] != '\0') {
        length++;
    }
    return length;
}
int find(char word_to_find[],char name_of_file[]) {
    int index=0;
    int len=length(word_to_find);
    int i = 0;
    int found = 1;
    FILE *fptr;/*pointer to file input*/
    char c1;
    fptr = fopen(name_of_file, "r");/*open communication with file*/
    if (fptr == NULL) /*check if file opens*/    {
        printf("\nfile would not open for some reason %s", name_of_file);

    }

    while ((c1 = fgetc(fptr)) != EOF) {
        if (c1 == word_to_find[0]) { /*if the first character matches*/
            found = 1; /*assume we've found the word*/
            /*check the rest of the word*/
            for (i = 1; i < len; i++) {
                c1 = fgetc(fptr);
                if (c1 == EOF || c1 != word_to_find[i]) {
                    found = 0; /*word not found*/
                    break;
                }
            }
            if (found) {
                fclose(fptr);/*closing communication with file*/
                return index; /*return the index where the word starts*/
            }
            /*rewind the file pointer to retry for next index*/
            fseek(fptr, -i, SEEK_CUR);
        }

        index++;

    }

    fclose(fptr);/*closing communication with file*/
    return -1;/* returning -1 means word wasn't found*/
}/*seems to work, might want to check more cases*/
void conNextWord(char name_of_file[],char toBeConcatenated[],int endOfOrgWord){/*concatenates the value of the next word to a char[]*/
    FILE *fptr;/*pointer to file input*/
    char c1;
    int i=0,j=0;
    char temp[FILESIZE];
    fptr = fopen(name_of_file, "r");/*open communication with file*/
    if (fptr == NULL) /*check if file opens*/    {
        printf("\nfile would not open for some reason %s", name_of_file);

    }
    for(; i < endOfOrgWord; i++){/*get to where the end of original word was*/
        c1 = fgetc(fptr);

    }
    while((c1 = fgetc(fptr)) != EOF && c1 != ' ' && c1 != ',' && c1 != ':'&& c1 != '\0'&& c1 != '\n') {

        temp[j] = c1;
        temp[j + 1] = '\0';
        j++;
    }
    strcat(toBeConcatenated,temp);
    fclose(fptr);/*closing communication with file*/

}
void copyMacroNameAndDef(char name_of_file[],char macroName[],char macroDef[]) {/*assuming there is macro in file*/
    int macroIndex, endMacroIndex,macroNameIndex;
    macroIndex =  find(MACRO,name_of_file);
    endMacroIndex = find(ENDMACRO,name_of_file);
    conNextWord(name_of_file,macroName,macroIndex+ length(MACRO)+1);
    macroNameIndex = find(macroName,name_of_file);
    copyIndexes(name_of_file,macroDef,macroNameIndex+ length(macroName),endMacroIndex);
}
void singleMacroHandle(char name_of_file[]){/*this function goes through the file, finds macros and puts their value in every place it says the macro's name*/
    char temp[] = "temp";
    int index = 0;
    char c1;
    FILE *fptr;/*pointer to file input*/
    FILE *result_file;/*pointer to temp-middle file*/
    /*find the macro*/
    int macroStartIndex =find(MACRO,name_of_file);
    int macroEndIndex = find(ENDMACRO,name_of_file) + length(ENDMACRO);
    int m1Index ;
    char macroName[FILESIZE]="";
    char macroDef[FILESIZE]="";
    /*find name and def of next macro*/
    copyMacroNameAndDef(name_of_file,macroName,macroDef);

    /*delete macro from file*/
    deleteIndex(name_of_file,macroStartIndex,macroEndIndex);

    /*replace macro with its value*/

    m1Index = find(macroName,name_of_file);
    /*replace macro with its value*/
    while(m1Index != -1){
        fptr = fopen(name_of_file, "r");/*open communication with file*/
        if (fptr == NULL) /*check if file opens*/    {
            printf("\nfile would not open for some reason %s", name_of_file);

        }
        result_file = fopen(temp, "w");
        /* If unable to create temporary file */
        if (result_file == NULL)    {
            printf("cant open file");
            fclose(fptr);
            exit(EXIT_FAILURE);
        }
        /*copy everything before the macro*/
        while((c1 = fgetc(fptr)) != EOF) {
            if(index < m1Index )
                fputc(c1, result_file);
            index++;
        }
        /*copy the macro's value*/
        for(int i = 0; i < length(macroDef); i++){
            fputc(macroDef[i], result_file);
        }
        index =0;
        /*go back to the start of the file*/
        rewind(fptr);
        /*copy everything after the macro*/
        while((c1 = fgetc(fptr)) != EOF) {
            if(index >= m1Index + length(macroName))
                fputc(c1, result_file);
            index++;
        }
        fclose(fptr);/*closing communication with file*/
        fclose(result_file);/*closing communication with file*/
        remove(name_of_file);
        rename(temp,name_of_file);
        index = 0;

        /*find the next macro name appearance*/
        m1Index = find(macroName,name_of_file);
    }

}
void multiMacroHandle(char name_of_file[]) {/*this function goes through the file, finds macros and puts their value in every place it says the macro's name*/
    int flagMacro = find(MACRO,name_of_file);

    while(flagMacro!=-1) {
        singleMacroHandle(name_of_file);
        flagMacro = find(MACRO,name_of_file);

    }
}