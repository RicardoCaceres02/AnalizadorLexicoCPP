#include"Expresiones.c"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


char simbolos[][16] = {"MIENTRAS", "HACER", "FIN"};
int longitudPTS[3] = {8, 5, 3};

bool mientras(char cadena[]);



bool mientras(char cadena[])
{
    typedef enum {q0,q1,q2,q3,qe} TEstado;

    TEstado Estado = q0;

    int longitud = strlen(cadena);

    if(longitud >= strlen(simbolos[0]))
    {
        int inicioMIENTRAS;
        for(int i=0; i<longitud; i++)
        {
            if(cadena[i] == simbolos[0][0])
            {
                inicioMIENTRAS = i;
                break;
            }
        }
        char subCadena_1[longitudPTS[0]+1];
        strncpy(subCadena_1, &cadena[inicioMIENTRAS], longitudPTS[0]);
        subCadena_1[longitudPTS[0]] = '\0';

        

        if(strcmp(subCadena_1, simbolos[0]) == 0) // Iguales
        {
            Estado = q1;

            int inicioCondicion, finCondicion = 0;
            for(int i=8; i<longitud; i++)
            {
                if(cadena[i] == '(')
                {
                    inicioCondicion = i;
                }

                if(cadena[i] == ')')
                {
                    finCondicion = i;
                    break;
                }
            }

            if(finCondicion > 0)
            {
                char condicion[(finCondicion-inicioCondicion-1)+1];
                strncpy(condicion, &cadena[inicioCondicion+1], (finCondicion-inicioCondicion));
                condicion[finCondicion-inicioCondicion-1] = '\0';
                //printf("%s\n", condicion);

                if(expresion(condicion))
                {
                    Estado = q2;

                    char subCadena_2[(longitud-finCondicion-1)+1];
                    strncpy(subCadena_2, &cadena[finCondicion+1], longitud);
                    subCadena_2[longitud-finCondicion-1] = '\0';
                    //printf("%s\n", subCadena_2);

                    for(int i=finCondicion+1; i < longitud; i++)
                    {
                        if(cadena[i] == ' ')
                        {
                            continue;
                        }

                        if(cadena[i] == simbolos[1][0])
                        {
                            char PR_HACER[longitudPTS[1]+1];
                            strncpy(PR_HACER, &cadena[i], longitudPTS[1]);
                            PR_HACER[longitudPTS[1]] = '\0';

                            
                            if(strcmp(PR_HACER, simbolos[1]) == 0)
                            {
                                Estado = q3;
                            }
                           

                            break;///////////////////////////////////////////////
                        }
                 
                        

    if(Estado == q3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
