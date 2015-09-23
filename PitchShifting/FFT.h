#ifndef FFT_H
#define FFT_H

#include "math.h"

#define PI 3.1415926535897932384626433832795028841971

typedef struct complex //��������
{
	complex(float r=0, float i=0) :real(r), imag(i) {}
	float real;		//ʵ��
	float imag;		//�鲿
}complex;

class FFT
{
private:
	FFT(const FFT& cp){}
	FFT& operator = (const FFT& cp){}
public:
	static void conjugate_complex(int n,complex in[],complex out[]);//ȡ����
	static void c_plus(complex a,complex b,complex *result);//������
	static void c_mul(complex a,complex b,complex *result) ;//������
	static void c_sub(complex a,complex b,complex *result);	//��������
	static void c_div(complex a,complex b,complex *result);	//��������
	static void c_abs(complex f[],float out[],int size);//��������ȡģ
	static double c_abs(const complex& f);//��������ȡģ
	static void Wn_i(int n,int i,complex *Wn,char flag);//
	static void fftshift(int N,float f[]);
public:
	FFT();
	~FFT();
	static void fft(int N,complex f[]);//����Ҷ�任 ���Ҳ��������f��
	static void ifft(int N,complex f[]); // ����Ҷ��任	
	static void ifft(int N, float in[]);
};

#endif

