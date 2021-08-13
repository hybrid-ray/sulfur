building from source:<br>
Note: building from source on windows is pain, because you need visual studio.<br>
first you need boost<br>
download boost at https://www.boost.org/users/download/<br>
build boost<br>
copy boost_iostreams library (libboost_iostreams.a or boost_iostreams.lib) into libs/libs/<br>
Note: it should be in boost_dir/stage/lib/<br>
`sulfur/build> cmake .. [flags]`<br>
and then continue with `make` or vs depending on platform and cmake generator<br>
output should be in ./out/<br>
