#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 func_8002DF78(void);

void func_800F5DAC_ovl26(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        (*(u8**)(obj + 0x7C))[7] = 2;
        obj[6]++;
        *(s16*)(obj + 0x90) = (func_8002DF78() & 0xF) + 1;
    }
}
