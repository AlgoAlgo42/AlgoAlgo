typedef struct data {
    char    **grid;
    int     rowSize;
    int     colSize;
}   data_t;

typedef struct mark mark_t;
struct mark {
    void (*up)(data_t *, mark_t *, int, int);
    void (*down)(data_t *, mark_t *, int, int);
    void (*right)(data_t *, mark_t *, int, int);
    void (*left)(data_t *, mark_t *, int, int);
};

static void    markIslandsDown(data_t *data, mark_t *mark, int i, int j);
static void    markIslandsUp(data_t *data, mark_t *mark, int i, int j);
static void    markIslandsRight(data_t *data, mark_t *mark, int i, int j);
static void    markIslandsLeft(data_t *data, mark_t *mark, int i, int j);

int numIslands(char** grid, int gridSize, int* gridColSize) {
    data_t  data = {.grid = grid, .rowSize = gridSize, .colSize = *gridColSize};
    mark_t  mark = {.up = markIslandsUp, .down = markIslandsDown, \
        .right = markIslandsRight, .left = markIslandsLeft};
    int     count = 0;

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            if (grid[i][j] == '1') {
                grid[i][j] == '0';
                ++count;
                mark.right(&data, &mark, i, j);
                mark.down(&data, &mark, i, j);
            }
        }
    }
    return (count);
}

static void    markIslandsDown(data_t *data, mark_t *mark, int i, int j)
{
    while (++i < data->rowSize && (data->grid)[i][j] == '1') {
        data->grid[i][j] = '0';
        mark->right(data, mark, i, j);
        mark->left(data, mark, i, j);
    }
}

static void    markIslandsUp(data_t *data, mark_t *mark, int i, int j)
{
    while (--i >= 0 && data->grid[i][j] == '1') {
        data->grid[i][j] = '0';
        mark->right(data, mark, i, j);
        mark->left(data, mark, i, j);
    }
}

static void    markIslandsRight(data_t *data, mark_t *mark, int i, int j)
{
    while (++j < data->colSize && data->grid[i][j] == '1') {
        data->grid[i][j] = '0';
        mark->down(data, mark, i, j);
        mark->up(data, mark, i, j);
    }
}

static void    markIslandsLeft(data_t *data, mark_t *mark, int i, int j)
{
    while (--j >= 0 && data->grid[i][j] == '1') {
        data->grid[i][j] = '0';
        mark->down(data, mark, i, j);
        mark->up(data, mark, i, j);
    }
}
