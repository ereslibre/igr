#! /usr/bin/env python

VERSION    = '0.0.1'
APPNAME    = 'IGr'
srcdir     = '.'
blddir     = 'build'

def set_options(opt):
    opt.tool_options('compiler_cxx qt4')

def configure(conf):
    conf.check_tool('compiler_cxx qt4')
    if conf.env['COMPILER_CXX'] == []:
        conf.fatal('Un compilador de C++ es requerido. Por favor, instálalo y vuelve a intentarlo')
    conf.find_program('pkg-config')
    conf.env['CXXFLAGS'] += ['-g']
    conf.check_cfg(package = 'QtCore', args = '--cflags --libs')
    conf.check_cfg(package = 'QtGui', args = '--cflags --libs')
    conf.check_cfg(package = 'QtOpenGL', args = '--cflags --libs')
    conf.check_cfg(package = 'glu', args = '--cflags --libs')

def build(bld):
	bld.add_subdirs('esqueleto esqueleto3d practica1 practica2 practica3 practica4 practica5 practica6');
