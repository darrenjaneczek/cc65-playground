#!/bin/sh

# This is a CGI script to get the list of files in `output`

# HEADER
echo Content-Type: text/plain
echo

# Currently in vic20-shell/cgi-bin
cd ../..
# Now in the parent of `output`
# The result is listerally the result of `ls`
ls output -R
