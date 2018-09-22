/*
 *2018-9-21
 *赵翘楚
 * */
#include <stdio.h>
#include <stdlib.h>
#define DEBUG

int decide(int** map, int* pos)
{
    int l = 1, r = 1, u = 1, d = 1;
    l = (map[pos[0]][pos[1] - 1] == (int)'#');
    r = (map[pos[0]][pos[1] + 1] == (int)'#');
    u = (map[pos[0] - 1][pos[1]] == (int)'#');
    d = (map[pos[0] + 1][pos[1]] == (int)'#');
    int n = 0;
    n = 8 * l + 4 * r + 2 * u + d;
    return n;
}

void move(int** map, int* pos, char direction)
{
    int canMove = 1;
    int posTo[2];
    posTo[0] = pos[0];
    posTo[1] = pos[1];
    while (canMove) {
        switch (direction) {
        case 'l':
            posTo[1]--;
        case 'r':
            posTo[1]++;
        case 'u':
            posTo[0]--;
        case 'd':
            posTo[0]++;
        }
        if (map[posTo[0]][posTo[1]] == (int)'#')
            canMove = 0;
        else {
            pos[0] = posTo[0];
            pos[1] = posTo[1];
        }
    }
}

int tryIt(int** map, int* s, int* e, int steps)
{
    if (s[0] == e[0] && s[1] == e[1]) {
        return steps;
    }
    int steps_min = 0;
    int pos[2];
    pos[0] = s[0];
    pos[1] = s[1];
    int direction_available = 0;
    direction_available = decide(map, pos);
    if (8 & direction_available) {
        move(map, pos, 'l');
        tryIt(map, pos, e, ++steps);
    }
    if (4 & direction_available) {
        move(map, pos, 'r');
        tryIt(map, pos, e, ++steps);
    }
    if (2 & direction_available) {
        move(map, pos, 'u');
        tryIt(map, pos, e, ++steps);
    }
    if (1 & direction_available) {
        move(map, pos, 'd');
        tryIt(map, pos, e, ++steps);
    }
    return steps_min;
}

int main()
{
    int i, j;
    int n = 0, m = 0;
    scanf("%d%d\n", &n, &m);
    int** map;
    int s[2], e[2];
    map = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < m; i++) {
        map[i] = (int*)malloc(m * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((map[i][j] = (int)getchar()) == 'S') {
                s[0] = i;
                s[1] = j;
            } else if (map[i][j] == 'E') {
                e[0] = i;
                e[1] = j;
            }
        }
        getchar();
    }

#ifdef DEBUG
    printf("***---DEBUG---***\n");
    printf("%d %d\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("START=(%d,%d)\n", s[0], s[1]);
    printf("END  =(%d,%d)\n", e[0], e[1]);
#endif

    for (i = 0; i < m; i++) {
        free(map[i]);
    }
    free(map);
    return 0;
}
