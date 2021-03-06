#ifndef RENDERING_H
#define RENDERING_H

#include "common.h"
#include "plugins.h"

class Renderer {
	BASE_PLUGIN(Renderer, ());
public:
	virtual ~Renderer() {}
	
	virtual void derender(NodePtr nv, RenderBuf* renderbuf) = 0;

	virtual bool render(NodeView block, RenderBuf* renderbuf) = 0;
};


class DefaultRenderer : public Renderer {
	PLUGIN(DefaultRenderer);
public:
	virtual bool render(NodeView block, RenderBuf* renderbuf);

	virtual void derender(NodePtr nv, RenderBuf* renderbuf);
	
};

#endif
