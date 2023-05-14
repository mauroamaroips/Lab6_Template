#include "vector3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* TODO: -- define data structure here -- */ 

struct vector3d{

    double x;
    double y;
    double z;

} Vector3D;


PtVector3d vector3dCreate(double x, double y, double z) {

    PtVector3d newVec = (PtVector3d) malloc(sizeof(Vector3D));
    
    if(newVec == NULL) return NULL;

    newVec->x = x;
    newVec->y = y;
    newVec->z = z; 

    return newVec;
}

void vector3dPrint(PtVector3d vec, bool lineBreakAfter) {

    if(vec == NULL) printf("(NULL)\n");
        
    if(lineBreakAfter == false && vec != NULL){

        printf("<%.2f, %.2f, %.2f>\n", vec->x, vec->y, vec->z);

    } else if(lineBreakAfter == true && vec != NULL){
        printf("%.2f\n", vec->x);
        printf("%.2f\n", vec->y);
        printf("%.2f\n", vec->z);
    }

}

int vector3dX(PtVector3d vec, double *x) {

    if( vec == NULL ) return VECTOR3D_NULL;

    (*x) = vec->x;

    return VECTOR3D_OK;
}

int vector3dY(PtVector3d vec, double *y) {

    if( vec == NULL ) return VECTOR3D_NULL;

    (*y) = vec->y;

    return VECTOR3D_OK;
}

int vector3dZ(PtVector3d vec, double *z) {

    if( vec == NULL ) return VECTOR3D_NULL;

    (*z) = vec->z;

    return VECTOR3D_OK;
}

int vector3dDestroy(PtVector3d *pVec) {
    
    PtVector3d vec = *pVec;

    if( vec == NULL ) return VECTOR3D_NULL;

    free(vec);

    *pVec = NULL;

    return VECTOR3D_OK;
}

PtVector3d vector3dMultiplyByScalar(PtVector3d vec, double scalar) {

    PtVector3d result = vector3dCreate(0,0,0);
    if(vec == NULL) return NULL;
    
    result->x = vec->x * scalar;
    result->y = vec->y * scalar;
    result->z = vec->z * scalar;

    return result;

}

PtVector3d vector3dAdd(PtVector3d vec1, PtVector3d vec2) {
    
    PtVector3d result = vector3dCreate(0,0,0);
    if(vec1 == NULL || vec2 == NULL) return NULL;

    result->x = vec1->x + vec2->x;
    result->y = vec1->y + vec2->y;
    result->z = vec1->z + vec2->z;

    return result;

}

double vector3dMagnitude(PtVector3d vec, double *magnitude) {
   
  *magnitude = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
  return *magnitude;
}

PtVector3d vector3dNormalize(PtVector3d vec) {

    PtVector3d result = vector3dCreate(0,0,0);
    double magnitude = vector3dMagnitude(vec, &magnitude);

    if(magnitude == 0) return result;
    if(vec == NULL) return NULL;

    result->x = vec->x / magnitude;
    result->y = vec->y / magnitude;
    result->z = vec->z / magnitude;

    return result;
}

