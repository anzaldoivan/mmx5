#include "types.h"

typedef struct Obj1884 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x58 - 0x7];
    /* 0x58 */ void* unk58;
} Obj1884;

extern void func_800171E8(Obj1884*, s32);
extern u8 D_80075340[];

void func_800F1884_ovl10(Obj1884* arg0) {
    func_800171E8(arg0, 1);
    arg0->unk58 = D_80075340;
    arg0->unk6++;
}
