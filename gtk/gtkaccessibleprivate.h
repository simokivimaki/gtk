/* GTK - The GIMP Toolkit
 * Copyright (C) 2011 Red Hat, Inc.
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __GTK_ACCESSIBLE_PRIVATE_H__
#define __GTK_ACCESSIBLE_PRIVATE_H__

#include "gtkaccessible.h"

G_BEGIN_DECLS

void     _gtk_accessible_set_factory_type (GType widget_type,
                                           GType factory_type);

G_END_DECLS

#endif  /* __GTK_ACCESSIBLE_PRIVATE_H__ */
