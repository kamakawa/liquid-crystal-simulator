# 🧊 Simulador Monte Carlo 3D para Cristais Líquidos com Ancoramento Superficial

> Projeto de Iniciação Científica desenvolvido por **Eric Kamakawa** e **Iago Sitta**, sob orientação dos professores **Rafael Zola** e **Rodolfo Teixeira**, no curso de Engenharia da Computação da UTFPR – Apucarana.

---

## 🎯 Objetivo

Desenvolver e aprimorar um simulador computacional para sistemas de **cristais líquidos nemáticos** usando o **modelo de Lebwohl-Lasher** em **três dimensões**, baseado no **método de Monte Carlo com algoritmo de Metropolis**, incorporando diferentes condições de **ancoramento superficial** e simulações em diferentes regimes físicos.

---

## 🔬 Contexto Físico

Cristais líquidos nemáticos são materiais com orientações moleculares parcialmente ordenadas, importantes em diversas aplicações tecnológicas, como **telas LCD**, **sensores térmicos** e **materiais fotônicos**.

Para estudar seu comportamento coletivo, utiliza-se o modelo de **Lebwohl-Lasher**, que trata cada molécula como um vetor tridimensional sujeito a interações com vizinhos e a restrições de contorno (como ancoramentos em paredes).

---

## 🧮 Metodologia Computacional

- Algoritmo de **Monte Carlo com Metropolis**
- Evolução do sistema sob diferentes condições:
  - Temperatura constante
  - Campo elétrico externo
  - Quench térmico
- Simulações em **lattice 3D**
- Diversas condições de **ancoramento nas fronteiras**

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
