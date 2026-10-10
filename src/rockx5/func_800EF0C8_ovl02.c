#include "types.h"

// from rockx5 800EF0C8_ovl02
typedef struct Obj0C8 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 pad3[3];
    /* 0x06 */ signed char unk6;
    /* 0x07 */ u8 pad7[0x20 - 7];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x72 - 0x28];
    /* 0x72 */ u8 unk72;
    /* 0x73 */ u8 pad73[3];
    /* 0x76 */ signed char unk76;
    /* 0x77 */ u8 pad77[0x84 - 0x77];
    /* 0x84 */ u8 unk84;
    /* 0x85 */ u8 pad85[5];
    /* 0x8A */ u8 unk8A;
    /* 0x8B */ u8 unk8B;
} Obj0C8;

// from rockx5 800EF0C8_ovl02: D_8009A0A0 view
typedef struct Scr0C8 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0x24 - 0x10];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0xF3 - 0x28];
    /* 0xF3 */ signed char unkF3;
    /* 0xF4 */ u8 padF4[4];
    /* 0xF8 */ u8 unkF8;
    /* 0xF9 */ u8 padF9;
    /* 0xFA */ u8 unkFA;
} Scr0C8;

extern void func_80032F70(Obj0C8*);
extern void func_80033024(Obj0C8*);
extern void func_8002DED4(Obj0C8*);
extern void func_800171E8(Obj0C8*, s32);
extern void func_80017248(Obj0C8*);
extern void func_8002D9EC(Obj0C8*, s32, s32);
extern s32 func_8003240C(Obj0C8*);
extern s32 func_800326BC(Obj0C8*);
extern void func_8003258C(Obj0C8*);
extern Scr0C8 D_8009A0A0;
extern void (*D_800F44C0_ovl02[])(Obj0C8*);
extern signed char D_800D1C0C;

void func_800EF0C8_ovl02(Obj0C8* o) {
    s32 t;

    func_80032F70(o);
    func_80033024(o);
    if (D_8009A0A0.unkF3 == 0) {
        D_800F44C0_ovl02[o->unk6](o);
    } else if ((u8)(D_8009A0A0.unkFA - 2) >= 2) {
        D_800F44C0_ovl02[o->unk6](o);
    }
    if (o->unk84 == 0) {
        if (D_8009A0A0.unkF3 == 0 || (u8)(D_8009A0A0.unkFA - 2) >= 2) {
            func_8002DED4(o);
        }
    } else if (--o->unk84 == 0) {
        func_800171E8(o, o->unk8B);
    }
    func_80017248(o);
    func_8002D9EC(o, 0x30, 0x20);
    if (D_8009A0A0.unkF8 == 0) {
        func_8003240C(o);
        if (o->unk2 != 1 && o->unk76 != 0 && (o->unk72 & 3)) {
            t = D_8009A0A0.unkC;
            D_8009A0A0.unkC = t - D_8009A0A0.unk24;
            func_8003240C(o);
            if (o->unk76 == 0) {
                D_8009A0A0.unkC = D_8009A0A0.unkC - D_8009A0A0.unk24;
            } else {
                D_8009A0A0.unkC = t;
            }
        }
    }
    func_800326BC(o);
    if (D_800D1C0C != 4) {
        func_8003258C(o);
    }
    if (o->unk72 & 8) {
        if (o->unk8A == 0) {
            o->unk8A = 1;
            switch (o->unk2) {
            case 0:
                func_800171E8(o, 5);
                break;
            case 1:
                if (o->unk20 > 0) {
                    if (o->unk84 != 0) {
                        o->unk8B = 8;
                        func_800171E8(o, 5);
                    } else {
                        func_800171E8(o, 8);
                    }
                } else {
                    if (o->unk84 != 0) {
                        o->unk8B = 7;
                        func_800171E8(o, 5);
                    } else {
                        func_800171E8(o, 7);
                    }
                }
                break;
            case 2:
                if (o->unk24 > 0) {
                    if (o->unk84 != 0) {
                        o->unk8B = 5;
                        func_800171E8(o, 5);
                    } else {
                        func_800171E8(o, 5);
                    }
                } else {
                    if (o->unk84 != 0) {
                        o->unk8B = 6;
                        func_800171E8(o, 5);
                    } else {
                        func_800171E8(o, 6);
                    }
                }
                break;
            case 5:
                if (o->unk20 == 0) {
                    if (o->unk24 > 0) {
                        func_800171E8(o, 5);
                    } else {
                        func_800171E8(o, 6);
                    }
                }
                if (o->unk24 == 0) {
                    if (o->unk20 > 0) {
                        func_800171E8(o, 8);
                    } else {
                        func_800171E8(o, 7);
                    }
                }
                break;
            }
        }
    }
    if (!(o->unk72 & 8)) {
        if (o->unk8A != 0) {
            o->unk8A = 0;
            switch (o->unk2) {
            case 0:
                func_800171E8(o, 1);
                break;
            case 1:
                if (o->unk20 > 0) {
                    if (o->unk84 != 0) {
                        o->unk8B = 4;
                        func_800171E8(o, 1);
                    } else {
                        func_800171E8(o, 4);
                    }
                } else {
                    if (o->unk84 != 0) {
                        o->unk8B = 3;
                        func_800171E8(o, 1);
                    } else {
                        func_800171E8(o, 3);
                    }
                }
                break;
            case 2:
                if (o->unk24 > 0) {
                    if (o->unk84 != 0) {
                        o->unk8B = 1;
                        func_800171E8(o, 1);
                    } else {
                        func_800171E8(o, 1);
                    }
                } else {
                    if (o->unk84 != 0) {
                        o->unk8B = 2;
                        func_800171E8(o, 1);
                    } else {
                        func_800171E8(o, 2);
                    }
                }
                break;
            case 5:
                if (o->unk20 == 0) {
                    if (o->unk24 > 0) {
                        func_800171E8(o, 1);
                    } else {
                        func_800171E8(o, 2);
                    }
                }
                if (o->unk24 == 0) {
                    if (o->unk20 > 0) {
                        func_800171E8(o, 4);
                    } else {
                        func_800171E8(o, 3);
                    }
                }
                break;
            }
        }
    }
}
