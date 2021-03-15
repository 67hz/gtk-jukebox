project(
  'juke-box',
  'c',
  version: '0.0.1',
  license: 'MIT',
  default_options: 'buildtype=debugoptimized',
  meson_version: '>= 0.50.0',
)

add_global_arguments('-DDEBUG', '-ggdb3', language: 'c')
# Use cc to query properties of compiler
# e.g., has_function(funcname)
# https://mesonbuild.com/Reference-manual.html#compiler-object
cc = meson.get_compiler('c')


gtkdep = dependency('gtk+-3.0')
glib = dependency('glib-2.0', version: '>=2.44')
libcurl4 = dependency('libcurl', version: '>= 4.0')
gstreamer1 = dependency('gstreamer-1.0')

headers = include_directories(
  'src',
  # 'src/core',
  # 'src/config',
)

sources = files(
  'main.c',
  './src/connection_manager.c',
  './src/jukebox-song-player.c',
  './src/jukebox-login-box.c',
  './src/jukebox-user.c',
  './src/jukebox-authorize-user.c',
  './src/core/jukebox-core.c',
)

executable('juke-box',
 'main.c',
 sources,
 include_directories : headers,
 dependencies : [glib, gtkdep, libcurl4, gstreamer1]
 )
