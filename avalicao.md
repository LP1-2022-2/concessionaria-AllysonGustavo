
# Identificação

* Nome: Allyson Gustavo Silva do Carmo

* Matrícula: 20210051717
  
# Compilação  

* a descrição de como compilar e rodar o programa, incluindo um roteiro de entradas e comandos que destaquem as funcionalidades

Para compilar o programa basta digitar make, já para rodá-lo basta digitar "./build/programa"(sem as aspas)

Caso deseje fazer uma bateria de testes basta digitar o comando de rodar o programa com um simbolo de "<", e logo a frente o arquivo de texto contendo os comandos a serem testados. Ex: "./build/programa < ./tests/test1.txt"(ou simplesmente "make teste")

Os comandos existentes são:
"create-concessionaria (nome da concessionaria) (cnpj) (estoque)" para criar uma nova concessionaria (Ex: create-concessionaria IMD_SA 11.111.111/0001-11 0)
"add-car (nome da concessionaria) (veiculo) (preço) (chassi) (ano) (tipo de motor)" para criar um automóvel (Ex: add-car IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 gasolina)
"add-truck (nome da concessionaria) (veiculo) (preço) (chassi) (ano) (tipo de carga)" para criar um caminhão (Ex: add-truck IMD_SA Scania 700000 7BRBLQHEXG0208811 2010 perigosa)
"add-motorcycle (nome da concessionaria) (veiculo) (preço) (chassi) (ano) (tipo de motor)" para criar uma moto (Ex: add-motorcycle IMD_SA XRE 500000 1FTHGAkSGA7MG5703 2020 clássico)
"remove-vehicle (chassi)" para remover o veículo (Ex: remove-vehicle 9BRBLWHEXG0107721)
"search-vehicle (chassi)" para procurar um veículo (Ex: search-vehicle 9BRBLWHEXG0107721)
"list-concessionaria (concessionária)" para ver as informações de uma concessionária (Ex: list-concessionaria IMD_SA)
"raise-price (concessionária) (porcentagem)" para aumentar em x% o valor dos veiculos de uma concessionária (Ex: raise-price IMD_SA 10)
"save-concessionaria (concessinária)" para salvar a concessionária em um arquivo .txt (Ex: save-concessionaria IMD_SA)
"load-concessionaria (concessinária)" para carregar uma concessionária em um arquivo .txt (Ex: load-concessionaria IMD_SA)
"quit" para encerrar o programa

# Limitações

* a descrição das limitações (caso existam) do programa e quaisquer dificuldades encontradas
   
# Autoavaliação

- Modelagem e implementação das classes Concessionária, Veículo, Automóvel, Moto, Caminhão | **10 / 10**
  - 0: sem modelagem e implementação de classes
  - 5: apenas algumas classes modeladas e implementadas; ausência de herança
  - 10: modelagem e implementação completa com uso de herança
  
- Implementação e uso do comando `create-concessionaria` | **10 / 10**
  - 0: não cria concessionária via linha de comando 
  - 5: permite criar apenas uma concessionária
  - 10: permite criar mais do que uma concessionária
  
- Implementação e uso dos comandos para adicionar veículos `add-car/add-bike/add-truck` | **10 / 10**
  - 0: não permite criar veículos via linha de comando
  - 5: permite criar apenas um ou outro veículo em uma única concessionária
  - 10: permite criar qualquer tipo de veículo em qualquer uma das concessionárias disponíveis

- Não permitir adicionar um veículo que já tenha sido anteriormente adicionado | **10 / 10**
  - 0: não realiza o teste
  - 10: realiza o teste e indica o erro  

- Implementação e uso do comando para remover veículos `remove-vehicle` | **10 / 10**
  - 0: comando não implementado
  - 10: comando implementado e funcional

- Implementação e uso do comando para busca de veículos `search-vehicle` | **15 / 15 - Bônus: ...**
  - 0: não implementado
  - 15: implementado e funcional
  - bonus +10: implementado com estratégia de busca diferente da busca exaustiva
  - bonus +10: uso de métodos virtuais para impressão na tela
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `list-concessionaria` | **10 / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional   
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `raise-price` | **10 / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional 
  - bonus +10: implementado com uso de método virtual

- Implementação e uso do comando `save-concessionaria` e `load-concessionaria` | **30 / 30**
  - 0: não implementado
  - 15: ambos os comandos implementados e funcionais
  
- Implementação eficiente através do uso de referencias e contêineres da STL | **10 / 10**
  - 0: não usou contêiner da STL nem fez uso eficiente dos recursos computacionais
  - 5: usou contêiner da STL mas não otimizou uso dos recursos computacionais
  - 10: usou contêiner da STL junto a algoritmos e práticas de bom uso de recursos computacionais
  
- Organização do código em src, include, data | **5 / 5**
  - 0: não organizou o código
  - 5: organizou o código 
  
- Documentação do código | **5 / 5**
  - 0: não documentou o código
  - 5: documentou o código 
  
- Implementação e documentação de arquivos e procedimentos de compilação e teste | **15 / 15**
  - 0: não implementou arquivos e procedimentos de compilação e teste
  - 5: implementou alguns arquivos e procedimentos de compilação e teste (com alguma documentação) 
  - 15: Ampla implementação e documentação de arquivos e procedimentos de compilação e teste (com exemplos)
 
 # Total
 
 **150 / 150 ** pontos (sem bônus)
 
 **... / 200 ** pontos (com bônus)
