#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

/// Falta idear la manera de que detecte el FIN de cierre
// Posible: contador de cuantas cosas se Abren, y que al finalizar de revisar el archivo verifique si la cantidad de Cierres es equivalente

char TablaSimbolos[][16] = {"FUNCION", "FIN"};
int longitudPTS[2] = {7, 3};
char *TablaSimbolosTipos[] = {"ENTERO", "FLOTANTE", "BYTE", "NUMERO", "BOOL", "LETRA", "STRING", "COLOR"};

bool funcion(char cadena[]);
bool declaracionFuncion(char cadena[]);
bool variable(char cadena[]);


int main()
{
    //printf("%s", TablaSimbolos[0]);
    //printf("%i", strlen(TablaSimbolos[0]));
    printf("%i\n", funcion("FUNCION (STRING teto)"));
    printf("%i\n", funcion("     FUNCION (BOOL oscar,LETRA romeo1234,COLOR estado)"));
    printf("%i\n", funcion("FUNCION ()"));
    return 0;
}
bool declaraF(char cadena[]){
    int longitud = strlen(cadena);
    int i=0;
    typedef enum {q0,q1,q2,q3,qe} TEstado;
    //printf("%s: ",cadena);
    TEstado Estado = q0;
    bool tipoEncontrado = false;//declaramos si se ha encontrado la palabra que define una variable
    int tam= sizeof(TablaSimbolosTipos) / sizeof(char *);
    //el token almacenara la cadena propuesta
    char *token2;
    //delimitara y separara las cadenas por un espacio
    token2 = strtok(cadena, " ");
        //printf("%s:\n",token2);
        if(token2 != NULL){
            //recorreremos toda la cadena
            for(i; i<longitud; i++)
            {
                //printf("siguiente");
                //revisaremos si la primer palabra se encuentra en la tabla
                for(int j=0; j<tam; j++)
                {
                    tipoEncontrado = true;//establecemos un estado de true
                    //printf("%s \n",TablaSimbolosTipos[j]);

                    if(strcmp(token2,TablaSimbolosTipos[j]) != 0)//se comprueba que sean iguales
                    {
                        tipoEncontrado = false;//si no son iguales se coloca el estado de false
                    }

                    if(tipoEncontrado)
                    {
                        break;//si se encontro rompemos el ciclo
                    }
                }

                if(tipoEncontrado)
                {
                    break;
                }
            }
        }

        //comprobamos que se halla encontrado
        if(tipoEncontrado==true)
        {
            Estado = q1;//cambiamos de estado


            //printf("%i\n", tipo);

            //printf("%i\n", longitud-strlen(TablaSimbolosTipos[tipo]));
            //printf("entre %s\n",token2);
            token2 = strtok(NULL, " ");//cambiamos al sig token2
            //printf("entre %s\n",token2);
            if(token2 != NULL)
            {
                switch(Estado)
                {
                    case q1:
                    {
                        if(variable(token2))//comprobamos que la variable cumpla con lo requerido para ser aceptada
                        {
                            Estado = q2;
                        }
                        else
                        {
                            Estado = qe;
                            //printf("Error q1: ");
                        }
                        break;
                    }
                    case q2:
                    {
                        if(variable(token2))
                        {
                            Estado = q2;
                        }
                        else
                        {
                            Estado = qe;
                            //printf("Error q2: ");
                        }
                        break;
                    }
                }
            }
        }
        else
        {
            Estado = qe;
            printf("Error q0: ");
        }
}


bool variable(char cadena[])
{
    //printf("%s: ", cadena);
	typedef enum {q0,q1,q2,qe} TEstado;

	TEstado Estado = q0;
	int Simbolo;
	int longitud = 0;
	int i = 0;

	longitud = strlen(cadena);

	while (longitud > i && Estado != qe)
    {
		Simbolo = cadena[i];

		switch (Estado)
		{
			case q0:
            {
				if ((Simbolo >= 'a' && Simbolo <= 'z') || (Simbolo >= 'A' && Simbolo <= 'Z'))
                {
					Estado = q1;
				}
				else
				{


					Estado = qe;
					//printf("Error Variable q0: ");
				}
				break;
            }
			case q1:
            {
				if ((Simbolo >= 'a' && Simbolo <= 'z') || (Simbolo >= 'A' && Simbolo <= 'Z'))
                {
					Estado = q1;
				}
				else if (Simbolo >= '0' && Simbolo <= '9')
                {
					Estado = q2;
				}
				else
				{
					Estado = qe;
					//printf("Error Variable q1: ");
				}
				break;
            }
            case q2:
            {

				if (Simbolo >= '0' && Simbolo <= '9')
                {
					Estado = q2;
				}
				else
				{
					Estado = qe;
					//printf("Error Variable q2: ");
				}
                break;
            }
		}

		// Si llega al estado de error, se detiene el analisis
		if (Estado == qe)
        {
            break;
        }

        i++;
	}

	if (Estado==q2 || Estado==q1)
    {
		return true;
	}
	else
	{
		return false;
	}
}

