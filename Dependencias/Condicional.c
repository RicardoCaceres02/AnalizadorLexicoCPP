#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool SI();
bool flotante(char a[]);
bool entero(char a[]);
bool variable(char a[]);
bool color(char a[]);
char *Temporal[]={"SI","(","VARIABLE","==","7",")","{","}","SINO","{","}"};
int contador=0;

//metodo main solamente para prueba de la funcion
int main(){

        if(SI()){
            printf("Es una cadena valida\n");
        }else{
            printf("    \n hecho");
        }

    return 1;
}

bool variable(char a[]){
    return true;
}

bool color(char a[]){
    return true;
}
bool entero(char a[]){
    return true;
}
bool flotante(char a[]){
    return true;
}
//funcion si, para verificar que la instruccion fue ingresada de forma correcta
bool SI(){
	contador++;
	
	if (Temporal[contador] == "("){
		contador++;
		
		if (variable(Temporal[contador]) || flotante(Temporal[contador]) || entero(Temporal[contador])|| color(Temporal[contador])){
			contador++;
			//Se revisa que luego del caracter o cadena, sea un signo matematico valido
			if (Temporal[contador]=="==" || Temporal[contador] == "!=" || Temporal[contador] == "<" || Temporal[contador] == ">"){
				contador++;
				
				if (variable(Temporal[contador]) || flotante(Temporal[contador]) || entero(Temporal[contador])|| color(Temporal[contador])){
					contador++;
					
					if (Temporal[contador]==")"){
						contador++;
						
						if (Temporal[contador]=="{"){
							contador++;
							
                            if (Temporal[contador]=="}"){
								contador++;
								
								if (Temporal[contador]=="SINO"){
                                    contador++;
                                 
                                    if (Temporal[contador]=="{"){
                                        contador++;
                                        
                                        if (Temporal[contador]=="}"){
                                            
                                            contador++;
                                            if (Temporal[contador] == "SI" || Temporal[contador] == "MIENTRAS" || Temporal[contador] == "VAR"){
                                           
                                                return true;
                                            }else{
                                                return false;
                                            }
                                        }else{
                                            
                                            contador++;
                                            return false;
                                        }
                                    }else{
                                       
                                        contador++;
                                        return false;
                                    }
                                }else{}
                                    if (Temporal[contador] == "SI" || Temporal[contador] == "MIENTRAS"){
                                     
                                        return true;
                                    }else{
                                        return false;
                                    }
								}



		}
		
		else if(Temporal[contador]=="true" || Temporal[contador]=="false"){
			contador++;
                if (Temporal[contador]==")"){
                    contador++;
                    if (Temporal[contador]=="{"){
                        contador++;
                        if (Temporal[contador]=="}"){
                            printf("--Instruccion    SI, aceptada como valida");
                            contador++;
                            if (Temporal[contador] == "si" || Temporal[contador] == "sino" || Temporal[contador] == "mientras" || Temporal[contador] == "definir" || Temporal[contador] == "encender" || Temporal[contador] == "apagar"){
                                
                                return true;
                            }else{
                                return false;
                            }
                        }
}

