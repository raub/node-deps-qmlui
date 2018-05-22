#include <QOffscreenSurface>
#include <QOpenGLContext>

#include "platform.hpp"
#include "qml-renderer.hpp"


QmlRenderer::QmlRenderer(const QString &workingDir, size_t windowHandle, size_t windowContext) {
	
	_directoryPath = workingDir;
	
	NativeContext nativeContext(
		reinterpret_cast<CtxHandle>(windowContext)
#ifndef __APPLE__
		, reinterpret_cast<WndHandle>(windowHandle)
#endif
	);
	QOpenGLContext* extContext = new QOpenGLContext();
	extContext->setNativeHandle(QVariant::fromValue(nativeContext));
	extContext->create();
	
	QSurfaceFormat format;
	format.setDepthBufferSize(16);
	format.setStencilBufferSize(8);
	
	_openglContext = new QOpenGLContext();
	_openglContext->setFormat( format );
	_openglContext->setShareContext( extContext );
	_openglContext->create();
	
	_offscreenSurface = new QOffscreenSurface();
	_offscreenSurface->setFormat(_openglContext->format());
	_offscreenSurface->create();
	
}


QmlRenderer::~QmlRenderer() {
	
	_openglContext->makeCurrent(_offscreenSurface);
	
	delete _offscreenSurface;
	_offscreenSurface = nullptr;
	
	delete _openglContext;
	_openglContext = nullptr;
	
}
