#include "bucle.c"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char TablaSimbolosTipos[][16] = {
    "ENTERO", 
    "FLOTANTE",
    "BYTE", 
    "NUMERO", 
    "BOOL", 
    "LETRA", 
    "STRING", 
    "COLOR"
    };


bool declaracion();
bool declaracionFuncion();



bool declaracion(char cadena[])
{
    typedef enum {q0,q1,q2,q3,qe} TEstado;

    TEstado Estado = q0;

    int longitud = strlen(cadena);


    char scTipo[16];
    bool tipoEncontrado = false;
    int inicioTipo = 0;
    int tipo = 0;
    for(int i=0; i<longitud; i++)
    {
        for(int j=0; j<strlen(TablaSimbolosTipos); j++)
        {
            if(cadena[i] == TablaSimbolosTipos[j][0])
            {
                tipoEncontrado = true;
                inicioTipo = i;
                tipo = j;

                strncpy(scTipo, &cadena[i], strlen(TablaSimbolosTipos[j])+1);
                scTipo[strlen(TablaSimbolosTipos[j])] = '\0';
                
            }
        }

        if(tipoEncontrado)
        {
            break;
        }
    }
    tipoEncontrado = false;

    //printf("%s", scTipo);
    if(strcmp(scTipo, TablaSimbolosTipos[tipo]) == 0)
    {
        tipoEncontrado = true;
    }

    if(tipoEncontrado==true)
    {
        Estado = q1;

        char subCadena_1[longitud-strlen(TablaSimbolosTipos[tipo]) + 1];
        strncpy(subCadena_1, &cadena[strlen(TablaSimbolosTipos[tipo])+1], longitud-strlen(TablaSimbolosTipos[tipo]));
        subCadena_1[longitud-strlen(TablaSimbolosTipos[tipo])] = '\0';
    

        char *token;
        token = strtok(subCadena_1, ",");

        while(token != NULL)
        {

            switch(Estado)
            {
                case q1:
                {
                    if(variable(token) || asignacion(token))
                    {Estado = q2;
                    else
                    {Estado = qe;}
                    break;
                }
                case q2:
                {
                    if(variable(token) || asignacion(token))
                    {Estado = q2;}
                    else
                    {Estado = qe}
                    break;
                }
            }

            token = strtok(NULL, ",");
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


bool declaracionFuncion(char cadena[])
{
    typedef enum {q0,q1,q2,q3,qe} TEstado;

    TEstado Estado = q0;

    int longitud = strlen(cadena);

        char cadenaTemporal[longitud + 1];
        strcpy(cadenaTemporal, cadena);
        cadenaTemporal[longitud] = '\0';
    
        char *token;
        token = strtok(cadenaTemporal, ",");

        while(token != NULL)
        {
            printf("\n TOKEN: %s\n", token);
            char partes[strlen(token)];
    
            strcpy(partes, token);
            char *declaraciones;
            declaraciones = strtok(partes," ");
            int porciones = 0;
            while(declaraciones != NULL)
            {
                printf("\n%s\n", declaraciones);

                switch(Estado)
                {
                    case q0:
                    {
                        char scTipo[16];
                        bool tipoEncontrado = false;
                        int inicioTipo = 0;
                        int tipo = 0;
                        for(int i=0; i<longitud; i++)
                        {
                            for(int j=0; j<strlen(TablaSimbolosTipos); j++)
                            {
                                if(declaraciones[i] == TablaSimbolosTipos[j][0])
                                {
                                    tipoEncontrado = true;
                                    inicioTipo = i;
                                    tipo = j;

                                    strncpy(scTipo, &cadena[i], strlen(TablaSimbolosTipos[j]));
                                    scTipo[strlen(TablaSimbolosTipos[j])] = '\0';
                                    //printf("%s : %i\n", scTipo, strlen(scTipo));
                                    break;
                                }
                            }

                            if(tipoEncontrado)
                            {
                                break;
                            }
                        }

                        if(strcmp(scTipo, TablaSimbolosTipos[tipo]) == 0)
                        {
                            Estado = q1;
                        }
                        else
                        {
                            Estado = qe;
                            printf("Error q0: \n");
                        }

                        break;
                    }
                    case q1:
                    {
                        if(variable(declaraciones))
                        {Estado = q2;}
                        else
                        {Estado = qe;
                        printf("Error q1: ");}

                        break;
                    }
                    case q2:
                    {
                        if(porciones > 2)
                        {printf("Error");}

                        break;
                    }
                }

                porciones++;
                declaraciones = strtok(NULL, " ");
            }

            token = strtok(NULL, ",");
        }
}
