#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_800FAF38_ovl06(u8*, s32, s32, s32);
extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);
extern signed char D_800D1C0C;
extern u8 D_800FF500_ovl06[];
extern u8 D_800FF510_ovl06[];
extern u8 D_800FF520_ovl06[];
extern u8 D_800FF530_ovl06[];
extern u8 D_8009A244;

void func_800F8CE8_ovl06(u8* o) {
    move_object(o);
    func_8002FB58(o);
    animate_object(o);
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
        start_pad_vibration(5);
        func_8002A600(0x28, 4, 2);
        o[0x9A] = 0;
        set_animation(o, 0x1E);
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
        start_pad_vibration(5);
        func_8002A600(0x28, 4, 2);
        o[0x9A] = 0;
        set_animation(o, 0x1E);
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

extern u8 D_8009A244;
extern s8 D_800D1C0C;
extern u8 D_800FF508_ovl06[];
extern u8 D_800FF518_ovl06[];
extern u8 D_800FF528_ovl06[];
extern u8 D_800FF538_ovl06[];

void func_800F8ED4_ovl06(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 2);
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        if (obj[0x15] == 0) {
            if (D_800D1C0C != 0xC) {
                ((void (*)(s32, s16, s16, void*))func_80028B18)(
                    0, 0x11B0, 0x10, D_800FF508_ovl06);
            } else {
                ((void (*)(s32, s16, s16, void*))func_80028B18)(
                    0, D_800FF94C_ovl06 + 0x11B0, D_800FF94E_ovl06 + 0x10,
                    D_800FF528_ovl06);
            }
        } else if (D_800D1C0C != 0xC) {
            ((void (*)(s32, s16, s16, void*))func_80028B18)(0, 0x1300, 0x10,
                                                            D_800FF518_ovl06);
        } else {
            ((void (*)(s32, s16, s16, void*))func_80028B18)(
                0, D_800FF94C_ovl06 + 0x1300, D_800FF94E_ovl06 + 0x10,
                D_800FF538_ovl06);
        }
        D_8009A244 = 1;
        obj[6]++;
    }
}
