Import('rtconfig')
from building import *

cwd     = GetCurrentDir()

src = Glob('src/c/core/log/*.c')
src += Glob('src/c/core/serialization/*.c')
src += Glob('src/c/core/session/*.c')
src += Glob('src/c/core/session/stream/*.c')
src += Glob('src/c/profile/transport/serial/serial_transport_external.c')
src += Glob('src/c/profile/transport/serial/serial_transport.c')
src += Glob('src/c/profile/transport/serial/serial_protocol.c')
src += Glob('src/c/profile/transport/ip/udp/udp_transport_external.c')
src += Glob('src/c/profile/transport/ip/udp/udp_transport.c')
src += Glob('src/c/profile/transport/ip/tcp/tcp_transport_external.c')
src += Glob('src/c/profile/transport/ip/tcp/tcp_transport.c')
src += Glob('src/c/util/*.c')
src += Glob('src/ucdr/src/c/*.c')
src += Glob('src/ucdr/src/c/types/*.c')

CPPPATH = [cwd + '/inc',
	cwd + '/src/c/core/log',
	cwd + '/src/c/core/serialization',
	cwd + '/src/c/core/session',
	cwd + '/src/c/core/session/stream',
	cwd + '/src/c/profile/transport/serial',
	cwd + '/src/c/profile/transport/ip/udp',
	cwd + '/src/c/profile/transport/ip/tcp',
	cwd + '/src/c/util',
	cwd + '/src/ucdr/src/c',
	cwd + '/src/ucdr/include']

group = DefineGroup('Micro-XRCE-DDS-Client', src, depend = [], CPPPATH = CPPPATH)

Return('group')
