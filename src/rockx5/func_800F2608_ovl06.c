#include "types.h"

extern s32 func_8002D800(u8* a0);
extern u8* func_8002D0E4(void);
extern void func_800EEF0C_ovl06(void* self);
extern void func_800EF074_ovl06(void* self);
extern void func_800EEB90_ovl06(void* self);
extern void func_800F23D8_ovl06(void* arg0);
extern s32 func_8002FB58(u8* obj);
extern int func_8002DAA0();
extern void func_8003CD08(u8* obj);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8004FD24(u8* a0);
extern void func_80016D54(s32, s32);
extern void func_8004FD90(u8*, s32, s32, s32);
extern void func_800F2500_ovl06(u8* o);
extern s8 D_8009A0A2;
extern s8 D_800D1C0F;
extern void* D_800FDEB4_ovl06[];
extern void* D_800FDEEC_ovl06[];
extern u8 D_8009A0A0[];
extern u8 D_800FDE7C_ovl06[];

void func_800F2608_ovl06(u8* o) {
    u8* p;
    u8* q;
    u8 f;

    o[3] = 0;
    if (func_8002D800(o) != 0) {
        return;
    }
    if (((s8*)o)[0x5C] < 0) {
        if (((s8*)o)[0x5C] == -0x80) {
            if (!(o[0x97] & 0x80)) {
                o[0x97] |= 0x80;
                o[0x92] = 0x1E;
                o[0x91] = 0x1E;
                o[0x8C] = 0;
            }
            o[0x5C] = 0x20;
        }
        *(s16*)(o + 0xA4) = 0x400;
        o[0x8C] = 0x79;
        p = func_8002D0E4();
        if (p != 0) {
            p[0] = o[0];
            p[1] = 0xC;
            p[2] = 8;
            *(s32*)(p + 0x8) = *(s32*)(o + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(o + 0xC);
            *(s32*)(p + 0x30) = *(s32*)(o + 0x30);
            *(s16*)(p + 0x40) = *(s16*)(o + 0x40);
            *(s32*)(p + 0x3C) = *(s32*)(o + 0x3C);
            *(u16*)(p + 0x42) = *(u16*)(o + 0x42) & 0x7FFF;
            p[0x16] = o[0x16];
            p[0x15] = o[0x15];
            *(u8**)(p + 0x50) = o;
        }
        o[0x93] = 1;
        o[0x85] = 1;
        o[0x97] |= 2;
    }
    if (o[0x8C] != 0) {
        o[0x8C]--;
        if (o[0x8C] == 0) {
            if (o[0x97] & 1) {
                (&D_8009A0A2)[1] = 1;
            }
        }
    }
    f = o[0x97];
    if ((f & 0x41) == 0x41 || (D_800D1C0F != 0 && (f & 0x40))) {
        o[0x97] = f ^ 1;
        o[5] = 0xB;
        o[6] = 0;
    }
    func_800EEF0C_ovl06(o);
    func_800EF074_ovl06(o);
    func_800EEB90_ovl06(o);
    if (o[0x8D] == 0) {
        if (((s8*)o)[2] == 0) {
            ((void (*)(u8*))D_800FDEB4_ovl06[((s8*)o)[5]])(o);
        } else {
            if (o[0x7E] != 0) {
                o[0x7E]--;
            }
            ((void (*)(u8*))D_800FDEEC_ovl06[((s8*)o)[5]])(o);
        }
        func_800F23D8_ovl06(o);
        func_8002FB58(o);
        if (o[0x97] & 0x40) {
            u8* pl = D_8009A0A0;
            *(s32*)(pl + 0x8) = *(s32*)(o + 0x8);
            *(s32*)(pl + 0xC) = *(s32*)(o + 0xC);
            pl[0x15] = o[0x15];
            if (o[0x97] & 0x40) {
                if (o[0x8C] != 0) {
                    if ((o[0x8C] & 3) == 0) {
                        *(u16*)(o + 0x42) |= 0x8000;
                    } else {
                        *(u16*)(o + 0x42) &= 0x7FFF;
                    }
                }
            }
        }
        if (o[0x97] & 0x80) {
            q = o + 0x88;
            *(u16*)(o + 0x42) &= 0x7FFF;
            q[10] = o[0x92] - 1;
            if (q[10] == 0) {
                *(u16*)(o + 0x42) |= 0x8000;
                o[0x92] = o[0x91];
                q[9] = o[0x91] - 1;
                if (q[9] == 0) {
                    o[0x8D] = 1;
                    *(u16*)(o + 0x42) &= 0x7FFF;
                }
            }
        }
        func_8002DAA0(o);
    }
    switch (o[0x8D]) {
    case 1:
        o[0x8D] = 2;
        o[0x8C] = 0xFF;
        D_8009A0A0[0xD5] = 0;
        o[0x97] ^= 0x40;
        func_8003CD08(D_8009A0A0);
        o[0x90] = 0x1E;
        o[0x97] |= 4;
        func_8004D4F4(7, D_800FDE7C_ovl06, o);
        break;
    case 2:
        o[0x90]--;
        if (((s8*)o)[0x90] == 0) {
            o[4] = 2;
            o[3] = 0;
            func_8004FD24(o);
            func_80016D54(5, 8);
        } else {
            func_8004FD90(o, 0, 0x1F, 0x1F);
        }
        break;
    default:
        if (o[0x8C] == 0) {
            o[0x85] = 0;
            *(u16*)(o + 0x42) &= 0x7FFF;
        }
        break;
    }
    func_800F2500_ovl06(o);
}
