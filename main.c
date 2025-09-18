/*
 * CHATBOT DE ATENDIMENTO VIRTUAL - NEXQUANTA LTDA
 * Desenvolvido por: Rodrigo Correia Diniz
 * 
 * Este programa implementa um sistema de atendimento automatizado
 * que oferece diferentes opções de serviço através de um menu interativo.
 * O sistema também coleta estatísticas de uso dos departamentos.
 */

#include <stdio.h>

// Declaração de variáveis globais para contadores de acesso
int acessos_suporte = 0;
int acessos_financeiro = 0;
int acessos_vendas = 0;
int acessos_recursos_humanos = 0;
int acessos_ouvidoria = 0;

// Declaração das funções (protótipos)
void exibir_cabecalho(void);
void exibir_menu(void);
void pausar_sistema(void);
void suporte_tecnico(void);
void departamento_financeiro(void);
void vendas_orcamentos(void);
void recursos_humanos(void);
void ouvidoria(void);
void exibir_estatisticas(void);
void mensagem_despedida(void);

/*
 * FUNÇÃO PRINCIPAL - Controla o fluxo do programa
 */
int main() {
    int opcao_usuario;              // Armazena a opção escolhida pelo usuário
    int sistema_ativo = 1;          // Flag para controlar o loop principal (1 = ativo, 0 = sair)
    
    // Exibir informações iniciais do sistema
    exibir_cabecalho();
    
    // Loop principal do sistema - continua até o usuário escolher sair (opção 0)
    while(sistema_ativo) {
        // Exibir menu e capturar opção do usuário
        exibir_menu();
        printf("Digite sua opção: ");
        scanf("%d", &opcao_usuario);
        
        // Estrutura switch para processar cada opção do menu
        switch(opcao_usuario) {
            case 1:
                suporte_tecnico();
                break;
                
            case 2:
                departamento_financeiro();
                break;
                
            case 3:
                vendas_orcamentos();
                break;
                
            case 4:
                recursos_humanos();
                break;
                
            case 5:
                ouvidoria();
                break;
                
            case 6:
                exibir_estatisticas();
                break;
                
            case 0:
                mensagem_despedida();
                sistema_ativo = 0;  // Encerra o loop principal
                break;
                
            default:
                // Tratamento de opção inválida
                printf("\nOPÇÃO INVÁLIDA!\n");
                printf("Por favor, escolha uma opção entre 0 e 6.\n");
                pausar_sistema();
                break;
        }
    }
    
    return 0;    // Retorna 0 indicando execução bem-sucedida
}

/*
 * FUNÇÃO: exibir_cabecalho
 * Exibe o cabeçalho inicial do sistema e instruções de uso
 */
void exibir_cabecalho(void) {
    printf("===============================================\n");
    printf("       CHATBOT DE ATENDIMENTO VIRTUAL       \n");
    printf("              NEXQUANTA LTDA                \n");
    printf("    Desenvolvido por: Rodrigo Correia Diniz \n");
    printf("===============================================\n\n");
    
    printf("Bem-vindo(a) ao nosso sistema automático!\n");
    printf("Este programa foi desenvolvido para oferecer\n");
    printf("atendimento rápido e eficiente 24 horas.\n\n");
    
    printf("COMO FUNCIONA:\n");
    printf("- Escolha uma opção digitando o número\n");
    printf("- Pressione ENTER após cada escolha\n");
    printf("- Use a opção 6 para ver estatísticas\n");
    printf("- Digite 0 quando quiser sair\n\n");
    
    printf("Vamos começar? Selecione uma opção:\n");
    printf("===============================================\n\n");
}

/*
 * FUNÇÃO: exibir_menu
 * Exibe o menu principal com todas as opções disponíveis
 */
void exibir_menu(void) {
    printf("================ MENU PRINCIPAL ===============\n");
    printf("1 - Suporte Técnico\n");
    printf("2 - Financeiro\n"); 
    printf("3 - Vendas e Orçamentos\n");
    printf("4 - Recursos Humanos\n");
    printf("5 - Ouvidoria\n");
    printf("6 - Estatísticas de Uso\n");
    printf("0 - Sair do Sistema\n");
    printf("===============================================\n");
}

/*
 * FUNÇÃO: pausar_sistema
 * Pausa o sistema aguardando o usuário pressionar ENTER
 */
void pausar_sistema(void) {
    printf("Pressione ENTER para retornar ao menu principal...");
    getchar();      // Captura o ENTER da entrada anterior
    getchar();      // Aguarda o ENTER do usuário
    printf("\n");
}

/*
 * FUNÇÃO: suporte_tecnico
 * Exibe informações do departamento de suporte técnico
 */
