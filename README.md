# tcall

tcall states for test-call - testing helper that gives ability to call (with passing arguments) any function from library.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

Application req

```
Give examples
```

### Installing

Compilation and instalation differs depending on used operating system.


```
Give the example
```

And repeat

```
until finished
```


## Usage

tcall can be used either by calling from the command line with all the arguments or by specifying file (or files) with sequence of the things to be done. That gives the ability for tcall to be script-friendly and allow to be used for testing inside other tools. 

Application comes with many built-in features that can be used to automate testing like argument generation or taking arguments from external sources (files, devices etc). It simplifies testing as user is not forced to write their own wrappers that eg. generate argument values - tcall can handle that itself and therefore can provide comprehensive testing using one-line invocation.

tcall can be used for testing libraries and binaries (executables). However, main functionality is aimed on libraries and ability to call exported functions. 

tcall argument generators can be used to fuzz testing executables, libraries and almost everything that can be called. 

Another use case for tcall is a need to call something from library from a script (like rundll in Windows). 

### Command line usage

The main 

Usage is the same over the different OS - the one and only difference is how to call the binary itself (./ in Linux/BSD or just by name in Windows).

```
./tcall --target mylib.so --func my_func -1 3 -2 10 -3 "test"

./tcall --target mylib.so --func my_func2 --types int,float,pstr -1 3 -2 1.0 -3 "test2"

./tcall --target mylib.so --func my_func3 --generator 1,int,1-10 --types int,std::string -1 gen1 -2 "tst"

./tcall --target mylib.so --func my_func4 --types p_int,blob48_hex -1 98 -2 "0129ad99cbe1"

./tcall --target mylib.so --func my_func5 --generator 88,blob48_hex --generator 90,pstr --types p_blob48_hex,pstr -1 gen88 -2 gen90  
```

### Batch mode

Batch mode allows user to write files with test sequences to make testing easier when calling the same or similar functions.

```
Give an example
```

### Advanced usage


## Deployment

tcall is ready to be packaged for different operating systems. 

### Linux

Currently there are RPM and DEB-based distros supported (Debian control file and specfile are provided in the repository).

### Windows

Native Windows packaging can be achieved using included Visual Studio project.

Compiled packages with installer are also available from the GitHub project page.

### BSD

There is ability to deploy package as tar.gz.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Versioning

I use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/asmie/tcall). 

## Authors

* **Piotr Olszewski** - *Original work* - [asmie](https://github.com/asmie) [homepage](https://asmie.pl)

See also the list of [contributors](https://github.com/asmie/tcall/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

* Code has been made for security testing purposes.
* 
