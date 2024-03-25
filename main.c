#include <stdio.h>
#include <string.h>
#include "macros_handler.h"

#include "funcs.h"

int main() {
    char name_of_file[FILESIZE];
    char name_of_file2[FILESIZE];
    strcpy(name_of_file, "C:/Users/Omer/CLionProjects/untitled1/test1_02.as");/*copy name into the char arr*/
    strcpy(name_of_file2,  name_of_file);/*copy string*/
    strcat(name_of_file2,COPY);/*concatenate*/

    printFile(name_of_file);
    perfectSpaces(name_of_file);

    multiMacroHandle(name_of_file);
    printFile(name_of_file);



    return 0;
}
