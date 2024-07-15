#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000

typedef struct no {
    char palavra[50]; // Armazena a palavra
    struct no* proximo;
} No;

typedef struct Lista {
    No* inicio;
    int tam;
}Lista;

int funcaoHash(const char* palavra) {
    int i,soma = 0;
    for (i = 0; palavra[i] != '\0'; i++) {
        soma += palavra[i];
    }
    return soma % TAM;
}

void inicializarLista(Lista* l) {
    l->inicio = NULL;
    l->tam = 0;
}

void inserirNaLista(Lista* l, const char* palavra) {
    No* novo = malloc(sizeof(No));
    if (novo) {
        strcpy(novo->palavra, palavra);
        novo->proximo = l->inicio;
        l->inicio = novo;
        l->tam++;
    } else {
        printf("\nErro ao alocar memória!\n");
    }
}

void buscarNaLista(Lista* l) {
    No* aux = l->inicio;
    while (aux) {
        printf("%s\n",aux->palavra);
        aux = aux->proximo;
    }
    //return 0; // Palavra não encontrada
}

/*int buscarNaLista(Lista* l, const char* palavra) {
    No* aux = l->inicio;
    while (aux) {
        if (strcmp(aux->palavra, palavra) == 0) {
            return 1; // Palavra encontrada
        }
        aux = aux->proximo;
    }
    return 0; // Palavra não encontrada
}*/

// Função para contar a frequência de cada letra
int* contar_frequencia(const char *palavra, int frequencia[26]) {
    int i;
	for (i = 0; palavra[i] != '\0'; i++) {
        
        int indice = tolower(palavra[i]) - 'a';
        frequencia[indice]++;
    }
    return frequencia;
}

// Função para imprimir as letras que aparecem apenas uma vez
void letras_nao_repetidas(const int frequencia[26]) {
    printf("Letras que não se repetem: ");
    int i;
	for (i = 0; i < 26; i++) {
        if (frequencia[i] > 0) {
            printf("%c ", 'a' + i);
        }
    }
    printf("\n");
}

int main() {
	Lista tabela[TAM];
    int i;
	for (i = 0; i < TAM; i++) {
        inicializarLista(&tabela[i]);
    }

    int option = 1;
	
	while(option != 0){
		
		char palavra[50];
    	char letters[26] = {0};
   	    int frequencia[26] = {0};
    	int i,j=0;
		printf("1 - Insira uma palavra\n2 - Procure uma chave\n0 - sair\n");
		scanf("%d",&option);
		
		switch(option){
			case 1:
				printf("Digite a palavra: ");
    			scanf("%s", palavra);
   				 //contar_frequencia(palavra, frequencia);
    			*frequencia = contar_frequencia(palavra, frequencia);
				for (i = 0; i < 26; i++) {
        			if (frequencia[i] > 0) {
            			letters[j] = 'a' + i;
    		        	j++;
        			}
    			}
    			inserirNaLista(&tabela[funcaoHash(letters)],palavra);
    			break;
    		case 2:
				printf("Digite uma chave: ");
				scanf("%s",palavra);
				
				buscarNaLista(&tabela[funcaoHash(palavra)]);
				break;
			default:
				break;
		}
		system("pause");
		system("cls");
	}
    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000 // Tamanho da tabela (pode ser ajustado)

// Estrutura para o nó da lista encadeada
typedef struct no {
    char palavra[50]; // Armazena a palavra
    struct no* proximo;
} No;

// Estrutura para a lista encadeada
typedef struct Lista {
    No* inicio;
    int tam;
}Lista;

// Função hash (resto da divisão)
int funcaoHash(const char* palavra) {
    int i,soma = 0;
    for (i = 0; palavra[i] != '\0'; i++) {
        soma += palavra[i];
    }
    return soma % TAM;
}

// Procedimento para inicializar uma lista
void inicializarLista(Lista* l) {
    l->inicio = NULL;
    l->tam = 0;
}

// Procedimento para inserir uma palavra na lista
void inserirNaLista(Lista* l, const char* palavra) {
    No* novo = malloc(sizeof(No));
    if (novo) {
        strcpy(novo->palavra, palavra);
        novo->proximo = l->inicio;
        l->inicio = novo;
        l->tam++;
    } else {
        printf("\nErro ao alocar memória!\n");
    }
}

// Função para buscar uma palavra na lista
int buscarNaLista(Lista* l, const char* palavra) {
    No* aux = l->inicio;
    while (aux) {
        if (strcmp(aux->palavra, palavra) == 0) {
            return 1; // Palavra encontrada
        }
        aux = aux->proximo;
    }
    return 0; // Palavra não encontrada
}

int main() {
    Lista tabela[TAM];
    int i;
	for (i = 0; i < TAM; i++) {
        inicializarLista(&tabela[i]);
    }

    char palavra[50];
    char resposta;

    do {
        printf("Digite uma palavra: ");
        scanf("%s", palavra);

        int indice = funcaoHash(palavra);
        inserirNaLista(&tabela[indice], palavra);

        printf("Deseja adicionar outra palavra? (S/N): ");
        scanf(" %c", &resposta);
    } while (resposta == 'S' || resposta == 's');

    // Busca
    printf("\nDigite uma palavra para buscar: ");
    scanf("%s", palavra);
    int resultado = buscarNaLista(&tabela[funcaoHash(palavra)], palavra);
    if (resultado) {
        printf("Palavra encontrada: %s\n", palavra);
    } else {
        printf("Palavra não encontrada.\n");
    }

    return 0;
}
*/
