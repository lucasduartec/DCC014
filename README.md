# Problema do Labirinto

Implementação do trabalho da disciplina DCC014 - Inteligência Artificial durante o período 2023.3 na Universidade Federal de Juiz de Fora.

##### Visualização

Visando auxiliar a visualização do problema e suas respectivas soluções foi utilizado o **Graphviz**. Graphviz é um software para manipular e processar grafos open-source. Os programas de layout Graphviz utilizam descrições de gráficos em uma linguagem de texto simples e projetam diagramas em formatos úteis.

##### Instalação do visualizador

Abra o terminal no seu computador e execute:<br/>
`sudo apt-get install graphviz`

##### Execução

Para auxiliar na compilação do projeto, foi utilizada a ferramenta **cmake**. Você pode instalá-lo da seguinte forma:<br/>
`sudo apt-get -y install cmake`

Depois de ter instalado o **Graphviz** e o **cmake**, o sistema estará apto para executar o programa.
Certifique-se de que está no diretório raíz do projeto. Primeiro crie a pasta usada para **build** com `mkdir build && cmake .` e depois já poderá rodar o programa com o script:<br/>
`./scripts/run.sh`

A imagem da árvore da busca escolhida será gerada dentro da pasta `images`.
