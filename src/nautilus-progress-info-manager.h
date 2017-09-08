/*
 * Nautilus
 *
 * Copyright (C) 2011 Red Hat, Inc.
 *
 * Nautilus is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * Nautilus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; see the file COPYING.  If not,
 * see <http://www.gnu.org/licenses/>.
 *
 * Author: Cosimo Cecchi <cosimoc@redhat.com>
 */

#ifndef __NAUTILUS_PROGRESS_INFO_MANAGER_H__
#define __NAUTILUS_PROGRESS_INFO_MANAGER_H__

#include <glib-object.h>

#include "nautilus-progress-info.h"

#define NAUTILUS_TYPE_PROGRESS_INFO_MANAGER nautilus_progress_info_manager_get_type()
#define NAUTILUS_PROGRESS_INFO_MANAGER(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), NAUTILUS_TYPE_PROGRESS_INFO_MANAGER, NautilusProgressInfoManager))
#define NAUTILUS_PROGRESS_INFO_MANAGER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), NAUTILUS_TYPE_PROGRESS_INFO_MANAGER, NautilusProgressInfoManagerClass))
#define NAUTILUS_IS_PROGRESS_INFO_MANAGER(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NAUTILUS_TYPE_PROGRESS_INFO_MANAGER))
#define NAUTILUS_IS_PROGRESS_INFO_MANAGER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), NAUTILUS_TYPE_PROGRESS_INFO_MANAGER))
#define NAUTILUS_PROGRESS_INFO_MANAGER_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), NAUTILUS_TYPE_PROGRESS_INFO_MANAGER, NautilusProgressInfoManagerClass))

typedef struct _NautilusProgressInfoManager NautilusProgressInfoManager;
typedef struct _NautilusProgressInfoManagerClass NautilusProgressInfoManagerClass;
typedef struct _NautilusProgressInfoManagerPriv NautilusProgressInfoManagerPriv;

struct _NautilusProgressInfoManager {
  GObject parent;

  /* private */
  NautilusProgressInfoManagerPriv *priv;
};

struct _NautilusProgressInfoManagerClass {
  GObjectClass parent_class;
};

GType nautilus_progress_info_manager_get_type (void);

NautilusProgressInfoManager* nautilus_progress_info_manager_dup_singleton (void);

void nautilus_progress_info_manager_add_new_info (NautilusProgressInfoManager *self,
                                                  NautilusProgressInfo *info);
GList *nautilus_progress_info_manager_get_all_infos (NautilusProgressInfoManager *self);
void nautilus_progress_info_manager_remove_finished_or_cancelled_infos (NautilusProgressInfoManager *self);
gboolean nautilus_progress_manager_are_all_infos_finished_or_cancelled (NautilusProgressInfoManager *self);

void nautilus_progress_manager_add_viewer (NautilusProgressInfoManager *self, GObject *viewer);
void nautilus_progress_manager_remove_viewer (NautilusProgressInfoManager *self, GObject *viewer);
gboolean nautilus_progress_manager_has_viewers (NautilusProgressInfoManager *self);

G_END_DECLS

#endif /* __NAUTILUS_PROGRESS_INFO_MANAGER_H__ */
