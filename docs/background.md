
GObject
=======

[gtk gobject intro](https://developer.gnome.org/gobject/stable/chapter-intro.html)
[gobject](https://developer.gnome.org/gobject/stable/)


Creating Custom GObject
-----------------------

For a type named 'file' in namespace 'viewer', name the type instance: `ViewerFile` and its class `ViewerFileClass`

### Final vs Derivable

Prefer final as it can be converted later but not the other way around

Declare final type: `G_DECLARE_FINAL_TYPE`

Instantiating
-------------

[new() table](https://developer.gnome.org/gobject/stable/gtype-non-instantiable-classed.html)

`instance_init` = similar to C++ ctor

Can never fail. Use `GInitable` and `GAsyncInitable` interfaces in `GIO` lib for fallible objects.






CLibs
------
[gstreamer tutorial](https://gstreamer.freedesktop.org/documentation/tutorials/index.html?gi-language=c)


gnome-photo
-----------

* see photo-error-box.c/h for GObject usage
