#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

#define DIR certificados/
#define NUMCERT 500000

using namespace std;

int main(int argc,char** argv){
	ifstream inCerts;
	ofstream output;
	
	if(argc != 4){
		printf("arg errados - mande o arquivo de certs, o nome do diretorio output e a posicao a ser lida\n");
		return 1;
		
	}

	inCerts.open(argv[1]);
	
	if(!inCerts.is_open()){
		printf("arquivo indisponivel\n");
		return 1;
		
	}
	int achou = 0;
        if(atoi(argv[3]) == 0){
            inCerts.seekg(1200,inCerts.beg);
            
            while(!achou){
		if(inCerts.get() == 'V' && inCerts.get() == 'A' && inCerts.get() == 'L' && inCerts.get() == 'U'){
			achou = 1;
		}
            }
        }else{
            inCerts.seekg(atoi(argv[3]),inCerts.beg);
        }
	
	
	int numCert = 1;
	char aux;
	int count = 0;
	int escaped;
        int sair;
        
        string meuDir(argv[2]);
        string nomeCert;
        nomeCert += meuDir;
        nomeCert += "/cert";
	string nomeFinal;
	while(count < NUMCERT){
		nomeFinal.clear();
                nomeFinal += nomeCert;
		nomeFinal += to_string(numCert);
		output.open(nomeFinal.c_str());
		
                if(!output.is_open()){
                    cout << "Problema ao gerar arquivo output, veja memória" << endl;
                    exit(1);
                }
		
		while(inCerts.get() != '('){
		}
		
		escaped = 0;
		sair = 0;
		while(!sair){
		
			while((aux = (char)inCerts.get()) != ',' || escaped){
				if(!escaped && aux == ')'){
					sair = 1;
					break;
				}
								
				if(aux == (char)39){
					if(escaped){
						escaped = 0;
					}else{
						escaped = 1;
					}
				}
				
				output << aux;
				
			}
			
			output << endl;
		
		}
		count++;
		output.close();
		numCert++;
	}
	
	cout << "Lido ate posicao: " << inCerts.tellg() << endl;



	return 0;
}
