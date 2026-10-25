#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);

void func_800EFA38_ovl03(u8* obj) {
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0x20000;
    func_8002DF54(obj);
    func_80017248(obj);
}
