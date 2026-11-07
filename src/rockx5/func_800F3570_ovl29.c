#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern u8* func_8002D27C(void);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DED4(u8* obj);
extern u8 D_800F9888_ovl29[];

void func_800F3570_ovl29(u8* obj) {
    s16 t;
    u8* p;

    t = *(s16*)(obj + 0x7C);
    if (t >= 0x21) {
        *(u8**)(obj + 0x68) = D_800F9888_ovl29;
        if ((obj[0x70] & 8) && t >= 0x31) {
            func_800171E8(obj, 0x10);
            obj[0x67] = 0;
            func_80016490(2, 0xAF, obj);
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x2C) = 0;
            obj[6]++;
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x26;
                p[2] = 2;
                *(u8**)(p + 0x50) = obj;
            }
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x26;
                p[2] = 3;
                *(u8**)(p + 0x50) = obj;
            }
        }
    }
    (*(s16*)(obj + 0x7C))++;
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
