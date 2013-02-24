ofxAutoReloadedShader
=====================================


Introduction
------------
ofxAutoReloadedShader is an extended version of ofShader that periodically checks the shader files you have provided it with for changes and reloads them if any have changed.

The sample program 'example-ShaderLiveCoding' shows how this may be of use, simply run the program and open LiveShader.frag or LiveShaderDesktop.frag (depending on platform) in your favourite text editor and the shader will recompile every time you save. Keep an eye on your debug console for an error log should the shader fail to compile.

By default ofxAutoReloadedShader will check for changes every 2 seconds, this can be changed by calling setMillisBetweenFileCheck( int _millis ).

Licence
-------
Distributed under the [MIT License](https://en.wikipedia.org/wiki/MIT_License), see the file 'license.md'.

Installation
------------

Dependencies
------------
None

Compatibility
------------
Created with openFrameworks 0.7.3

Known issues
------------


Version history
------------

### Version 0.1 (24/02/2113):

	First Release.


