# Problema do Labirinto

Implementação do trabalho da disciplina DCC014 - Inteligência Artificial durante o período 2023.3 na Universidade Federal de Juiz de Fora.

##### Execução (via script)

Certifique-se de que está no diretório raíz do projeto e execute o script com o comando:
`./scripts/run.sh`

##### Compilação

Para compilar o projeto, esteja no diretório principal `maze` e execute a seguinte sequência de comandos no terminal:<br/>
`cmake -B build`<br/>
`cd build`<br/>
`make`<br/>

##### Execução

Para executar, digite no terminal:<br/>
`./main`

##### Visualização do labirinto

Graphviz é um software para manipular e processar grafos open source. Os programas de layout Graphviz utilizam descrições de gráficos em uma linguagem de texto simples e projetam diagramas em formatos úteis.

##### Instalação do visualizador

Abra o terminal e execute:<br/>
`sudo apt-get install graphviz`

##### Visualizar

Depois de ter executado o programa principal, certifique-se de voltar para o diretório onde o arquivo `output.dot` foi gerado. Feito isso, você poderá visualizar o grafo executando:<br/>
`dot -Kfdp -n -Tpng -o grafo.png output.dot`
