#include <stdio.h> 
#include <stdlib.h>
#include "vector3d.h"

void printComponentsOf(PtVector3d vec);

int main() {

    PtVector3d v1 = vector3dCreate(2, 1, -4);
    PtVector3d v2 = vector3dCreate(1, 0, 3);
    PtVector3d v3 = NULL; //Rever esta declaração (valgrind)

    if(v1 == NULL) {
        printf("No memory available. \n");
        return EXIT_FAILURE;
    }
    
    vector3dPrint(v1, true);
    vector3dPrint(v2, false);
    vector3dPrint(v3, true);

    printComponentsOf(v2);
    printComponentsOf(v3);

    // Multiplicar um vetor por um escalar
    PtVector3d multiplyVec = vector3dMultiplyByScalar(v1, 3);
    vector3dPrint(multiplyVec, false);

    // Somar 2 vetores
    PtVector3d sumVectors = vector3dAdd(v1, v2);
    vector3dPrint(sumVectors, false);

    //Calcular a magnitude de um vetor
    double magnitude;
    vector3dMagnitude(v1, &magnitude);
    printf("%.2f\n", magnitude);

    //Normalizar de um vetor
    PtVector3d normalizeVector = vector3dNormalize(v1);
    vector3dPrint(normalizeVector, false);
    vector3dMagnitude(normalizeVector, &magnitude);
    printf("%.2f\n", magnitude);

    vector3dDestroy(&v1);
    vector3dDestroy(&v2);
    vector3dDestroy(&v3);
    vector3dDestroy(&multiplyVec);
    vector3dDestroy(&sumVectors);
    vector3dDestroy(&normalizeVector);

    return EXIT_SUCCESS;
}

void printComponentsOf(PtVector3d vec){

    double xValue;
    double yValue;
    double zValue;

    double extractX = vector3dX(vec, &xValue);
    double extractY = vector3dY(vec, &yValue);
    double extractZ = vector3dZ(vec, &zValue);

    if(extractX == VECTOR3D_NULL || extractY == VECTOR3D_NULL || extractZ == VECTOR3D_NULL) {
        printf("Vector NULL. Não é possível apresentar as componentes.\n");
    } else
        printf("x = %.2f | y = %.2f | z = %.2f\n", xValue, yValue, zValue);
}