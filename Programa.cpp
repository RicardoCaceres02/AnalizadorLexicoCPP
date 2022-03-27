#include <iostream>

using namespace std;

int main()
{
 FILE *lectura;
    char CadenaMixta [1000];
/*********Abriendo el archivo para su lectura*************************/

    lectura = fopen("Lectura.txt" , "r");

    /***Identificando si no contiene caracteres nulos*****************/

    if(lectura == NULL) printf("Archivo vacío");
    else{

        /***Mientras el caracter no sea nulo**************************/

        while (! feof (lectura))
        {

            /***Leyendo cada parte del arrerglo hasta que sea nulo  ***/

            if (fgets (CadenaMixta , 1000 , lectura)==NULL)break;

            /**Imprimiendo el contenido del archivo********************/

            fputs (CadenaMixta , stdout);
        }
        /***Cerrando el archivo***/
        fclose (lectura);
    } 

    return 0;
}
