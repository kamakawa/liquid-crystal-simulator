# 🧊 Simulador Monte Carlo 3D para Cristais Líquidos com Ancoramento Superficial

> Projeto de Iniciação Científica desenvolvido por **Eric Kamakawa** e **Iago Sitta**, sob orientação dos professores **Rafael Zola** e **Rodolfo Teixeira**, no curso de Engenharia da Computação da UTFPR – Apucarana.

---

## 🎯 Objetivo

Este projeto de Iniciação Científica visa dar continuidade e aprimorar o simulador computacional McLiCS (Monte Carlo Liquid Crystal Simulator), explorando o comportamento de sistemas de cristais líquidos nemáticos em três dimensões. O foco principal é a implementação e análise do modelo de Lebwohl-Lasher e a incorporação de diversas condições de ancoramento superficial para simulações em diferentes regimes físicos.

O projeto é uma aplicação direta de física computacional, combinando conceitos de física estatística e programação para resolver problemas complexos da matéria condensada.

---

## 🔬 Contexto Físico

Cristais líquidos nemáticos são um estado da matéria com orientações moleculares parcialmente ordenadas, encontrando aplicações em tecnologias de ponta como telas LCD, sensores térmicos e materiais fotônicos.

Para estudar o comportamento de orientação coletiva dessas moléculas, o projeto utiliza o modelo de Lebwohl-Lasher (LL). Neste modelo, cada molécula é simplificada como um vetor tridimensional que interage com seus vizinhos mais próximos. A energia de interação é descrita pelo potencial U 
ij
​
 =−JP 
2
​
 (cosθ 
ij
​
 ), onde P 
2
​
 (cosθ 
ij
​
 ) é o segundo polinômio de Legendre e θ 
ij
​
  é o ângulo entre as orientações de moléculas vizinhas.

O projeto também explora o papel das superfícies, que exercem forças de ancoramento capazes de influenciar a orientação das moléculas, fenômeno crucial para o comportamento de displays e dispositivos ópticos.

---

## 🧮 Metodologia Computacional

A base do simulador é o Método de Monte Carlo, um algoritmo estocástico usado para modelar sistemas termodinâmicos. A evolução do sistema é governada pelo algoritmo de Metropolis, que aceita ou rejeita novas configurações (mudanças nas orientações moleculares) com base na variação de energia do sistema e na temperatura.

A simulação evolui o sistema sob diversas condições:

- Temperatura Constante: Análise do comportamento de equilíbrio em temperaturas específicas.

- Campo Elétrico Externo: Estudo da resposta do sistema à aplicação de um campo externo, simulando o princípio de operação de displays.

- Quench Térmico: Simulação de um resfriamento rápido, fundamental para investigar a formação de defeitos topológicos.

- Ancoramento de Fronteira: Simulação da interação das moléculas com as superfícies da célula, usando diferentes potenciais de ancoramento.


---

## 🗂️ Estrutura do Código

| Arquivo                      | Função |
|-----------------------------|--------|
| `main.cpp`                  | Inicia a simulação, configura parâmetros, seleciona métodos de evolução e ancoramento. |
| `evolve.cpp`                | Evolução padrão do sistema. |
| `evolve_step.cpp`          | Evolução em passos controlados. |
| `evolve_electric.cpp`      | Evolução com campo elétrico aplicado. |
| `evolve_quench.cpp`        | Evolução simulando quench térmico. |
| `anchoring.cpp`            | Ancoramento superficial genérico. |
| `anchoring_fg.cpp`         | Ancoramento do tipo “fixed grid”. |
| `anchoring_rp.cpp`         | Ancoramento randômico-planar. |
| `anchoring_homeotropic.cpp`| Ancoramento homeotrópico (perpendicular à superfície). |
| `anchoring_strong.cpp`     | Ancoramento forte e rígido. |

---

## 🛠️ Tecnologias Utilizadas

- **C++** moderno
- (Futuramente: **CUDA** para simulação paralela em GPU)
- Organização modular do código
- Possibilidade de expansão para visualização 3D

---


## 📚 Referências

- Tese de Doutorado – Eric Koudhi Omori (2018)
- Dissertação de Mestrado – Eric Koudhi Omori (2016)
- Landau & Binder – *A Guide to Monte Carlo Simulations in Statistical Physics*

---

## 📌 Futuras Etapas

- Implementação de CUDA para paralelismo em GPU
- Visualização 3D das direções moleculares (ordem nemática)
- Estudo de propriedades óticas e defeitos topológicos
- Escrita de artigo científico com base nos resultados

---

**Desenvolvido com ciência, código e propósito.**
