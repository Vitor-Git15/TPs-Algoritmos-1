#include <iostream>

#define MAX(x, y) (x < y ? y : x)
#define LimMAX 20000

class Loja{
  public:

    /** 
    * Esse é o construtor padrão da classe Loja.
    * Utiliza-se como padrão o número de rolos igual a 0.
    * @param Nothing 
    */
    Loja();

    /** 
    * Esse é o construtor com parâmetros da classe Loja.
    * Nessa recebe-se o número de rolos que chegarão à loja.
    * @param numRolls Isso é o número de rolos que chegarão à loja
    */
    Loja(int numRolls);

    /** 
    * Esse método é responsável por setar a quantidade
    * de rolos que chegarão a loja
    * @param numRolls Isso é o número de rolos que chegarão à loja
    * @return Nothing
    */
    void setN(int N);

    /** 
    * Esse método é utilizado para inicializar o vetor auxiliar
    * que indica a maior subsequência até a posição i
    * @param Nothing
    * @return Nothing
    */
    void inicialize();

    /** 
    * Esse método obtém a quantidade de elementos na maior sub-
    * sequência do vetor
    * @param Nothing
    * @return int Retorna a quantidade de elementos da maior 
    * subsequência
    */
    int getValMax();

    /** 
    * Esse método insere um rolo de tecido a Loja, indicando
    * ser o i-ésimo rolo e o seu respectivo valor
    * @param position Isso indica a posição em que o rolo chegou
    * @param value Isso indica o preço do produto
    * @return Nothing
    */
    void insertValue(int position, int value);

    /** 
    * Esse método encontra a maior sequência crescente
    * iniciando em n+1
    * @param str Isso é a posição n a ser analisada
    * @return int Isso é o número de elementos da sequência mais
    * longa
    */
    int LIS(int n);
    
    /** 
    * Esse método encontra a maior sequência decrescente
    * iniciando em n+1
    * @param str Isso é a posição n a ser analisada
    * @return int Isso é o número de elementos da sequência mais
    * longa
    */
    int LDS(int n);
    
  private:
    int N;
    int arr[LimMAX];
    int lis[LimMAX];
    int lds[LimMAX];
};