
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


char TablaSimbolos[7] = {'mientras','si','sino','para','definir','encender','apagar'};
char Temporal[200];
char variable[200];

//Contador
int contador;

bool cadena(char palb[]);
bool apagar();


void tokens(){
	char *token;
	int n = 0;
	int TamanioTemporal;
	token = strtok(cadena, " ,;");
	int TamanioArreglo = sizeof TablaSimbolos/sizeof TablaSimbolos[0];


	while(token){
       char *comando = token;

		for (TamanioTemporal = 0; TamanioTemporal<TamanioArreglo; TamanioTemporal++){
			//comparamos si el comando existe en  nuestra tabla de simbolos
			if (strcmp(&comando,TablaSimbolos[TamanioTemporal])==0){
				printf("Comando reconocido: %s", &comando);

				break;
			}
		}
		
		token = strtok(NULL," ,;");
		Temporal[n] = &comando;
		n++;
	}
	TamanioTemporal = n;
}




bool cadena(char palb[]){
	int conta =0;
	while(conta< strlen(palb)){
        if(!(palb[conta]>='A' && palb[conta] <= 'Z' || palb[conta]>='a' && palb[conta] <= 'z'
                        || palb[conta]>= '0' && palb[conta] <= '9')){
            return false;
        }
        conta++;
    }
    return true;
}



bool apagar(){
    int centinela = 0;
    int i= 0;
    contador ++;

    if(cadena(Temporal[contador]))
    {
        char var = Temporal[contador];
        int arrayTamanio = sizeof variable/sizeof variable[0];
        for(i = 0; i < arrayTamanio; i++)
        {

            if (strcmp(var,variable[i])==0)
            {
                if (cadena(Temporal[contador]))
                {
                    centinela = 1;
                    printf("Instruccion valida, apagando...%s", Temporal[contador]);
                    contador ++;

                }
                else
                {
                    contador ++;
                    return false;

                }
            }
            else
            {
                printf("");
            }
        }
        if (centinela == 0)
        contador++;
    }
    
    }



