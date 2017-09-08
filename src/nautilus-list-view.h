
/* fm-list-view.h - interface for list view of directory.

   Copyright (C) 2000 Eazel, Inc.
   Copyright (C) 2001 Anders Carlsson <andersca@gnu.org>
   
   The Gnome Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The Gnome Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the Gnome Library; see the file COPYING.LIB.  If not,
   see <http://www.gnu.org/licenses/>.

   Authors: John Sullivan <sullivan@eazel.com>
            Anders Carlsson <andersca@gnu.org>
*/

#ifndef NAUTILUS_LIST_VIEW_H
#define NAUTILUS_LIST_VIEW_H

#include "nautilus-files-view.h"

#define NAUTILUS_TYPE_LIST_VIEW nautilus_list_view_get_type()
#define NAUTILUS_LIST_VIEW(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), NAUTILUS_TYPE_LIST_VIEW, NautilusListView))
#define NAUTILUS_LIST_VIEW_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), NAUTILUS_TYPE_LIST_VIEW, NautilusListViewClass))
#define NAUTILUS_IS_LIST_VIEW(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NAUTILUS_TYPE_LIST_VIEW))
#define NAUTILUS_IS_LIST_VIEW_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), NAUTILUS_TYPE_LIST_VIEW))
#define NAUTILUS_LIST_VIEW_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), NAUTILUS_TYPE_LIST_VIEW, NautilusListViewClass))

typedef struct NautilusListViewDetails NautilusListViewDetails;

typedef struct {
	NautilusFilesView parent_instance;
	NautilusListViewDetails *details;
} NautilusListView;

typedef struct {
	NautilusFilesViewClass parent_class;
} NautilusListViewClass;

GType nautilus_list_view_get_type (void);
NautilusFilesView * nautilus_list_view_new (NautilusWindowSlot *slot);

#endif /* NAUTILUS_LIST_VIEW_H */
