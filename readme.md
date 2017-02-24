Configure with CMake
--------------------

    # 
    # .. set environment variables ..
    #

    cd <BUILD_DIR>
    cmake <PATH_TO_PROJECT> \
          -DCMAKE_PREFIX_PATH=$QT_ANDROID_ROOT \
          -DCMAKE_TOOLCHAIN_FILE=$(pwd)/../submodules/qt-android-cmake/toolchain/android.toolchain.cmake
    make
    adb install -r ./android/bin/QtApp-debug.apk 


Configure with qmake
--------------------

see http://stackoverflow.com/questions/28684647/developing-a-qt-app-for-android-from-the-command-line

    # 
    # .. set environment variables ..
    #

    /path/to/Qt-for-Android/bin/qmake ..
    make
    make install INSTALL_ROOT=android
    /path/to/Qt-for-Android/bin/androiddeployqt --output android --verbose --input android-libTestGeo.so-deployment-settings.json 
    adb install -r android/bin/QtApp-debug.apk

