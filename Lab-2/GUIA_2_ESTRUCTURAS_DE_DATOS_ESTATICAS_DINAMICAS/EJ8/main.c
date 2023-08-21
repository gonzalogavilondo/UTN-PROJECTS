#include "declaraciones.h"

/**
    Sistema de notas. Se tiene que administrar un sistema para un curso con 20 alumnos que cursan 5 materias
    diferentes. Se deben almacenar los datos de los alumnos y las notas que obtuvieron en el examen final de cada
    materia.
    Se deben hacer las siguientes funciones:
    1. Cargar el arreglo de Materia
    2. Agregar un Alumno
    3. Agregar una Nota, validando que exista “matrícula” y “código”. La función debe retornar 1 si la operación fue
    exitosa y 0 (cero) en caso contrario.
    4. Hacer una función que muestre por pantalla el nombre del alumno y la lista de materias con sus
    respectivas notas. La función debe recibir como parámetro el nombre del alumno. Estrategia: con el
    nombre del alumno se busca su matrícula en el arreglo alus, luego se recorre el arreglo notas filtrandolo
    por matrícula, y con el código se accede al nombre de la materia revisando el arreglo mats.
**/
int main()
{
    Alumno alus[20]; // para almacenar los datos de los 20 alumnos.
    Materia mats[5]; // para almacenar los códigos y nombres de las 5 materias.
    Nota notas[100]; // para almacenar todas las notas de los alumnos.



    return 0;
}
