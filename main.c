#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca_UTN.h"
#include "BibliotecaArrayEmployees.h"

#define CANT_EMPLEADOS 1000
#define TAM_SECTORS 5

int main()
{
    char seguir= 's';

    Employee nomina[CANT_EMPLEADOS];

    int flagDatosIngresados=0;
    int freePlace;
    //INICIALIZAR
    emp_InitEmployees(nomina,CANT_EMPLEADOS);

   do
    {
        switch(menu())
        {
       case 1://ALTAS
            emp_FindFree(nomina, CANT_EMPLEADOS, &freePlace);
            //printf("%d Lugar libre-\n ", freePlace);
            if(freePlace>=0)
            {
                emp_NewEmployee(nomina,CANT_EMPLEADOS);
                flagDatosIngresados=1;
            }
            break;
        case 2://MODIFICAR
                if(flagDatosIngresados==0)
            {

                printf("No hay datos que mostrar\n");
            }
            else
            {
                emp_ModifyEmployee(nomina,CANT_EMPLEADOS, nomina[CANT_EMPLEADOS].idUnico);
            }
            /*system("pause");
            system("cls");*/
            break;
        case 3://BAJAS
             if(flagDatosIngresados==0)
            {
                printf("No hay datos ingresados.");
            }
              else
                {
                    emp_RemoveEmployee(nomina, CANT_EMPLEADOS, nomina[CANT_EMPLEADOS].idUnico);
                    flagDatosIngresados=1;
                }
            break;
        case 4://INFORMAR
             if(flagDatosIngresados==0)
            {
                printf("No hay datos ingresados.");
            }
              else
                {
                    emp_SortEmployees(nomina, CANT_EMPLEADOS);
                    flagDatosIngresados=1;
                }
            break;
        case 5:
            seguir='n';
            printf("EXIT ==>");
            break;
        default :
            printf("\n-INGRESO MAL EL DATO-\n");
            system("pause");
            system("cls");
        }
    }while(seguir == 's');
    return 0;
}
