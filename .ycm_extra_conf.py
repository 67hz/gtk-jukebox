def Settings( ** kwargs):
    return {
    'flags': [
        '-x',
        'c',
        '-std=c99',
        'fvisibility=hidden',
        '-Wall',
        '-Wextra',
        '-Werror',
        '-I/usr/local/Cellar/gtk+3/3.24.14/include/gtk-3.0',
        ],
    }


        # '`pkg-config --cflags gtk+-3.0`',
        # '`pkg-config --libs gtk+-3.0`',
