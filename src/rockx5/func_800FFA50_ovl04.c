#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FC64(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_800D1C2A;

void func_800FFA50_ovl04(u8* obj) {
    u8* p;

    func_80017248(obj);
    if (((s8*)obj)[5] == 0) {
        p = *(u8**)(obj + 0x7C);
        *(s16*)(obj + 0xA) = *(s16*)(p + 0xA);
        *(s16*)(obj + 0xE) = *(s16*)(p + 0xE);
        *(s16*)(obj + 0xA) += 8;
        *(s16*)(obj + 0xE) -= 0x10;
        if (--*(s16*)(obj + 0x88) == 0) {
            obj[5]++;
        }
        if (!(D_800D1C2A & 8) && ((s8*)p)[5] < 4) {
            goto ec; // !FAKE: goto kept for the matching branch layout
        }
        goto inc; // !FAKE: goto kept for the matching branch layout
    }
    func_8002DF54(obj);
ec: // !FAKE: label kept for the matching branch layout
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        func_8004FC64(obj);
        obj[4]++;
    } else if (func_8002D938(obj, 0x40, 0x40) == 0) {
        func_8002D9EC(obj, 0x10, 0x10);
    } else {
    inc: // !FAKE: label kept for the matching branch layout
        obj[4]++;
    }
}
