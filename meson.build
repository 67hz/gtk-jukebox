project(
  'juke-box',
  'c',
  version: '0.0.1',
  license: 'MIT',
  default_options: 'buildtype=debugoptimized',
  meson_version: '>= 0.50.0',
)
gtkdep = dependency('gtk+-3.0')
libcurl4 = dependency('libcurl', version: '>= 4.0')

headers = include_directories('src')

sources = files(
  'main.c',
  './src/connection_manager.c',
)

executable('juke-box',
 'main.c',
 sources,
 include_directories : headers,
 dependencies : [gtkdep, libcurl4]
 )
