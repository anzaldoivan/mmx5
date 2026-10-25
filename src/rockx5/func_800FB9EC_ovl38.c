#include "types.h"

#include "addr.h"

extern u8* func_8002D144(void);
extern void func_800171E8(Obj3DD4*, s32);
extern signed char D_8009A0A5;

void func_800FB9EC_ovl38(Obj3DD4* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        p = func_8002D144();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(u8**)(D_1F80004C.bytes + 0x80) = p;
        }
        func_800171E8(a, 0);
        a->unk6++;
    }
}
