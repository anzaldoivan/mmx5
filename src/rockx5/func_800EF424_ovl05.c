#include "types.h"

typedef struct ObjF424 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 state;
    /* 0x05 */ u8 pad5[0x70 - 5];
    /* 0x70 */ u8 unk70;
    /* 0x71 */ u8 pad71[0x84 - 0x71];
    /* 0x84 */ s32 unk84;
} ObjF424;

s32 func_8002F8FC(ObjF424* a0);
extern void (*D_800F5008_ovl05[])(ObjF424*);

void func_800EF424_ovl05(ObjF424* o) {
    if (o->unk84 == 0 && o->unk70 == 0) {
        func_8002F8FC(o);
    }
    D_800F5008_ovl05[o->state](o);
}
