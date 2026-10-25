/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80047E34.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "addr.h"
#define M2C_UNK s32

M2C_UNK func_800171E8(void*, M2C_UNK);
M2C_UNK func_8002D9EC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002DF54(void*);
void func_8002E058(void*, s32);
extern u32* D_8007B2E8[];
extern s8 D_8007B4E8[];
extern X4_Obj D_8009A0A0;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define FP(p, o) (*(void**)((u8*)(p) + (o)))

void func_8004DB18(u8* arg0) {
    s32 vx;
    s32 vy;
    s32 anim;
    s8* tbl;
    u8* sp;
    s32 off;
    X4_Obj* pl = &D_8009A0A0;

    F8(arg0, 3) = 1;
    U8(arg0, 0x14) = U8(pl, 0x14);
    F32(arg0, 0x38) = 0;
    sp = D_1F80001C.bytes;
    off = *(s32*)(sp + 4);
    FP(arg0, 0x30) = D_8007B2E8;
    F16(arg0, 0x40) = 0;
    F16(arg0, 0x42) = 0x7802;
    F8(arg0, 0x16) = 0x10;
    F8(arg0, 0x15) = 0;
    FP(arg0, 0x3C) = sp + off;
    F32(arg0, 8) = F32(pl, 8);
    F32(arg0, 0xC) = F32(pl, 0xC);
    func_8002E058(arg0, U8(arg0, 2) & 0x7F);
    vx = F32(arg0, 0x20);
    vy = F32(arg0, 0x24);
    anim = 7;
    if (F8(arg0, 2) & 0x80) {
        F32(arg0, 0x20) = vx * 8;
        F32(arg0, 0x24) = vy * 8;
    } else {
        s32 h;
        s32 m;
        h = vx / 2;
        m = D_8007B4E8[U8(arg0, 2) & 3];
        F32(arg0, 0x20) = vx + h * m;
        anim = 6;
        F32(arg0, 0x24) = vy + (vy / 2) * D_8007B4E8[U8(arg0, 2) & 3];
    }
    func_800171E8(arg0, anim);
    func_8002DF54(arg0);
    U8(arg0, 4) = U8(arg0, 4) + 1;
    func_8002D9EC(arg0, 0x80000, 0x80000);
}
