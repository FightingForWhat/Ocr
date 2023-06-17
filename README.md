# Ocr
图片文字Ocr识别


基于 RapidOcrOnnx 项目

Based on the Project of RapidOcrOnnx


target: https://github.com/RapidAI/RapidOcrOnnx


编译：
将source code下载，执行build_windows.bat

文件树如下：
```
.
│  build_windows.bat
│  CMakeLists.txt
│  CMakeSettings.json
│  Ocr.cpp
│  Ocr.h
│
└─OcrLib
    ├─bin
    │      RapidOcrOnnx.dll
    │
    ├─include
    │      AngleNet.h
    │      CrnnNet.h
    │      DbNet.h
    │      getopt.h
    │      main.h
    │      OcrLite.h
    │      OcrLiteCApi.h
    │      OcrResultUtils.h
    │      OcrStruct.h
    │      OcrUtils.h
    │      version.h
    │
    └─lib
            RapidOcrOnnx.lib
```
