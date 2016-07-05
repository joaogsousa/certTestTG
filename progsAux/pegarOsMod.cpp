#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc,char** argv){
    ifstream input;
    ofstream output;
    if(argc != 2){
        printf("Erro args\n");
        return 1;
    }
    
    input.open(argv[1]);
    if(!input.is_open()){
        printf("Erro ao abrir cert\n");
    }
    
    int i,j;
    char straux[2000];
    for(i = 0;i<9;i++){
        input.getline(straux,2000);
    }
    
    input.getline(straux,2000);
    
    char strModulus[2000];
    j = 0; i = 0;
    while(straux[i] != '\0'){
        if(straux[i] != ':' && straux[i] != '\''){
            strModulus[j] = straux[i];
            j++;
        }
        i++;
    }
    strModulus[j] = '\0';
    
    char outName[300] = "modDir/";
    
    strcat(outName,argv[1]);
    
    output.open(outName);
    output << strModulus;
    
    input.close();
    output.close();
    
    
    return 0;
}