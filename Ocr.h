// Ocr.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>
#include <OcrLiteCApi.h>

// TODO: 在此处引用程序需要的其他标头。
class Ocr {
	

public:
	static OCR_HANDLE Init();
	static void Detect(OCR_HANDLE handle, const  char* imagePath, const char* imageName, OCR_PARAM * params);
};