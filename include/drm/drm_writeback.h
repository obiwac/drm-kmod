/* Public domain. */

#ifndef _DRM_WRITEBACK_H
#define _DRM_WRITEBACK_H

#include <drm/drm_connector.h>

struct drm_writeback_connector {
	struct drm_connector base;
	struct drm_property_blob *pixel_formats_blob_ptr;
};

struct drm_writeback_job {
	struct drm_writeback_connector *connector;
	struct dma_fence *out_fence;
	struct drm_framebuffer *fb;
};

static inline struct drm_writeback_connector *
drm_connector_to_writeback(struct drm_connector *connector)
{
	return container_of(connector, struct drm_writeback_connector, base);
}

static inline struct dma_fence *
drm_writeback_get_out_fence(struct drm_writeback_connector *connector)
{
	return NULL;
}

static inline void
drm_writeback_cleanup_job(struct drm_writeback_job *j)
{
}

static inline int
drm_writeback_prepare_job(struct drm_writeback_job *j)
{
	return 0;
}

static inline int
drm_writeback_set_fb(struct drm_connector_state *cs, struct drm_framebuffer *fb)
{
	return 0;
}

static inline void
drm_writeback_queue_job(struct drm_writeback_connector *connector, struct drm_connector_state *cs)
{
	pr_debug("%s: TODO\n", __func__);
}

static inline void
drm_writeback_signal_completion(struct drm_writeback_connector *connector, int status)
{
	pr_debug("%s: TODO\n", __func__);
}

static inline int
drm_writeback_connector_init_with_encoder(
	struct drm_device *dev,
	struct drm_writeback_connector *wb_conn,
	struct drm_encoder *encoder,
	struct drm_connector_funcs const *funcs,
	uint32_t const *formats,
	size_t size
)
{
	return 0;
}

#endif
