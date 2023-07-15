#include "campanha.hpp"

/*-----------------------------Definições do candidato-----------------------------*/
Candidate::Candidate()
// descrição: construtor padrão da classe candidate
// entrada: -
// saída: -
{

    this->setFollowers(0);
    this->setProposals(0);
}
Candidate::Candidate(int followers, int proposals)
// descrição: construtor com parâmetros da classe candidate
// entrada: número de seguidores e de propostas
// saída: -
{

    this->setFollowers(followers);
    this->setProposals(proposals);
}

void Candidate::setFollowers(int f)
// descrição: seta a quantidade de seguidores do candidato
// entrada: número de seguidores
// saída: -
{
    this->C.followers = f;
}
void Candidate::setProposals(int p)
// descrição: seta a quantidade de propostas do candidato
// entrada: número de propostas
// saída: -
{
    this->C.proposals = p;
}

int Candidate::getFollowers()
// descrição: retorna a quantidade de seguidores do candidato
// entrada: -
// saída: número de seguidores
{
    return this->C.followers;
}
int Candidate::getProposals()
// descrição: retorna a quantidade de propostas do candidato
// entrada: -
// saída: número de seguidores
{
    return this->C.proposals;
}
/*----------------------------------------------------------------------------------*/


/*------------------------------Definições da campanha------------------------------*/
void PoliticCampaing::addEdges(int P1, int P2)
// descrição: adiciona uma aresta entre os vértices P1 e P2 no grafo original
// entrada: proposta 1 e proposta 2
// saída: -
{
    adj[P1].push_back(P2);
}

void PoliticCampaing::addEdgesInverse(int P1, int P2)
// descrição: adiciona uma aresta entre os vértices P2 e P1 no grafo inverso
// entrada: proposta 1 e proposta 2
// saída: -
{
    adjInv[P2].push_back(P1);
}

void PoliticCampaing::dfsFirst(int V)
// descrição: realiza o algoritmo DFS no grafo original
// entrada: vertice a ser analisado
// saída: -
{
    if (visited[V])
        return;

    visited[V] = 1;

    for (long unsigned int i = 0; i < adj[V].size(); i++)
        dfsFirst(adj[V][i]);

    s.push(V);
}

