Algoritmo "CestaBasica_VariacaoPrecos"

// Descrição: Lê 3 produtos da cesta básica e analisa variação percentual
// Autor: Rodrigo Correia Diniz
// Data: 15/09/2025

Var
   // Constante
³   N: inteiro

   // Variáveis de controle
   i: inteiro

   // Variáveis de entrada
   nome: caractere
   preco_anterior, preco_atual: real

   // Variáveis de processamento
   variacao: real
   situacao, alerta: caractere

Inicio
   // Inicialização
   N <- 3

   escreval("=== MONITORAMENTO DE PREÇOS DA CESTA BÁSICA ===")
   escreval("Análise de variação percentual de 3 produtos")
   escreval("===============================================")
   escreval("")

   // Loop para processar os 3 produtos
   para i de 1 ate N faca
      escreval("PRODUTO ", i, ":")
      escreva("Informe o nome do produto: ")
      leia(nome)

      escreva("Informe o PREÇO ANTERIOR (use vírgula como separador decimal, ex: 5,50): R$ ")
      leia(preco_anterior)

      escreva("Informe o PREÇO ATUAL (use vírgula como separador decimal): R$ ")
      leia(preco_atual)

      // Verificação se o preço anterior é zero (evita divisão por zero)
      se (preco_anterior = 0) entao
         variacao <- 0
         situacao <- "DADO INVÁLIDO (preço anterior = 0)"
         alerta <- ""
      senao
         // Cálculo da variação percentual
         variacao <- ((preco_atual - preco_anterior) / preco_anterior) * 100

         // Classificação da situação baseada na variação
         se (variacao > 0) entao
            situacao <- "AUMENTO"
         senao
            se (variacao < 0) entao
               situacao <- "QUEDA"
            senao
               situacao <- "ESTÁVEL"
            fimse
         fimse

         // Verificação de aumento abusivo (superior a 10%) ou limite
         se (variacao > 10.01) entao
            alerta <- "AUMENTO ABUSIVO"
         senao
            se (variacao >= 9.99) e (variacao <= 10.01) entao
               alerta <- "LIMITE DE AUMENTO"
            senao
               alerta <- ""
            fimse
         fimse
      fimse

      // Exibição dos resultados
      escreval("")
      escreval("--- RESULTADO DO PRODUTO ", i, " ---")
      escreval("Produto: ", nome)
      escreval("  Preço Anterior: R$ ", preco_anterior:0:2)
      escreval("  Preço Atual:    R$ ", preco_atual:0:2)

      // Formatação da variação com sinal
      se (variacao >= 0) entao
         escreval("  Variação: +", variacao:0:2, "%")
      senao
         escreval("  Variação: ", variacao:0:2, "%")
      fimse

      escreval("  Situação: ", situacao)

      // Exibe alerta apenas se existir
      se (alerta <> "") entao
         escreval("  ??  Alerta: ", alerta)
      fimse

      escreval("------------------------------")
      escreval("")
   fimpara

   escreval("Análise concluída! Obrigado por usar o sistema.")

Fimalgoritmo