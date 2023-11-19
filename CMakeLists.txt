# 変数SOURCE_CORDEを宣言し、opencv_testという値を入れる。
# cmake -D SOURCE_CODE=(ソース名)で上書き可
set(SOURCE_FILE src) 
file( GLOB MY_SOURCE ${SOURCE_FILE}/*.cpp ${SOURCE_FILE}/*.hpp )

# CMakeの最低バージョンを記述
cmake_minimum_required(VERSION 2.8)

# OpenCVのビルド環境の設定ファイルを読み込む
find_package( OpenCV REQUIRED )

#ヘッダファイルのパスを指定
include_directories( ${OpenCV_INCLUDE_DIRS} )

# 実行ファイル名とソース指定（ここではソースと同じ名前の実行ファイルを作ります）
add_executable( main ${MY_SOURCE} )

# リンク先のライブラリを指定
target_link_libraries( main ${OpenCV_LIBS} )

