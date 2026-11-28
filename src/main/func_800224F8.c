#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

extern int func_8002DAA0();

void func_800224F8(void) {
    s8* obj;

    if ((s8)g_Player[0xCC] != 0) {
        return;
    }
    for (D_1F800060 = g_class4_slots.u; D_1F800060 < g_class4_slots.u + 0x2900;
         D_1F800060 += 0xA4) {
        obj = (s8*)D_1F800060;
        if (obj[0] != 0) {
            if ((s8)g_Player[0xCC] != 0 ||
                ((s8)g_playthrough_state.u[0x16] != 0 && !(*(u8*)obj & 8))) {
                if (obj[3] != 0) {
                    func_8002DAA0(obj);
                }
            } else {
                D_1F800094[obj[1]]((u8*)obj);
            }
        }
    }
}
