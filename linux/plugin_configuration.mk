# The name of the plugin.
# The primary source file is assumed to be $(PLUGIN_NAME)_plugin.cc, with
# $(PLUGIN_NAME)_plugin.h as the public header meant for inclusion by the
# application.
PLUGIN_NAME=package_info_by_all
# Any files other than the plugin class files that need to be compiled.
EXTRA_SOURCES=
# Extra flags (e.g., for library dependencies).
EXTRA_CXXFLAGS= -gdwarf-2
EXTRA_CPPFLAGS=
EXTRA_LDFLAGS=