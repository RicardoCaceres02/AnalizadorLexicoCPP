
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main( )
{
    
    typedef enum {q0,q1,q2,q3,q4} TEstado;
    TEstado Estado;
    char secundari[100]; 
    int Simbolo;  


    int i; 
    int longitud; 
    i = 0;
    longitud = 0;
    Estado = q0;


    printf("estado %d: ", q0);
    printf("Ingrese una cadena de numeros: ");
    scanf("%s", &secundari);
    printf("letra: %s\n\n",secundari);
    longitud = strlen(secundari);
    printf("tamanio cadena ingresada: %d", longitud);

    while(secundari[i] !='\0')
    {


        
        printf("impreme : %s", &secundari[i]);
        switch ( Estado)
        {
        case q0:
            
            if(secundari[i] == '-' || secundari[i] == '+' )
            {Estado = q1;}else{Estado = q1;}
            break;
        case q1:
            
            if(secundari[i] >= '0' && secundari[i] <= '9')
            {Estado = q2;}
            break;
        case q2:
            
            if(secundari[i] >= '0' && secundari[i] <= '9')
            {Estado = q2;}
            else
            {
                if(secundari[i] == '.')
                {Estado = q3;}
            }
            break;
        case q3:
            if(secundari[i] >= '0' && secundari[i] <= '9')
            {
                Estado = q4;
            }
            break;
        case q4:
            if(secundari[i] >= '0' && secundari[i] <= '9')
            {Estado = q4;}
            break;
        }
     

        if(!(secundari[i] >= '0' && secundari[i] <= '9') ||

                !(secundari[i] == '.'))
        {
            break;}
       
        i++;

    }

    if(Estado == q4)
        printf("Cadena acepatada");
    else
        printf("Cadena No acepatada");

    return 0;
}