void suporte_tecnico(void) {
    acessos_suporte++;              // Incrementa contador de acessos
    
    printf("\n=== SUPORTE TÉCNICO ===\n");
    printf("Olá! Sou seu assistente de suporte técnico.\n");
    printf("Estou aqui para ajudar com:\n\n");
    
    // Array com os serviços oferecidos
    char servicos[][50] = {
        "Problemas de conexão com internet",
        "Instalação e configuração de software", 
        "Manutenção de computadores",
        "Recuperação de senhas e dados",
        "Atualizações de sistema"
    };
    
    // Loop for para exibir todos os serviços
    for(int i = 0; i < 5; i++) {
        printf("• %s\n", servicos[i]);
    }
    
    printf("\nTelefone: (11) 3000-1111\n");
    printf("Email: suporte@nexquanta.com.br\n");
    printf("Horário: 24 horas por dia\n\n");
    
    pausar_sistema();
}

/*
 * FUNÇÃO: departamento_financeiro
 * Exibe informações do departamento financeiro
 */
void departamento_financeiro(void) {
    acessos_financeiro++;           // Incrementa contador de acessos
    
    printf("\n=== DEPARTAMENTO FINANCEIRO ===\n");
    printf("Bem-vindo ao setor financeiro da NEXQUANTA!\n");
    printf("Nossos serviços incluem:\n\n");
    
    // Array com os serviços financeiros
    char servicos_financeiros[][40] = {
        "Emissão de segunda via de boletos",
        "Negociação de débitos em atraso",
        "Parcelamento de faturas",
        "Esclarecimentos sobre cobranças",
        "Atualização de dados bancários"
    };
    
    // Loop for para exibir serviços financeiros
    for(int i = 0; i < 5; i++) {
        printf("• %s\n", servicos_financeiros[i]);
    }
    
    printf("\nTelefone: (11) 3000-2222\n");
    printf("Email: financeiro@nexquanta.com.br\n");
    printf("Horário: Segunda a Sexta, 8h às 18h\n\n");
    printf("Dica: Tenha em mãos seu CPF/CNPJ para atendimento mais rápido!\n\n");
    
    pausar_sistema();
}

/*
 * FUNÇÃO: vendas_orcamentos
 * Exibe informações de vendas e pacotes disponíveis
 */
void vendas_orcamentos(void) {
    acessos_vendas++;               // Incrementa contador de acessos
    
    printf("\n=== VENDAS E ORÇAMENTOS ===\n");
    printf("Olá! Que bom que você tem interesse em nossos produtos!\n");
    printf("Confira nossas soluções:\n\n");
    
    // Arrays com informações dos pacotes
    char nome_pacotes[][20] = {"BÁSICO", "PREMIUM", "EMPRESARIAL"};
    char precos[][20] = {"R$ 149,90/mês", "R$ 299,90/mês", "Sob consulta"};
    
    // Loop for para exibir pacotes
    for(int i = 0; i < 3; i++) {
        printf("PACOTE %s - %s\n", nome_pacotes[i], precos[i]);
        
        // Switch para exibir características específicas de cada pacote
        switch(i) {
            case 0:  // Pacote Básico
                printf("   → Sistema de gestão completo\n");
                printf("   → Suporte via chat\n\n");
                break;
                
            case 1:  // Pacote Premium
                printf("   → Tudo do básico +\n");
                printf("   → Suporte telefônico prioritário\n");
                printf("   → Backup automático na nuvem\n\n");
                break;
                
            case 2:  // Pacote Empresarial
                printf("   → Soluções personalizadas\n");
                printf("   → Consultoria especializada\n\n");
                break;
        }
    }
    
    printf("Telefone: (11) 3000-3333\n");
    printf("Email: vendas@nexquanta.com.br\n");
    printf("Promoção: 20%% de desconto no primeiro mês!\n\n");
    
    pausar_sistema();
}

/*
 * FUNÇÃO: recursos_humanos
 * Exibe informações sobre vagas e benefícios
 */
