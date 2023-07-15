#define FLT_MIN (-__FLT_MAX__)

// A utility function to find maximum of two integers
#define MAX2(x, y) ((x > y) ? x : y)
// A utility function to find maximum of three integers
#define MAX3(x,y,z) ((x > MAX2(y,z)) ? x : MAX2(y,z))

struct position
// descrição: struct de posições, armazena o início e o fim do subvetor de
// soma máxima e a soma máxima obtida
{
  int start, end;
  float sumMax;

  // construtor padrão da struct
  position(): start(0), end(0), sumMax(FLT_MIN){}
};
// definição da função que encontra o subarray de maior soma
float maxSumSubArray(float ratings[], int l, int h, position* p);
float maxCrossingSum(float ratings[], int l, int m, int h, position* p);
