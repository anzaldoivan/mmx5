#include "types.h"

typedef struct Obj3700 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x10];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
} Obj3700;

extern void func_800171E8(Obj3700*, s32);
extern s32 func_80068058(s32, s32);
extern s32 func_80067EF8(s32);
extern s32 func_80067E28(s32);
extern void func_80017248(Obj3700*);
extern void func_8002DED4(Obj3700*);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern s16 D_800FA248_ovl03;

void func_800F3700_ovl03(Obj3700* obj) {
    s16 x;
    s16 a;
    s32 e;

    func_800171E8(obj, 1);
    if (obj->unkA < D_800FA248_ovl03) {
        x = D_800FA240_ovl03 - 1;
    } else {
        x = D_800FA242_ovl03 + 1;
    }
    e = obj->unkE + 1;
    a = func_80068058(D_800FA244_ovl03 - e, x - obj->unkA);
    obj->unk20 = func_80067EF8(a) * 48;
    obj->unk24 = -func_80067E28(a) * 48;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk6++;
    func_80017248(obj);
    func_8002DED4(obj);
}
