#include "loja.hpp"

void inicializeVector(int* vector){
  for (int i = 0; i < LimMAX; i++){
    vector[i] = -1;
  }
    
}

void Loja::inicialize(){
    inicializeVector(lis);
    inicializeVector(lds);
}

Loja::Loja(){
    this->N = 0;
    this->inicialize();
}

Loja::Loja(int N){
    this->N = N;
    this->inicialize();
}

void Loja::setN(int N){
    this->N = N;
}

int Loja::getValMax(){
    int max;
    for(int i = 0; i < this->N; i++) max = MAX(max, (lis[i] + lds[i] - 1));
    return max;
}

void Loja::insertValue(int position, int value){
    this->arr[position] = value;
}

int Loja::LIS(int n)
{
    if (n == N - 1)
        return lis[n] = 1;
    if (lis[n] != -1)
        return lis[n];
    int res = 1;

    for(int i = n + 1; i < N; i++){
        if ((arr[i] > arr[n]) && LIS(i) + 1 > res)
            res = LIS(i) + 1;
    }
    return lis[n] = res;
}

int Loja::LDS(int n)
{
    if (n == N - 1)
       return lds[n] = 1;
    if (lds[n] != -1)
       return lds[n];
    int res = 1;
 
    for(int i = n + 1; i < N; i++){
        if ((arr[i] < arr[n]) && LDS(i) + 1 > res)
           res = LDS(i) + 1;
    }
    return lds[n] = res;
}