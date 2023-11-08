#include "RendererAdapter.h"

// Adapter for windows library conio.h
class ConioAdapter: public RendererAdapter{
    public:
        void initialize() override;
        void finalize() override;
        void render() override;
        int handleInput() override;
};
