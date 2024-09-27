mkdir $1

case "$2" in
"cpp")
cp file_templates/source.cpp $1/source.cpp;;

"python" | "py")
cp file_templates/source.py $1/source.py;;

"rust" | "rs")
echo "Not implemented yet!"
rmdir $1;;

*)
echo "Wrong input!"
rmdir $1;;

esac