import pygame

screen = pygame.display.set_mode((600, 600))

Grid_cor = [(i, j) for i in range(0, 600, 200) for j in range(0, 600, 200)]

Grid_cor_new = []

played = ['' for x in range(9)]
for i in range(3):
    Grid_cor_new.append(Grid_cor[i])
    Grid_cor_new.append(Grid_cor[i+3])
    Grid_cor_new.append(Grid_cor[i+6])
pygame.font.init()
font = pygame.font.SysFont('comicsans', 150)
size = 200
player = "X"
count = 0
radius = 80

def clicked(pos):
    global count, Grid_cor_new, player
    for i in Grid_cor_new:
        if pos[0] >= i[0] and pos[0] <= i[0] + size and pos[1] >= i[1] and pos[1] <= i[1] + size:
            if played[Grid_cor_new.index(i)] != "":
                return
            text = font.render(player, 1, white)
            screen.blit(text, (i[0] + 70, i[1] + 50))
            count += 1
            played[Grid_cor_new.index(i)] = player
            player = "O" if player == "X" else "X"
            return
white = (255, 255, 255)

def displayGrid():
    pygame.draw.line(screen, white, (200, 0), (200, 600), 1)
    pygame.draw.line(screen, white, (400, 0), (400, 600), 1)
    pygame.draw.line(screen, white, (0, 200), (600, 200), 1)
    pygame.draw.line(screen, white, (0, 400), (600, 400), 1)
    pygame.display.update()
def isTie():
    global count
    if count == 9:
        quit()
def isWin():
    global played, player
    checkRows = lambda a, b: a[0] == a[1] == a[2] == b or a[3] == a[4] == a[5] == b or a[6] == a[7] == a[8] == b
    checkCol = lambda a, b: a[0] == a[4] == a[6] == b or a[1] == a[4] == a[7] == b or a[2] == a[5] == a[8] == 7
    checkDia = lambda a, b: a[0] == a[4] == a[8] == b or a[2] == a[4] == a[6] == b
    if checkRows(played, player) or checkCol(played, player) or checkDia(played, player):
        return True

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            quit()
        pos = pygame.mouse.get_pos()
        if event.type == pygame.MOUSEBUTTONDOWN:
            clicked(pos)
            if isWin():
                quit()
            isTie()
    displayGrid()


