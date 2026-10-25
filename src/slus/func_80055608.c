#include "types.h"

extern void func_80055E2C(void* arg0, void* arg1);
extern void func_80016490(s32, s32, void*);
extern int func_8002D6FC();
extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s8 D_8009A195;

void func_80055608(u8* obj) {
    void* a1 = *(void**)(obj + 0x50);

    if (*(s8*)(obj + 4) == 0) {
        func_80055E2C(obj, a1);
        *(s16*)(obj + 0x54) = 0x78;
        func_80016490(0, 0x24, 0);
    } else if (*(s16*)(obj + 0x54) == 0) {
        D_8009A195 = 2;
        func_8002D6FC(obj);
        return;
    } else {
        func_80017248(obj);
        (*(s16*)(obj + 0x54))--;
    }
    func_8002D9EC(obj, 0x88, 0x88);
}
