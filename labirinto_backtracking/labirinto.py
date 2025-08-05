

### Código Completo e Personalizado (Pygame)

import pygame
import sys
import time

# --- Configurações Iniciais ---
# Dimensões da tela e do labirinto
TELA_LARGURA = 800
TELA_ALTURA = 600
TAMANHO_CELULA = 30
FPS = 20  # Velocidade da animação: 20 FPS

# Cores personalizadas
PRETO = (0, 0, 0)
COR_FUNDO = (25, 25, 25)          # Fundo escuro
COR_PAREDE = (80, 80, 80)         # Paredes em cinza escuro
COR_CAMINHO_LIVRE = (40, 40, 40)  # Caminho em cinza mais claro
COR_INICIO = (0, 200, 50)         # Início em verde vibrante
COR_TESOURO = (255, 200, 0)       # Tesouro em dourado
COR_EXPLORANDO = (0, 100, 255)    # Posição atual em azul
COR_FALHOU = (200, 50, 50)        # Caminhos explorados (sem sucesso) em vermelho
COR_SOLUCAO = (0, 255, 100)       # Caminho da solução em verde neon

# --- Definição do Labirinto ---
# 0: Caminho livre, 1: Parede, 2: Tesouro, 3: Início
labirinto_modelo = [
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 3, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1],
    [1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1],
    [1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1],
    [1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1],
    [1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1],
    [1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1],
    [1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1],
    [1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1],
    [1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
    [1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1],
    [1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1],
    [1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1],
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
]

# --- Inicialização do Pygame ---
pygame.init()
tela = pygame.display.set_mode((TELA_LARGURA, TELA_ALTURA))
pygame.display.set_caption("Labirinto com Backtracking")
relogio = pygame.time.Clock()

def desenhar_labirinto(labirinto, visitados, pilha, caminho_final=None):
    """Função para desenhar o labirinto na tela."""
    tela.fill(COR_FUNDO)
    
    # Offsets para centralizar o labirinto
    offset_x = (TELA_LARGURA - len(labirinto[0]) * TAMANHO_CELULA) // 2
    offset_y = (TELA_ALTURA - len(labirinto) * TAMANHO_CELULA) // 2

    for r in range(len(labirinto)):
        for c in range(len(labirinto[0])):
            x = c * TAMANHO_CELULA + offset_x
            y = r * TAMANHO_CELULA + offset_y
            celula = pygame.Rect(x, y, TAMANHO_CELULA, TAMANHO_CELULA)
            
            cor = COR_CAMINHO_LIVRE
            if labirinto[r][c] == 1:
                cor = COR_PAREDE
            elif labirinto[r][c] == 2:
                cor = COR_TESOURO
            elif labirinto[r][c] == 3:
                cor = COR_INICIO

            if (r, c) in visitados and labirinto[r][c] not in [2, 3]:
                cor = COR_FALHOU
            
            if (r, c) in pilha:
                cor = COR_EXPLORANDO
                
            if caminho_final and (r, c) in caminho_final:
                cor = COR_SOLUCAO

            pygame.draw.rect(tela, cor, celula)
            pygame.draw.rect(tela, PRETO, celula, 1) # Borda

    pygame.display.flip()

def encontrar_posicao_inicial(labirinto):
    """Localiza a posição inicial (3) no labirinto."""
    for r in range(len(labirinto)):
        for c in range(len(labirinto[0])):
            if labirinto[r][c] == 3:
                return (r, c)
    return None

def resolver_labirinto_backtracking(labirinto):
    """Resolve o labirinto com backtracking e exibe a animação."""
    inicio = encontrar_posicao_inicial(labirinto)
    if not inicio:
        print("Posição inicial não encontrada!")
        return None

    pilha = [inicio]
    visitados = set([inicio])
    caminho_solucao = {inicio: None} # Dicionário para reconstruir o caminho
    
    tesouro_encontrado = False

    while pilha and not tesouro_encontrado:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        posicao_atual = pilha[-1] # Pega o topo sem remover para a visualização
        
        desenhar_labirinto(labirinto, visitados, pilha)
        relogio.tick(FPS)
        
        posicao_atual = pilha.pop()
        r, c = posicao_atual
        
        if labirinto[r][c] == 2:
            tesouro_encontrado = True
            break
        
        # Explora os vizinhos (cima, baixo, esquerda, direita)
        direcoes = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        for dr, dc in direcoes:
            nova_r, nova_c = r + dr, c + dc
            nova_posicao = (nova_r, nova_c)
            
            if 0 <= nova_r < len(labirinto) and \
               0 <= nova_c < len(labirinto[0]) and \
               labirinto[nova_r][nova_c] != 1 and \
               nova_posicao not in visitados:
                
                pilha.append(nova_posicao)
                visitados.add(nova_posicao)
                caminho_solucao[nova_posicao] = posicao_atual

    if tesouro_encontrado:
        print("Tesouro encontrado!")
        
        caminho_final = []
        pos = (r, c)
        while pos in caminho_solucao and caminho_solucao[pos] is not None:
            caminho_final.append(pos)
            pos = caminho_solucao[pos]
        caminho_final.append(inicio)
        caminho_final.reverse()

        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
            desenhar_labirinto(labirinto, visitados, [], caminho_final)
    else:
        print("Caminho não encontrado.")
        
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
            desenhar_labirinto(labirinto, visitados, [])

if __name__ == "__main__":
    resolver_labirinto_backtracking(labirinto_modelo)