/* Synthetic fixture: the X5 type layer port_text reads (names it must not re-emit). */
#ifndef TYPES_H
#define TYPES_H
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct {
    u8 pad[4];
} X4_Shared;
typedef struct {
    u8 pad0;
    s8 state;
    u8 pad2[0xE];
    s16 y_pos;
} X4_Thing;
#endif
