#include "types.h"

extern void (*D_800FE6F0_ovl28[])(u8*);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F9404_ovl28(u8* arg0) {
    D_800FE6F0_ovl28[(signed char)arg0[6]](arg0);
    func_8002D9EC(arg0, 0x30, 0x30);
    func_80017248(arg0);
    func_8002DED4(arg0);
}
