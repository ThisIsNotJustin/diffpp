typedef struct {
    int x;
    int y;
} Something;

int test1() {
    printf("Hello World!\n");
    Something s = {
        .x = 4,
        .y = 2
    };

    printf("Something x: %d, y: %d", s.x, s.y);

    return 0;
}