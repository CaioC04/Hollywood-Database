# Definindo e explicando decisões de arquitetura do projeto

## Structs

### Filme

Essa estrutura é simples e direta. A partir do arquivo de texto concedido pela professora, que funciona como um banco de dados bruto, definimos a estrutura para que os dados possam ser armazenados corretamente:

- **id** para que possa ser referenciado por um valor único, e não pelo título completo.
- **titulo** para armazenar o nome do filme como char.
- **ano** para armazenar o ano de lançamento do filme como inteiro.
- **tagline** para armazenar a tagline do filme como char.

### Pessoa

Mesma ideia da estrutura anterior:

- **id** para que possa ser referenciado por um valor único.
- **nome** para armazenar o nome da pessoa como char.
- **nascimento** para armazenar o ano de nascimento da pessoa como número inteiro.

### Relacionamento


