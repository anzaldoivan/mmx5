#include "types.h"
#include "addr.h"

extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A11A;
extern u8 D_800D1C00[];

#define S16(p, o) (*(s16*)((p) + (o)))
#define U16(p, o) (*(u16*)((p) + (o)))
#define S8(p, o) (*(signed char*)((p) + (o)))

void func_800FB6D0_ovl38(u8* obj) {
    u8* child;
    u8* g;

    obj[3] = 0;
    child = *(u8**)(D_1F80004C.bytes + 0x80);
    if (S8(child, 0) != 0) {
        if (S8(child, 7) == 0) {
            if (--S16(obj, 0x7E) == -1) {
                S16(obj, 0x7E) = 5;
                U16(obj, 0x42) ^= 0x8000;
            }
            func_8002D9EC(obj, 0x60, 0x60);
        }
    } else {
        g = D_800D1C00;
        g[0x24] = 0;
        *(s32*)(g + 0x20) = 0;
        D_8009A11A = 0;
        obj[5]++;
    }
}
