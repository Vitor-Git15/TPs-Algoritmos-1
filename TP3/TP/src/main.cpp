#include <iostream>
#include "loja.hpp"

/** 
 * Esse método é utilizado para obter os dados da Loja
 * inserindo os valores nas respectivas variáveis da
 * classe
 * @param numRolls Isso é o número de rolos que chegarão
 * à loka
 * @param loja Isso é a classe loja que será abordada
 * @return NOthing
 */
void getInfos(int numRolls, Loja& loja){
  for(int i = 0; i < numRolls; i++){
    int value;
    std::cin >> value;
    loja.insertValue(i, value);
  }
}
/** 
 * Esse método é utilizado para inicializar a quantidade
 * de rolos que serão inseridos e colocar a flag -1 nas
 * váriaveis que serão utilizadas
 * @param numRolls Isso é o número de rolos que chegarão
 * à loka
 * @param loja Isso é a classe loja que será abordada
 * @return Nothing
 */
void startLoja(int numRolls, Loja& loja){
  loja.setN(numRolls);
  loja.inicialize();
}

/** 
 * Essa é a função principal do programa, onde ocorrerá a 
 * inicialização do programa e da ação desejada
 * @return 0 caso ocorra corretamente e outro valor caso contrário
 */
int main()
{
  int numTests;
  std::cin >> numTests;

  
  Loja loja;

  while (numTests--)
  {
    int numRolls;
    std::cin >> numRolls;

    startLoja(numRolls, loja);
    getInfos(numRolls, loja);
    
    for(int i = 0; i < numRolls; i++) loja.LIS(i);
    for(int i = 0; i < numRolls; i++) loja.LDS(i);

    std::cout << loja.getValMax() << std::endl;
  }
  return 0;
}