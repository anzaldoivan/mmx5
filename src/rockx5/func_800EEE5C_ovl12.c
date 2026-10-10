#include "types.h"

typedef struct ObjEE5C {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x15];
    /* 0x45 */ s8 unk45;
    /* 0x46 */ s8 unk46;
    /* 0x47 */ u8 pad47[0x29];
    /* 0x70 */ u8 unk70;
    /* 0x71 */ u8 pad71[0xB];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[8];
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
} ObjEE5C;

extern void func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern void func_800171E8(ObjEE5C*, s32);
extern void func_80017248(ObjEE5C*);
extern void func_8002DED4(ObjEE5C*);
extern s16 D_8009A0AA;
extern u8 D_800F1F94_ovl12[][6];

void func_800EEE5C_ovl12(ObjEE5C* obj) {
    if (obj->unk24 < 0) {
        if (obj->unk20 < 0) {
            obj->unk20 = -0x10000;
        } else {
            obj->unk20 = 0x10000;
        }
    }
    if (obj->unk45 == 3) {
        obj->unk45 = 0;
        if (obj->unk15 == 0) {
            obj->unk15 = 0x40;
        } else {
            obj->unk15 = 0;
        }
    }
    if (obj->unk70 & 8) {
        if (obj->unk24 != 0) {
            func_80016490(2, 0x42, obj);
        }
        obj->unk20 = 0;
        obj->unk24 = 0;
        obj->unk2C = 0;
    }
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
    func_80017248(obj);
    func_8002DED4(obj);
}
