#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_80016490(s32, s32, void*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_8004A8C4(u8* obj) {
    func_80017248(obj);
    func_8002DF54(obj);
    if (*(s16*)(obj + 0x8E) >= 4) {
        if (func_8002D938(obj, 0x20, 0x20) == 1) {
            obj[4]++;
        }
        return;
    }
    if ((u16)(*(u16*)(obj + 0xA) - 0x10) > 0x120) {
        (*(s16*)(obj + 0x8E))++;
        *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
        func_80016490(1, 0x1B, obj);
    } else if ((u16)(*(u16*)(obj + 0xE) - 0x10) > 0xD0) {
        (*(s16*)(obj + 0x8E))++;
        *(s32*)(obj + 0x24) = -*(s32*)(obj + 0x24);
        func_80016490(1, 0x1B, obj);
    }
    func_8002D9EC(obj, 0x20, 0x20);
}
