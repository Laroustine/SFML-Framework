#include "ResourceManager/ResourceHolder.hpp"

ResourceHolder& ResourceHolder::get()
{
    static ResourceHolder holder;
    return holder;
}

ResourceHolder::ResourceHolder()
:   fonts           ("fonts", "ttf")
,   textures        ("images", "png")
,   soundBuffers    ("sounds", "ogg")
{

}
