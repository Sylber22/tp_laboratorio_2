#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define CANT_EMPLEADOS 10
#define TAM_SECTORS 5

#include "Biblioteca_UTN.h"
#include "BibliotecaArrayEmployees.h"

static int generateId(void)
{
    static int id = 0;
    id ++;
    return id;
}

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in 0 in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int emp_InitEmployees(Employee* list, int len)
{
    int ret = -1;
     if ((list!=NULL) && (len>=0))
     {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty= 0;
            ret =0;
        }
     }
     return ret;
}

/** \brief This funcion look for the fist empty place in the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param pResult pointer type int* to the empty direccion
 * \return int Return (-1) if Error [Invalid length or NULL pointer] -
     (0) if Ok-1 if there is no empty place
 */
int emp_FindFree(Employee* list, int len, int* pResult)
{
    int ret=-1;
    int i;
    for(i=0;i<len;i++)
        {
            if(!list[i].isEmpty)
            {
                (*pResult)=i;
                ret=0;
                break;
            }
            ret =-1;
        }
    return ret;
}

/** \brief carga un empleado nuevo
* \param list employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or
NULL pointer or without free space] - (0) if Ok
*/
int emp_NewEmployee(Employee* list,int len)
{
    char name[51];
    char lastName[51];
    float salary;
    int idSector;
    int r=1;
    int index;

    emp_FindFree(list, len, &index);

    if(!emp_FindFree(list, len, &index))
            {
                getStringLetras(name,"Ingrese nombre del empleado/a: ", "\n-INGRESO MAL EL DATO-\n", 2);
                getStringLetras(lastName, "Ingrese apellido del empleado/a: ", "\n-INGRESO MAL EL DATO-\n", 2);
                salary=getValidFloat("\nIngrese salario: ","\n-INGRESO MAL EL DATO-\n",0,1000000);
                idSector=getValidInt("Ingrese sector:\n1)RRHH\n2)Ventas\n3)Compras\n4)Contable\n5)Sistemas\n Elija sector correspondiente: ","\n-INGRESO MAL EL DATO-\n",1,5);

                r= emp_AddEmployee(list, len,name, lastName, salary, idSector, index);
                if (!r)
                {
                    printf("-alta-\n");
                    emp_PrintEmployees(list, len);
                }
            }
            else
            {
                printf("-No hay lugar para ingresar otro empleado/a.-");
            }
    return r;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary char
* \param sector int
* \return int Return (-1) if Error [Invalid length or
NULL pointer or without free space] - (0) if Ok
*/
int emp_AddEmployee(Employee* list,
                int len,
                char* name,
                char* lastName,
                float salary,
                int idSector,
                int index)
{
    int ret=-1;
    Employee auxList;

   if ((index>=0) && (list !=NULL))
   {
       strncpy(auxList.name, name, sizeof(auxList.name));
       strcpy(auxList.lastName, lastName);
       auxList.salary= salary;
       auxList.idSector= idSector;
       auxList.idUnico=generateId();
       auxList.isEmpty= 1;
       list[index] = auxList;
       ret=0;
   }
   else
    {
        printf("No hay lugar para agregar un nuevo empleado/a.");
    }
    return ret;
}


/** \brief Muestra un unico empleado
 * \param lista array de empleados
 * \param index int posicion del array a ser mostrada
 * \return int 0 si los datos se cargaron correctamente 1 si hubo un error
 */
int emp_PrintOnlyEmployee(Employee* list, int index)
{
    int ret=-1;
    if(list!=NULL)
    {
        if(list[index].isEmpty == 1)
        {
            printf("%d\t    %s\t    %s\t    %.2f\t    %d \n",list[index].idUnico,
                                                             list[index].name,
                                                             list[index].lastName,
                                                             list[index].salary,
                                                             list[index].idSector);
            ret=0;
        }
    }
    return ret;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param len int
* \return int 0 si los datos se cargaron correctamente 1 si hubo un error
*/
int emp_PrintEmployees(Employee* list, int len)
{
    int ret=-1;
    int i;
    if(list!= NULL)
    {
        printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");
        for( i=0; i<len ; i ++ )
        {
            if(list[i].isEmpty == 1)
            {
              emp_PrintOnlyEmployee(list,i);
              ret=0;
            }
        }
    }
    return ret;
}
/** \brief modifica datos existentes
 *
 * \param lista del array
 * \param tamaño del array
  * \param idUnico identidicacion del empleado a modificar
 * \return 0 si hubo alguna modificacion 1 si no se logro
 */

int emp_ModifyEmployee(Employee* list ,int len, int idUnico)
 {
     char seguir='n';
     int ret=-1;
     char bufferName[51];
     char bufferLastName[51];
     float bufferSalary;
     int bufferIdSector;
     int place;

     idUnico= getValidInt("Ingrese ID a modificar: ", "\n-INGRESO MAL EL DATO-\n",0,1000);
     place=emp_FindEmployeeById(list,len,idUnico);

     if((list!=NULL) && (place>=0))
     {
         do
         {
            printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");
            emp_PrintOnlyEmployee(list, place);
            switch(menuModificar())
            {
                case 1:
                       if(!getStringLetras(bufferName,"Ingrese nombre:", "\n-INGRESO MAL EL DATO-\n",2));
                      {
                           strcpy(list[place].name, bufferName);
                           ret =0;
                       }
                break;
                  case 2:
                       if(!getStringLetras(bufferLastName,"Ingrese apellido:", "\n-INGRESO MAL EL DATO-\n",2));
                       {
                           strcpy(list[place].lastName, bufferLastName);
                           ret =0;
                       }
                break;
                  case 3:
                      bufferSalary=getValidFloat("Ingrese salario:\n","\n-INGRESO MAL EL DATO-\n", 0, 1000000);
                      list[place].salary=bufferSalary;
                      ret=0;
                break;
                  case 4:
                      bufferIdSector=getValidInt("Ingrese sector:\n","\n-INGRESO MAL EL DATO-\n", 0, 200);
                      list[place].idSector=bufferIdSector;
                      ret=0;
                break;
                 case 5:
                        seguir='n';
                        printf("BACK <==\n");
                        system("pause");
                        system("cls");
                     break;
                  default:
                    printf("\n-INGRESO MAL EL DATO-\n");
            }//SWITCH

            }while(seguir=='s' || seguir=='S');
         }//IF
          else if(place< 0)
        {
            printf("\n-INGRESO MAL EL DATO-\n");
        }
         return ret;
}

/** \brief menu
 * \param le pide al usuario que eliga una opcion
 * \param muestra las opciones del menu
 * \return la opcion elegida
 */
int menuModificar()
{
    int opcionElegida;
    getInt(&opcionElegida,"\n--MODIFICAR--\n\n1)Nombre\n2)Apellido\n3)Salario\n4)Sector\n5)Atras\n\nIngrese una opcion: ", "\nIngrese un dato correcto");
   return opcionElegida;
}

 /** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*/
int emp_FindEmployeeById(Employee* list, int len,int idUnico)
{
    int ret= -1;

    for (int i=0; i<len; i++)
        {
            if (list[i].isEmpty == 1 && list[i].idUnico == idUnico)
            {
            ret = i;
            break;
        }
    }
    return ret;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
*  find a employee] - (0) if Ok
*/
int emp_RemoveEmployee(Employee* list, int len, int idUnico)
{
    int ret=-1;
    int i;
    int place;

    if(list!=NULL)
    {
        printf("\n Ingrese el ID a borrar: ");
        scanf("%d",&idUnico);

        place= emp_FindEmployeeById(list, len, idUnico);

        if(list[place].isEmpty==0)
        {
            printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");

            emp_PrintOnlyEmployee(list, place);
        }
        for( i=0; i<len; i++)
        {
            if(place >= 0)
            {
                printf("\n El usuario fue eliminado.\n");
                list[place].isEmpty = 0;
                ret=0;
                 break;
            }
            else
            {
                printf("\n-INGRESO MAL EL DATO-\n");
                break;
           }
        }
    }
    return ret;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int emp_SortEmployees(Employee* list, int len)
{
    char seguir='s';
    int ret=-1;

    if((list!=NULL) && (len>0))
    {
        do{
          switch(menuOrdenar())
        {
        case 1://ASCENDENTE
           if(!emp_AscendentSort(list, len))
           {
                emp_PrintEmployees(list, len);
                ret=0;
           }
           else
            {
             printf("\n-IMPOSIBLE ORDENAR-\n");
            }
            break;
        case 2://DESCENDIENTE
            if(!emp_DecendenSort(list, len))
           {
                emp_PrintEmployees(list, len);
                ret=0;
           }
           else
            {
             printf("\n-INGRESO MAL EL DATO-\n");
            }
            break;
        case 3://PROMEDIOS
               emp_AverageSalary(list, len);
            break;
        case 4://ATRAS
                seguir='n';
                printf("BACK <==\n");
                system("pause");
                system("cls");
                    break;
        default:
            printf("\n-INGRESO MAL EL DATO-\n");

        }
    }while(seguir=='s' || seguir=='S');
   }//IF
return ret;
}

/** \brief menu
 * \param le pide al usuario que eliga una opcion
 * \param muestra las opciones del menu
 * \return la opcion elegida
 */
int menuOrdenar()
{
    int opcionElegida;
    getInt(&opcionElegida,"\n--ORDENAR POR APELLIDO--\n\n1)Ascendente \n2)Descendente\n3)Promedios\n4)Atras\n\nIngrese una opcion: ",
           "\nIngrese un dato correcto");
   return opcionElegida;
}

/** \brief ordenamiento ascendiente
 * \param lista de array
 * \param len tamaño del array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int emp_AscendentSort(Employee* list, int len)
{
    Employee bufferList;
    int ret=-1;
    int i;
    int j;

    if ((list!=NULL) && (len>0))
        {
        for (i=0; i<len-1; i++)
        {
            for (j=i+1; j<len; j++)
            {
                if (list[i].isEmpty == 1)
                {
                    if (strcmp(list[i].lastName,list[j].lastName) > 0)
                    {
                        bufferList = list[i];
                        list[i] = list[j];
                        list[j] = bufferList;
                    }
                    else if (strcmp(list[i].lastName,list[j].lastName) == 0
                             && list[i].idSector > list[j].idSector)
                    {
                        bufferList = list[i];
                        list[i] = list[j];
                        list[j] = bufferList;
                    }
                    ret=0;
                }
            }
        }
    }//IF
    return ret;
}

/** \brief ordenamiento descendiente
 * \param lista de array
 * \param len tamaño del array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int emp_DecendenSort(Employee* list, int len)
{
    Employee bufferList;
    int ret=-1;
    int i;
    int j;

    if((list!=NULL) && (len>0))
        {
        for (i=0; i<len-1; i++)
        {
            for (j=i+1; j<len; j++)
            {
                if (list[i].isEmpty == 1)
                {
                    if (strcmp(list[i].lastName,list[j].lastName) < 0)
                    {
                        bufferList = list[i];
                        list[i] = list[j];
                        list[j] = bufferList;
                    }else if(strcmp(list[i].lastName,list[j].lastName) == 0
                              && list[i].idSector < list[j].idSector)
                    {
                        bufferList = list[i];
                        list[i] = list[j];
                        list[j] = bufferList;

                    }
                    ret=0;
                }
            }
        }
        }//IF
        return ret;
}

/** \brief informa promedios
 *
 * \param lista de array
 * \param len tamaño del array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int emp_AverageSalary(Employee* list, int len)
{
    int ret=-1;
    float totalSalary;
    float average;
    int counterSalary=0;
    int counterEmployees=0;

    for(int i=0; i< len ; i++)
    {
        if (list[i].isEmpty == 1)
        {
            totalSalary= totalSalary+list[i].salary;
            counterSalary++;
            ret=0;
        }
    }
    average=totalSalary/counterSalary;
    for(int i=0; i< len; i++)
    {
        if((list[i].isEmpty== 1) && (list[i].salary> average))
        {
            counterEmployees++;
            ret=0;
        }
    }
    printf("Total de Empleados: %d\n", counterSalary);
    printf("Promedio de salarios: %2.f\n", average);
    printf("Cantidad de empleados que superan el salario medio: %d", counterEmployees);
    return ret;
}