bool funcion(char cadena[])
{
    typedef enum {q0,q1,q2,qe} TEstado;

    TEstado Estado = q0;

    int longitud = strlen(cadena);//longitud de la cadena

    //se comprueba que la longitud de la cadena sea menor que la palabra clave FUNCION
    if(longitud >= strlen(TablaSimbolos[0]))
    {
        int inicioFUNCION;
        //sacomos el inicio real de la funcion para verificar los parametros
        for(int i=0; i<longitud; i++)
        {
            if(cadena[i] == TablaSimbolos[0][0])
            {
                inicioFUNCION = i;
                break;
            }
        }

        //se guarda la palabra y se compara con la tabla de simbolos
        char subCadena_1[longitudPTS[0]+1];
        strncpy(subCadena_1, &cadena[inicioFUNCION], longitudPTS[0]);
        subCadena_1[longitudPTS[0]] = '\0';

        if(strcmp(subCadena_1, TablaSimbolos[0]) == 0) // que sean iguales
        {
            Estado = q1;//cambiamos a estado 1

            int inicioDeclaracion, finDeclaracion = 0;
            //calculamos el ininio y final de la declaracion de paramentro, limitados por los parentesis
            for(int i=8; i<longitud; i++)
            {
                if(cadena[i] == '(')
                {
                    inicioDeclaracion = i;
                }

                if(cadena[i] == ')')
                {
                    finDeclaracion = i;
                    break;
                }
            }

            //comprobamos que existe un final, es decir, un parentecis de cierre
            if(finDeclaracion > 0)
            {
                int inicio=inicioDeclaracion;//guardamos el inicio
                if(inicioDeclaracion==finDeclaracion-1){
                    Estado = q2;//si lo esta cambiamos de estado
                }else{
                    //creamos todas las cadenas separadas por una ',' y estas siendo analizadas de forma independiente.
                    for(int e=inicioDeclaracion+1;e<finDeclaracion;e++){
                        //se calcula en que pocicion se encontro una coma
                        if(cadena[e] == ','){
                            //creamos una intancia que nos guarda esa seccion de cadena
                            char condicion[e-inicio];
                            strncpy(condicion, &cadena[inicio+1], (e-inicio));
                            condicion[e-inicio-1] = '\0';
                            //printf("lo esta haciendo: %s\n",condicion);

                            if(declaraF(condicion))//llamamos a la funcion para que compruebe si esta bien
                            {
                                Estado = q2;//si lo esta cambiamos de estado
                            }
                            else
                            {
                                Estado = qe;//sino, da un error
                                printf("Error q1: ");
                            }
                            inicio = e;
                        }
                        //lo colvemos a realizar asegurando tomar el ultimo elemento de la cadena, o el unico parametro definido
                        if(e==finDeclaracion-1){
                            char condicion[e-inicio+1];
                            strncpy(condicion, &cadena[inicio+1], (e-inicio+1));
                            condicion[e-inicio] = '\0';
                            //printf("lo desarrollo: %s\n",condicion);//
                            if(declaraF(condicion))
                            {
                                Estado = q2;
                            }
                            else
                            {
                                Estado = qe;
                                printf("Error q1: ");
                            }
                        }
                    }
                }
                //printf("%s\n", condicion);

            }
            else
            {
                Estado = qe;
                printf("Error q1: ");
            }
        }
        else
        {
            Estado = qe;
            printf("Error q0: ");
        }
    }
    else
    {
        Estado = qe;
        printf("Error q0: ");
    }

    if(Estado == q2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
