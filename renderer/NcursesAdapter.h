#include "RendererAdapter.h"

class NcursesRenderer: public RendererAdapter{
    public:
        void initialize() override;
        void finalize() override;
        void render() override;
        void handleInput() override;
};