void PoliticCampaing::dfsSecond(int V_inv)
// descrição: realiza o algoritmo DFS no grafo inverso
// entrada: vertice a ser analisado
// saída: -
{
    if (visitedInv[V_inv])
        return;

    visitedInv[V_inv] = 1;

    for (long unsigned int i = 0; i < adjInv[V_inv].size(); i++)
        dfsSecond(adjInv[V_inv][i]);

    scc[V_inv] = counter;
}
template <typename T>
void setZeros(T vector[], int size)
// descrição: inicializa um vetor com zeros
// entrada: vetor e tamanho do vetor
// saída: -
{
    for (int i = 0; i < size; i++)
    {
        vector[i] = 0;
    }
}
void PoliticCampaing::is2Satisfiable(int var_qnt, int cla_qnt, int F_Op1[], int F_Op2[])
// descrição: inicializa e confere se o grafo é 2-SAT
// entrada: quantidade de variáveis, quantidade de clausulas, vetor com 
//          primeiros valores da operação or e vetores com os segundos valores
// saída: sim caso for satisfeito e não caso contrário
{

    // adiciona as arestas no grafo conforme o algoritmo
    for (int i = 0; i < cla_qnt; i++)
    {
        // variável x é mapeada em x
        // váriavel !x é mapeada como n+x = n-(-x)

        // para (F_Op1[i] ^ F_Op2[i]), adicionam-se arestas
        // -F_Op1[i] -> F_Op2[i] e -F_Op2[i] -> F_Op1[i]
        if (F_Op1[i] > 0 && F_Op2[i] > 0)
        {
            addEdges(F_Op1[i] + var_qnt, F_Op2[i]);
            addEdgesInverse(F_Op1[i] + var_qnt, F_Op2[i]);
            addEdges(F_Op2[i] + var_qnt, F_Op1[i]);
            addEdgesInverse(F_Op2[i] + var_qnt, F_Op1[i]);
        }

        else if (F_Op1[i] > 0 && F_Op2[i] < 0)
        {
            addEdges(F_Op1[i] + var_qnt, var_qnt - F_Op2[i]);
            addEdgesInverse(F_Op1[i] + var_qnt, var_qnt - F_Op2[i]);
            addEdges(-F_Op2[i], F_Op1[i]);
            addEdgesInverse(-F_Op2[i], F_Op1[i]);
        }

        else if (F_Op1[i] < 0 && F_Op2[i] > 0)
        {
            addEdges(-F_Op1[i], F_Op2[i]);
            addEdgesInverse(-F_Op1[i], F_Op2[i]);
            addEdges(F_Op2[i] + var_qnt, var_qnt - F_Op1[i]);
            addEdgesInverse(F_Op2[i] + var_qnt, var_qnt - F_Op1[i]);
        }

        else if (F_Op1[i] < 0 && F_Op2[i] < 0)
        {
            addEdges(-F_Op1[i], var_qnt - F_Op2[i]);
            addEdgesInverse(-F_Op1[i], var_qnt - F_Op2[i]);
            addEdges(-F_Op2[i], var_qnt - F_Op1[i]);
            addEdgesInverse(-F_Op2[i], var_qnt - F_Op1[i]);
        }
        // caso ambas preferências de retirada ou manutenção sejam
        // anuladas não adicionam-se vertices ao grafo
        else if (F_Op1[i] == 0 && F_Op2[i] == 0)
            ;
        // caso alguma preferências de retirada ou manutenção seja
        // anulada a outra deve ser necessáriamente aceita, logo
        // todos vertices devem apontar para no grafo original
        // e ele deve apontar para todos no grafo inverso
        else if (F_Op1[i] == 0)
        {
            if (F_Op2[i] > 0)
            {
                for (int j = 0; j < cla_qnt; j++)
                {
                    if (F_Op1[j] > 0)
                    {
                        addEdges(F_Op1[j], F_Op2[i]);
                        addEdgesInverse(F_Op1[j], F_Op2[i]);
                    }
                    else if (F_Op1[j] < 0)
                    {
                        addEdges(var_qnt - F_Op1[j], F_Op2[i]);
                        addEdgesInverse(var_qnt - F_Op1[j], F_Op2[i]);
                    }
                    if ((F_Op2[j] > 0))
                    {
                        addEdges(F_Op2[j], F_Op2[i]);
                        addEdgesInverse(F_Op2[j], F_Op2[i]);
                    }
                    else if ((F_Op2[j] < 0))
                    {
                        addEdges(var_qnt - F_Op2[j], F_Op2[i]);
                        addEdgesInverse(var_qnt - F_Op2[j], F_Op2[i]);
                    }
                }
            }
            else
            {
                for (int j = 0; j < cla_qnt; j++)
                {
                    if (F_Op1[j] > 0)
                    {
                        addEdges(F_Op1[j], var_qnt - F_Op2[i]);
                        addEdgesInverse(F_Op1[j], var_qnt - F_Op2[i]);
                    }
                    else if (F_Op1[j] < 0)
                    {
                        addEdges(var_qnt - F_Op1[j], var_qnt - F_Op2[i]);
                        addEdgesInverse(var_qnt - F_Op1[j], var_qnt - F_Op2[i]);
                    }
                    if ((F_Op2[j] > 0))
                    {
                        addEdges(F_Op2[j], var_qnt - F_Op2[i]);
                        addEdgesInverse(F_Op2[j], var_qnt - F_Op2[i]);
                    }
                    else if ((F_Op2[j] < 0))
                    {
                        addEdges(var_qnt - F_Op2[j], var_qnt - F_Op2[i]);
                        addEdgesInverse(var_qnt - F_Op2[j], var_qnt - F_Op2[i]);
                    }
                }
            }
        }
        else if (F_Op2[i] == 0)
        {
            if (F_Op1[i] > 0)
            {
                for (int j = 0; j < cla_qnt; j++)
                {
                    if (F_Op2[j] > 0)
                    {
                        addEdges(F_Op2[j], F_Op1[i]);
                        addEdgesInverse(F_Op2[j], F_Op1[i]);
                    }
                    else if (F_Op2[j] < 0)
                    {
                        addEdges(var_qnt - F_Op2[j], F_Op1[i]);
                        addEdgesInverse(var_qnt - F_Op2[j], F_Op1[i]);
                    }
                    if ((F_Op1[j] > 0))
                    {
                        addEdges(F_Op1[j], F_Op1[i]);
                        addEdgesInverse(F_Op1[j], F_Op1[i]);
                    }
                    else if ((F_Op1[j] < 0))
                    {
                        addEdges(var_qnt - F_Op1[j], F_Op1[i]);
                        addEdgesInverse(var_qnt - F_Op1[j], F_Op1[i]);
                    }
                }
            }
            else
            {
                for (int j = 0; j < cla_qnt; j++)
                {
                    if (F_Op2[j] > 0)
                    {
                        addEdges(F_Op2[j], var_qnt - F_Op1[i]);
                        addEdgesInverse(F_Op2[j], var_qnt - F_Op1[i]);
                    }
                    else if (F_Op2[j] < 0)
                    {
                        addEdges(var_qnt - F_Op2[j], var_qnt - F_Op1[i]);
                        addEdgesInverse(var_qnt - F_Op2[j], var_qnt - F_Op1[i]);
                    }
                    if ((F_Op1[j] > 0))
                    {
                        addEdges(F_Op1[j], var_qnt - F_Op1[i]);
                        addEdgesInverse(F_Op1[j], var_qnt - F_Op1[i]);
                    }
                    else if ((F_Op1[j] < 0))
                    {
                        addEdges(var_qnt - F_Op1[j], var_qnt - F_Op1[i]);
                        addEdgesInverse(var_qnt - F_Op1[j], var_qnt - F_Op1[i]);
                    }
                }
            }
        }
    }
    // inicializa os vetores auxiliares com 0
    setZeros<int>(scc, 2 * var_qnt + 1);
    setZeros<bool>(visited, 2 * var_qnt);
    setZeros<bool>(visitedInv, 2 * var_qnt);

    // percorre os elementos do grafo original a partir do algoritmo DFS
    for (int i = 1; i <= 2 * var_qnt; i++)
        if (!visited[i])
            dfsFirst(i);

    // percorre os elementos do grafo original a partir do algoritmo DFS
    while (!s.empty())
    {
        int n = s.top();
        s.pop();

        if (!visitedInv[n])
        {
            dfsSecond(n);
            counter++;
        }
    }

    for (int i = 1; i <= var_qnt; i++)
    {
        // caso exista um caminho de x a !x e vice-versa
        if (scc[i] == scc[i + var_qnt])
        {
            std::cout << "nao" << std::endl;
            return;
        }
    }

    // caso não exista um caminho de x a !x e vice-versa
    std::cout << "sim" << std::endl;
}

