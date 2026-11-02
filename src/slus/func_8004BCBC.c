#include "types.h"
#include "addr.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002D6FC(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DF54(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern void func_80044F78(void* arg0);
extern s32 D_80077240[];
extern u8 D_80077254[];
extern u8 D_8007B3D8[];
extern u8 D_8009A0A0[];

void func_8004BCBC(u8* arg0) {
    u8* g = D_8009A0A0;
    u8* s;
    s32 v;
    s32 e;
    s32 h;
    s32 t;
    s8 st;

    st = FX(arg0, s8, 0x4);
    if (st == 0) {
        FX(arg0, u8, 0x3) = 1;
        FX(arg0, s32*, 0x68) = D_80077240;
        FX(arg0, u8*, 0x50) = D_80077254;
        s = D_1F80001C.bytes;
        FX(arg0, u8*, 0x3C) = s + FX(s, s32, 0x4);
        FX(arg0, u8*, 0x30) = D_8007B3D8;
        FX(arg0, s16, 0x40) = 0;
        FX(arg0, s16, 0x42) = 0x7802;
        FX(arg0, u8, 0x16) = 1;
        if (FX(arg0, u8, 0x15) == 0) {
            FX(arg0, s16, 0xA) = FX(g, s16, 0xA) - 0x14;
            if (FX(g, s32, 0xFC) & 0x200) {
                FX(arg0, s32, 0x20) = 0xFFF34000;
            } else {
                FX(arg0, s32, 0x20) = 0xFFF74000;
            }
        } else {
            FX(arg0, s16, 0xA) = FX(g, s16, 0xA) + 0x14;
            v = 0x80000;
            if (FX(g, s32, 0xFC) & 0x200) {
                v = 0xC0000;
            }
            FX(arg0, s32, 0x20) = v | 0xC000;
        }
        FX(arg0, s16, 0xE) = FX(g, s16, 0xE) - 0xA;
        FX(arg0, s32, 0x24) = 0;
        func_800171E8(arg0, 1);
        FX(arg0, s32, 0x84) = FX(arg0, s16, 0xA);
        FX(arg0, u8, 0x4)++;
    } else if (st == 1) {
        if (func_8002D938(arg0, 0x10, 0x10) != 0 || FX(arg0, s8, 0x98) != 0) {
            func_8002D6FC(arg0);
            return;
        }
        FX(arg0, s32*, 0x68) = &D_80077240[FX(arg0, u8, 0x45) & 0x7F];
        if (FX(arg0, u8, 0x70) != 0 ||
            (func_8002F8FC(arg0), FX(arg0, u8, 0x70) != 0)) {
            func_80044F78(arg0);
            func_8002D6FC(arg0);
            return;
        }
        func_80017248(arg0);
        t = FX(arg0, u8, 0x45);
        FX(arg0, s32*, 0x68) = &D_80077240[t & 0x7F];
        if (t & 0x80) {
            func_8002DF54(arg0);
        } else if (FX(g, s8, 0x5) == 0x11) {
            func_8002D6FC(arg0);
            return;
        }
        h = FX(arg0, s16, 0xA);
        e = FX(arg0, s32, 0x84);
        if (((e - h) < 0 ? (h - e) : (e - h)) >= 0xA0) {
            FX(arg0, u8, 0x4)++;
            func_800171E8(arg0, 0xC);
            FX(arg0, s32, 0x68) = 0;
            FX(arg0, s32, 0x50) = 0;
            return;
        }
    } else {
        func_80017248(arg0);
        if (func_8002D938(arg0, 0x10, 0x10) != 0 || FX(arg0, s8, 0x46) == 0) {
            func_8002D6FC(arg0);
            return;
        }
    }
    func_8002D9EC(arg0, 0x10, 0x10);
}
