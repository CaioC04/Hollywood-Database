typedef enum {
    PAPEL_ACTOR,
    PAPEL_DIRECTOR,
    PAPEL_PRODUCER,
    PAPEL_WRITER
}Papel;

typedef struct{
    int id;
    char titulo[50];
    int ano;
    char tagline[100];
}Filme;

typedef struct{
    int id;
    char nome[50];
    int nascimento;
}Pessoa;

typedef struct{
    int pessoaID;
    int filmeID;
    Papel papel;
    char personagem[50];
}Relacionamento;
