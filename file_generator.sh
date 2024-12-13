mkdir $1

case "$2" in
"cpp")
cp file_templates/source.cpp $1/source.cpp;;

"cpp_custom_algorithms")
cp file_templates/source_with_custom_algorithms.cpp $1/source.cpp
mkdir $1/custom_data_structures
cp custom_data_structures/geometric_line.hpp $1/custom_data_structures/geometric_line.hpp
cp custom_algorithms.hpp $1/custom_algorithms.hpp
;;

"python" | "py")
cp file_templates/source.py $1/source.py;;

"rust" | "rs")
echo "Not implemented yet!"
rmdir $1;;

*)
echo "Wrong input!"
rmdir $1;;

esac