/* GAIL - The GNOME Accessibility Implementation Library
 * Copyright 2011 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GAIL_LINK_BUTTON_H__
#define __GAIL_LINK_BUTTON_H__

#include <gail/gailbutton.h>

G_BEGIN_DECLS

#define GAIL_TYPE_LINK_BUTTON                (gail_link_button_get_type ())
#define GAIL_LINK_BUTTON(obj)                (G_TYPE_CHECK_INSTANCE_CAST ((obj), GAIL_TYPE_LINK_BUTTON, GailLinkButton))
#define GAIL_LINK_BUTTON_CLASS(klass)        (G_TYPE_CHECK_CLASS_CAST ((klass), GAIL_TYPE_LINK_BUTTON, GailLinkButtonClass))
#define GAIL_IS_LINK_BUTTON(obj)             (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GAIL_TYPE_LINK_BUTTON))
#define GAIL_IS_LINK_BUTTON_CLASS(klass)     (G_TYPE_CHECK_CLASS_TYPE ((klass), GAIL_TYPE_LINK_BUTTON))
#define GAIL_LINK_BUTTON_GET_CLASS(obj)      (G_TYPE_INSTANCE_GET_CLASS ((obj), GAIL_TYPE_LINK_BUTTON, GailLinkButtonClass))

typedef struct _GailLinkButton                   GailLinkButton;
typedef struct _GailLinkButtonClass              GailLinkButtonClass;

struct _GailLinkButton
{
  GailButton parent;

  AtkHyperlink *link;
};

GType gail_link_button_get_type (void);

struct _GailLinkButtonClass
{
  GailButtonClass parent_class;
};

G_END_DECLS

#endif /* __GAIL_LINK_BUTTON_H__ */