void recursos_humanos(void) {
    acessos_recursos_humanos++;    // Incrementa contador de acessos
    
    printf("\n=== RECURSOS HUMANOS ===\n");
    printf("A NEXQUANTA está sempre em busca de talentos!\n");
    printf("Venha fazer parte da nossa equipe:\n\n");
    
    printf("VAGAS ABERTAS:\n");
    
    // Array com vagas disponíveis
    char vagas[][40] = {
        "Desenvolvedor(a) Full Stack",
        "Analista de Suporte Técnico",
        "Designer UX/UI", 
        "Representante de Vendas",
        "Estagiário(a) em TI"
    };
    
    // Loop for para exibir vagas
    for(int i = 0; i < 5; i++) {
        printf("• %s\n", vagas[i]);
    }
    
    printf("\nBENEFÍCIOS:\n");
    
    // Array com benefícios
    char beneficios[][35] = {
        "Vale alimentação e transporte",
        "Plano de saúde e odontológico",
        "Home office híbrido",
        "Treinamentos e certificações"
    };
    
    // Loop for para exibir benefícios
    for(int i = 0; i < 4; i++) {
        printf("• %s\n", beneficios[i]);
    }
    
    printf("\nTelefone: (11) 3000-4444\n");
    printf("Email: rh@nexquanta.com.br\n");
    printf("Site: www.nexquanta.com.br/carreiras\n\n");
    
    pausar_sistema();
}

/*
 * FUNÇÃO: ouvidoria
 * Exibe informações da ouvidoria e gera protocolo
 */
void ouvidoria(void) {
    acessos_ouvidoria++;            // Incrementa contador de acessos
    
    printf("\n=== OUVIDORIA ===\n");
    printf("Sua opinião é fundamental para melhorarmos!\n");
    printf("A Ouvidoria da NEXQUANTA está aqui para:\n\n");
    
    printf("REGISTRAR:\n");
    
    // Array com tipos de solicitações
    char tipos_solicitacao[][35] = {
        "Elogios e sugestões",
        "Reclamações sobre atendimento", 
        "Denúncias de condutas inadequadas",
        "Solicitações de melhoria"
    };
    
    // Loop for para exibir tipos de solicitação
    for(int i = 0; i < 4; i++) {
        printf("• %s\n", tipos_solicitacao[i]);
    }
    
    printf("\nPROCESSO RÁPIDO:\n");
    printf("→ Protocolo gerado automaticamente\n");
    printf("→ Resposta em até 48 horas\n");
    printf("→ Acompanhamento por email\n\n");
    
    printf("Telefone: (11) 3000-5555\n");
    printf("Email: ouvidoria@nexquanta.com.br\n");
    printf("Sigilo total garantido!\n\n");
    
    // Geração de protocolo único baseado no número de acessos
    printf("Protocolo da sua consulta: #NEX%d\n", 1000 + acessos_ouvidoria);
    
    printf("\n");
    pausar_sistema();
}

/*
 * FUNÇÃO: exibir_estatisticas
 * Calcula e exibe estatísticas de uso do sistema
 */
void exibir_estatisticas(void) {
    printf("\n=== ESTATÍSTICAS DE USO ===\n");
    printf("Dados de acesso ao sistema:\n");
    printf("─────────────────────────────────────\n");
    
    // Arrays para organizar dados das estatísticas
    char nomes_departamentos[][20] = {
        "Suporte Técnico", "Financeiro", "Vendas", 
        "Recursos Humanos", "Ouvidoria"
    };
    
    int acessos_departamentos[] = {
        acessos_suporte, acessos_financeiro, acessos_vendas,
        acessos_recursos_humanos, acessos_ouvidoria
    };
    
    int total_acessos = 0;
    
    // Loop for para exibir estatísticas e calcular total
    for(int i = 0; i < 5; i++) {
        printf("%s: %d acesso(s)\n", nomes_departamentos[i], acessos_departamentos[i]);
        total_acessos += acessos_departamentos[i];
    }
    
    printf("─────────────────────────────────────\n");
    printf("Total de acessos: %d\n\n", total_acessos);
    
    // Análise do departamento mais acessado (apenas se houver acessos)
    if(total_acessos > 0) {
        printf("DEPARTAMENTO MAIS ACESSADO:\n");
        
        int maior_acesso = 0;
        int indice_maior = 0;
        
        // Loop for para encontrar o departamento com mais acessos
        for(int i = 0; i < 5; i++) {
            if(acessos_departamentos[i] > maior_acesso) {
                maior_acesso = acessos_departamentos[i];
                indice_maior = i;
            }
        }
        
        printf("→ %s (%d acessos)\n", nomes_departamentos[indice_maior], maior_acesso);
    }
    
    printf("\n");
    pausar_sistema();
}

/*
 * FUNÇÃO: mensagem_despedida
 * Exibe mensagem de encerramento do sistema
 */
void mensagem_despedida(void) {
    printf("\n===============================================\n");
    printf("       OBRIGADO POR USAR A NEXQUANTA!        \n");
    printf("===============================================\n");
    printf("Esperamos ter atendido suas expectativas.\n");
    printf("Volte sempre que precisar de nossos serviços!\n\n");
    printf("Desenvolvido por: Rodrigo Correia Diniz\n");
    printf("NEXQUANTA - Inovação e Qualidade em TI\n");
    printf("===============================================\n");
}