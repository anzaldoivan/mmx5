#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80028B18(s32, s32, s32, void*);
extern u8* func_8002D0E4(void);
extern u32* D_80098118;
extern u8 D_800F75B0_ovl18[];
extern u8 D_800F75E8_ovl18[];
extern u8 D_800F75EC_ovl18[];
extern D1C00_800F6A94 D_800D1C00;
extern u8 D_8009A244;

void func_800EF0F0_ovl18(u8* obj) {
    s32* tbl;
    s32 a;
    s32 b;
    s32 i;
    s32 n;
    s32 v;
    u8* c;

    obj[0] = 0x41;
    obj[0x16] = 4;
    obj[0x15] = 0;
    *(u16*)(obj + 0x40) = D_80098118[func_8002B5B4(0x99)] >> 7;
    a = func_8002B5B4(0x99);
    tbl = D_1F800020.s32s;
    *(s32*)(obj + 0x3C) = (s32)tbl + tbl[a];
    a = func_8002B5B4(0x99);
    b = func_8002B5B4(0x99);
    *(u16*)(obj + 0x42) = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    *(u8**)(obj + 0x30) = D_800F75B0_ovl18;
    *(u8**)(obj + 0x68) = D_800F75E8_ovl18;
    obj[0x75] = 0;
    if (obj[2] & 0x10) {
        for (i = 8, n = 0; i < 16; i++) {
            if (D_800D1C00.f26[i] != 0) {
                n++;
            }
        }
        if (n >= 8) {
            obj[4] = 1;
            obj[5] = 0;
            obj[2] = obj[2] & 0xF;
            func_800171E8(obj, 9);
            func_80028B18(0, 0xD30, 0x5D0, D_800F75EC_ovl18);
            D_8009A244 = 1;
            c = func_8002D0E4();
            if (c != 0) {
                c[0] = 0x41;
                c[1] = 0x18;
                c[2] = 0;
                c[0x16] = 3;
                c[0x15] = 0;
                c[0x14] = obj[0x14];
                *(u16*)(c + 0xA) = *(u16*)(obj + 0xA);
                *(u16*)(c + 0xE) = *(u16*)(obj + 0xE);
                *(u16*)(c + 0x42) = *(u16*)(obj + 0x42);
                *(u16*)(c + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(c + 0x3C) = *(s32*)(obj + 0x3C);
                *(s32*)(c + 0x30) = *(s32*)(obj + 0x30);
                *(u8**)(c + 0x50) = obj;
            }
            c = func_8002D0E4();
            if (c != 0) {
                c[0] = 0x41;
                c[1] = 0x18;
                c[2] = 2;
                c[0x16] = 1;
                c[0x15] = 0;
                c[0x14] = obj[0x14];
                *(u16*)(c + 0xA) = *(u16*)(obj + 0xA);
                *(u16*)(c + 0xE) = *(u16*)(obj + 0xE);
                *(u16*)(c + 0x42) = *(u16*)(obj + 0x42);
                *(u16*)(c + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(c + 0x3C) = *(s32*)(obj + 0x3C);
                *(s32*)(c + 0x30) = *(s32*)(obj + 0x30);
                *(u8**)(c + 0x50) = obj;
            }
        } else {
            obj[4] = 2;
        }
        return;
    }
    v = D_800D1C00.f26[(s8)obj[2] + 6];
    if (v != 1) {
        if (v < 2) {
            if (v == 0) {
                obj[2] = obj[2] & 0xF;
                obj[4] = 1;
                obj[5] = 0;
                func_800171E8(obj, 4);
                c = func_8002D0E4();
                if (c != 0) {
                    c[0] = 0x41;
                    c[1] = 0x18;
                    c[2] = 0;
                    c[0x16] = 3;
                    c[0x15] = 0;
                    c[0x14] = obj[0x14];
                    *(u16*)(c + 0xA) = *(u16*)(obj + 0xA);
                    *(u16*)(c + 0xE) = *(u16*)(obj + 0xE);
                    *(u16*)(c + 0x42) = *(u16*)(obj + 0x42);
                    *(u16*)(c + 0x40) = *(u16*)(obj + 0x40);
                    *(s32*)(c + 0x3C) = *(s32*)(obj + 0x3C);
                    *(s32*)(c + 0x30) = *(s32*)(obj + 0x30);
                    *(u8**)(c + 0x50) = obj;
                }
                c = func_8002D0E4();
                if (c != 0) {
                    c[0] = 0x41;
                    c[1] = 0x18;
                    c[2] = 2;
                    c[0x16] = 1;
                    c[0x15] = 0;
                    c[0x14] = obj[0x14];
                    *(u16*)(c + 0xA) = *(u16*)(obj + 0xA);
                    *(u16*)(c + 0xE) = *(u16*)(obj + 0xE);
                    *(u16*)(c + 0x42) = *(u16*)(obj + 0x42);
                    *(u16*)(c + 0x40) = *(u16*)(obj + 0x40);
                    *(s32*)(c + 0x3C) = *(s32*)(obj + 0x3C);
                    *(s32*)(c + 0x30) = *(s32*)(obj + 0x30);
                    *(u8**)(c + 0x50) = obj;
                }
                goto end; // !FAKE: goto kept for the matching branch layout
            }
        }
    } else {
        obj[2] = obj[2] & 0xF;
        obj[4] = 1;
        obj[5] = 1;
        func_800171E8(obj, 4);
        D_800D1C00.f26[((s8*)obj)[2] + 6] = 2;
        c = func_8002D0E4();
        if (c != 0) {
            c[0] = 0x41;
            c[1] = 0x18;
            c[2] = 1;
            c[0x16] = 3;
            c[0x15] = 0;
            c[0x14] = obj[0x14];
            *(u16*)(c + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(c + 0xE) = *(u16*)(obj + 0xE);
            *(u16*)(c + 0x42) = *(u16*)(obj + 0x42);
            *(u16*)(c + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(c + 0x3C) = *(s32*)(obj + 0x3C);
            *(s32*)(c + 0x30) = *(s32*)(obj + 0x30);
            *(u8**)(c + 0x50) = obj;
        }
        goto end; // !FAKE: goto kept for the matching branch layout
    }
    obj[4] = 1;
    obj[5] = 1;
    obj[2] = obj[2] & 0xF;
    func_800171E8(obj, 4);
end:
    obj[6] = 0;
    obj[7] = 0;
}
