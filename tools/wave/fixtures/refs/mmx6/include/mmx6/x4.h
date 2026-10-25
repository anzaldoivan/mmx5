/* Synthetic fixture (not mmx6 text): mmx6/x4.h, guarded blocks as x4port.py writes them. */
#ifndef MMX6_X4_H
#define MMX6_X4_H
#include "common.h"
#include "mmx6/psyq_api.h"
#ifndef SIX_OBJ
#define SIX_OBJ(o) ((struct X4_Obj*)(o))
#endif
#ifndef X4_D_Unused
#define X4_D_Unused
struct X4_Unused {
    s32 a;
};
#endif
#ifndef X4_D_Obj
#define X4_D_Obj
struct X4_Obj {
    s8 active;
    s8 state;
    char tag[2];
    X4_RECT box;
    struct X4_Unused* link;
    s16 y;
    s32 z;
};
#endif
#ifndef X4_D_Uni
#define X4_D_Uni
struct X4_Uni {
    union {
        s32 w;
        s16 h[2];
    } u;
};
#endif
#ifndef X4_D_Shared
#define X4_D_Shared
typedef struct {
    s32 big;
} X4_Shared;
#endif
#endif /* MMX6_X4_H */
