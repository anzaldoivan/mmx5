#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_8002D6FC(u8* obj);

void func_800F4CD4_ovl26(u8* obj) {
    func_80017248(obj);
    if (((s8*)obj)[0x45] != 0) {
        (*(u8**)(D_1F80004C.bytes + 0x80))[0x92] = 0;
        func_8002D6FC(obj);
    }
}
