#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1C44;
extern u8 D_800F976C_ovl11[];
extern u8 D_800F9854_ovl11[];

void func_800F0F78_ovl11(u8* arg0) {
    u8* o;

    o = func_8002D1A4();
    if (o != 0) {
        o[0] = 0x41;
        o[1] = 0x1E;
        if (*(s8*)(arg0 + 2) == 2) {
            o[2] = D_800F976C_ovl11[*(s32*)(arg0 + 0x84)];
        } else {
            o[2] = (u8)D_800D1C44 ^ (arg0[0x84] & 1);
        }
        if (*(s32*)(arg0 + 0x84) == 3 && D_800D1C44 == 0) {
            o[2]++;
        }
        *(u8**)(o + 0x7C) = arg0;
        *(u16*)(o + 0x42) = *(u16*)(arg0 + 0x42);
        *(u8**)(o + 0x30) = D_800F9854_ovl11;
        *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
        o[0x15] = arg0[0x15];
        o[0x14] = arg0[0x14];
        o[0x16] = 4;
    }
}

extern u8 D_800F9854_ovl11[];

void func_800F1074_ovl11(u8* arg0) {
    u8* p;
    u8 i;

    for (i = 0; i < 2; i++) {
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x1D;
            p[2] = i;
            *(u8**)(p + 0x7C) = arg0;
            *(s16*)(p + 0x42) = *(s16*)(arg0 + 0x42);
            *(u8**)(p + 0x30) = D_800F9854_ovl11;
            *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
            *(s16*)(p + 0x40) = *(s16*)(arg0 + 0x40);
            p[0x15] = arg0[0x15];
            p[0x14] = arg0[0x14];
            p[0x16] = 4;
        }
    }
}

extern u8 D_800F9854_ovl11[];

void func_800F1148_ovl11(Obj1148* arg0) {
    Obj1148* obj;
    u8 i;

    for (i = 0; i < 2; i++) {
        obj = func_8002D1A4();
        if (obj != 0) {
            obj->unk0 = 0x41;
            obj->unk1 = 0x1E;
            if (i == 0) {
                obj->unk2 = 0;
            } else {
                obj->unk2 = 2;
            }
            obj->unk7C = arg0;
            obj->unk42 = arg0->unk42;
            obj->unk30 = D_800F9854_ovl11;
            obj->unk3C = arg0->unk3C;
            obj->unk40 = arg0->unk40;
            obj->unk15 = arg0->unk15;
            obj->unk14 = arg0->unk14;
            obj->unk16 = 4;
        }
    }
}
