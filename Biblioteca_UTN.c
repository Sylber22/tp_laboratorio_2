#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "Biblioteca_UTN.h"


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param buffer Se crea un auxiliar para cargar el dato
 * \param msg Es el mensaje a ser mostrado
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \param pResultado donde se carga el resultado
 * \return '-1' si hubo un error y '0' si esta todo bien
 */
int getInt(int* pResultado, char* msg, char* msgError)
{
    int buffer;
    int ret=-1;
    printf("%s",msg);
    if(scanf("%d",&buffer)==1)
    {
        (*pResultado)=buffer;
        ret=0;
    }
    else
    {
        printf("%s",msgError);
        fflush(stdin);
        //fpurge(stdin);
    }
    return ret;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param buffer Se crea un auxiliar para cargar el dato
 * \param msg Es el mensaje a ser mostrado
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \param pResultado donde se carga el resultado
 * \return '-1' si hubo un error y '0' si esta todo bien
 */
int getFloat(float* pResultado, char* msg, char* msgError)
{
    float buffer;
    int ret=-1;

    printf("%s",msg);
    if(scanf("%f",&buffer)==1)
    {
        (*pResultado)=buffer;
        ret=0;
    }
    else
    {
        printf("%s",msgError);
    }
    return ret;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param buffer Se crea un auxiliar para cargar el dato
 * \param msg Es el mensaje a ser mostrado
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \return El caracter ingresado por el usuario
 */
int getChar(char* pResultado,char* msg, char* msgError)
{
    char buffer;
    int ret=-1;

    printf("%s",msg);
    if(scanf("%c",&buffer)==1)
    {
        (*pResultado)=buffer;
        ret=0;
    }
    else
    {
        printf("%s",msgError);
        fflush(stdin);
        //fpurge(stdin);
    }
    return ret;
}

/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo espacios y letras y -1 si no lo es
 */
int esSoloLetras(char* str)
{
    int ret=-1;
    int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       {
         ret=0;
        }
        i++;
    }
   return ret;
}

/**
 * \brief Verifica si el valor recibido son numeros
 * \param str Array con la cadena a ser analizada
 * \return 0 si es númerico y -1 si no lo es
 */
int esNumerico(char* str)
{
    int ret=-1;
    int i=0;
    while(str[i] != '\0')
   {
        if(str[i] < '0' || str[i] > '9')
       {
          ret=0;
       }
    i++;
   }
   return ret;
}


/**
 * \brief Verifica si el valor recibido contiene solo números y guiones o espacios
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo numeros, espacios y un guion, -1 si no tiene
 */
int esTelefono(char* str)
{
    int i=0;
    int contadorGuion=0;
    while(str[i]!='\0')
    {
        if((str[i]!=' ')&&(str[i]!='-')&&(str[i]<'0' || str[i]>'9'))
        {
            return 0;
        }
        if(str[i]=='-')
        {
            contadorGuion++;
        }
        i++;
    }
    if(contadorGuion==1)
        {
            return 1;
        }
    return 0;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo espacio o letras y números, y -1 si no lo es
 */
int esAlfaNumerico(char* str)
{
    int ret=-1;
    int i=0;
    while(str[i] != '\0')
    {
       if((str[i] != ' ') &&
          (str[i] < 'a' || str[i] > 'z') &&
          (str[i] < 'A' || str[i] > 'Z') &&
          (str[i] < '0' || str[i] > '9'))
       {
           ret=0;
       }
       i++;
   }
   return ret;
}

/**
 * \brief Verifica si el valor recibido es un numero, entero o con coma
 * \param str Array con la cadena a ser analizada
 * \return 0 si es númerico y 1 si no lo es
 */
int esNumericoFlotante(char* str)
{
    int i=0;
    int contadorPuntos=0;

    while(str[i]!='\0')
    {
            if((str[i]<'0' || str[i]>'9')&&(str[i]!='.'))
        {
            return 0;
        }
        if(str[i]=='.')
        {
            contadorPuntos++;
            if(contadorPuntos>1)
            {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

/**
 * \brief Solicita un dato al usuario y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \param pResultado Array donde se cargará el dato ingresado
 * \return 0
 */
int getString(char* pResultado, char* msg)
{
    char bufferStr[20];
    printf(msg);
    fflush(stdin);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';
    if(pResultado!=NULL)
    {
        strncpy(pResultado,bufferStr,sizeof(bufferStr));
    }
      return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param pResultado Array donde se cargará el texto ingresado
 * \param magError mensaje a ser mostrado en caso de error
 * \param reintentos cantidad de reintentos habilitadas para ingresar un dato correcto
 * \return 0 si el texto contiene solo letras -1 si no
 */
int getStringLetras(char* pResultado, char* msg, char* msgError, int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while((reintentos>=0) && (ret==-1))
    {
        if(!getString(bufferStr,msg)&&(pResultado!=NULL)&&(esSoloLetras(bufferStr)))
        {
            strncpy(pResultado,bufferStr,sizeof(bufferStr));
            ret=0;
        }
        else
        {
            printf(msgError);
            reintentos--;
        }
    }
    return ret;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param pResultado Array donde se cargará el texto ingresado
  * \param magError mensaje a ser mostrado en caso de error
 * \param reintentos cantidad de reintentos habilitadas para ingresar un dato correcto
 * \return 0 si el texto contiene solo números -1 si no
 */
int getStringNumeros(char* pResultado,char* msg,char* msgError, int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg)&&(pResultado!=NULL)&&(esNumerico(bufferStr)))
        {
            strncpy(pResultado,bufferStr,sizeof(bufferStr));
            ret=0;
        }
        else
        {
             printf(msgError);
             reintentos--;
        }
    }
    return ret;
}

/**
 * \brief toma un telefono
 * \param pResultado donde se cargaran los datos
 * \param msg mensaje a ser mostrado
 * \param magError mensaje a ser mostrado en caso de error
 * \param reintentos cantidad de reintentos habilitadas para ingresar un dato correcto
 * \return 0 si es un telefono valido y -1 si no lo es
 */
int getTelefono(char* pResultado, char* msg, char* msgError,int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getStringNumeros(bufferStr,msg,msgError, reintentos)&&(pResultado!=NULL)&&(esTelefono(bufferStr)))
        {
            strncpy(pResultado,bufferStr,20);
            ret=0;
        }
        else
        {
            printf("%s",msgError);
            reintentos--;
        }
    }
    return ret;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param msg Es el mensaje a ser mostrado
 * \param pResultado Array donde se cargará el texto ingresado
 * \param magError mensaje a ser mostrado en caso de error
 * \param reintentos cantidad de reintentos habilitadas para ingresar un dato correcto
 * \return 0 si el texto contiene solo números con coma
 */
int getStringNumerosFlotantes(char* pResultado,char* msg,char* msgError, int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg)&&(esNumericoFlotante(bufferStr)))
        {
            strncpy(pResultado,bufferStr,sizeof(bufferStr));
            ret=0;
        }
        else
        {
            printf(msgError);
            reintentos--;
        }
    }
    return ret;
}
/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param Msg Es el mensaje a ser mostrado para solicitar el dato
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
float getValidFloat(char* msg, char* msgError, int lowLimit, int hiLimit)
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (getStringNumerosFlotantes(auxStr,msg, msgError,2)==-1)
        {
            printf ("%s\n",msgError);
            continue;
        }
        auxFloat = atof(auxStr);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxFloat;
    }
}
/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param Msg Es el mensaje a ser mostrado para solicitar el dato
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \param low y hi Limit, parametros delimitadores de la eleccion del numero
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char* msg,char* msgError, int lowLimit, int hiLimit)
{
    char bufferNumero[256];
    int auxInt;
    while(1)
    {
        if (getStringNumeros(bufferNumero,msg, msgError,2)==-1)
        {
            printf ("%s\n",msgError);
            continue;
        }
        auxInt = atoi(bufferNumero);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;
    }
}
/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 */

void cleanStdin(void)
{
    int x;
    do {
        x = getchar();
    } while (x != '\n' && x != EOF);
}

/**
 * \brief Menu de opciones
 * \param imprime un menu de opciones para
    que el usuario elija mediante numeros
 * \return 0
 */
int menu()
{
    int opcionElegida;
    getInt(&opcionElegida,"\n--MENU--\n\n1)Alta\n2)Modificar\n3)Baja\n4)Informar\n5)Salir\n\nIngrese una opcion: ", "\nIngrese un dato correcto");
   return opcionElegida;
}