void PoliticCampaing::StartPoliticCampaing(int Op1[], int Op2[], Candidate C)
// descrição: inicializa o processo politico para verificação da satisfatibilidade
// entrada: vetor com osprimeiros valores da operação or, vetores com os segundos valores
//          e o candidato com camapnha politica a ser analisada
// saída: -
{
    // vetores que receberam os as propostas numeradas conforme aparecem no arquivo
    int F_Op1[2 * C.getFollowers()], F_Op2[2 * C.getFollowers()];
    setZeros(F_Op1, 2 * C.getFollowers());
    setZeros(F_Op2, 2 * C.getFollowers());

    // vetor que converte as propostas nas respectivas numerações conforme aparecem no arquivo
    int Convert[C.getProposals() + 1];
    setZeros(Convert, C.getProposals() + 1);

    int count = 1;
    for (int i = 0; i < 2 * C.getFollowers(); i++)
    {

        if ((Convert[Op1[i]] == 0) && (Op1[i] != 0))
        {
            Convert[Op1[i]] = count;
            count++;
        }
        if ((Convert[Op2[i]] == 0) && (Op2[i] != 0))
        {
            Convert[Op2[i]] = count;
            count++;
        }
    }
    // enumera as propostas conforme aparecem no arquivo e passa a negativo as operações barradas
    for (int i = 0; i < 2 * C.getFollowers(); i += 2)
    {
        F_Op1[i] = Convert[Op1[i]];
        F_Op1[i + 1] = -Convert[Op1[i + 1]];
        F_Op2[i] = Convert[Op2[i]];
        F_Op2[i + 1] = -Convert[Op2[i + 1]];
    }
    is2Satisfiable(count - 1, 2 * C.getFollowers(), F_Op1, F_Op2);
}
/*----------------------------------------------------------------------------------*/