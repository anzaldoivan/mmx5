#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern s32 func_8002DF78(void);

void func_800F4F48_ovl26(u8* obj) {
    func_80017248(obj);
    D_1F80004C.bytes[0x94] = (u32)func_8002DF78() % 3 + 3;
    *(s16*)(obj + 0x7C) = 0;
    *(s16*)(obj + 0x7E) = 30;
    obj[7] = 0;
    obj[6]++;
}
