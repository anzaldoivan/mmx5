#include "types.h"
#include "mmx5/globals.h"

extern u8 D_8009A427;
extern u8 D_80070C54;

void func_8004E848(u8* a0) {
    if (*(s16*)(a0 + 0xE) != 0x18) {
        if (*(s8*)(a0 + 7) == D_8009A427) {
            *(s16*)(a0 + 0x42) = 0x7803;
        } else if (*(s8*)(a0 + 2) == 0x1C && D_80070C54 == 0xFF) {
            *(s16*)(a0 + 0x42) = 0x7804;
        } else {
            *(s16*)(a0 + 0x42) = 0x7800;
        }
    }
    func_8002D89C(a0);
}

extern u8 D_800D1599;

void func_8004E8C0(u8* obj) {
    u8 v = D_800D1599;
    if (v != obj[0x54]) {
        obj[0x47] = v ? 10 : 11;
        obj[0x54] = D_800D1599;
    }
    func_8002D89C(obj);
}

extern u8 D_8006FADD;

void func_8004E914(u8* obj) {
    u8 v = D_8006FADD;
    obj[0x47] = v ? 9 : 7;
    func_8002D89C(obj);
}

extern u8 D_8006FADC;

void func_8004E948(u8* obj) {
    obj[0x47] = D_8006FADC + 6;
    func_8002D89C(obj);
}

extern u8 D_800D1F2B;

void func_8004E974(u8* a0) {
    if ((a0[2] & 0x3F) == 3) {
        a0[0x47] = (s8)D_800D1F2B / 10 + 12;
    } else {
        a0[0x47] = (s8)D_800D1F2B % 10 + 12;
    }
    func_8002D89C(a0);
}
