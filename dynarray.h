//---------------------------------------------------------------------------

#ifndef dynarrayH
#define dynarrayH
//---------------------------------------------------------------------------
#endif

double *CreateDoubleArray(int size);
double ** CreateDoubleArray(int size1, int size2);
double *** CreateDoubleArray(int size1, int size2, int size3);
void DestroyArray(double * a, int);
void DestroyArray(double ** a, int size1, int size2);
void DestroyArray(double *** a, int size1, int size2, int size3);
int *CreateIntArray(int size);
int ** CreateIntArray(int size1, int size2);
int *** CreateIntArray(int size1, int size2, int size3);
void DestroyArray(int * a, int);
void DestroyArray(int ** a, int size1, int size2);
void DestroyArray(int *** a, int size1, int size2, int size3);
bool *CreateBoolArray(int size);
bool ** CreateBoolArray(int size1, int size2);
bool *** CreateBoolArray(int size1, int size2, int size3);
void DestroyArray(bool * a, int);
void DestroyArray(bool ** a, int size1, int size2);
void DestroyArray(bool *** a, int size1, int size2, int size3);
