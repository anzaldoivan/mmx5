#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void func_800F1308_ovl07(u8* obj);
extern void func_80044F78(void* arg0);

void func_800F1358_ovl07(u8* obj) {
    func_800F1308_ovl07(obj);
    animate_object(obj);
    move_object(obj);
    if (is_off_screen(obj, 0x20, 0x20) != 0) {
        goto done; // !FAKE: goto kept for the matching branch layout
    }
    if (*(s8*)(obj + 0x98) != 0) {
        *(s32*)(obj + 0x68) = 0;
        obj[4] = 2;
        obj[3] = 0;
        return;
    }
    if (obj[0x70] == 0) {
        ((s32(*)())func_8002F8FC)(obj);
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

void func_800F1414_ovl07(u8* arg0) {
    u8* p;

    p = *(u8**)(arg0 + 0x7C);
    p[0x98]--;
    clear_object_slot();
}
