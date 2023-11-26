#    Any live cell with fewer than two live neighbours dies (referred to as underpopulation).
#    Any live cell with more than three live neighbours dies (referred to as overpopulation).
#    Any live cell with two or three live neighbours lives, unchanged, to the next generation.
#    Any dead cell with exactly three live neighbours comes to life.

# Globals
WIDTH = 10
HEIGHT = 10

def draw_grid() -> None:
    for i in range(HEIGHT + 1):
        for j in range(WIDTH + 1):
            if i == 0 or i == HEIGHT or j == 0 or j == WIDTH:
                print("#", end=" ")
            else:
                print(" ", end=" ")
        print()

draw_grid()