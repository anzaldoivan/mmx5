#include "types.h"

extern s16 D_8009A0AA;
extern void func_80016490(s32, s32, void*);
extern s32 func_8003C784(void* arg0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800F9A9C_ovl28(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        obj[0x45] = 0;
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        if (obj[0x15] == 0) {
            *(s32*)(obj + 0x20) = 0xFFFBE000;
        } else {
            *(s32*)(obj + 0x20) = 0x42000;
        }
        func_80016490(2, 0x85, obj);
        func_8003C784(obj);
    }
    if (*(s8*)(obj + 0x45) == 2) {
        obj[6]++;
    }
    func_8002D9EC(obj, 0x30, 0x30);
    func_80017248(obj);
    func_8002DED4(obj);
}
