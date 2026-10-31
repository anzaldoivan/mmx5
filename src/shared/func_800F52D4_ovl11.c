/* Shared body (DK-5), from the banked draft of func_800F52D4_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern u8 D_80074EE0[];
extern u8 D_80075F20[];
extern u8 D_8009A0A0[];
extern u8 D_800F9D14_ovl11[];
extern u8 D_800F9D20_ovl11[];
extern void* D_800F9F28_ovl11[];

void DEDUP_NAME(u8* arg0) {
    s32 r;
    u8 t;

    if (D_8009A0A0[0xF7] == 0) {
        ((void (*)(u8*))D_800F9F28_ovl11[((s8*)arg0)[5]])(arg0);
    }
    if (D_1F80004C.bytes[0x8B] != 0) {
        if (arg0[0x47] == 0xB) {
            ((u8**)arg0)[0x14] = D_800F9D20_ovl11;
        } else {
            ((u8**)arg0)[0x14] = D_800F9D14_ovl11;
        }
        if (((s8*)arg0)[3] != 0) {
            func_800317B8(arg0);
        }
        D_1F80004C.bytes[0x8D] = arg0[0x5C];
        r = func_80031DD0(arg0);
        if (r < 0) {
            D_8009A0A0[0x7A] = 1;
            arg0[4] = 2;
            arg0[5] = 0;
            return;
        }
        if (r > 0 && r != 0x7F) {
            ((u8**)arg0)[0x16] = D_80074EE0;
            if ((u32)(r - 0x19) < 2) {
                D_1F80004C.bytes[0x8A] = 2;
            } else {
                D_1F80004C.bytes[0x8A] = 0x1E;
            }
        }
        t = D_1F80004C.bytes[0x8A];
        if (t != 0) {
            D_1F80004C.bytes[0x8A] = t + 0xFF;
            if (t & 2) {
                ((u16*)arg0)[0x21] = ((u16*)arg0)[0x21] | 0x8000;
            } else {
                ((u16*)arg0)[0x21] = ((u16*)arg0)[0x21] & 0x7FFF;
            }
            if (D_1F80004C.bytes[0x8A] == 0) {
                ((u8**)arg0)[0x16] = D_80075F20;
                ((u16*)arg0)[0x21] = ((u16*)arg0)[0x21] & 0x7FFF;
            }
        }
    }
    if (((s8*)arg0)[3] != 0) {
        func_8002D9EC(arg0, 0x60, 0x60);
        arg0[3] = 1;
    }
}
