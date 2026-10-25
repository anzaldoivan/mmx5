#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D89C(u8*);

void func_800F7A40_ovl09(u8* obj) {
    s32 n = (s8)obj[2];

    switch (n) {
    case 1:
    case 2:
        func_800171E8(obj, n + 1);
        break;
    case 3:
        func_8002D89C(obj);
        break;
    }
    obj[0x54] = 0;
    obj[4]++;
}
