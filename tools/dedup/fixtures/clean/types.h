/* Synthetic fixture (not game-derived): two distinct shapes, one scalar typedef. */
typedef short s16;
typedef struct {
    s16 a;
    char pad[6];
    int b;
} Alpha;
struct Beta {
    char c;
    Alpha* next;
};
