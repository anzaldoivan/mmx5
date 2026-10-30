/* Shared body (DK-5), from the banked draft of func_800F8CE8_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_8002DF54(u8* a0);
extern s32 func_8002FB58(u8* obj);
extern void func_80017248(u8* obj);
extern void func_800FAF38_ovl06(u8*, s32, s32, s32);
extern void func_8001296C(s32);
extern void func_8002A600(s32, s32, s32);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80028B18(s32, s16, s16, void*);
extern signed char D_800D1C0C;
extern u8 D_800FF500_ovl06[];
extern u8 D_800FF510_ovl06[];
extern u8 D_800FF520_ovl06[];
extern u8 D_800FF530_ovl06[];
extern u8 D_8009A244;
extern u16 D_800FF94C_ovl06;
extern u16 D_800FF94E_ovl06;

void DEDUP_NAME(u8* o) {
    func_8002DF54(o);
    func_8002FB58(o);
    func_80017248(o);
    if (--*(s16*)(o + 0x7C) == 0) {
        func_800FAF38_ovl06(o, *(s16*)(o + 0xA), *(s16*)(o + 0xE),
                            (u8)(o[0x7E] + 0x10));
        *(s16*)(o + 0x7C) = 10;
        (*(s16*)(o + 0x7E))++;
    }
    if (o[0x15] == 0) {
        if (!(o[0x70] & 2)) {
            return;
        }
        func_8001296C(5);
        func_8002A600(0x28, 4, 2);
        o[0x9A] = 0;
        func_800171E8(o, 0x1E);
        if (D_800D1C0C != 12) {
            func_80028B18(0, 0x11B0, 0x10, D_800FF500_ovl06);
        } else {
            func_80028B18(0, (s16)(D_800FF94C_ovl06 + 0x11B0),
                          (s16)(D_800FF94E_ovl06 + 0x10), D_800FF520_ovl06);
        }
        D_8009A244 = 1;
        *(s16*)(o + 0x7C) = 0x28;
        D_1F80004C.bytes[0x8A] = 1;
        o[6]++;
    } else {
        if (!(o[0x70] & 1)) {
            return;
        }
        func_8001296C(5);
        func_8002A600(0x28, 4, 2);
        o[0x9A] = 0;
        func_800171E8(o, 0x1E);
        if (D_800D1C0C != 12) {
            func_80028B18(0, 0x1300, 0x10, D_800FF510_ovl06);
        } else {
            func_80028B18(0, (s16)(D_800FF94C_ovl06 + 0x1300),
                          (s16)(D_800FF94E_ovl06 + 0x10), D_800FF530_ovl06);
        }
        D_8009A244 = 1;
        *(s16*)(o + 0x7C) = 0x28;
        D_1F80004C.bytes[0x8A] = 1;
        o[6]++;
    }
}
