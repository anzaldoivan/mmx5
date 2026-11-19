#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern void func_80055E2C(void* arg0, void* arg1);
extern s8 D_8009A195;

void func_80055608(u8* obj) {
    void* a1 = *(void**)(obj + 0x50);

    if (*(s8*)(obj + 4) == 0) {
        func_80055E2C(obj, a1);
        *(s16*)(obj + 0x54) = 0x78;
        play_sound(0, 0x24, 0);
    } else if (*(s16*)(obj + 0x54) == 0) {
        D_8009A195 = 2;
        clear_object_slot(obj);
        return;
    } else {
        animate_object(obj);
        (*(s16*)(obj + 0x54))--;
    }
    func_8002D9EC(obj, 0x88, 0x88);
}
