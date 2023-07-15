#include "rock.hpp"


float maxCrossingSum(float ratings[], int l, int m, int h, position *p)
// descrição: encontra a maior soma possível do array de modo que
// o elemento do meio do vetor esteja incluso
// entrada: vetor com dados, elemento mais a esquerda da partição, 
// elemento do meio da partição, elemento mais a direita da partição e 
// struct com posições e soma máxima do maior subvetor até então
// saída: retorna a soma do maior subarray da partição lidada
{
    // inclui elementos à esquerda do elemento central
    float sum = 0;
    float left_sum = FLT_MIN;
    int left_i = 0;
    for (int i = m; i >= l; i--)
    {
        sum = sum + ratings[i];
        if (sum >= left_sum)
        {
            left_sum = sum;
            left_i = i;
            if (p->sumMax <= left_sum)
            {
                p->sumMax = left_sum;
                p->start = i;
                p->end = m;
            }
        }
    }

    // inclui elementos à direita do elemento central
    sum = 0;
    float right_sum = FLT_MIN;
    int right_i = 0;
    for (int i = m; i <= h; i++)
    {
        sum = sum + ratings[i];
        if (sum >= right_sum)
        {
            right_sum = sum;
            right_i = i;
            if (p->sumMax <= right_sum)
            {
                p->sumMax = right_sum;
                p->start = m;
                p->end = i;
            }
        }
    }

    if (p->sumMax <= left_sum + right_sum - ratings[m])
    {
        p->sumMax = left_sum + right_sum - ratings[m];
        p->start = left_i;
        p->end = right_i;
    }
    return MAX3(left_sum + right_sum - ratings[m], left_sum, right_sum);
}

// Returns sum of maximum sum subarray in aa[l..h]
float maxSumSubArray(float ratings[], int l, int h, position *p)
// descrição: encontra a maior soma possível na partição de l a h
// entrada: vetor com dados, elemento mais a esquerda da partição,
// elemento mais a direita da partição e struct com posições e soma
// máxima do maior subvetor até então
// saída: retorna a soma do maior subarray da partição lidada
{
    // caso a partição seja invalida
    if (l > h)
    {
        return FLT_MIN;
    }

    // caso a partição possua apenas um elemento
    if (l == h)
    {
        if (p->sumMax < ratings[l])
        {
            p->start = l;
            p->end = l;
            p->sumMax = ratings[l];
        }
        return ratings[l];
    }

    // encontra o elemento central da partição
    int m = (l + h) / 2;

    return MAX3(maxSumSubArray(ratings, l, m - 1, p),
                maxSumSubArray(ratings, m + 1, h, p),
                maxCrossingSum(ratings, l, m, h, p));
}