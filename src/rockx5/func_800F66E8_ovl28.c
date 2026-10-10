#include "types.h"

#define G (*(u8**)0x1F80004C)

extern void func_80017248(u8*);

void func_800F66E8_ovl28(u8* obj) {
    func_80017248(obj);
    if (G[0x8C] == 2) {
        obj[6]++;
    }
}
