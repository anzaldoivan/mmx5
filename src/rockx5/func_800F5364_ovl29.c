#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D27C(void);
extern void func_80016490(s32, s32, void*);
extern u8 D_800F9894_ovl29[];

void func_800F5364_ovl29(u8* obj) {
    u8* child;

    func_80017248(obj);
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        obj[6]++;
        func_800171E8(obj, 6);
        *(u8**)(obj + 0x50) = D_800F9894_ovl29;
        obj[0x60] = 4;
        child = func_8002D27C();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x26;
            child[2] = 2;
            *(u8**)(child + 0x50) = obj;
        }
        child = func_8002D27C();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x26;
            child[2] = 3;
            *(u8**)(child + 0x50) = obj;
        }
        obj[0x67] = 0;
        func_80016490(2, 0xAF, obj);
    }
}
