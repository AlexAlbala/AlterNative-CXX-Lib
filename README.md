# AlterNative-CXX-Lib [![Build Status](https://travis-ci.org/AlexAlbala/AlterNative-CXX-Lib.svg?branch=master)](https://travis-ci.org/AlexAlbala/AlterNative-CXX-Lib)

C++ library for AlterNative engine

Getting the code
----------------

	git clone https://github.com/AlexAlbala/AlterNative-CXX-Lib.git

Compiling
---------
* Install boost and cmake libraries. For more information see https://github.com/AlexAlbala/Alter-Native Readme
* Run the provided script
  + Windows

                    alternative-lib-compile.bat

  + Linux

                    ./alternative-lib-compile.sh

  + OS X

                    source ./alternative-lib-compile.sh
                    
* Note: If you are compiling the library standalone (without downloading Alter-Native repository), make sure to copy Alter-Native/Tools folder and set ALTERNATIVE_TOOLS_PATH environment variable to this path. Link: https://github.com/AlexAlbala/Alter-Native                  
* If compiled libraries appear in build/libfiles you have finished :)
