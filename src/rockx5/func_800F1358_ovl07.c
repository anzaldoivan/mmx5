#include "types.h"

extern void func_800F1308_ovl07(u8* obj);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern s32 func_8002F8FC(u8* a0);
extern void func_80044F78(void* arg0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F1358_ovl07(u8* obj) {
    func_800F1308_ovl07(obj);
    func_80017248(obj);
    func_8002DF54(obj);
    if (func_8002D938(obj, 0x20, 0x20) != 0) {
        goto done; // !FAKE: goto kept for the matching branch layout
    }
    if (*(s8*)(obj + 0x98) != 0) {
        *(s32*)(obj + 0x68) = 0;
        obj[4] = 2;
        obj[3] = 0;
        return;
    }
    if (obj[0x70] == 0) {
        func_8002F8FC(obj);
        if (obj[0x70] == 0) {
            goto move; // !FAKE: goto kept for the matching branch layout
        }
    }
    func_80044F78(obj);
    obj[4] = 2;
move:
    func_8002D9EC(obj, 0x10, 0x10);
    return;
done:
    obj[4] = 2;
    obj[3] = 0;
}
