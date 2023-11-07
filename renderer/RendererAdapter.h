#ifndef _RENDERERADAPTER_H_
#define _RENDERERADAPTER_H_

class RendererAdapter{
    public:
        virtual void initialize() = 0;
        virtual void finalize() = 0;
        virtual void render() = 0;
        virtual void handleInput() = 0;
};

#endif
