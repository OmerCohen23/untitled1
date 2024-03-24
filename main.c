#include <stdio.h>
#include <string.h>
#include "macros_handler.h"

#include "funcs.h"

int main() {



    char name_of_file[FILESIZE];
    char name_of_file2[FILESIZE];
    char mcrName[FILESIZE]="";
    char mcrDef[FILESIZE] = "";
    FILE* file2;
    strcpy(name_of_file, "C:/Users/Omer/CLionProjects/untitled1/test1_02.as");/*copy name into the char arr*/
    strcpy(name_of_file2,  name_of_file);/*copy string*/
    strcat(name_of_file2,COPY);/*concatenate*/
    printf();



    perfectSpaces(name_of_file);
    indexPrintFile(name_of_file);
    printf("\n");
    printf("\nfind:%i\n",find("mcro",name_of_file));
    printf("\nfind:%i\n",find("endmcro",name_of_file));
    copyMacroNameAndDef(name_of_file,mcrDef,mcrName);
    printf("\nname:%s\n",mcrName);
    printf("\ndef:%s\n",mcrDef);

//    if(mcrptr=='m') printf("%c",mcrptr);

    //printFile(name_of_file2);
    return 0;
}
