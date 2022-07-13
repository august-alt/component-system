#include "plugin.h"

#include "bazsnapin.h"

#include "isnapin.h"

namespace gpui
{
class BazPlugin : public Plugin
{
public:
    BazPlugin()
        : Plugin("BazPlugin")
    {
        GPUI_REGISTER_PLUGIN_CLASS(typeid(::gpui::ISnapIn).name(), BazSnapIn);
    }
};
} // namespace gpui

GPUI_EXPORT_PLUGIN(admx, gpui::BazPlugin)
