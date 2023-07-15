#include <iostream>

#include "rock.hpp"


int main()
// descrição: função principal do programa
// entrada: -
// saída: 0 se o programa rodar com sucesso
{
  // definição das variáveis iniciais: número de amigos e de shows
  int friends, shows;

  // loop de execução do programa
  while (true){

    // atribuição dos valores
    std::cin >> friends >> shows;

    // condição de parada friends e shows igual a zero
    if((!friends) && (!shows))
      break;

    // definição do vetor com as notas, posições e auxiliar de atribuição de notas
    float ratings[shows] = {0};
    position p;
    float score;

    // atribui a nota de cada show a cada amigo
    for (int i = 0; i < friends; i++){
      for (int j = 0; j < shows; j++){
        std::cin >> score;
        ratings[j] += score;
      }  
    }
    
    // calcula as posições do maior subvetor e printa na saída padrão
    maxSumSubArray(ratings, 0, shows-1, &p);
    std::cout << p.start+1 << " " << p.end+1 << std::endl;
  }
  return(0);
}
