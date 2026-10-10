#include "types.h"

typedef struct Obj001C {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x30];
    /* 0x46 */ s8 unk46;
    /* 0x47 */ u8 pad47[0x35];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[8];
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
} Obj001C;

extern void func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern void func_800171E8(Obj001C*, s32);
extern s16 D_8009A0AA;
extern u8 D_800F1F94_ovl12[][6];

void func_800F001C_ovl12(Obj001C* obj) {
    if (obj->unk46 == 0) {
        if ((func_8002DF78() & 3) == 0) {
            func_80016490(2, 0x3D, obj);
            func_800171E8(obj, 8);
            if (D_8009A0AA > obj->unkA) {
                obj->unk15 = 0x40;
            } else {
                obj->unk15 = 0;
            }
            obj->unk7C = 0;
            obj->unk6++;
        } else {
            func_800171E8(obj, 1);
            obj->unk5 = D_800F1F94_ovl12[obj->unk86][obj->unk87++];
            obj->unk6 = 0;
        }
    }
}
