#include "types.h"
#include "addr.h"

extern u8 D_800FE198_ovl28[][3];
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);

#define G D_1F80004C.bytes
void func_800F57FC_ovl28(u8* obj) {
    if (D_800FE198_ovl28[G[0x89]][G[0x8A] + 1] == 5) {
        *(s16*)(obj + 0x7E) = 100;
    } else {
        *(s16*)(obj + 0x7E) = 0;
    }
    func_800171E8(obj, 1);
    func_80017248(obj);
    obj[6]++;
}
