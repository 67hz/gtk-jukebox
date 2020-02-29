project(
  'musicplayer',
  'c',
  version: '0.0.1',
  license: 'MIT',
  default_options: 'buildtype=debugoptimized',
  meson_version: '>= 0.50.0',
)
gtkdep = dependency('gtk+-3.0')
libcurl4 = dependency('libcurl', version: '>= 4.0')

srcdir = include_directories('musicplayer')

executable('player',
 'main.c',
 include_directories : srcdir,
 dependencies : [gtkdep, libcurl4]
 )
