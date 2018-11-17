#include <iostream>
#include <fstream>
#include <string>

using namespace std;

FILE* openArchive(char opcao){
    FILE* arch;
    switch(opcao){
        case 'r':
            arch = fopen("../src/inventory/index.txt", "r");
        break;
        case 'w':
            arch = fopen("../src/inventory/index.txt", "w");
        break;
    }

    if (arch == NULL){
        printf("Problemas na CRIACAO do arquivo\n");
    }

    return arch;
}

void closeArchive(FILE *arch){
    fclose(arch);
}

void setIndex(){
    FILE *arch;
    arch = openArchive('r');
    int index = 0;

    if(ftell(arch) != 0) {
      arch = openArchive('w');
      index = 1;
      fprintf(arch, "%d", index);
    } else {
      arch = openArchive('r');
      fscanf(arch, "%d", &index);
      index ++;
      arch = openArchive('w');
      fprintf(arch, "%d", index);
    }
    closeArchive(arch);
}

int getIndex(){
    
    setIndex();
    
    FILE *arch;
    arch = openArchive('r');
    int index = 0; 
    fscanf(arch, "%d", &index);
    return index;
}