#include "types.h"

typedef struct Scr5F70 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 pad3[0xB];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[0xFA - 0x10];
    /* 0xFA */ u8 unkFA;
} Scr5F70;

extern Scr5F70 D_8009A0A0;
extern s16 D_800FA05A_ovl11;
extern Row5C8C D_8009A1F8[];

extern void func_800171E8(Obj5C8C*, s32);
extern void func_80017248(Obj5C8C*);
extern s32 func_80016490(s32, s32, void*);

extern s32 func_8002DF78(void);

void func_800F5F70_ovl11(Obj5C8C* obj) {
    s32 r;
    Scr5F70* s;

    obj->unk60 = 8;
    if (D_8009A0A0.unk2 == 0 && D_8009A0A0.unkFA == 0) {
        obj->unk62 = 8;
    } else {
        obj->unk62 = 6;
    }
    func_800171E8(obj, 3);
    if (obj->unkA > D_800FA05A_ovl11) {
        obj->unk15 = 0;
        obj->unk20 = 0xFFFA0000;
        obj->unkA = (obj->unk14 + D_8009A1F8)->unkA + 0x180;
    } else {
        obj->unk15 = 0x40;
        obj->unk20 = 0x60000;
        obj->unkA = (obj->unk14 + D_8009A1F8)->unkA - 0x40;
    }
    obj->unk24 = 0;
    r = func_8002DF78();
    s = &D_8009A0A0;
    r = (r & 0x3F) - 0x20;
    obj->unkE = s->unkE + r;
    func_80017248(obj);
    func_80016490(2, 0x32, obj);
    obj->unk6++;
}
