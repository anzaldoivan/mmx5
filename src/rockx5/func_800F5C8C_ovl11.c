#include "types.h"

typedef struct Scr5C8C {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 pad3[7];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[0xFA - 0x10];
    /* 0xFA */ u8 unkFA;
} Scr5C8C;

extern Scr5C8C D_8009A0A0;
extern s16 D_800FA05A_ovl11;
extern Row5C8C D_8009A1F8[];

extern void func_800171E8(Obj5C8C*, s32);
extern void func_80017248(Obj5C8C*);
extern s32 func_80016490(s32, s32, void*);

s32 func_800F5C8C_ovl11(Obj5C8C* obj) {
    s32 ret;

    obj->unk60 = 8;
    if (D_8009A0A0.unk2 == 0 && D_8009A0A0.unkFA == 0) {
        obj->unk62 = 8;
    } else {
        obj->unk62 = 6;
    }
    func_800171E8(obj, 7);
    if (obj->unkA > D_800FA05A_ovl11) {
        obj->unk15 = 0;
        obj->unk20 = 0xFFFA0000;
        obj->unkA = (obj->unk14 + D_8009A1F8)->unkA + 0x180;
        obj->unkE = D_8009A0A0.unkE - (obj->unkA - D_8009A0A0.unkA);
    } else {
        obj->unk15 = 0x40;
        obj->unk20 = 0x60000;
        obj->unkA = (obj->unk14 + D_8009A1F8)->unkA - 0x40;
        obj->unkE = D_8009A0A0.unkE - (D_8009A0A0.unkA - obj->unkA);
    }
    obj->unk24 = 0xFFFA0000;
    func_80017248(obj);
    ret = func_80016490(2, 0x32, obj);
    obj->unk6++;
    return ret;
}
