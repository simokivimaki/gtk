/* GDK - The GIMP Drawing Kit
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
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

#if !defined (__GDKX_H_INSIDE__) && !defined (GDK_COMPILATION)
#error "Only <gdk/gdkx.h> can be included directly."
#endif

#ifndef __GDK_BROADWAY_CURSOR_H__
#define __GDK_BROADWAY_CURSOR_H__

#include <gdk/gdk.h>

G_BEGIN_DECLS

#define GDK_TYPE_BROADWAY_CURSOR              (gdk_broadway_cursor_get_type ())
#define GDK_BROADWAY_CURSOR(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), GDK_TYPE_BROADWAY_CURSOR, GdkBroadwayCursor))
#define GDK_BROADWAY_CURSOR_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), GDK_TYPE_BROADWAY_CURSOR, GdkBroadwayCursorClass))
#define GDK_IS_BROADWAY_CURSOR(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), GDK_TYPE_BROADWAY_CURSOR))
#define GDK_IS_BROADWAY_CURSOR_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), GDK_TYPE_BROADWAY_CURSOR))
#define GDK_BROADWAY_CURSOR_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), GDK_TYPE_BROADWAY_CURSOR, GdkBroadwayCursorClass))

#ifdef GDK_COMPILATION
typedef struct _GdkBroadwayCursor GdkBroadwayCursor;
#else
typedef GdkCursor GdkBroadwayCursor;
#endif
typedef struct _GdkBroadwayCursorClass GdkBroadwayCursorClass;

GType    gdk_broadway_cursor_get_type          (void);

G_END_DECLS

#endif /* __GDK_BROADWAY_CURSOR_H__ */
