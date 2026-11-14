#include "types.h"
#include "addr.h"

extern u8* func_8002D27C(void);
extern u32* D_80098118;
extern u8 D_800D1CAA;
extern u8 D_800D1CAB;

static inline void func_800EFA84_ovl25_spawn(u8* obj) {
    u8* p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x38;
        p[2] = obj[2] + 1;
        *(s32*)(p + 0x54) = *(s32*)(obj + 0x54);
    }
}

void func_800EFA84_ovl25(u8* obj) {
    s32 b;
    s32 n;

    ((s8*)obj)[0x14] = -1;
    obj[4]++;
    *(s16*)(obj + 0x40) = *D_80098118 >> 7;
    *(s16*)(obj + 0x42) = 0x7800;
    n = *D_1F800020.s32s;
    *(s32*)(obj + 0x3C) = (s32)D_1F800020.u32s + n;
    b = 1;
    obj[0x16] = b;
    obj[3] = b;
    *(s16*)(obj + 0xE) = 0x98;
    switch ((s8)obj[2]) {
    case 0:
        b = D_800D1CAA;
        *(s16*)(obj + 0xA) = 0x120;
        *(s16*)(obj + 0xE) = 0xB8;
        b += 11;
        obj[0x47] = b;
        break;
    case 1: {
        s32 t = *(s32*)(obj + 0x54);
        if (t / 216000 >= 100) {
            obj[0x47] = 9;
            *(s32*)(obj + 0x54) = 2159940;
        } else if (t < 60) {
            obj[3] = 0;
            *(s32*)(obj + 0x54) = 0;
        } else if (t / 216000 >= 10) {
            obj[0x47] = t / 2160000;
            *(s32*)(obj + 0x54) = t - obj[0x47] * 2160000;
        } else {
            obj[3] = 0;
            obj[4] = 2;
        }
        func_800EFA84_ovl25_spawn(obj);
        *(s16*)(obj + 0xA) = 0xC0;
        break;
    }
    case 2: {
        n = *(s32*)(obj + 0x54);
        obj[0x47] = n / 216000;
        n -= obj[0x47] * 216000;
        *(s32*)(obj + 0x54) = n;
        func_800EFA84_ovl25_spawn(obj);
        *(s16*)(obj + 0xA) = 0xD0;
        break;
    }
    case 3: {
        s32 t = *(s32*)(obj + 0x54);
        if (t / 3600 >= 10) {
            obj[0x47] = t / 36000;
            *(s32*)(obj + 0x54) = t - obj[0x47] * 36000;
        } else {
            obj[0x47] = 0;
        }
        func_800EFA84_ovl25_spawn(obj);
        *(s16*)(obj + 0xA) = 0xF0;
        break;
    }
    case 4: {
        s32 t = *(s32*)(obj + 0x54);
        obj[0x47] = t / 3600;
        *(s32*)(obj + 0x54) = t - obj[0x47] * 3600;
        func_800EFA84_ovl25_spawn(obj);
        *(s16*)(obj + 0xA) = 0x100;
        break;
    }
    case 5: {
        s32 t = *(s32*)(obj + 0x54);
        if (t / 60 >= 10) {
            obj[0x47] = t / 600;
            *(s32*)(obj + 0x54) = t - obj[0x47] * 600;
        } else {
            obj[0x47] = 0;
        }
        func_800EFA84_ovl25_spawn(obj);
        *(s16*)(obj + 0xA) = 0x120;
        break;
    }
    case 6:
        obj[0x47] = *(s32*)(obj + 0x54) / 60;
        if (obj[0x47] >= 10) {
            obj[0x47] = 0;
        }
        *(s16*)(obj + 0xA) = 0x130;
        break;
    case 7:
        obj[0x47] = 10;
        *(s16*)(obj + 0xA) = 0xD8;
        break;
    case 8:
        obj[0x47] = 0x13;
        *(s16*)(obj + 0xA) = 0x108;
        break;
    case 9:
        b = D_800D1CAB;
        *(s16*)(obj + 0xA) = 0x120;
        *(s16*)(obj + 0xE) = 0xC8;
        b += 11;
        obj[0x47] = b;
        break;
    }
    obj[0x15] = 0;
}
