#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main( )
{
    //Tipos de dato Estados

    typedef enum {q0,q1,q2} TEstado;
    //variable de estado
    TEstado Estado;

    //variables
    char secundari[100]; // es donde se almacenara la cadena
    bool EsNumero;

    int i; //iterador


    //Definiciendo los valores iniciales
    i = 0;
    int longitud = 0;
    Estado = q0;
    printf("estado %d: ", q0);


    printf("Ingrese una cadena de numeros: ");
    scanf("%s", &secundari);
    printf("letra: %s\n\n",secundari);
    longitud = strlen(secundari);
    printf("tamanio cadena ingresada: %d", longitud);



    while(secundari[i] !='\0')
    {

        EsNumero = (secundari[i] >= '0' && secundari[i] <= '9');

        switch (Estado)
        {
        case q0:
            //Si es un simbolo valido cambia de estado en este caso menos(-) o mas(+)
            if(secundari[i] == '-' || secundari[i] == '+' )
            {
                Estado = q1;
            }else{
                Estado = q1;
            }
            break;
        case q1:
            //Si secundari[i] es un digito entre cero y nueve cambia de estado
            if(EsNumero)
            {
                Estado = q2;
            }
            break;

        case q2:
            //Si secundari[i] es un digito entre cero y nueve no cambia de estado
            if(EsNumero)
            {
                Estado = q2;
            }
            break;
        }

        //iterador aunmeta y avanza al siguiente caracter de la cadena
        i++;

    }

    if(Estado == q2)
        printf("Cadena acepatada");
    else
        printf("Cadena No acepatada");

    return 0;
}
