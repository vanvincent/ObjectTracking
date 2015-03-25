FILE(REMOVE_RECURSE
  "../srv_gen"
  "../src/colortrack_ros/srv"
  "../srv_gen"
  "CMakeFiles/ROSBUILD_gensrv_py"
  "../src/colortrack_ros/srv/__init__.py"
  "../src/colortrack_ros/srv/_GetDirection.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
