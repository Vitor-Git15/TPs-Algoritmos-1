#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "campanha.hpp"

int main() {
  
  while (true)
  {
    // inicialização dos parâmetros
    // seguidores e propostas
    int F, P;
    std::cin >> F >> P;

    // fim da execução
    if((F == 0) && (P == 0)) return 0;

    // inicializa o candidato
    Candidate C(F,P);

    // inicializa os vetores com as propostas
    int Op1[2*C.getFollowers()], Op2[2*C.getFollowers()];
    for (int i = 0; i < 2*C.getFollowers(); i+=2)
    {
        std::cin >> Op1[i] >> Op2[i] >> Op1[i+1] >> Op2[i+1];
    }

    //inicializa as operações sobre a campanha
    PoliticCampaing PC;
    PC.StartPoliticCampaing(Op1, Op2,  C);
  }

  return(0);
}
