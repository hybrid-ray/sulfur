building from source:
Note: building from source on windows is pain, because you need visual studio.
first you need boost
download boost at https://www.boost.org/users/download/
build boost
copy boost_iostreams library (libboost_iostreams.a or boost_iostreams.lib) into libs/libs/
Note: it should be in boost_dir/stage/lib/
`sulfur/build> cmake .. [flags]`
and then continue with `make` or vs depending on platform and cmake generator
output should be in ./out/
