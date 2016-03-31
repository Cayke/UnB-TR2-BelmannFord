1-O padrão da lista de adjacência é:
ID_NO-ID_CONEXÃO[CUSTO];ID_CONEXÃO[CUSTO];
ID_NO-ID_CONEXÃO[CUSTO];ID_CONEXÃO[CUSTO];ID_CONEXÃO[CUSTO];

2-Para compilar basta estar na pasta do Makefile(.../belmann-ford/belmann-ford/) e utilizar o comando make. o executável ficará em 
/belmann-ford/belmann-ford/dist/Debug/GNU-Linux/.

3-Ao iniciar o programa será pedido o nome do arquivo que contém o grafo, ele deve ser fornecido no padrão NOME_ARQUIVO.txt.
Após fornecer o arquivo o usuário deve escolher se vai querer o Caminho da fonte ao destino ou a matriz de custo se a primeira opção for escolhida o usuária
ira  fornecer o nó fonte e o nó de destino.

4- O caminho na opção 1 será mostrado no padrão NÓ[custo] -> NÓ[custo] ->... . Na segunda opção será mostrada uma matriz de custo de cada nó para cada nó,
onde a coluna mostra a fonte e a linha o destino.