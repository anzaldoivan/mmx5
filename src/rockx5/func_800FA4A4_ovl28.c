#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DED4(u8* obj);

void func_800FA4A4_ovl28(u8* obj) {
    u8* p;
    u8 st;
    s8 v;
    s32 t;

    p = *(u8**)(obj + 0x7C);
    t = p[0x15];
    obj[0x15] = t;
    t = *(u16*)(p + 0xA);
    *(volatile u16*)(obj + 0xA) =
        t; // !FAKE: volatile pins the reload below this store
    p = *(
        u8* volatile*)(obj +
                       0x7C); // !FAKE: volatile forces the target's parent reload
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    st = p[0x47];
    switch (*(s8*)(obj + 5)) {
    case 0:
        if ((u32)(st - 7) < 4) {
            func_800171E8(obj, 0xB);
            obj[5]++;
        }
        break;
    case 1:
        if ((u32)(st - 7) >= 4) {
            func_800171E8(obj, 0xA);
            obj[5]--;
        }
        break;
    }
    v = *(s8*)(*(u8**)(obj + 0x7C) + 4);
    if (v == 2) {
        obj[4] = v;
    }
    func_8002D9EC(obj, 0x30, 0x30);
    func_80017248(obj);
    func_8002DED4(obj);
}
