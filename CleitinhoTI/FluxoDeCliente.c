#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


    




int main(){
    setlocale(LC_ALL, "");
    int opcao, valor;
    char nome[50], email[25], tel[15], linha[512], usuario[50], pecaTipo[50], servicoTipo[50], urgencia[20], data[15];
    char cpf [12];
   
do{
    printf("\n### BEM VINDOS A CENTRAL DO REST TI ###\n");
    printf("\n--- Escolha sua opcao: --- \n");
    printf("1- Cadastrar Cliente\n");
    printf("2- Listar os Clientes\n");
    printf("3- Atualizar dados\n");
    printf("4- Deletar\n");
    printf("5- Faturamento\n");
    printf("6- Fechar Sistema:");
    printf("\nOpcao: ");
    if (scanf(" %d", &opcao) != 1){ // se scanf devolver algum outro número além de 1 (comando funcionou normalmente), entra num bloco de tratamento de erro
       while(getchar() != '\n'); //Limpa o chacê  da variável até não sobrar nada 
       printf("Valor inválido, digite um NUMERO: ");
       continue;
    }
    
    switch(opcao){
        case 1:
            FILE *arquivo = fopen("dados.csv", "r");
            if(arquivo == NULL){
            arquivo = fopen("dados.csv", "w");
                                }
            else{
            fclose(arquivo);
            arquivo = fopen("dados.csv", "a");
                }     
            if(arquivo == NULL){
            printf("Erro ao abrir o arquivo.");
                                }
           
            
            printf("Digite seu nome: ");
            scanf(" %[^\n]", nome);
            
            printf("Digite seu e-mail: ");
            scanf(" %s", email);
            
            printf("Digite seu CPF (somente numero): ");
            scanf(" %s", cpf);

            printf("Digite seu telefone: ");
            scanf(" %s", tel);

            printf("Insira qual tipo de peça: ");
            scanf(" %[^\n]", pecaTipo);

            printf("Insira o tipo de Servico: ");
            scanf(" %[^\n]", servicoTipo);

            printf("Insira o valor cobrado pelo serviço: ");
            scanf("%d", &valor);

            printf("Insira a data de entrada da peça (no formato DD/MM/AA): ");
            scanf(" %[^\n]", data);

            printf("Insira a urgencia:");
            scanf(" %[^\n]", urgencia);

            fprintf(arquivo, "%s;%s;%s;%s;%s;%s;%d;%s;%s\n", nome, email, cpf, tel, pecaTipo, servicoTipo, valor, data, urgencia);
            printf("Arquivo salvo!\n");
            
            fclose(arquivo);
            printf("Dados Salvo com Sucesso!");

        break;

        case 2:

            int contador = 1;
            arquivo = fopen("dados.csv", "r");
            if (arquivo==NULL){
                printf("Não há usuarios para listar!.\n");
                break;
            }
            while(fgets(linha, sizeof(linha), arquivo)){
                char *coluna;
                int indice = 0;
                 
                coluna = strtok(linha, ";");
    

                while(coluna != NULL){
                    if (indice == 0){
                        printf("\n%d - %s\n", contador, coluna);
                        
                    }
                    if (indice == 0){
                        contador++;
                    }
                    
                    coluna = strtok(NULL, ";");
                    indice++;
                   
                }
            }

            fclose(arquivo);
            break;

        case 3: //Atualizar/Editar

            int clienteEstoque;
            char produtoNome[30];

            printf("Deseja atualizar (1) Cliente ou (2) Estoque: "); /* Bloco condicional para saber se o usuário que atualizar cliente ou usuário */
            scanf("%d", &clienteEstoque);
            getchar();

            // CASO O USUÁRIO ESCOLHA CLIENTE
            if (clienteEstoque == 1){
                    arquivo = fopen("dados.csv", "r");
                if (arquivo==NULL){
                    printf("Usuários não encontrados!");
                    break;
                }
            
            char valorBuscado [256]; /* Declara uma váriavel pra eu digitar a palavra-chave que eu quero buscar (Futuramente, nome ou CPF:)*/
            int nomeCPF; /* Variavel pra receber se vai ser nome ou cpf*/

                // Laço de repetição para tratar e erros, e distinguir nome e CPF
         do{ 
            printf("Deseja buscar usuário por nome (1) ou CPF (2)?: ");
            if (scanf("%d", &nomeCPF) != 1){
                printf("\nValor Invalido!\n");
                while (getchar() != '\n');
                break;
            }
            getchar(); /* 'scanf' deixa resquícios. Quando nós usamos um comnado para entrada de dados do teclado, ele lê até o usuário apertar '\n' 
                            que seria o 'Enter', então ele escaneia esse '\n' e insere como um caracter, mas existe um buffer de entrada de dados, que
                            quando usamos o scanf, ele mantém o '\n', então esse 'getchar()' serve pra limpar esse cache (ou seja, remove
                             o '\n' do buffer) e evidar futuros erros!*/

            if (nomeCPF == 1){
                printf("Insira o nome que você deseja buscar: ");
                fgets(valorBuscado, sizeof(valorBuscado), stdin); // serve como o scanf, (Variavel_Destino, tamanho da variavel, Variavel_Origem) -> Sendo variávvel origem, o stdin (teclado)
                valorBuscado[strcspn(valorBuscado, "\n")] = '\0'; // remove o '\n'
            }
            else if (nomeCPF == 2){
                printf("Insira o CPF do usuário que você deseja buscar: ");
                fgets(valorBuscado, sizeof(valorBuscado), stdin);
                valorBuscado[strcspn(valorBuscado, "\n")] = '\0';
                            }
                            
            else{
                printf("Opção Inválida! Tente outro valor!\n");
            }
            }while(nomeCPF != 1 && nomeCPF != 2);

            //Laço de repetição para mudar a posição da coluna a ser encontrada, conforme nome ou CPF
            int posicaoColuna = (nomeCPF == 1) ? 0 : 2;
            char linhaEncontrada[256];

            while(fgets(linha, sizeof(linha), arquivo)){  //Ler o arquivo linha por linha
                char linhaOriginal[256];  // Auxiliar a leitura da linha
                strcpy(linhaOriginal, linha); //copia a  lida pelo fgets, numa variável, pois o strtok altera a leitura da linha no arquivo original 

                char *coluna;
                int indice = 0;  //indice da linha percorrida
                int encontrou = 0; //variável pra definir se achou

                coluna = strtok(linha, ";"); // encontra o ';' e separa em colunas
                while(coluna != NULL){
                    if (indice == posicaoColuna){
                        coluna[strcspn(coluna, "\n")] = '\0'; 
                        if(strcmp(coluna, valorBuscado) == 0){  // compara se a coluna é igual a variavel para buscar
                            encontrou = 1; // se encontrou a coluna que é igual ao valor buscado, retorna encontrou como True
                        }
                        
                    }
                    coluna = strtok(NULL, ";"); // por que ele começa a analisar novamente do ponto onde parou até a próxima, é um comando pra continuar separando os valores a cada ';'
                    indice++;
                }

                if (encontrou){
                    printf("\nRegistro encontrado: %s", linhaOriginal); // imprime a linha original
                }
    
            }
            typedef struct{
                    char nomeArchive[50], emailArchive[50], cpfArchive[15], telArchive[12],
                    pecaTipoArchive[50], servicoTipoArchive[50], dataArchive[15], urgenciaArchive[25];
                    int valorArchive;
            } Dados; //struct para facilitar o armazenamento de dados no arquivo

            FILE *temporario; //cria um arquivo temporário para fazer alterações
            Dados dados;
            char novoValor[100];
            int encontrado = 0, opcaoChange, valorNovo;

            rewind(arquivo); // toda vez que o arquivo é lido, ele 'termina de ler' no final, então rewind(arquivo) prepara pra próxima leitura
            char linhaEcontrada[256];
            Dados dadosEncontrados;

           
            while(fgets(linha, sizeof(linha), arquivo)){
                //remove a quebra de linha
                linha[strcspn(linha, "\n")] = '\0'; //substitui \n por \0
            
            char linhaCopia[256];
            strcpy(linhaCopia, linha); //copia a linha original em linhaCopia
            
            char *token = strtok(linhaCopia, ";"); //separa a linha por ';'
            if (token == NULL) continue;
            // a cada strtok, pega um elemento do csv (nome, email, cpf) e atribui ele a um valor do struct, esse processo é feito para cada valor no csv
            strcpy(dados.nomeArchive, token);

            token = strtok(NULL, ";");
            if (token != NULL) strcpy(dados.emailArchive, token);
            
            token = strtok(NULL, ";");
            if (token != NULL) strcpy(dados.cpfArchive, token);

            token = strtok(NULL, ";");
            if (token != NULL) strcpy(dados.telArchive, token);
        
            token = strtok(NULL, ";");
            if (token != NULL) strcpy(dados.pecaTipoArchive, token);
            
            token = strtok(NULL, ";");
            if (token != NULL) strcpy(dados.servicoTipoArchive, token);
            
            token = strtok(NULL, ";");
            if (token != NULL) dados.valorArchive = (int)strtol(token, NULL, 10);

            token = strtok(NULL, ";");
            if (token != NULL) strcpy(dados.dataArchive, token);
            
            token = strtok(NULL, ";");
            if (token != NULL) strcpy(dados.urgenciaArchive, token);
            
            int corresponde = 0;
            //checa se o valor buscado é igual ao no arquivo

            if (nomeCPF == 1 && strcmp(dados.nomeArchive, valorBuscado) == 0){
                corresponde = 1;
            }else if (nomeCPF == 2 && strcmp(dados.cpfArchive, valorBuscado) == 0){
                corresponde = 1;
            } 
            if(corresponde){
                    encontrado = 1;
                    strcpy(linhaEncontrada, linha);
                    //salva os dados encontrados
                    memcpy(&dadosEncontrados, &dados, sizeof(Dados));
                    printf("\n=== EDITANDO REGISTRO ===\n");
                    printf("1 - Nome: %s\n", dados.nomeArchive);
                    printf("2 - Email: %s\n", dados.emailArchive);
                    printf("3 - CPF: %s\n", dados.cpfArchive);
                    printf("4 - Tel: %s\n", dados.telArchive);
                    printf("5 - Tipo de Peça: %s\n", dados.pecaTipoArchive);
                    printf("6 - Tipo de serviço: %s\n", dados.servicoTipoArchive);
                    printf("7 - Valor: %d\n", dados.valorArchive);
                    printf("8 - Data de entrada: %s\n", dados.dataArchive);
                    printf("9 - urgencia: %s\n", dados.urgenciaArchive);
            }
        }

        if (!encontrado){
            printf("Registro não encontrado! \n");
            fclose(arquivo);
            break;
        }
                    printf("\n### EDITANDO REGISTRO ###\n");
                    printf("Qual campo você quer alterar?\n");
                    printf("1 - Nome\n");
                    printf("2 - Email\n");
                    printf("3 - CPF\n");
                    printf("4 - Telefone\n");
                    printf("5 - Tipo de Peça\n");
                    printf("6 - Tipo de serviço\n");
                    printf("7 - Valor\n");
                    printf("8 - Data de entrada\n");
                    printf("9 - urgencia\n");
          
                    printf("Opção: ");
                        scanf(" %d", &opcaoChange);
                        getchar();

                        memcpy(&dados, &dadosEncontrados, sizeof(Dados)); // 'memcpy' copia bloco de dados, nesse caso, copiou os valores pro struct

                        switch(opcaoChange){
                            case 1:
                                printf("Insira o novo nome: ");
                                fgets(novoValor, sizeof(novoValor), stdin);
                                novoValor[strcspn(novoValor, "\n")] = '\0';
                                strcpy(dados.nomeArchive, novoValor);
                                printf("Nome atualizado com sucesso!\n");
                                break;

                            case 2:
                                printf("Insira o novo email: ");
                                fgets(novoValor, sizeof(novoValor), stdin);
                                novoValor[strcspn(novoValor, "\n")] = '\0';
                                strcpy(dados.emailArchive, novoValor);
                                printf("Email atualizado com sucesso!\n");
                                break;
                            case 3:
                                printf("Insira o novo CPF: ");
                                fgets(novoValor, sizeof(novoValor), stdin);
                                novoValor[strcspn(novoValor, "\n")] = '\0';
                                strcpy(dados.cpfArchive, novoValor);
                                printf("CPF atualizado com sucesso!\n");
                                break;
                             case 4:
                                printf("Insira o novo número de cel: ");
                                fgets(novoValor, sizeof(novoValor), stdin);
                                novoValor[strcspn(novoValor, "\n")] = '\0';
                                strcpy(dados.telArchive, novoValor);
                                printf("Numero de celular atualizado com sucesso!\n");
                                break;
                            case 5:
                                printf("Insira o novo tipo de peça: ");
                                fgets(novoValor, sizeof(novoValor), stdin);
                                novoValor[strcspn(novoValor, "\n")] = '\0';
                                strcpy(dados.pecaTipoArchive, novoValor);
                                printf("Tipo de peça atualizado com sucesso!\n");
                                break;
                            case 6:
                                printf("Insira o novo serviço: ");
                                fgets(novoValor, sizeof(novoValor), stdin);
                                novoValor[strcspn(novoValor, "\n")] = '\0';
                                strcpy(dados.servicoTipoArchive, novoValor);
                                printf("Tipo de serviço atualizado com sucesso!\n");
                                break;
                            case 7:
                                printf("Insira o novo valor: ");
                                scanf(" %d", &valorNovo);
                                dados.valorArchive = valorNovo;
                                printf("Valor atualizado com sucesso!\n");
                                break;
                            case 8:
                               printf("Insira a nova data de entrada: ");
                                fgets(novoValor, sizeof(novoValor), stdin);
                                novoValor[strcspn(novoValor, "\n")] = '\0';
                                strcpy(dados.dataArchive, novoValor);
                                printf("Data atualizado com sucesso!\n");
                                break;
                            case 9:
                               printf("Insira a nova urgência: ");
                                fgets(novoValor, sizeof(novoValor), stdin);
                                novoValor[strcspn(novoValor, "\n")] = '\0';
                                strcpy(dados.dataArchive, novoValor);
                                printf("Urgência atualizada com sucesso!\n");
                                break;

                            default:
                                printf("Opcao Invalida!");
                                fclose(arquivo);
                                break;

                        }
                        rewind(arquivo);
                         temporario = fopen("temporario.csv", "w");
                            if (temporario == NULL){
                                printf("Erro ao criar arquivo temporário!\n");
                                fclose(arquivo);
                                break;
                                                }

                    int atualizado = 0;
                    while(fgets(linha, sizeof(linha), arquivo)){
                        
                        linha[strcspn(linha, "\n")] = '\0';

                        char linhaCopia[256];
                        strcpy(linhaCopia, linha);

                        char *token = strtok(linhaCopia, ";");
                        if (token == NULL) continue;

                        char nomeAtual[50];
                        strcpy(nomeAtual, token);

                        token = strtok(NULL, ";");
                        char emailAtual[50];
                        strcpy(emailAtual, token);

                        token = strtok(NULL, ";");
                        char cpfAtual[15];
                        if (token != NULL) strcpy(cpfAtual,token);

                        int ehORegistro = 0;
                        
                        if (nomeCPF == 1 && strcmp(nomeAtual, valorBuscado) || (nomeCPF == 2 && strcmp(cpfAtual, valorBuscado)) == 0){
                            ehORegistro = 1;
                        }
                        else{
                            ehORegistro = 0;
                        }

                        if (ehORegistro && !atualizado){
                             fprintf(temporario, "%s;%s;%s;%s;%s;%s;%d;%s;%s\n", dados.nomeArchive, dados.emailArchive, dados.cpfArchive, dados.telArchive,
                                dados.pecaTipoArchive, dados.servicoTipoArchive, dados.valorArchive, dados.dataArchive, dados.urgenciaArchive);
                            atualizado = 1;
                            printf("\nRegistro atualizado no arquivo\n"); 

                        }else{
                            fprintf(temporario, "%s\n", linha);
                        }
                    }
                   
                    
                fclose(arquivo);
                fclose(temporario); 

                    if (atualizado){
                        remove("dados.csv");
                        rename("temporario.csv", "dados.csv");
                        printf("Arquivo atualizado com sucesso!\n");
                    }else{
                        remove("temporario.csv");
                        printf("Erro ao atualizar o arquivo!\n");
                    }
                } else if (clienteEstoque == 2){
                    //Falta criar a parte de estoque pra poder criar Atualizar/Editar estoque
                    //O que deve ser feito?
                    //1. A opcao de remover itens ( decrementar itens / quais itens foram usados)
                    int removerAdicionar;
                    printf("(1) Adicionar\n(2) Remover\n");
                    scanf(" %d", &removerAdicionar);

                    if (removerAdicionar == 1){
                        typedef struct {
                            char nome[50];
                            int quantidade;
                        }Produto;

                        FILE *estoque = fopen("estoque.csv", "r");
                        FILE *temp = fopen("temp.csv", "w");

                        Produto p;
                        char nomeBusca[50];
                        int quantidadeAdd;
                        int encontrado = 0;

                        if (estoque == NULL){

                            estoque = fopen("estoque.csv", "w");
                            fclose(estoque);
                            estoque = fopen("estoque.csv", "r");
                        }
                        getchar();
                        printf("Nome do produto que você deseja adicionar: ");
                        fgets(nomeBusca, sizeof(nomeBusca), stdin);
                        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

                        printf("\nQuantidade a adicionar: ");
                        scanf("%d", &quantidadeAdd);
                        getchar();

                        char linha[256];
                        while (fgets(linha, sizeof(linha), estoque)){
                            sscanf(linha, "%49[^;];%d", p.nome, &p.quantidade);

                            if (strcmp(p.nome,  nomeBusca) == 0 ){
                                p.quantidade += quantidadeAdd;
                                encontrado = 1;     

                            }
                            fprintf(temp, "%s;%d\n", p.nome, p.quantidade);
                        }
                        if (!encontrado){
                            fprintf(temp, "%s;%d\n", nomeBusca, quantidadeAdd);
                        }

                        fclose(estoque);
                        fclose(temp);
                        remove("estoque.csv");
                        rename("temp.csv", "estoque.csv");

                        printf("Produto alterado com sucesso!\n");
                                        }
                                    
                    //2. A opcao de adicionar itens (quais itens foram comprados, obs: se não existir, adicionar, se existir incrementar o contador)
                    if (removerAdicionar == 2){
                        FILE *estoque = fopen("estoque.csv", "r");
                        FILE *temp = fopen("temp.csv", "w");
                        typedef struct {
                            char nome[50];
                            int quantidade;
                        }Produto;

                        Produto p;
                        char nomeBusca[50];
                        int quantidadeAdd;
                        int encontrado = 0;

                        if (estoque == NULL){

                            estoque = fopen("estoque.csv", "w");
                            fclose(estoque);
                            estoque = fopen("estoque.csv", "r");
                        }
                        
                        getchar();
                        printf("Nome do produto que você deseja remover: ");
                        fgets(nomeBusca, sizeof(nomeBusca), stdin);
                        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

                        printf("\nQuantidade a remover: ");
                        scanf("%d", &quantidadeAdd);
                        getchar();

                        char linha[256];
                        while (fgets(linha, sizeof(linha), estoque)){
                            sscanf(linha, "%49[^;];%d", p.nome, &p.quantidade);

                            if (strcmp(p.nome,  nomeBusca) == 0 ){
                                p.quantidade -= quantidadeAdd;
                                encontrado = 1;     

                            }
                            fprintf(temp, "%s;%d\n", p.nome, p.quantidade);
                        }
                        if (!encontrado){
                            fprintf(temp, "%s;%d\n", nomeBusca, quantidadeAdd);
                        }

                        fclose(estoque);
                        fclose(temp);
                        remove("estoque.csv");
                        rename("temp.csv", "estoque.csv");

                        printf("Produto alterado com sucesso!\n");
                                        }
                                    }

                        break;
                                   
        case 4:
            char pessoaRemover[50];
            printf("Insira o nome do cliente que você deseja deletar: ");
            getchar();
            fgets(pessoaRemover, sizeof(pessoaRemover), stdin);
            pessoaRemover[strcspn(pessoaRemover, "\n")] = '\0';

            arquivo = fopen("dados.csv", "r");
            FILE *temp = fopen("temp.csv", "w");
            while (fgets(linha, sizeof(linha), arquivo)) {

                char nome[50];
                char linhaCopia[256];

                strcpy(linhaCopia, linha);  // Para preservar a linha original

                // Pega só o nome (primeira coluna)
                sscanf(linhaCopia, "%[^;]", nome);

                // Se o nome NÃO é o que queremos remover → copia linha para temp
                if (strcmp(nome, pessoaRemover) != 0) {
                    fputs(linha, temp);  // Escreve linha como ela é
                }
            }

            printf("\nUsuário deletado com sucesso!\n");

            fclose(arquivo);
            fclose(temp);
            remove("dados.csv");
            rename("temp.csv", "dados.csv");
            break;
        case 5:
            char linha[100];
            char mesDesejado[3];
            int faturamentoTotal = 0;

            getchar();
            printf("Digite o mês desejado \n01- Janeiro\n02- Fevereiro \n03- Março \n04- Abril \n05- Maio \n06- Junho \n07- Julho \n08- Agosto \n09- Setembro \n10- Outubro \n11- Novembro \n12- Dezembro \nOpcao: ");
            fgets(mesDesejado, sizeof(mesDesejado), stdin);
            mesDesejado[strcspn(mesDesejado, "\n")] = '\0';

            FILE *moneyArchive = fopen("dados.csv", "r");

            while (fgets(linha, sizeof(linha), moneyArchive)) {
                char data[15], faturamentoStr[20];
                int faturamento;

                // Separa data e faturamento da linha
                sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%[^;];%[^;]", faturamentoStr, data);

                // Converte faturamento para número
                faturamento = atoi(faturamentoStr);
               
                // Extrai o mês da data
                char mes[3];
                sscanf(data, "%*[^/]/%2[^/]/", mes);

                // Verifica se o mês é o desejado
                if (strcmp(mes, mesDesejado) == 0) {
                    faturamentoTotal += faturamento;
                    printf("Data: %s | Faturamento: R$ %d\n", data, faturamento);
                }

            }
            printf("Faturamento total no mês %s : %d", mesDesejado, faturamentoTotal);
            faturamentoTotal = 0;
            fclose(moneyArchive);
            break;
        case 6:
            printf("Encerrando sistema...");

        default:
            printf("Opcao Inválida");


    }
}while(opcao!=6);
}