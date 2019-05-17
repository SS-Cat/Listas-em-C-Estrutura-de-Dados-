# Rouba monte _'EDA'_

Compile e rode o codigo
make all

Compilar e rodar
make start

Para realização do jogo, separei ele em 5 partes importantes:
Jogador;
Mesa;
Montes;
Baralho(ou ACE);
Mão do Jogador;

Assim tentei fazer estruturas as quais guardassem estado para cada uma dessas partes, e no final
juntei tudo, ficando com uma arquitetura como:
Deck (ace): onde guarda as cartas embaralhadas da partida;
Fila de jogadores: Onde os jogadores ficam;
Jogadores: Os proprios jogadores, eles tem seu proprio monte( o qual é uma pilha) e a mão com cartas
a pilha de cartas que os jogadores tem, é feita com nó, assim a operação de merge pode ser O(1);
a mão deles é um vetor, e a inserção e remoção é ordenada, assim a busca pode ser binaria e rapida;
e por ultimo a mesa, ela tem uma lista linkada com as cartas que vai recebendo

Essas estruturas utilizam o nó de cartas, o qual tem uma carta em sua chave.

Arquivos:
Card:
Estrutura da carta, contem campos para os dados do nipe e de seu numero, alem de funções 
axiliares de impressao.
Também tem o nó com a carta e sua função de inicialização.

DeckOfCard:
Estrutura a qual armazena um vetor de cartas, e tem funções para inicializar, sortear os dados,
retirar carta do topo e impressao

CardStack:
pilha de cartas, tem como campos o topo, o bottom(utilizado para fazer o merge ser O(1)) e o tamanho.
tem como funções a inicialização, a função de incerção, e a de serge.

Player:
Estrutura mãe do jogador, contem um vetor de cartas com as operações de inicialização, adicionar, 
remover, pesquisar, imprimir e retorna carta do topo de seu monte(CardStack).
Contem um Monte(CardStack).
e informações do jogador como nome e indice.

PlayerQueue:
fila que armazena usuarios,
tem o jogador, o final da fila(utilizado para operações) e seu tamanho
tem como funções inicialização, adicionar, remover, e proximo jogador(que remove e adiciona 
o jogador recem removido).

Board:
Mesa, Lista linkada com nó de inicio e fim acoplada
tem funções de inicialização, inserção, remoção, e duas de busca.

no main o jogo é executado:
o primeiro loop, mais externo é de inicialização do jogo
chama as funções de inicialização das estruturas e prepara o estado do jogo
tambem serve como loop para reinicialização, no fim ele pergunta se deseja continuar, caso digite zero o loop acaba
depois vem outro loop, o loop do jogo, ele mostra os dados, e recebe as entradas, apos as entradas ele verifica se os valores estão corretos
a verificação é outro loop, o qual recebe o dado, se o dado estiver correto, o loop acaba, o estado do jogo é prosseguido e assim continua seu fluxo
caso contrario, ele diz qual a entrada errada, e pede a reinserção da entrada
apos essa verificação, o estado do jogo é continuado
onde se ve se o jogador não pegou carta, se ele pegou carta da mesa, ou se ele pegou um monte, e caso precise reidratar as cartas na mão dos jogadores ou da mesa é feito isso
e não menos importante, tambem analiza se o jogo ja foi finalizado





