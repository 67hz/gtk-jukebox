GTK
===


[getting started app](https://developer.gnome.org/gtk3/stable/gtk-getting-started.html#id-1.2.3.5)
[GTK](https://www.gtk.org/docs/getting-started/hello-world/)



GObject
=======

[gtk gobject intro](https://developer.gnome.org/gobject/stable/chapter-intro.html)
[gobject](https://developer.gnome.org/gobject/stable/)


GStreamer
=========

[spotify plugin](https://github.com/liamw9534/gstspotify)

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


Virtual/Pure Virtual/Private/...
--------------------------------
[notes](https://developer.gnome.org/gobject/stable/howto-gobject-methods.html)


Debugging
---------

[gdb](https://developer.gnome.org/gobject/stable/tools-refdb.html)


Testing
-------
[Check](https://libcheck.github.io/check/)

Docs
----
[Doxygen Examples](http://fnch.users.sourceforge.net/doxygen_c.html)

CLibs
------
[gstreamer tutorial](https://gstreamer.freedesktop.org/documentation/tutorials/index.html?gi-language=c)


gnome-photo
-----------

* see photo-error-box.c/h for GObject usage
