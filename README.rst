P Y T H O N - S T R E A M A N A L Y Z E R
-----------------------------------------

This project is part of the streamanalyzer-bindings project (http://github.com/ustramooner/streamanalyzer-bindings).

The streamanalyzer module is a set of python bindings around Strigi's libstreams and libstreamanalyzer.

These bindings only expose the libstreams and libstreamanalyzer capabilities in order to make it easy to create your own indexer, or meta data extractor. It is also possible to create analyzers plugins in python.

After installing, have a look at the samples and test folder to see how to create your first python-streamanalyzer app. 


Ubuntu Packages
-----------------------------
Ubuntu packages are available from my ppa. To get them, run:

 sudo add-apt-repository ppa:ustramooner
 
 sudo apt-get update
 
 sudo apt-get install python-streamanalyzer

Installing from source
-------------------------------------
You will need the following packages installed:
 * python (I have only tested 2.6.6 so far)
 * Strigi (Install libstreams-dev and libstreamanalyzer-dev or get it from http://sf.net/projects/strigi )

 # cd <python-streamanalyzer-dir>/python/
 
It is better to use a package, so that you can remove it:
 # python setup.py bdist_rpm
If you are on a debian system, convert the rpm into a deb
 # fakeroot alien --to-deb `ls python-streamanalyzer-*.rpm|grep -v src`

Then install the resulting rpm or deb from the `dist` folder.

Or you can intall it directly using
 # python setup.py install

H A C K I N G
-------------
If you want to make changes to the code, you will need the full source distribution,
you can find that at https://github.com/ustramooner/streamanalyzer-bindings
You will also need cmake 2.8+ and swig version 2.0.1.
Note that different swig versions are known to create changes that break the system.
If you use another version, be sure to do a diff of what gets created before actually 
changing something

 # cd <python-streamanalyzer-dir>/python/

 # mkdir build &&  cd build

 # bash ../swigme

Make python look for the module here since it's not installed.
 # export PYTHONPATH=`pwd`:`cd ../ && pwd`

Testing
 * Note: Currently the test suite is not very complete
 * You'll need python-unittest2 installed
 * Run:
 # python ../test/BaseTestCase.py

