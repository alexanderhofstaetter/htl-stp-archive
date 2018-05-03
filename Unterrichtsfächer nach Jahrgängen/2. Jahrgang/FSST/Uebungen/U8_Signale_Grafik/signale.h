#ifndef SIGNALE_H_INCLUDED
#define SIGNALE_H_INCLUDED

/**
* Berechnungen
*/
void array_rand(float a[], int n, float am);
void array_dc(float a[], int n, float am);
void array_sinus(float a[], int n, float am, float fn);
void array_rect(float a[], int n, float am, float fn);
void array_impuls(float a[], int n, float am, float az);
void array_out(float a[], int n);
float array_ss ( float a[], int n1 , int n2 );
float array_mittel(float a[], int n1, int n2);
float array_max(float a[], int n1 , int n2);
float array_min(float a[], int n1 , int n2);
float array_rms(float a[], int n);

#endif // SIGNALE_H_INCLUDED
