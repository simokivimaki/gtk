/* GDK - The GIMP Drawing Kit
 * Copyright (C) 2000 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * Modified by the GTK+ Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/.
 */

#include "config.h"

#include "gdkprivate-broadway.h"
#include "gdkinternals.h"
#include "gdkdisplay-broadway.h"
#include "gdkkeysprivate.h"
#include "gdkkeysyms.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>

typedef struct _GdkBroadwayKeymap   GdkBroadwayKeymap;
typedef struct _GdkKeymapClass GdkBroadwayKeymapClass;

#define GDK_TYPE_BROADWAY_KEYMAP          (gdk_broadway_keymap_get_type ())
#define GDK_BROADWAY_KEYMAP(object)       (G_TYPE_CHECK_INSTANCE_CAST ((object), GDK_TYPE_BROADWAY_KEYMAP, GdkBroadwayKeymap))
#define GDK_IS_BROADWAY_KEYMAP(object)    (G_TYPE_CHECK_INSTANCE_TYPE ((object), GDK_TYPE_BROADWAY_KEYMAP))

typedef struct _DirectionCacheEntry DirectionCacheEntry;

struct _GdkBroadwayKeymap
{
  GdkKeymap     parent_instance;
};

struct _GdkBroadwayKeymapClass
{
  GdkKeymapClass keymap_class;
};

G_DEFINE_TYPE (GdkBroadwayKeymap, gdk_broadway_keymap, GDK_TYPE_KEYMAP)

static void  gdk_broadway_keymap_finalize   (GObject           *object);

static void
gdk_broadway_keymap_init (GdkBroadwayKeymap *keymap)
{
}

static void
gdk_broadway_keymap_finalize (GObject *object)
{
  G_OBJECT_CLASS (gdk_broadway_keymap_parent_class)->finalize (object);
}

GdkKeymap*
_gdk_broadway_display_get_keymap (GdkDisplay *display)
{
  GdkBroadwayDisplay *broadway_display;

  g_return_val_if_fail (GDK_IS_DISPLAY (display), NULL);
  broadway_display = GDK_BROADWAY_DISPLAY (display);

  if (!broadway_display->keymap)
    broadway_display->keymap = g_object_new (gdk_broadway_keymap_get_type (), NULL);

  broadway_display->keymap->display = display;

  return broadway_display->keymap;
}

static PangoDirection
gdk_broadway_keymap_get_direction (GdkKeymap *keymap)
{
  return PANGO_DIRECTION_NEUTRAL;
}

static gboolean
gdk_broadway_keymap_have_bidi_layouts (GdkKeymap *keymap)
{
  return FALSE;
}

static gboolean
gdk_broadway_keymap_get_caps_lock_state (GdkKeymap *keymap)
{
  return FALSE;
}

static gboolean
gdk_broadway_keymap_get_num_lock_state (GdkKeymap *keymap)
{
  return FALSE;
}

static gboolean
gdk_broadway_keymap_get_entries_for_keyval (GdkKeymap     *keymap,
					    guint          keyval,
					    GdkKeymapKey **keys,
					    gint          *n_keys)
{
  *n_keys = 0;
  return FALSE;
}

static gboolean
gdk_broadway_keymap_get_entries_for_keycode (GdkKeymap     *keymap,
					     guint          hardware_keycode,
					     GdkKeymapKey **keys,
					     guint        **keyvals,
					     gint          *n_entries)
{
  *n_entries = 0;
  return FALSE;
}

static guint
gdk_broadway_keymap_lookup_key (GdkKeymap          *keymap,
				const GdkKeymapKey *key)
{
  return 0;
}


static gboolean
gdk_broadway_keymap_translate_keyboard_state (GdkKeymap       *keymap,
					      guint            hardware_keycode,
					      GdkModifierType  state,
					      gint             group,
					      guint           *keyval,
					      gint            *effective_group,
					      gint            *level,
					      GdkModifierType *consumed_modifiers)
{
  return FALSE;
}

static void
gdk_broadway_keymap_add_virtual_modifiers (GdkKeymap       *keymap,
					   GdkModifierType *state)
{
}

static gboolean
gdk_broadway_keymap_map_virtual_modifiers (GdkKeymap       *keymap,
					   GdkModifierType *state)
{
  return FALSE;
}

static void
gdk_broadway_keymap_class_init (GdkBroadwayKeymapClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GdkKeymapClass *keymap_class = GDK_KEYMAP_CLASS (klass);

  object_class->finalize = gdk_broadway_keymap_finalize;

  keymap_class->get_direction = gdk_broadway_keymap_get_direction;
  keymap_class->have_bidi_layouts = gdk_broadway_keymap_have_bidi_layouts;
  keymap_class->get_caps_lock_state = gdk_broadway_keymap_get_caps_lock_state;
  keymap_class->get_num_lock_state = gdk_broadway_keymap_get_num_lock_state;
  keymap_class->get_entries_for_keyval = gdk_broadway_keymap_get_entries_for_keyval;
  keymap_class->get_entries_for_keycode = gdk_broadway_keymap_get_entries_for_keycode;
  keymap_class->lookup_key = gdk_broadway_keymap_lookup_key;
  keymap_class->translate_keyboard_state = gdk_broadway_keymap_translate_keyboard_state;
  keymap_class->add_virtual_modifiers = gdk_broadway_keymap_add_virtual_modifiers;
  keymap_class->map_virtual_modifiers = gdk_broadway_keymap_map_virtual_modifiers;
}

