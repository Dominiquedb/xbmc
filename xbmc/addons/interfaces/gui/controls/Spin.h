/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "addons/kodi-dev-kit/include/kodi/c-api/gui/controls/spin.h"

extern "C"
{

  struct AddonGlobalInterface;

  namespace ADDON
  {

  /*!
   * @brief Global gui Add-on to Kodi callback functions
   *
   * To hold general gui functions and initialize also all other gui related types not
   * related to a instance type and usable for every add-on type.
   *
   * Related add-on header is "./xbmc/addons/kodi-dev-kit/include/kodi/gui/controls/Spin.h"
   */
  struct Interface_GUIControlSpin
  {
    static void Init(AddonGlobalInterface* addonInterface);
    static void DeInit(AddonGlobalInterface* addonInterface);

    /*!
     * @brief callback functions from add-on to kodi
     *
     * @note To add a new function use the "_" style to directly identify an
     * add-on callback function. Everything with CamelCase is only to be used
     * in Kodi.
     *
     * The parameter `kodiBase` is used to become the pointer for a `CAddonDll`
     * class.
     */
    //@{
    static void set_visible(KODI_HANDLE kodiBase, KODI_GUI_CONTROL_HANDLE handle, bool visible);
    static void set_enabled(KODI_HANDLE kodiBase, KODI_GUI_CONTROL_HANDLE handle, bool enabled);

    static void set_text(KODI_HANDLE kodiBase, KODI_GUI_CONTROL_HANDLE handle, const char* text);
    static void reset(KODI_HANDLE kodiBase, KODI_GUI_CONTROL_HANDLE handle);
    static void set_type(KODI_HANDLE kodiBase, KODI_GUI_CONTROL_HANDLE handle, int type);

    static void add_string_label(KODI_HANDLE kodiBase,
                                 KODI_GUI_CONTROL_HANDLE handle,
                                 const char* label,
                                 const char* value);
    static void add_int_label(KODI_HANDLE kodiBase,
                              KODI_GUI_CONTROL_HANDLE handle,
                              const char* label,
                              int value);

    static void set_string_value(KODI_HANDLE kodiBase,
                                 KODI_GUI_CONTROL_HANDLE handle,
                                 const char* value);
    static char* get_string_value(KODI_HANDLE kodiBase, KODI_GUI_CONTROL_HANDLE handle);

    static void set_int_range(KODI_HANDLE kodiBase,
                              KODI_GUI_CONTROL_HANDLE handle,
                              int start,
                              int end);
    static void set_int_value(KODI_HANDLE kodiBase, KODI_GUI_CONTROL_HANDLE handle, int value);
    static int get_int_value(KODI_HANDLE kodiBase, KODI_GUI_CONTROL_HANDLE handle);

    static void set_float_range(KODI_HANDLE kodiBase,
                                KODI_GUI_CONTROL_HANDLE handle,
                                float start,
                                float end);
    static void set_float_value(KODI_HANDLE kodiBase, KODI_GUI_CONTROL_HANDLE handle, float value);
    static float get_float_value(KODI_HANDLE kodiBase, KODI_GUI_CONTROL_HANDLE handle);
    static void set_float_interval(KODI_HANDLE kodiBase,
                                   KODI_GUI_CONTROL_HANDLE handle,
                                   float interval);
    //@}
  };

  } /* namespace ADDON */
} /* extern "C" */
