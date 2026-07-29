# Definindo e explicando decisões de arquitetura do projeto

## Tipos de dados

### Papel

O enum Papel foi criado para representar as possíveis funções exercidas por uma pessoa em um filme. Essa decisão foi tomada em vez de utilizar uma string (char[]), pois o conjunto de valores possíveis é limitado. Além de consumir menos memória, o uso de um enum evita erros de digitação e torna as comparações mais eficientes.

## Modelagem das entidades

### Filme

Essa struct é simples e direta. A partir do arquivo de texto concedido pela professora, que funciona como um conjunto de dados brutos, definimos a struct para que os dados possam ser armazenados corretamente:

- **id** para que possa ser identificado por um valor único, e não pelo título completo.
- **titulo** para armazenar o nome do filme como char.
- **ano** para armazenar o ano de lançamento do filme como inteiro.
- **tagline** para armazenar a tagline do filme como char.

### Pessoa

Mesma ideia da struct anterior:

- **id** para que possa ser identificado por um valor único.
- **nome** para armazenar o nome da pessoa como char.
- **nascimento** para armazenar o ano de nascimento da pessoa como número inteiro.

### Relacionamento

A struct Relacionamento representa a associação entre uma pessoa e um filme. Ela não armazena diretamente os dados dessas entidades, mas sim referências pra elas por meio dos seus identificadores (pessoaID e filmeID). Essa abordagem evita duplicação de informações e segue o mesmo princípio utilizado por bancos de dados relacionais, onde as tabelas são conectadas através de chaves.

- **pessoaID** é a chave que irá se relacionar com o **id** da struct Pessoa. Essa chave é essencial para fazer essa ligação sem desperdiçar memória, como seria se armazenassemos aqui a struct Pessoa inteira, ou repetíssemos o nome da pessoa.
- **filmeID** segue a mesma linha de raciocínio, ou seja, teremos duas contagens distintas de ID para pessoa e filme, que deverão ser únicos.
- **papel** irá armazenar o papel da pessoa no filme.
- **personagem** irá armazenar o personagem interpretado pela pessoa no filme, caso a pessoa seja ator.

## Gerenciamento de memória

- Na struct Relacionamento, **personagem** foi implementado como um ponteiro para char, permitindo alocação dinâmica de memória apenas quando houver um personagem associado ao relacionamento. Para papéis diferentes de ator, o ponteiro permanecerá com valor NULL. Decidi dessa maneira pra reduzir o consumo de memória em comparação com a reserva fixa de um vetor de caracteres para todos os relacionamentos, ao custo da necessidade de gerenciar manualmente a alocação (malloc) e a liberação (free) da memória. Acredito que nesse projeto a diferença seja mínima, talvez sendo até um trabalho a mais desnecessário, mas segui dessa forma pela otimização e aprendizado.

- As entidades Pessoa, Filme e Relacionamento serão armazenadas em vetores dinâmicos. Decidi dessa maneira pelo acesso rápido aos elementos, simplicidade de implementação e crescimento conforme a necessidade do programa. Além disso, evita o desperdício de memória dos vetores estáticos e mantém a estrutura de armazenamento independente da Árvore B, que será utilizada apenas como índice pra busca.