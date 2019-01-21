//---------------------------------------------------------------------------


#pragma hdrstop

#include "dynarray.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

double *CreateDoubleArray(int size)
{
	double * a = new double [size];
	return a;
}

double ** CreateDoubleArray(int size1, int size2)
{
	double ** a = new double * [size1];
	for(int i=0; i<size1; i++)
		a[i] = CreateDoubleArray(size2);
	return a;
}

double *** CreateDoubleArray(int size1, int size2, int size3)
{
	double *** a = new double ** [size1];
	for(int i=0; i<size1; i++)
		a[i] = CreateDoubleArray(size2, size3);
	return a;
}

void DestroyArray(double * a, int)
{
	delete [] a;
}

void DestroyArray(double ** a, int size1, int size2)
{
	for(int i=0; i<size1; i++)
		DestroyArray(a[i], size2);
	delete [] a;
}

void DestroyArray(double *** a, int size1, int size2, int size3)
{
	for(int i=0; i<size1; i++)
		DestroyArray(a[i], size2, size3);
	delete [] a;
}

// Int

int *CreateIntArray(int size)
{
	int * a = new int [size];
	return a;
}

int ** CreateIntArray(int size1, int size2)
{
	int ** a = new int * [size1];
	for(int i=0; i<size1; i++)
		a[i] = CreateIntArray(size2);
	return a;
}

int *** CreateIntArray(int size1, int size2, int size3)
{
	int *** a = new int ** [size1];
	for(int i=0; i<size1; i++)
		a[i] = CreateIntArray(size2, size3);
	return a;
}

void DestroyArray(int * a, int)
{
	delete [] a;
}

void DestroyArray(int ** a, int size1, int size2)
{
	for(int i=0; i<size1; i++)
		DestroyArray(a[i], size2);
	delete [] a;
}

void DestroyArray(int *** a, int size1, int size2, int size3)
{
	for(int i=0; i<size1; i++)
		DestroyArray(a[i], size2, size3);
	delete [] a;
}

// Boolean

bool *CreateBoolArray(int size)
{
	bool * a = new bool [size];
	return a;
}

bool ** CreateBoolArray(int size1, int size2)
{
	bool ** a = new bool * [size1];
	for(int i=0; i<size1; i++)
		a[i] = CreateBoolArray(size2);
	return a;
}

bool *** CreateBoolArray(int size1, int size2, int size3)
{
	bool *** a = new bool ** [size1];
	for(int i=0; i<size1; i++)
		a[i] = CreateBoolArray(size2, size3);
	return a;
}

void DestroyArray(bool * a, int)
{
	delete [] a;
}

void DestroyArray(bool ** a, int size1, int size2)
{
	for(int i=0; i<size1; i++)
		DestroyArray(a[i], size2);
	delete [] a;
}

void DestroyArray(bool *** a, int size1, int size2, int size3)
{
	for(int i=0; i<size1; i++)
		DestroyArray(a[i], size2, size3);
	delete [] a;
}