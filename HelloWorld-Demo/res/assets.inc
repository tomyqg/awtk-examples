#include "awtk.h"
#include "base/assets_manager.h"
#ifndef WITH_FS_RES
#include "assets/inc/strings/en_US.data"
#include "assets/inc/strings/zh_CN.data"
#include "assets/inc/styles/default.data"
#include "assets/inc/styles/keyboard.data"
#include "assets/inc/ui/kb_ascii.data"
#include "assets/inc/ui/kb_default.data"
#include "assets/inc/ui/kb_float.data"
#include "assets/inc/ui/kb_hex.data"
#include "assets/inc/ui/kb_int.data"
#include "assets/inc/ui/kb_phone.data"
#include "assets/inc/ui/kb_ufloat.data"
#include "assets/inc/ui/kb_uint.data"
#ifdef WITH_STB_IMAGE
#include "assets/inc/images/backspace.res"
#include "assets/inc/images/earth.res"
#include "assets/inc/images/shift.res"
#include "assets/inc/images/shifton.res"
#else
#endif/*WITH_STB_IMAGE*/
#ifdef WITH_STB_FONT
#ifdef WITH_MINI_FONT
#include "assets/inc/fonts/default.mini.res"
#else/*WITH_MINI_FONT*/
#endif/*WITH_MINI_FONT*/
#else/*WITH_STB_FONT*/
#endif/*WITH_STB_FONT*/
#endif/*WITH_FS_RES*/

ret_t assets_init(void) {
  assets_manager_t* rm = assets_manager();

#ifdef WITH_FS_RES
#ifdef WITH_MINI_FONT
  asset_info_t* info = assets_manager_load(rm, ASSET_TYPE_FONT, "default.mini");
  if (info) {
    strcpy(info->name, "default");
  }
#else 
  assets_manager_load(rm, ASSET_TYPE_FONT, "default");
#endif
  assets_manager_load(rm, ASSET_TYPE_STYLE, "default");
#else
#ifdef WITH_STB_FONT
  assets_manager_add(rm, font_default);
#endif
  assets_manager_add(rm, image_backspace);
  assets_manager_add(rm, image_earth);
  assets_manager_add(rm, image_shift);
  assets_manager_add(rm, image_shifton);
  assets_manager_add(rm, style_default);
  assets_manager_add(rm, style_keyboard);
  assets_manager_add(rm, ui_kb_ascii);
  assets_manager_add(rm, ui_kb_default);
  assets_manager_add(rm, ui_kb_float);
  assets_manager_add(rm, ui_kb_hex);
  assets_manager_add(rm, ui_kb_int);
  assets_manager_add(rm, ui_kb_phone);
  assets_manager_add(rm, ui_kb_ufloat);
  assets_manager_add(rm, ui_kb_uint);
  assets_manager_add(rm, strings_en_US);
  assets_manager_add(rm, strings_zh_CN);
#endif

  tk_init_assets();
  return RET_OK;
}
