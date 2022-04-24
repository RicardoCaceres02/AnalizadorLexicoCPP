#include "Dependencias/bucle.c"
#include "Dependencias/Funciones.c"
#include "Dependencias/condicional.c"
#include "Dependencias/Numero.c"
#include "Dependencias/Expresiones.c"
#include "Dependencias/Cadena.c"
#include "Dependencias/Finalizar.c"
#include<stdio.h>
#include<stdlib.h>


bool leerArchivo();
void contarCantidadLineas();
int cantidadLineas = 0;
bool instrucciones(char cadena[]);

typedef enum {q0, q1, q2, qf, qe} TEstado;
TEstado Estado;

int ambitosAbiertos = 0;
int ambitosCerrados = 0;

struct arrChar
{
    char string[400];
};

int main()
{
    if(leerArchivo())
    {printf("Analisis sin Errores\n");}
    else
    {printf("Se encontraron Errores\n");}

    return 0;
}

bool leerArchivo()
{
    TEstado Estado = q0;

    
    char inputFilename[] = "entrada.txt";
    char outputFilename[] = "salida.txt";
    struct arrChar aux;
    *aux.string = "";

    int lineaActual=0;
    char *linea;

    FILE *ifp;
    ifp = fopen(inputFilename, "r");

    for(int i=0; linea!=NULL; i++)
    {
        lineaActual = i;
        linea = fgets(aux.string, 4000, ifp);

        switch(Estado)
        {
            case q0:
            {
                if(strcmp(linea, "INICIO\n") == 0)
                {
                    Estado = q1;
                }
                else
                {
                    Estado = qe;
                    printf("Error q0");
                }
                break;
            }
            case q1:
            {
                if(lineaActual == cantidadLineas)
                {
                    if(strcmp(linea, "FINAL\n") == 0)
                    {
                        Estado = q2;
                    }
                    else
                    {
                        Estado = qe;
                        printf("Error q1");
                    }
                }
                else if(instrucciones(linea))
                {
                    Estado = q1;
                }
                else
                {
                    Estado = qe;
                    printf("Error q1");
                }
                break;
            }
        }

        if(Estado == qe)
        {
            break;
        }

        printf("%s", linea);
    }

    if(Estado == q2)
    {
        if(ambitosAbiertos == ambitosCerrados)
        {
            Estado = qf;
        }
        else
        {
            Estado = qe;
            printf("Error q1");
        }
    }

    if(Estado == qf)
    {return true;}
    else
    {return false;}

    printf("\n\nEl archivo tiene %d lineas\n", lineaActual);
    fclose (ifp);
}

void contarCantidadLineas()
{
    char inputFilename[] = "entrada.txt";

    struct arrChar aux;
    *aux.string = "";

    int lineaActual=0;
    char *linea;

    FILE *ifp;
    ifp = fopen(inputFilename, "r");

    for(int i=0; linea!=NULL; i++)
    {
        lineaActual = i;
        linea = fgets(aux.string, 4000, ifp);
    }

    cantidadLineas = lineaActual;
}

bool instrucciones(char cadena[]){
    int longitud = strlen(cadena);
}
