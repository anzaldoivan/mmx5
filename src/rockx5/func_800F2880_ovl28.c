#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8002DF78(void);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_800F6ABC_ovl28(u8* a0);
extern u8 D_80074EE0[];
extern u8 D_800764C0[];
extern u8 D_8009A11A;
extern void* D_800FE1C4_ovl28[];

void func_800F2880_ovl28(u8* arg0) {
    s32 r;
    u8 v;
    u8* p;

    ((void (*)(u8*))D_800FE1C4_ovl28[(s8)arg0[5]])(arg0);
    if (D_1F80004C.bytes[0x87] != 0) {
        if (((s8*)arg0)[7] == 0) {
            func_800F6ABC_ovl28(arg0);
            arg0[7] = 1;
        }
        func_800317B8(arg0);
        r = func_80031DD0(arg0);
        if (r < 0) {
            D_8009A11A = 1;
            arg0[4] = 2;
            arg0[5] = 0;
            return;
        }
        if (r > 0) {
            switch (func_8002DF78() & 1) {
            case 0:
                func_80016490(2, 0x79, arg0);
                break;
            case 1:
                func_80016490(2, 0x7A, arg0);
                break;
            }
            if (r != 0x7F) {
                *(u8**)(arg0 + 0x58) = D_80074EE0;
                if ((u32)(r - 0x19) < 2) {
                    D_1F80004C.bytes[0x86] = 2;
                } else {
                    D_1F80004C.bytes[0x86] = 0x1E;
                }
            }
        }
        p = D_1F80004C.bytes;
        v = p[0x86];
        if (v != 0) {
            p[0x86] = v + 0xFF;
            if (v & 2) {
                *(u16*)(arg0 + 0x42) |= 0x8000;
            } else {
                *(u16*)(arg0 + 0x42) &= 0x7FFF;
            }
            if (D_1F80004C.bytes[0x86] == 0) {
                *(u8**)(arg0 + 0x58) = D_800764C0;
                *(u16*)(arg0 + 0x42) &= 0x7FFF;
            }
        }
    }
    func_8002D9EC(arg0, 0x60, 0x60);
}
