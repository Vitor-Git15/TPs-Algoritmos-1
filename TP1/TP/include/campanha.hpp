#ifndef CAMPANHA
#define CAMPANHA

#include <iostream>
#include <vector>
#include <stack>

const int MAX = 100000;

struct candidate{
  int followers;
  int proposals;
};

class Candidate{
  public:

    Candidate();
    Candidate(int followers, int proposals);

    void setFollowers(int S);
    void setProposals(int P);

    int getFollowers();
    int getProposals();

  private:
    candidate C;
};

class PoliticCampaing{

  public:
    void StartPoliticCampaing(int Op1[], int Op2[], Candidate C);

    void addEdges(int P1, int P2);
  
    void addEdgesInverse(int P1, int P2);
  
    void dfsFirst(int V);
  
    void dfsSecond(int V_inv);
  
    void is2Satisfiable(int var_qnt, int cla_qnt, int F_Op1[], int F_Op2[]);

  private:
    // grafo original
    std::vector<int> adj[MAX];
    // grafo inverso
    std::vector<int> adjInv[MAX];
    // vertices acessados do grafo original
    bool visited[MAX];
    // vertices acessados do grafo inverso
    bool visitedInv[MAX];
    // pilha com vertices acessados
    std::stack<int> s;
    // vetor que armazena vertices normais e os seus respectivos barrados
    int scc[MAX];
    int counter = 1;

};
#endif