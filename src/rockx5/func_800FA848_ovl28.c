#include "types.h"

extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* obj);

void func_800FA848_ovl28(u8* obj) {
    s8 v;

    func_800317B8(obj);
    func_80031DD0(obj);
    switch ((s8)obj[5]) {
    case 0:
        if (++*(s32*)(obj + 0x8C) == 10) {
            obj[0x16] = 1;
            obj[5]++;
        }
        break;
    case 1:
        if (++*(s32*)(obj + 0x8C) == 100) {
            obj[4] = 2;
        }
        break;
    }
    v = (*(u8**)(obj + 0x7C))[4];
    if (v == 2) {
        obj[4] = v;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    func_80017248(obj);
    func_8002DF54(obj);
}
