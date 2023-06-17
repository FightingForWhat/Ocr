// Ocr.cpp: 定义应用程序的入口点。
//

#include "Ocr.h"
#include <Windows.h>
using namespace std;

#pragma execution_character_set( "utf-8" )


OCR_HANDLE Ocr::Init() {

	try
	{
		const char* DET_MODEL = "models/ch_PP-OCRv3_det_infer.onnx";
		const char* CLS_MODEL = "models/ch_ppocr_mobile_v2.0_cls_infer.onnx";
		const char* REC_MODEL = "models/ch_PP-OCRv3_rec_infer.onnx";
		const char* KEY_FILE = "models/ppocr_keys_v1.txt";
		int THREAD_NUM = 3;
		OCR_HANDLE handle = OcrInit(DET_MODEL, CLS_MODEL, REC_MODEL, KEY_FILE, THREAD_NUM);
		return handle;
	}
	catch (const std::exception&)
	{
		return NULL;
	}

}

void Ocr::Detect(OCR_HANDLE handle, const char * imagePath, const  char* imageName, OCR_PARAM * params) {
	// const char * iPath = imageName.c_str()
	OCR_BOOL bRet = OcrDetect(handle, imagePath, imageName, params);
	if (bRet) {
		int nLen = OcrGetLen(handle);
		if (nLen > 0) {
			char* szInfo = (char*)malloc(nLen);
			if (szInfo) {
				if (OcrGetResult(handle, szInfo, nLen)) {
					printf("%s", szInfo);
				}
				free(szInfo);
			}
		}
	}
}

int main()
{

	SetConsoleOutputCP(65001);
	
	try {
		OCR_HANDLE handle = Ocr::Init();
		if (handle) {
			bool isContinue = true;
			OCR_PARAM param = { 0 };
			string imagePath;
			string imageName;
			cout << "\n\n\n";
			cout << "请输入图片路径：" << endl;
			cin >> imagePath;
			if (!imagePath.empty()) {
				size_t i = imagePath.find('.');
				if (i == string::npos) {
					cout << "请输入图片名称：" << endl;
					cin >> imageName;
					cout << endl;
					if (imagePath[-1] != '\\') {
						imagePath += '\\';
					}
					Ocr::Detect(handle, imagePath.data(), imageName.data(), &param);
				}
				else {
					size_t m = imagePath.rfind('\\');
					imageName = imagePath.substr(m + 1);
					imagePath = imagePath.substr(0, m + 1);
					Ocr::Detect(handle, imagePath.data(), imageName.data(), &param);
				}

			}
			else
			{
				cout << "输入为空" << endl;
			}
			cout << "\n\n\n";
		}
		else {
			cout << "初始化失败， 请检查配制文件及路径" << endl;
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}
