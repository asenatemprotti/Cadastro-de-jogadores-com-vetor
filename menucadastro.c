#include <stdio.h>

int main() {
    int nj[20], idade[20], i, n, op, varredura, nvetor, j, maior_pontuacao;
    float pontuacao[20], bonus, media_geral, soma;

    // Cadastro
    do {
        printf("Digite a quantidade de jogadores (max 20): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 20);

    for (i = 0; i < n; i++) {
        printf("\n--- Jogador %d ---\n", i + 1);

        printf("Numero do jogador: ");
        scanf("%d", &nj[i]);

        printf("Idade: ");
        scanf("%d", &idade[i]);

        printf("Pontuacao: ");
        scanf("%f", &pontuacao[i]);
    }

    printf("\nNumeros dos jogadores cadastrados: ");
    for (i = 0; i < n; i++) {
        printf("%d ", nj[i]);
    }
    printf("\n");

    do {
        printf("\n===== MENU DE OPCOES =====\n");
        printf("1 - Atualizar pontuacao de um jogador\n");
        printf("2 - Aumentar a pontuacao de todos (bonus global)\n");
        printf("3 - Remover um jogador do torneio\n");
        printf("4 - Exibir relatorio final\n");
        printf("Outro numero qualquer - Encerrar o programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op) {

        case 1:
            printf("Digite o numero do jogador que deseja alterar os pontos.\n");
            scanf("%d", &varredura);

            for (i = 0; i < n; i++) {
                if (nj[i] == varredura) {
                    printf("Digite a nova pontuacao: ");
                    scanf("%f", &pontuacao[i]);
                    printf("Pontuacao atualizada!\n");
                    break;
                }
            }
            break;

        case 2:
            printf("Digite o quanto voce quer aumentar a pontuacao de todos: ");
            scanf("%f", &bonus);
            for (i = 0; i < n; i++) {
                pontuacao[i] += bonus;
            }
            printf("Pontuacao de todos atualizada!\n");
            break;

        case 3:
            printf("Digite o numero do jogador que deseja apagar.\n");
            scanf("%d", &varredura);

            for(i = 0; i < n; i++) {
                if(nj[i] == varredura) {
                    for(j = i; j < n-1; j++) {
                        nj[j] = nj[j+1];
                        idade[j] = idade[j+1];
                        pontuacao[j] = pontuacao[j+1];
                    }
                    n--;
                    printf("Jogador apagado.\n");
                    break;
                }
            }
            break;

        case 4:
            maior_pontuacao = 0;
            for (i = 1; i < n; i++) {
                if (pontuacao[i] > pontuacao[maior_pontuacao]) {
                    maior_pontuacao = i;
                }
            }

            soma = 0;
            for (i = 0; i < n; i++) 
                soma += pontuacao[i];
            media_geral = soma / n;

            nvetor = 0;
            for (i = 0; i < n; i++) {
                if (pontuacao[i] > media_geral) nvetor++;
            }

            varredura = 0;
            for (i = 1; i < n; i++) {
                if (idade[i] < idade[varredura]) {
                    varredura = i;
                }
            }

            printf("\n--- RELATORIO FINAL ---\n");
            printf("Jogador com maior pontuacao: %d (%.2f pontos)\n", nj[maior_pontuacao], pontuacao[maior_pontuacao]);
            printf("Pontuacao media: %.2f\n", media_geral);
            printf("Jogadores acima da media: %d\n", nvetor);
            printf("Jogador mais jovem: %d (idade %d)\n", nj[varredura], idade[varredura]);

            return 0;

        default:
            printf("Encerrando o programa...\n");
        }

    } while(op >= 1 && op <= 4);

    return 0;
}
