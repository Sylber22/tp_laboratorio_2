#ifndef BIBLIOTECAARRAYEMPLOYEES_H_INCLUDED
#define BIBLIOTECAARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int idUnico;
    int isEmpty;
    //------------
    char name[51];
    char lastName[51];
    float salary;
    int idSector;
}Employee;

//----------------------------------------------------------------
int emp_InitEmployees(Employee* list, int len);
int emp_FindFree(Employee* list, int len, int* pResult);
int emp_NewEmployee(Employee* list,int len);
int emp_AddEmployee(Employee* list,
                    int len,
                    char* name,
                    char* lastName,
                    float salary,
                    int idSector,
                    int index);
int emp_PrintOnlyEmployee(Employee* list, int index);
int emp_PrintEmployees(Employee* list, int len);
int emp_ModifyEmployee(Employee* list,int len,int idUnico);
int emp_FindEmployeeById(Employee* list, int len,int idUnico);
int emp_RemoveEmployee(Employee* list, int len, int idUnico);
int emp_SortEmployees(Employee* list, int len);
int emp_AscendentSort(Employee* list, int len);
int emp_DecendenSort(Employee* list, int len);
int emp_AverageSalary(Employee* list, int len);



//----------------------------------------------------------------
int menuModificar();
int menuOrdenar();

#endif // BIBLIOTECAARRAYEMPLOYEES_H_INCLUDED
